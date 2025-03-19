#Converter o seguinte código de C em Assembly:
#x = 8;
#y = 4;
#i = 2;
#while(i > 0){
#y = y + 2;
#i = i - 1;
#}
#z = x + y;
 
 li $t0, 8
 li $t1, 4
 li $t2, 2
 li $t4, 0
 
 beq $t2, $t4, igual
 bne $t2, $t4, diferente
 
 igual:
 	add $t5, $t0, $t1
 	j fim
 	
 diferente:
 	addi $t1, $t1, 2
 	subi $t2, $t2, 1
 	j fim
 	
 fim:
 	syscall