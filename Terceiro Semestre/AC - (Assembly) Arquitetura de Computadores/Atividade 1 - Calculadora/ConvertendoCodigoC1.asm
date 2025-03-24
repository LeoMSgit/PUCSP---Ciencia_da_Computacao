#Converter o seguinte código de C para Assembly:
#if (x == y)
 #z = 2;
 #else
 #z = 3;
 
 li $t0, 3			# Registra em $t0 o valor da variável x em C, 3
 li $t1, 2			# Registra em $t1 o valor da variável y em C, 2
 
 beq $t0, $t1, igual		# A função 'beq' compara os valores registrados em $t0 e $t1, caso sejam iguais, o programa seguirá para o Bloco "igual"
 				# Essa função equivale ao 'if (x == y)' em C

 bne $t0, $t1, diferente	# A função 'bne' compara os valores registrados em $t0 e $t1, caso sejam diferentes, o programa seguiá para o Bloco "diferente"
 				# Essa função equivale ao 'else' em C, pois cobre qualquer outra possibilidade da comparação
 				
 igual:
 	li $t5, 2		# Registra em $t5 o valor 2
 				# Isso equivale ao 'z = 2' em C
 	j fim			# Pula para o Bloco "fim"
 	
 diferente:
 	li $t5, 3		# Registra em $t5 o valor 3
 				# Isso equivale ao 'z = 3' em C
 	j fim			# Pula para o Bloco "fim"
 	
fim:				# Encerra o programa
 	
