import math

Menu = 0

while Menu != 4:
    print("\nEscolha sua opção de cálculo: ")
    print("1 - IMC\n2 - Peso Ideal\n3 - Altura Ideal\n4 - Sair")
    Menu = int(input("Opção: "))
    
    if Menu == 1:
        print("\nVocê selecionou IMC")
        Peso = float(input("Digite seu Peso em Kg: "))
        while Peso <= 0:
            print("Erro: Entrada inválida")
            Peso = float(input("Digite seu Peso em Kg: "))
            
        Altura = float(input("Digite sua Altura em Centímetros: "))
        while Altura <= 0:
            print("Erro: Entrada inválida")
            Altura = float(input("Digite sua Altura em Centímetros: "))
            
        Altura /= 100
        IMC = Peso / (Altura * Altura)
        
        print(f"\nSeu IMC é: {IMC:.1f}")
        
        if IMC < 18.5:
            print("Sua classificação é: Peso Baixo")
        elif IMC >= 18.5 and IMC <= 24.9:
            print("Sua classificação é: Peso Normal")
        elif IMC > 24.9 and IMC <= 29.9:
            print("Sua classificação é: Sobrepeso")
        elif IMC > 29.9 and IMC <= 34.9:
            print("Sua classificação é: Obesidade (Grau 1)")
        elif IMC > 34.9 and IMC <= 39.9:
            print("Sua classificação é: Obesidade Severa (Grau 2)")
        else:
            print("Sua classificação é: Obesidade Mórbida (Grau 3)")
    
    elif Menu == 2:
        print("\nVocê selecionou Peso Ideal")
        IMC = float(input("Digite seu IMC: "))
        while IMC <= 0:
            print("Erro: Entrada inválida")
            IMC = float(input("Digite seu IMC: "))
            
        Altura = float(input("Digite sua Altura em Centímetros: "))
        while Altura <= 0:
            print("Erro: Entrada inválida")
            Altura = float(input("Digite sua Altura em Centímetros: "))
            
        Altura /= 100
        Peso_Ideal = IMC * (Altura * Altura)
        
        print(f"\nSeu Peso Ideal é: {Peso_Ideal:.1f} Kg")
    
    elif Menu == 3:
        print("\nVocê selecionou Altura Ideal")
        Peso = float(input("Digite seu Peso em Kg: "))
        while Peso <= 0:
            print("Erro: Entrada inválida")
            Peso = float(input("Digite seu Peso em Kg: "))
            
        IMC = float(input("Digite seu IMC: "))
        while IMC <= 0:
            print("Erro: Entrada inválida")
            IMC = float(input("Digite seu IMC: "))
            
        Altura_Ideal = math.sqrt(Peso / IMC)
        
        print(f"\nSua Altura ideal é: {Altura_Ideal:.2f} metros")
    
    elif Menu == 4:
        print("\nEncerrando o programa...")
    
    else:
        print("\nErro: Opção inválida")
