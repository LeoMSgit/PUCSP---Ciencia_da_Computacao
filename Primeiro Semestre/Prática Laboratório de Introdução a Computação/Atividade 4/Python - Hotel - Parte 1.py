# Estrutura Dados Hospede - Endereco
class Endereco:
    def __init__(self, rua, numero, bairro, cidade, uf):
        self.rua = rua
        self.numero = numero
        self.bairro = bairro
        self.cidade = cidade
        self.uf = uf

# Estrutura Dados Hospede
class Quarto:
    def __init__(self, status, nome="", cpf="", telefone="", endereco=None):
        self.status = status
        self.nome = nome
        self.cpf = cpf
        self.telefone = telefone
        self.endereco = endereco

# Criação de Matriz
def cria_matriz():
    m = [[i * 14 + j + 1 for j in range(14)] for i in range(20)]
    status = [['.' for _ in range(14)] for _ in range(20)]
    return m, status

# Mostrar Matriz e Ocupação
def mostra_matriz(m, status):
    total_quartos = 20 * 14
    vagos = sum(row.count('.') for row in status)
    ocupados = sum(row.count('O') + row.count('R') for row in status)
    print("  Quartos:", "\t".join(str(i + 1) for i in range(14)))
    for i in range(20):
        print(f"Andar {20 - i}:", "\t".join(status[i]))
    print("\n---------------------------------------------------------------------")
    print(f"Porcentagem de quartos vagos: {vagos / total_quartos * 100:.2f}%")
    print(f"Porcentagem de quartos ocupados: {ocupados / total_quartos * 100:.2f}%")

# Menu Principal
def menu_principal():
    print("\nBEM VINDO AO MENU PRINCIPAL DO HOTEL")
    print("1 - Mostrar Mapa; 2 - Check-in; 3 - Check-out; 4 - Realizar Reserva; 5 - Cancelar Reserva; 6 - Sair")
    while True:
        try:
            opcao = int(input("Escolha uma opção: "))
            if opcao in range(1, 7):
                return opcao
            else:
                print("Opção inválida! Por favor, escolha uma opção de 1 a 6.")
        except ValueError:
            print("Entrada inválida! Por favor, insira um número.")

# Realizar Check-in
def realizar_check_in(m, status):
    while True:
        try:
            andar_quarto = int(input("Digite o número do andar para check-in (0 para retornar ao Menu): "))
            if andar_quarto < 1 or andar_quarto > 20:
                print("Número de andar inválido! Por favor, insira um número entre 1 e 20.")
                continue
            if andar_quarto == 0:
                return
            numero_quarto = int(input("Digite o número do quarto para check-in (0 para retornar ao Menu): "))
            if numero_quarto < 1 or numero_quarto > 14:
                print("Número de quarto inválido! Por favor, insira um número entre 1 e 14.")
                continue
            if numero_quarto == 0:
                return
            if status[20 - andar_quarto][numero_quarto - 1] == '.':
                status[20 - andar_quarto][numero_quarto - 1] = 'O'
                print(f"Check-in realizado com sucesso no quarto {andar_quarto} {numero_quarto}.")
                mostra_matriz(m, status)
                break
            else:
                print(f"O quarto {andar_quarto} {numero_quarto} já está ocupado ou reservado.")
        except ValueError:
            print("Entrada inválida! Por favor, insira um número.")

# Realizar Check-out
def realizar_check_out(m, status):
    while True:
        try:
            andar_quarto = int(input("Digite o número do andar para check-out: "))
            if andar_quarto < 1 or andar_quarto > 20:
                print("Número de andar inválido! Por favor, insira um número entre 1 e 20.")
                continue
            numero_quarto = int(input("Digite o número do quarto para check-out: "))
            if numero_quarto < 1 or numero_quarto > 14:
                print("Número de quarto inválido! Por favor, insira um número entre 1 e 14.")
                continue
            if status[20 - andar_quarto][numero_quarto - 1] == 'O':
                status[20 - andar_quarto][numero_quarto - 1] = '.'
                print(f"Check-out realizado com sucesso no quarto {andar_quarto} {numero_quarto}.")
                mostra_matriz(m, status)
                break
            else:
                print(f"O quarto {andar_quarto} {numero_quarto} não está ocupado.")
        except ValueError:
            print("Entrada inválida! Por favor, insira um número.")

# Realizar Reserva
def realizar_reserva(m, status):
    while True:
        try:
            andar_quarto = int(input("Digite o número do andar para reserva (0 para retornar ao Menu): "))
            if andar_quarto < 1 or andar_quarto > 20:
                print("Número de andar inválido! Por favor, insira um número entre 1 e 20.")
                continue
            if andar_quarto == 0:
                return
            numero_quarto = int(input("Digite o número do quarto para reserva (0 para retornar ao Menu): "))
            if numero_quarto < 1 or numero_quarto > 14:
                print("Número de quarto inválido! Por favor, insira um número entre 1 e 14.")
                continue
            if numero_quarto == 0:
                return
            if status[20 - andar_quarto][numero_quarto - 1] == '.':
                status[20 - andar_quarto][numero_quarto - 1] = 'R'
                print(f"Reserva realizada com sucesso no quarto {andar_quarto} {numero_quarto}.")
                mostra_matriz(m, status)
                break
            else:
                print(f"O quarto {andar_quarto} {numero_quarto} já está ocupado ou reservado.")
        except ValueError:
            print("Entrada inválida! Por favor, insira um número.")

# Cancelar Reserva
def cancelar_reserva(m, status):
    while True:
        try:
            andar_quarto = int(input("Digite o número do andar para cancelar a reserva (0 para retornar ao Menu): "))
            if andar_quarto < 1 or andar_quarto > 20:
                print("Número de andar inválido! Por favor, insira um número entre 1 e 20.")
                continue
            if andar_quarto == 0:
                return
            numero_quarto = int(input("Digite o número do quarto para cancelar a reserva (0 para retornar ao Menu): "))
            if numero_quarto < 1 or numero_quarto > 14:
                print("Número de quarto inválido! Por favor, insira um número entre 1 e 14.")
                continue
            if numero_quarto == 0:
                return
            if status[20 - andar_quarto][numero_quarto - 1] == 'R':
                status[20 - andar_quarto][numero_quarto - 1] = '.'
                print(f"Reserva cancelada com sucesso no quarto {andar_quarto} {numero_quarto}.")
                mostra_matriz(m, status)
                break
            else:
                print(f"O quarto {andar_quarto} {numero_quarto} não está reservado.")
        except ValueError:
            print("Entrada inválida! Por favor, insira um número.")


# Função Principal
def main():
    m, status = cria_matriz()
    while True:
        opcao = menu_principal()
        if opcao == 1:
            print("\nIMPRIMINDO MAPA...\n")
            mostra_matriz(m, status)
        elif opcao == 2:
            realizar_check_in(m, status)
        elif opcao == 3:
            realizar_check_out(m, status)
        elif opcao == 4:
            realizar_reserva(m, status)
        elif opcao == 5:
            cancelar_reserva(m, status)
        elif opcao == 6:
            print("\nSaindo do sistema.")
            break

if __name__ == "__main__":
    main()
