#Converter o seguinte código de C em Assembly:
#x = 8;
#y = 4;
#i = 2;
#while(i > 0){
#y = y + 2;
#i = i - 1;
#}
#z = x + y;
 
 li $t0, 8			# Registra em $t0 o valor da variável x em C, 8
 li $t1, 4			# Registra em $t0 o valor da variável y em C, 4
 li $t2, 2			# Registra em $t0 o valor da variável i em C, 2
 li $t4, 0			# Registra em $t0 o valor da variável de comparaçáo em C, o 0
 
 loop: 				# Condições de execução do loop 'while()'
 beq $t2, $t4, igual		# A função 'beq' compara os valores registrados em $t2 e $t4, caso sejam iguais, o programa seguirá para o Bloco "igual"
 				# Isso representa a condição do loop 'while(i > 0)' em C, para os casos em que a condição é descumprida (i == 0)
 				
 bne $t2, $t4, diferente	# A função 'bne' compara os valores registrados em $t2 e $t4, caso sejam diferentes, o programa seguiá para o Bloco "diferente"
 				# Isso representa a condição do loop 'while(i > 0)' em C, para os casos em que a condição é cumprida (i != 0)
 				
 				
 igual:
 	add $t5, $t0, $t1	# Registra em $t5 o resultado da operação de adição ('add') dos valores registrados em $t0 e $t1
 				# Representa a operação 'z = x + y' em C
 	j fim			# Pula para o Bloco "fim"
 	
 diferente:
 	addi $t1, $t1, 2	# Registra em $t1 o resultado da operação de adição com inteiro ('addi') do valor registrados no próprio $t1 e o inteiro 2
  				# Representa a operação 'y = y + 2' em C
 	subi $t2, $t2, 1	# Registra em $t1 o resultado da operação de subtração com inteiro ('subi') do valor registrados no próprio $t2 e o inteiro 1
 				# Representa a operação 'i = i - 1' em C
 	j loop			# Pula para o Bloco "loop", para ser rodado novamente, pois a condição ainda está sendo comprida (i != 0)
 	
fim:				# Encerra o programa
 	
