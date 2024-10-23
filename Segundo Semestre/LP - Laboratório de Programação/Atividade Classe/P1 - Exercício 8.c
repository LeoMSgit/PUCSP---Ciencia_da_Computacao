// Montar um programa que calcule e imprima a distancia percorrida e a quantidade de litros consumidos em uma viagem para um carro que faz 16 kilometros por litro
// Receber a velocidade media da viagem e tempo da viagem
// Devolver velocidade media de viegem, tempo da viagem, distancia percorrida e combustivel consumido

#include <stdio.h>

int main (){
	float tempo;
	float dist;
	float velo;
	float combu;

	printf("Qual o tempo estimado da viagem (em horas)? ");
	scanf("%f", &tempo);	
	
	printf("Qual a velocidade media da viagem (em km/h)? ");
	scanf("%f", &velo);
	
	dist = tempo * velo;
	combu = dist / 16;
	
	printf("Sua viagem de %.f horas, com uma velocidade media de %.f kilometros por hora, tera uma distancia de %.f kilometros e consumira %.2f litros de combustivel", tempo, velo, dist, combu);
	
	return 0;
}
