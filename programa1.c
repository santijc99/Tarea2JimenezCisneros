#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *calcpotencia(void *num1, void *num2,void *vec)
{	
	int *i1=( int *) num1;
	int *i2=( int *) num2;
	for(int i=i1;i<i2;i++)
	{
		int (*vec)[i]=vec[i]*vec[i]*vec[i];
	}
}

int main (void) 
{
	int j=0;
	int largo= 100000;
	int lista[largo];
	for(int i=0; i<largo;i++)/*Rellena el array de los elementos*/
		{
			lista[i]=i;
		}
	/*Hilo unico para realizar un recorrido*/
	pthread_t proceso0;
	printf("Se inicio el primer recorrido de un solo hilo");
	pthread_create(&proceso0, NULL,calcpotencia,&j,&largo,&lista);
	pthread_join(proceso0,NULL);
	printf("Se termino el primer recorrido de un solo hilo");
	
	/*Hilos para realizar un recorrido, se vuelve a crear el array*/
	
	for(int i=0; i<largo;i++)/*Rellena el array de los elementos*/
		{
			lista[i]=i;
		}
	pthread_t proceso1;
	pthread_t proceso2;
	pthread_t proceso3;
	pthread_t proceso4;
	/*Se definen indices para la division equitativa de las secciones del array*/
	int i1 = 25001; /*para 0 a 25000*/
	int i2 = 50001; /*para 25001 a 50000*/
	int i3 = 75001; /*para 50001 a 75000*/
	
	printf("Se inicio el recorrido de varios hilos");
	pthread_create(&proceso1, NULL,calcpotencia,&j,&i1,&lista);
	pthread_create(&proceso2, NULL,calcpotencia,i&1,&i2,&lista);
	pthread_create(&proceso3, NULL,calcpotencia,&i2,&i3,&lista);
	pthread_create(&proceso3, NULL,calcpotencia,&i3,&largo,&lista);
	pthread_join(proceso1,NULL);
	pthread_join(proceso2,NULL);
	pthread_join(proceso3,NULL);
	pthread_join(proceso4,NULL);
	printf("Se termino el recorrido de varios hilos");
	
}