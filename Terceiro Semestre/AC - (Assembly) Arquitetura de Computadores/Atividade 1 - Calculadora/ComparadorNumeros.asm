# Definição e Registro de Variáveis
li $t1, 30	# Registra em $t1 o valor 30
li $t2, 20	# Registra em $t2 o valor 20
li $t3, 0	# Registra em $t3 o valor 0


# Comparação Igualdade
beq $t1, $t2, igual	# A função 'beq' compara os valores registrados em $t1 e $t2, caso sejam iguais, o programa seguirá para o Bloco "igual"


# Comparação Maior-Menor
slt $t0, $t1, $t2 	# A função 'slt' verifica se '$t1 < $t2' é verdadeiro ou falso e registra o resultado em $t0, sendo: 0 = FALSO || 1 = VERDADEIRO


#Desvio Maior
beq $t0, $t3, maior	# A função 'beq' compara os valores registrados em $t0 e $t3, caso sejam iguais, o programa seguiá para o Bloco "maior"
			# Isso se traduz em, se o resultado de '$t1 < $t2' for igual a zero, significa que o valor registrado em $t1 é o maior valor, pois '$t1 < $t2' é FALSO (=0)

#Desvio Menor
bne $t0, $t3, menor	# A função 'bne' compara os valores registrados em $t0 e $t3, caso sejam diferentes, o programa seguiá para o Bloco "menor"
			# Isso se traduz em, se o resultado de '$t1 < $t2' for diferente de 0, significa que o valor registrado em $t1 é o menor valor, pois '$t1 < $t2' é VERDADEIRO (=1)
	

maior:
	move $t5, $t1	# Aloca no espaço $t5 o mesmo conteúdo de $t1, ou seja, o MAIOR VALOR
	j fim		# Pula para o Bloco "fim"
	
menor:
	move $t5, $t2	#Aloca no espaço $t5 o mesmo conteúdo de $t2, ou seja, o MAIOR VALOR
	j fim		# Pula para o Bloco "fim"
	
igual:
	move $t5, $t2	#Aloca no espaço $t5 o mesmo conteúdo de $t2, como ambos são iguais, ambos são o MAIOR VALOR
	j fim		# Pula para o Bloco "fim"

fim:			# Encerra o programa
			
