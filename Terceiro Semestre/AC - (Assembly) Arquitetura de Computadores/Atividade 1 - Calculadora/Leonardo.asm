li $t0, 3
li $t1, 5         
li $t2, 2          
li $t3, 9                    
#RA = 323595
    
add $t6, $t0, $t1  # $t6 = $t0 + $t1 -> 3 + 5 = 8
add $t7, $t0, $t2  # $t7 = $t0 + $t2 -> 3 + 2 = 5
add $t8, $t3, $t1  # $t8 = $t3 + $t1 -> 9 + 5 = 14

    
add $t9, $t6, $t7  # $t9 = $t6 + $t7 -> 8 + 5 = 13
add $t0, $t9, $t8  # $t0 = $t9 + $t8 -> 13 + 14 = 27

#RESULTADO(Hexadecimal) = 1b ou 27