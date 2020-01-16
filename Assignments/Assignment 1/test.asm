TITLE Assignment No. 1

Include irvine32.inc

.data
	gradeAverage DWORD ?
	credits DWORD ?

	msg1 byte "Please enter grade average  : ", 0
	msg2 byte "Please enter credits        : ", 0

	msg3 byte "Error in values.", 0dh, 0ah, 0
	msg4 byte "You Cannot Register.", 0dh, 0ah, 0
	msg5 byte "You Can Register.", 0dh, 0ah, 0

.code
Main Proc 

;input gradeAverage
	mov edx, OFFSET msg1
	call WriteString		;print msg1
	call ReadInt
	mov  gradeAverage, eax		;input from user
;input credits
	mov edx, OFFSET msg2
	call WriteString		;print msg1
	call ReadInt
	mov  credits, eax		;input from user

;check ranges of gradeAverage & credits
	cmp word ptr gradeAverage, 400
	ja err_ext
	cmp word ptr credits, 30
	ja err_ext
	cmp word ptr gradeAverage, 0
	jb err_ext
	cmp word ptr credits, 0
	jb err_ext

;check whether user can register or not
	cmp word ptr gradeAverage, 350
	jbe condtn1
	jmp CanRegister
condtn1:				;condition 1
	cmp word ptr gradeAverage,250
	jbe condtn2
	cmp word ptr credits,16
	ja condtn2
	jmp CanRegister
condtn2:				;condition 2
	cmp word ptr credits,12
	ja CanRegister
	jmp NotRegister

;Exiting program with the respective message
err_ext:
	mov edx, OFFSET msg3
	call WriteString
	jmp extpgm
NotRegister:
	mov edx, OFFSET msg4
	call WriteString
	jmp extpgm
CanRegister:
	mov edx, OFFSET msg5
	call WriteString
	jmp extpgm
extpgm:
	exit

Main endp
End main
