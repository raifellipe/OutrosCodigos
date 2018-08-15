#include <ctime> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <algorithm> 
#include <string>
using namespace std;
#define N 5

int mina[N][N];
int D_x, D_y;
int cont=0;

void inicia(void)
{
	srand(time(NULL));
	D_x = rand()%(N-1);
	D_y = rand()%(N-1);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{

			if((i!=D_x) || (j!=D_y))
			   mina[i][j]=0;
			else
			   mina[i][j]=1;
		}

}

void imprime_mina(int i, int j, int t)
{
	for( i=0; i<t; i++)
	{
	  cout<<endl;
	  for(j=0; j<t; j++)
		cout<<mina[i][j]<<" ";
	}
	cout<<endl;
}

string verifica( int posX, int posY)
{
if(posX==D_x && posY==D_y)
 return "ACHOU";
else if (posX==D_x && posY>D_y)
 return "N";
else if (posX==D_x && posY<D_y)
 return "S";
else if (posX>D_x && posY==D_y)
return "E";
else if (posX<D_x && posY==D_y)
return "O";
else if (posX<D_x && posY>D_y)
return "NE";
else if (posX>D_x && posY>D_y)
return "NO";
else if (posX<D_x && posY<D_y)
return "SO";
else if (posX>D_x && posY<D_y)
return "SE";
}
void minera(int inicio_x, int inicio_y, int tamanho)
{
        imprime_mina(inicio_x, inicio_y, tamanho);
	inicio_x=inicio_y=tamanho/2;
	string resp=verifica(inicio_x,inicio_y);
	cont++;
	cout<<resp<<"   "<<"Tentativa numero: "<<cont<<endl;
	if (resp == "E")
	 minera(inicio_x,0,inicio_y);
	else if (resp == "O")
	 minera(0,0,inicio_y);
	else if (resp == "S")
	 minera(0, inicio_y,inicio_x);
	else if (resp == "NE")
	 minera(inicio_x,0,tamanho-inicio_x);
	else if (resp == "N0")
	 minera(0,0,tamanho-inicio_x);
	else if (resp == "SO")
	 minera(0, inicio_y,tamanho-inicio_y);
	else if (resp == "SE")
	 minera(inicio_x,inicio_y,tamanho-inicio_y);
	else if (resp == "N")
	 minera(0,inicio_y,N);
	else
	cout<<"ACABOU!!!!!!"<<endl<<endl;
}

int main()
{
	inicia();
	minera(0,0,N+1);
	return 0;
}
