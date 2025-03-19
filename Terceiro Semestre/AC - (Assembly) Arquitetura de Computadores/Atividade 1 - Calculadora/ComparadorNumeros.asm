li $t1, 30
li $t2, 20
li $t3, 0

beq $t1, $t2, igual


slt $t0, $t1, $t2 # Compara de t1 < t2
# 0 = Não || 1 = Sim

#Desvio Maior
beq $t0, $t3, maior

#Desvio Menor
bne $t0, $t3, menor

#Desvio Igual
beq $t0, $t3, igual

maior:
	move $t5, $t1
	j fim
	
menor:
	move $t5, $t2
	j fim
	
igual:
	move $t5, $t2
	j fim

fim:
	syscall