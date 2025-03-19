#Converter o seguinte código de C em Assembly:
#if (x == y)
 #z = 2;
 #else
 #z = 3;
 
 li $t0, 3
 li $t1, 2
 
 beq $t0, $t1, igual
 bne $t0, $t1, diferente
 
 igual:
 	li $t5, 2
 	j fim
 	
 diferente:
 	li $t5, 3
 	j fim
 	
 fim:
 	syscall
