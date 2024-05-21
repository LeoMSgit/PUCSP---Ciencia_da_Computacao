def ano_bissexto(a):
    if (a % 4 == 0 and a % 100 != 0) or (a % 400 == 0):
        return True  # Ano bissexto
    else:
        return False  # Não Ano bissexto

def data_valida(a, m, d):
    # Verificação de ano válido
    if a < 1600 or a > 5000:
        return False

    # Verificação de mês válido
    if m < 1 or m > 12:
        return False

    # Verificação do máximo de dias no mês
    if m == 2:
        # Verificação bissexto
        if ano_bissexto(a):
            max_dias = 29
        else:
            max_dias = 28
    elif m in [4, 6, 9, 11]:
        max_dias = 30
    else:
        max_dias = 31

    # Verificação de dia válido
    if d < 1 or d > max_dias:
        return False

    # Data válida
    return True

def dias_fim_ano(a, soma):
    if ano_bissexto(a):
        soma = 366 - soma
    else:
        soma = 365 - soma

    print("Até o fim do ano inserido restam {} dias".format(soma))

def dias_inicio_ano(d, m, a):
    dias_corridos = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]  # Não Bissexto
    if ano_bissexto(a):
        dias_corridos[1] = 29  # Bissexto

    soma = d - 1  # Dias do mês atual e correção
    for i in range(m - 1):
        soma += dias_corridos[i]  # Total de dias até o fim do mês anterior

    print("Do início do ano inserido até o dia inserido se passaram {} dias".format(soma))

    # Chamada para função de fim do ano
    dias_fim_ano(a, soma)

def menu():
    print("\nBEM VINDO A CALCULADORA DE DATAS")
    print("1 - Iniciar; 2 - Sair")
    return int(input("Escolha uma opção: "))

# Corpo do programa
def main():
    opcao = 0

    while opcao != 2:
        opcao = menu()

        if opcao == 1:
            # Input do ano
            ano = int(input("Digite o ANO (Entre 1600 e 5000): "))
            while data_valida(ano) == 3:
                print("\nERRO: Ano inválido")
                ano = int(input("Digite o ANO (Entre 1600 e 5000): "))

            if ano_bissexto(ano):
                print("O ano {} é Bissexto".format(ano))
            else:
                print("O ano {} não é Bissexto".format(ano))

            # Input do mês
            mes = int(input("Digite o MÊS: "))
            while data_valida(mes) == 2:
                print("\nERRO: Mês inválido")
                mes = int(input("Digite o MÊS: "))

            # Input do dia
            dia = int(input("Digite o DIA: "))
            while data_valida(dia) == 1:
                print("\nERRO: Dia inválido para este mês")
                dia = int(input("Digite o DIA: "))

            # Data inserida
            print("\nData Inserida: {:02}/{:02}/{}".format(dia, mes, ano))

            # Dias do começo do ano e fim do ano
            dias_inicio_ano(dia, mes, ano)

        elif opcao != 1 and opcao != 2:
            print("ERRO: Opção inválida. Escolha 1 para Iniciar ou 2 para Sair.")
            print("----------------------------------------------------------------")

    print("\nSAINDO...")
