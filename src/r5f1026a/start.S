    .list

    .global __rl78_fini
    .type __rl78_fini,@function

__rl78_fini:
    br $__rl78_fini

    .extern _data
    .extern _mdata
    .extern _ebss
    .extern _bss
    .extern _edata
    .extern _main
    .extern _stack

    .text

    .global _PowerOnReset ; global start routine
    .type _PowerOnReset,@function

_PowerOnReset:
    movw sp, #_stack    ; set stack pointer

    ;; hl = start of list
    ;; de = end of list
    ;; bc = step direction (+2 or -2)
    ;;
    ;; block move to initialize .data
    ;; we're copying from 00:[_romdatastart] to 0F:[_datastart]
    ;; and our data is not in the mirrored area

    /* load data section from rom to ram */

    mov     es, #0
#ifndef __RL78_G10__
    sel     rb0         ; bank 0
#endif
    movw    de, #_mdata ; src rom address of data section in de
    movw    hl, #_data  ; dest start ram address of data section in hl
#ifndef __RL78_G10__
    sel     rb1         ; bank 1
    movw    hl, #_data  ; dest start ram address of data section in hl
#endif
    movw    ax, #_edata ; size of romdata section in ax
    subw    ax, hl      ; store data size
    shrw    ax, 1
1:
    cmpw    ax, #0      ; check if end of data
    bz      $1f
    decw    ax
#ifdef __RL78_G10__
    movw     bc, ax     ; save ax value in bc
#endif

#ifndef __RL78_G10__
    sel     rb0         ; bank 0
#endif
    movw    ax, es:[de]
    movw    [hl], ax
    incw    de
    incw    de
    incw    hl
    incw    hl
#ifndef __RL78_G10__
    sel     rb1         ; bank 1 - compare and decrement
#endif

#ifdef __RL78_G10__
    movw     ax, bc     ; restore ax value
#endif
    br      $1b
1:

/* bss initialization: zero out bss */

#ifndef __RL78_G10__
    sel     rb0         ; bank 0
    movw    ax, #0      ; load ax reg with zero
    sel     rb1         ; bank 1
    movw    ax, #_ebss  ; store the end address (size of) bss section in ax
    movw    hl, #_bss   ; store the start address of bss in hl
    subw    ax, hl      ; store data size
    shrw    ax, 1
#endif

#ifdef __RL78_G10__
    movw    hl, #_bss   ; store the start address of bss in hl
    movw    ax, #_ebss  ; store the end address (size of) bss section in ax
    subw    ax,hl       ; store data size
    shrw    ax,1
#endif

1:
    cmpw    ax, #0
    bz      $1f
    decw    ax
#ifdef __RL78_G10__
    movw    bc, ax      ; save ax value in bc
    movw    ax, #0
#endif
#ifndef __RL78_G10__
    sel     rb0         ; bank 0
#endif
    movw    [hl], ax
    incw    hl
    incw    hl
#ifdef __RL78_G10__
    movw    ax, bc      ; restore ax value
#endif
#ifndef __RL78_G10__
    sel     rb1
#endif
    br      $1b
1:
#ifndef __RL78_G10__
    sel     rb0         ; bank 0
#endif

    movw    ax, #0
    push    ax          ; envp
    push    ax          ; argv
    push    ax          ; argc
    call    !!_main     ; start user program

    .global _exit
    .type   _exit,@function

_exit:
    br      $_exit      ; call to exit

    .end

