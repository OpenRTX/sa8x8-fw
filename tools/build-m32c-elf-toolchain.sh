#!/usr/bin/env -S bash -x

ctr=$(buildah from docker.io/library/alpine:3.18)

name=m32c-elf-toolchain
user=toolbox

makdeps="build-base gmp-dev mpfr-dev mpc1-dev zlib-dev diffutils automake texinfo"
rundeps="sudo gmp mpfr mpc1 make nano git"

binutils_ver="2.30"
binutils_uri="https://ftp.gnu.org/gnu/binutils/binutils-${binutils_ver}.tar.gz"

gcc_ver="6.5.0"
gcc_uri="https://ftp.gnu.org/gnu/gcc/gcc-${gcc_ver}/gcc-${gcc_ver}.tar.gz"

newlib_ver="3.0.0"
newlib_uri="https://sourceware.org/pub/newlib/newlib-${newlib_ver}.tar.gz"

gdb_ver="8.0.1"
gdb_uri="https://sourceware.org/pub/gdb/releases/gdb-${gdb_ver}.tar.gz"

target=m32c-elf
tmp="/tmp"
workdir="/build"
prefix="/usr/local"
njobs="$(nproc)"

buildah config --annotation com.github.build.host=$(uname -n) $ctr

buildah run $ctr -- apk add --no-cache $makdeps $rundeps

buildah run $ctr -- adduser -D $user
buildah run $ctr -- sh -c "echo '$user ALL=(ALL) NOPASSWD: ALL' >> /etc/sudoers.d/toolbox"

buildah add $ctr $binutils_uri $tmp
buildah add $ctr $gcc_uri      $tmp
buildah add $ctr $newlib_uri   $tmp
buildah add $ctr $gdb_uri      $tmp

buildah config --workingdir $workdir $ctr
buildah run $ctr -- tar xf "${tmp}/binutils-${binutils_ver}.tar.gz"
buildah run $ctr -- rm     "${tmp}/binutils-${binutils_ver}.tar.gz"
buildah run $ctr -- tar xf "${tmp}/gcc-${gcc_ver}.tar.gz"
buildah run $ctr -- rm     "${tmp}/gcc-${gcc_ver}.tar.gz"
buildah run $ctr -- tar xf "${tmp}/newlib-${newlib_ver}.tar.gz"
buildah run $ctr -- rm     "${tmp}/newlib-${newlib_ver}.tar.gz"
buildah run $ctr -- tar xf "${tmp}/gdb-${gdb_ver}.tar.gz"
buildah run $ctr -- rm     "${tmp}/gdb-${gdb_ver}.tar.gz"

buildah config --workingdir "${workdir}/binutils-${binutils_ver}/m32c_build" $ctr
buildah run $ctr -- ../configure \
	--target=${target} \
	--prefix=${prefix} \
	--disable-nls \
	--with-system-zlib
buildah run $ctr -- make -j${njobs}
buildah run $ctr -- make install

buildah config --workingdir "${workdir}/gcc-${gcc_ver}/m32c_build" $ctr
buildah run $ctr -- ../configure \
	--target=${target} \
	--prefix=${prefix} \
	--enable-languages=c \
	--disable-libssp \
	--with-newlib \
	--disable-nls \
	--disable-threads \
	--disable-libgomp \
	--disable-libmudflap \
	--disable-libstdcxx-pch \
	--disable-multilib \
	--enable-lto \
	--with-system-zlib
buildah run $ctr -- make -j${njobs}
buildah run $ctr -- make install

buildah config --workingdir "${workdir}/newlib-${newlib_ver}/m32c_build" $ctr
buildah run $ctr -- ../configure \
	--target=${target} \
	--prefix=${prefix}
buildah run $ctr -- make -j${njobs}
buildah run $ctr -- make install

buildah config --workingdir "${workdir}/gdb-${gdb_ver}/m32c_build" $ctr
buildah run $ctr -- ../configure \
	--target=${target} \
	--prefix=${prefix}
buildah run $ctr -- make -j${njobs}
buildah run $ctr -- make install

buildah config --workingdir "/home/${user}" $ctr
buildah run $ctr -- rm -rf "${workdir}"
buildah run $ctr -- apk del $makdeps

buildah config --user $user $ctr

buildah commit --rm $ctr $name:latest
