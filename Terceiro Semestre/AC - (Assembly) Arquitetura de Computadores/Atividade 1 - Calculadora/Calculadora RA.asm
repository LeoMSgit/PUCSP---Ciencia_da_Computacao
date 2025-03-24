# Definição e Registro de Variáveis
li $t0, 3	# Registra em $t0 o valor 3
li $t1, 5	# Registra em $t0 o valor 5  
li $t2, 2	# Registra em $t0 o valor 2   
li $t3, 9	# Registra em $t0 o valor 9                    
#RA = 323595

# Operações de Adição das Variáveis        
add $t6, $t0, $t1  # Registra em $t6 o resultado da operação de adição ('add') dos valores registrados em $t0 e $t1 -> 3 + 5 = 8
add $t7, $t0, $t2  # Registra em $t7 o resultado da operação de adição ('add') dos valores registrados em $t0 e $t2 -> 3 + 2 = 5
add $t8, $t3, $t1  # Registra em $t8 o resultado da operação de adição ('add') dos valores registrados em $t3 e $t1 -> 9 + 5 = 14

# Operações de Adição dos Resultados   
add $t9, $t6, $t7  # Registra em $t9 o resultado da operação de adição ('add') dos resultados registrados em $t6 e $t7 -> 8 + 5 = 13
add $t0, $t9, $t8  # Registra em $t0 o resultado da operação de adição ('add') dos resultados registrados em $t9 e $t8 -> 13 + 14 = 27

#RESULTADO(Hexadecimal) = 1b ou 27
