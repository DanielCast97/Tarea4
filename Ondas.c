#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
main()
{

// Valores constantes:
#define L 0.64
#define c 250.0
#define Pi 3.141592
#define dt 0.000001
#define dx 0.005

// Cargar datos. Solo me interesa la columna de las amplitudes.
FILE* data;
data = fopen("cond_ini_cuerda.dat", "r");
int len = 129;
float *a = malloc(len*sizeof(float)); // Posiciones
float *b = malloc(len*sizeof(float)); // Amplitudes
float *amp = malloc(len*sizeof(float)); // 

int i;
for(i=0;i<129;i++)
{
	fscanf(data, "%f %f\n", &a[i], &b[i]);
	amp[i]=b[i];
//	printf("%f\n", amp[i]);
}
fclose(data);

// Resolver ecuacion de onda:
float *Inicio = malloc(len*sizeof(float));
float *Modify = malloc(len*sizeof(float));
float *Time = malloc(len*sizeof(float));
float alpha = 10.0;
float omega = 10.0;
float cambio = 1.0/dt;
float r = (pow(c,2)*pow(dt, 2))/pow(dx, 2);
float Form1=0.0;
float Form2=0.0;
float Form3=0.0;
int j;
for(i=0;i<5;i++) //Recorrido para tiempos
{
	for(j=1;j<5;j++) //Recorrido para nodos
{
		if(i=0)
{			
			Form1 = (Inicio[j-1]-2*Inicio[j]+Inicio[j+1])*r;
			Form2 = (2.0*Inicio[j]);
			Form3 = (2.0*Inicio[j]-Time[j]);
			Modify[j] = Form1+Form2;
}		
		else
{
			Modify[j] = Form1+Form3;
}
}

}



}

