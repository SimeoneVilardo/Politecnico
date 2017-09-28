# Simeone Vilardo 28/09/2017

.data
	.eqv PRINT_INT 1
	.eqv PRINT_STR 4
	.eqv READ_INT 5
	.eqv ALLOCATE_HEAP 9
	.eqv EXIT 10
	prompt_len: .asciiz "Inserire la lunghezza dell'array: "
	prompt_elem: .asciiz "Inserire l'elemento numero "
	colon: .asciiz ": "
	prompt_result: .asciiz "Il risultato della somma di ogni elemento nell'array è: "
	prompt_ltz: .asciiz "Il risultato è minore di 0"
	prompt_gtz: .asciiz "Il risultato è maggiore di 0"
	prompt_eqz: .asciiz "Il risultato è esattamente 0"
	new_line: .asciiz "\n"
	
.text
	.globl main
		# $s0 = lenght array
		# $s1 = base array address
		# $s2 = current iteration index
		# $s3 = current array address
		# $s4 = sum result
		# $t0 = array address offset
		main:
			la $a0, prompt_len
			jal print_str
			
			jal read_int
			move $s0, $v0
			
			# Passaggio come parametro della lunghezza dell'array moltiplicata per 4 (int)
			move $a0, $s0
			jal allocate_heap
			
			move $s1, $v0
			
			li $s2, 0
			
			while_load_arr: bge $s2, $s0, end_while_load_arr
			sll $t0, $s2, 2
			addu $s3, $s1, $t0
			
			la $a0, prompt_elem
			jal print_str
			addi $a0, $s2, 1
			jal print_int
			la $a0, colon
			jal print_str
			
			jal read_int
			sw $v0, 0($s3)
			
			addi $s2, $s2, 1
			j while_load_arr
			
			end_while_load_arr: move $a0, $s0
			move $a1, $s1
			
			jal sum_array
			move $s4, $v0
			jal print_new_line
			
			bgt $s4, $zero, if
			blt $s4, $zero, else
			la $a0, prompt_eqz
			j end_if
			if: la $a0, prompt_gtz
			j end_if
			else: la $a0, prompt_ltz
			j end_if
			end_if: jal print_str
			
			li $v0, EXIT
			syscall
			
			
		# $a0 = lenght array	
		# $a1 = base array address
		# $s0 = current iteration index
		# $s2 = current array address
		# $s3 = sum result
		# $t1 = array address offset
		# $t2 = current array element
		sum_array:
			addiu $sp, $sp, -20
			sw $ra, -16($sp)
			sw $s0, -12($sp)
			sw $s1, -8($sp)
			sw $s2, -4($sp)
			sw $s3, 0($sp)

			li $s0, 0
			li $s3, 0
			
			while_print_arr: bge $s0, $a0, end_while_print_arr
			sll $t1, $s0, 2
			addu $s2, $a1, $t1
			
			lw $t2, 0($s2)
			add $s3, $s3, $t2
			
			addi $s0, $s0, 1
			j while_print_arr
			
			end_while_print_arr: la $a0, prompt_result
			jal print_str
			move $a0, $s3
			jal print_int
			move $v0, $s3
			
			lw $ra, -16($sp)
			lw $s0, -12($sp)
			lw $s1, -8($sp)
			lw $s2, -4($sp)
			lw $s3, 0($sp)
			addiu $sp, $sp, 12

			jr $ra
			
			
		allocate_heap:
			sll $a0, $a0, 2
			li $v0, ALLOCATE_HEAP
			syscall
			jr $ra
		
		
		print_int:
			li $v0, PRINT_INT
			syscall
			jr $ra
			
			
		print_str:
			li $v0, PRINT_STR
			syscall		
			jr $ra
			
		print_new_line:
			addiu $sp, $sp, 4
			sw $ra, 0($sp)
			la 	$a0, new_line
			jal print_str
			lw $ra, 0($sp)
			addiu $sp, $sp, -4
			jr $ra
			
		read_int:
			li $v0, READ_INT
			syscall	
			jr $ra		
