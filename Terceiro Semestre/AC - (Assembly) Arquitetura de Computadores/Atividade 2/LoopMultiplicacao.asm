.data
  prompt1: .asciiz "Digite o primeiro numero: "
  prompt2: .asciiz "Digite o segundo numero: "
  message: .asciiz "\nResultado da multiplicacao: "
  newline: .asciiz "\n"

.text
.globl main

main:
    # Solicita o primeiro numero
    li $v0, 4
    la $a0, prompt1
    syscall
    
    # Lê o primeiro numero
    li $v0, 5
    syscall
    move $t0, $v0
    
    # Solicita o segundo numero
    li $v0, 4
    la $a0, prompt2
    syscall
    
    # Lê o segundo numero
    li $v0, 5
    syscall
    move $t1, $v0
    
    li $t2, 0           # Inicializa o resultado como 0
    
    blez $t1, end       # Caso especial: Se $t1 for 0, encerra com valor padrão de $t2
    blez $t0, end       # Caso especial: Se $t0 for 0, encerra com valor padrão de $t2
    beq $t0, 1, caso_um_A   # Se $t0 for 1, resultado é $t1
    beq $t1, 1, caso_um_B   # Se $t1 for 1, resultado é $t0
	
multiplicacao_loop:
    add $t2, $t2, $t0   # Soma $t0 ao contador $t2
    subi $t1, $t1, 1    # Decrementa $t1, controlador do loop
    bgtz $t1, multiplicacao_loop # Se $t1 > 0, continua o loop

    j end
    
caso_um_A: 
    move $t2, $t1       # Define o resultado como $t1
    j end
    
caso_um_B:
    move $t2, $t0       # Define o resultado como $t0
    j end
    
end:
    # Exibe a mensagem do resultado
    li $v0, 4
    la $a0, message
    syscall
    
    # Exibe o resultado da multiplicacao
    li $v0, 1
    move $a0, $t2
    syscall
    
    # Nova linha
    li $v0, 4
    la $a0, newline
    syscall
    
    # Finaliza o programa
    li $v0, 10
    syscall
