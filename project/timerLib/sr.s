.arch msp430g2553
.p2align 1,0
.text

;; Routines to access and manipulate SR (Status Register)

.global set_sr
set_sr:
    ; Save the value in R12 to SR
    mov r12, r2
    ret

.global get_sr
get_sr:
    ; Load SR value into R12
    mov r2, r12
    ret

.global or_sr
or_sr:
    ; OR the value in R12 with SR
    bis r12, r2
    ret

.global and_sr
and_sr:
    ; AND the value in R12 with SR
    and r12, r2
    ret
