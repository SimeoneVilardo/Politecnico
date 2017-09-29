.data
	.eqv PRINT_INT 1
	.eqv EXIT 10
	.eqv PRINT_STR 4
	.eqv READ_INT 5
	
	prompt_ask_num: .asciiz "Inserire un numero: "
	msg_result: .asciiz "Il fattoriale è: "

.text
	.globl main
		main:
			la $a0, prompt_ask_num
			jal print_str
			jal read_int
			move $a0, $v0
			jal factorial
			move $s0, $v0
			la $a0, msg_result
			jal print_str
			move $a0, $s0
			jal print_int
			
			# Termina
			li $v0, EXIT
			syscall
			
			
		factorial:
			addiu $sp, $sp, -8
			sw $ra, 4($sp)
			sw $s0, 0($sp)
			li $v0, 1
			blt $a0, 1, if
			move $s0, $a0
			addi $a0, $a0, -1
			jal factorial
			mul $v0, $v0, $s0
			if: lw $ra, 4($sp)
			lw $s0, 0($sp)
			addiu $sp, $sp, 8
			jr $ra
			
		print_int:
			li $v0, PRINT_INT
			syscall
			jr $ra
			
			
		print_str:
			li $v0, PRINT_STR
			syscall
			jr $ra 		
		
		
		read_int:
			li $v0, READ_INT
			syscall
			jr $ra