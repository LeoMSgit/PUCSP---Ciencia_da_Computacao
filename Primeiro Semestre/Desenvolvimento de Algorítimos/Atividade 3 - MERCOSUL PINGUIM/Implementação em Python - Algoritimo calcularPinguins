def calcular_pinguins(N):
    R, P, Q, S, i = 0, 0, 0, 1, 0

    P = N // 5
    R = N % 5

    while R != 0:
        while R < 3:
            P = P - 1
            R = R + 5
            i = i + 1

        Q = (R // 3) + i
        R = R % 3

    print("P = {}, Q = {}".format(P, Q))

def main():
    N = int(input("Digite um valor para N: "))
    calcular_pinguins(N)
    
if __name__ == "__main__":
    main()
