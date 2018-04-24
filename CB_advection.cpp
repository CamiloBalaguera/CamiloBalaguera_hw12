#include <iostream>
#include <stdlib.h>
using namespace std;
const float ini = -2.0;
const float fin = 2.0;
const float c = 1.0;
const int nt = 700;
const float dt = 0.001;
const float dx = 45*dt;
const int nx = (fin - ini)/dx;
float x[nx];
float u[nx][nt];
void evolucion(void);

int main()
{
	cout << nx << " " << nt << endl;
	for (int i = 0; i < nt ; i++)
	{
		u[0][i] = 0.0;
		u[nx-1][i] = 0.0;
	}
	x[0] = -2.0;
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
	evolucion();
	return 0;
}

void evolucion (void)
{
	for (int j = 1; j < nt; j++)
	{
		for(int i = 1; i < nx; i++)
		{
			u[i][j] = u[i][j-1] - c*(dt/dx)*(u[i][j-1]-u[i-1][j-1]);
		}
	}
	for (int k = 0; k < nt; k+=nt/5)
	{
		for (int i = 0; i < nx; i++)
		{
			cout << x[i] << " " << u[i][k] << endl;
		}
	}

}



