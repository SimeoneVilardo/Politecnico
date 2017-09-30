.data
	prompt_ask_word: .asciiz "Inserisci una parola: "
	msg_result_yes: .asciiz "La parola inserita è palindroma"
	msg_result_no: .asciiz "La parola inserita NON è palindroma"
	user_word: .space 20
	.eqv LF 10
	
.text
	.globl main
		main:
			la $a0, prompt_ask_word
			jal print_str
			jal read_str
			la $a0, user_word
			jal get_length
			move $a1, $v0
			jal palindrome
			beq $v0, $zero, else
			la $a0, msg_result_yes
			j end_if
			else: la $a0, msg_result_no
			end_if: jal print_str		
			#Termina
			li $v0, 10
			syscall	
			
		# $s0 = iteration index
		# $t0 = array index		
		# $t1 = current array value
		get_length:
			addiu $sp, $sp, -4
			sw $s0, 0($sp)
			li $s0, 0
			while: bge $s0, 20, end_while
			addu $t0, $a0, $s0	
			lb $t1, 0($t0)
			beq $t1, LF, end_while
			addi $s0, $s0, 1
			j while
			end_while: move $v0, $s0
			lw $s0, 0($sp)
			addiu $sp, $sp, 4
			jr $ra
			
		palindrome:
			addiu $sp, $sp, -12
			sw $ra, 8($sp)
			sw $s0, 4($sp)
			sw $s1, 0($sp)		
			li $v0, 1
			ble $a1, 1, base_case
			lb $s0, 0($a0) # Prima lettera
			addi $t0, $a1, -1 # Lunghezza parola -1, indice ultima lettera
			addu $t1, $a0, $t0 # Indirizzo valore ultima lettera in memoria
			lb $s1, 0($t1) # Ultima lettera
			addu $a0, $a0, 1
			addi $a1, $a1, -2
			jal palindrome
			lw $ra, 8($sp)
			lw $s0, 4($sp)
			lw $s1, 0($sp)	
			addiu $sp, $sp, 12
			base_case: bne $s0, $s1, else_palindrome
			and $v0, $v0, 1
			jr $ra
			else_palindrome: li $v0, 0
			jr $ra
		
		print_str:
			li $v0, 4
			syscall
			jr $ra
			
		read_str:
			li $v0, 8,
			la $a0, user_word
			li $a1, 20
			syscall		
			jr $ra			
