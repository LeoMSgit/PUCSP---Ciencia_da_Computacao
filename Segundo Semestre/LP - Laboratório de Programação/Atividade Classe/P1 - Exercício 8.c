// Montar um programa que calcule e imprima a distancia percorrida e a quantidade de litros consumidos em uma viagem para um carro que faz 16 kilometros por litro
// Receber a velocidade media da viagem e tempo da viagem
// Devolver velocidade media de viegem, tempo da viagem, distancia percorrida e combustivel consumido

#include <stdio.h>

int main (){
	int tempo;
	int dist;
	int velo;
	int combu;

	printf("Qual o tempo estimado da viagem (em horas)? ");
	scanf("%d", &tempo);	
	
	printf("Qual a velocidade media da viagem (em km/h)? ");
	scanf("%d", &velo);
	
	dist = tempo * velo;
	combu = dist / 16;
	
	printf("Sua viagem de %d horas, com uma velocidade media de %d kilometros por hora, tera uma distancia de %d kilometros e consumira %d litros de combustivel", tempo, velo, dist, combu);
	
	return 0;
}
