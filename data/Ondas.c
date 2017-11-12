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
#define dt 0.0001
#define dx 0.005
#define arg 2*Pi*c/L

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

// Resolver ecuacion de onda en 1D:
float *past = malloc(len*sizeof(float));
float *present = malloc(len*sizeof(float));
float *future = malloc(len*sizeof(float));
float *initial = malloc(len*sizeof(float));
float alpha = 10.0;
float omega = 10.0;
float cambio = 1.0/dt;
float r = (pow(c,2)*pow(dt, 2))/pow(dx, 2);
float Form1=0.0;
float Form2=0.0;
float Form3=0.0;
int j;

// Primera parte: Cuerda con extremos fijos:
for(i=0;i<len-1;i++)
{
	initial[i] = amp[i]; 
	future[i] = initial[i] + (r/2.0) * (initial[i+1] - 2.0 * initial[i] + initial[i-1]);
}

for(i=0;i<cambio;i++)
{
	for(j=0;j<len;j++)
{
		future[j] = (2.0*(1.0-r))*present[j] - past[j] + (r)*(present[j+1] +  present[j-1]);
}
	past[j] = present[j];
	present[j] = future[j];
}

FILE* datos = fopen("onda1.dat", "w");
for(i=0;i<len;i++)
{
	fprintf(datos, "%f\n", future[i]);
}

// Segunda parte: Cuerda con un extremo perturbado:

float *past1 = malloc(len*sizeof(float));
float *present1 = malloc(len*sizeof(float));
float *future1 = malloc(len*sizeof(float));
float *initial1 = malloc(len*sizeof(float));
float t = dt*cambio
for(i=0;i<cambio;i++)
{
	initial1[i] = sin(arg*t);
}
}

