$NOMOD51 			; suppress pre-definition of 8051 SFR names 
					; core SFRs (ACC, B, DPL, DPH, PSW, SP) remain defined 

$include (aduc834.h) 	; include ADuC834 symbols 

; ___________________________________________________________________ 
; user symbols here 
FAN EQU P1.0 			; P1.0 toggles the fan 

; ___________________________________________________________________ 
CSEG 					; Code SEGment starts here 

ORG 0000H 				; set ORiGin for subsequent statements at 0000H 
	JMP START 			; jump to START (0060H) 
	
ORG 0060H 				; main program starts here 
START: 
; initialization starts here 
; code between START and LOOP labels is intended 
; for a single execution at the beginning of the program 
	MOV SP,#7FH 		; set the stack pointer to 0x7F (hex) 
	MOV P0,#0 			; turn the motor off 
	CLR FAN 			; turn the fan off 
	
LOOP: 
; main program loop 

	JMP LOOP 
; _________________________________________________________________ 
; subroutines and interrupt service routines start here 
DELAY: 
; subroutine example 
	NOP 
	RET 
; _________________________________________________________________ 
END 					; compiled code ends here