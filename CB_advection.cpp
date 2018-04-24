#include <iostream>
#include <stdlib.h>
using namespace std;
const float ini = -2.0; // Valor inicial
const float fin = 2.0; // Valor final
const float c = 1.0; // VElocidad
const int nt = 700; // Numero de datos temporales
const float dt = 0.001; // Diferencial de tiempo
const float dx = 45*dt; // Diferencial de espacio
const int nx = (fin - ini)/dx; // Numero de datos espaciales
float x[nx]; // Lista de posiciones
float u[nx][nt]; // Matriz de amplitudes. Primera dimension espacial. Segunda dimension temporal
void evolucion(void); // Funcion que evoluciona

int main()
{
	cout << nx << " " << nt << endl; // Se imprime el numero de datos espaciales y temporales para utilizar en el .py
	// Condiciones de frontera	
	for (int i = 0; i < nt ; i++)
	{
		u[0][i] = 0.0;
		u[nx-1][i] = 0.0;
	}
	// Valor inicial de posicion
	x[0] = -2.0;

	//Condiciones iniciales.
	for (int i = 1; i < nx; i ++)
	{
		x[i] = x[i-1] + dx;
		if ((abs(x[i]) <= 0.5))
		{ 
			u[i][0] = 0.5;
		}
		else
		{
			u[i][0] = 0.0;
		}
	}
	
	// Evolucion de la amplitud
	evolucion();
	return 0;
}

// Funcion que evoluciona la funcion amplitud(x, t)
void evolucion (void)
{
	for (int j = 1; j < nt; j++)
	{
		for(int i = 1; i < nx; i++)
		{
			u[i][j] = u[i][j-1] - c*(dt/dx)*(u[i][j-1]-u[i-1][j-1]); // Evolución.
		}
	}
	for (int k = 0; k < nt; k+=nt/5)
	{
		for (int i = 0; i < nx; i++)
		{
			cout << x[i] << " " << u[i][k] << endl; // Se imprimen todas las posiciones para 5 tiempos particulares.
		}
	}

}



