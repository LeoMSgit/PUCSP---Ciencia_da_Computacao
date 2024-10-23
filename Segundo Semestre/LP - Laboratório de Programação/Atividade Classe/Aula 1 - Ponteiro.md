Ponteiros 
char ch = 'x' -> Define a variável ch como tipo char e valor x
char *prt = &ch -> Define o ponteiro prt como tipo char e o valor referente Á POSIÇÃO ONDE A VARIÁVEL ch ESTÁ ALOCADA

O *prt indica o conteúdo da variável
O &ch indica o endereço da variável
O prt indica o endereço para qual ele aponta


int main() {
	int a = 100;
    int *ptr = &a;
    printf("%d, %d, %d", *ptr, a, ptr);
}

Nesse caso     *ptr retorna 100, pois está apontando o conteúdo do endereço da variável a
                a retorna 100, pois é o conteúdo da variável a
                ptr retorna 6684180, pois está apontando o endereço onde a variável a está registrada

Ao modificar um ponteiro a modificação não é transmitida para a variável, apenas modifica a "cópia" que está presente no ponteiro
