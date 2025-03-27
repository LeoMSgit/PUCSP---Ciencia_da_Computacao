li $t0, 5          		# Carrega o valor para calcular o fatorial
li $t5, 1         		# Inicializa o resultado como 1
    
blez $t0, end     		# Caso especial se o valor for 0, encerra o códico com valor padrão de $t5
beq $t0, $t5, end      		# Caso especial se o valor for 1, encerra o códico com valor padrão de $t5

fatorial_loop:
    mul $t5, $t5, $t0   	# Multiplica o resultado pelo valor atual de $t0
    subi $t0, $t0, 1    	# Decrementa $t0, ou seja, forma o "próximo" número da fatoração
    bgtz $t0, fatorial_loop 	# Se $t0 ainda for maior que zero, continua o loop

end:
