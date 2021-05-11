#include <iostream>
#include <vector>
using namespace std;
void output(long long a[100][100], int n);
//void binary_exp_matrix(long long a[100][100], int n, long long l, int u, int v);
void bin_martix_exp(long long a[100][100], long long product[100][100], int n, long long k);
void mul(long long a[100][100], long long b[100][100], int n);
#define MOD 1000000007
int main()
{ 
  long long product[100][100];
  int n, m, u, v;
  long long l;
  cin >> n >> m >> u >> v >> l;
  u--, v--;
  long long  a[100][100] = {0}; //adjacency_matrix
  for(int i = 0; i < m; i++)
  {
     int A,B;
     cin >> A >> B;
     A--;
     B--;
     if(A == B)
     {
		  a[A][B] +=2;
	 }
     else
     {
          a[A][B] = 1;
          a[B][A] = 1;
     }
  }
      bin_martix_exp(a,product,n,l);
      cout << product[u][v];
  return 0;
}
void bin_martix_exp(long long a[100][100], long long product[100][100], int n, long long k)
{  
	for(int i = 0; i < n; i++)
	{
        product[i][i] = 1;
	}
	while(k > 0)
	{
		if(k & 1)
		{
			mul(product, a,n);
		}
		k = k /2;
		mul(a,a,n);
	}	
}

void mul(long long a[100][100], long long b[100][100], int n)
{
	long long tmp[100][100] = {0};
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{   
			for(int k = 0; k < n; k++)
			{
				tmp[i][j] = ((tmp[i][j] % MOD) + ((a[i][k] % MOD) * (b[k][j] % MOD))%MOD) % MOD;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{   
			a[i][j] = tmp[i][j];
		}
	}
}

void output(long long a[100][100], int n) 
{ 
  cout << "\n    ";
  for(int i = 0; i < n; i++)
  {
	  cout << i << "  ";
  }
  cout << "\n";
  cout << "\n";
  for(int i = 0; i < n; i++)
  {
	  cout << i << "  ";
	  for(int j = 0; j < n; j++)
	  {
		  cout << " "<< a[i][j] << " ";
	  }
	  cout << "\n";
  }	
}

//void binary_exp_matrix(long long a[100][100], int n, long long k, int u, int v)
//{
	//long long product_prom[100][100];
	//long long a_prom[100][100];
	//long long product[100][100];
	//for(int i = 0; i < n; i++)
	//{
		//product_prom[i][i] = 1;
	//}
	//for(int i = 0; i < n; i++)
	//{
		//for(int j = 0; j < n; j++)
		//{
			//product[i][j] = a[i][j];
			//a_prom[i][j] = a[i][j];
		//}
	//}
	//while(k > 0)
	//{
		//if(k % 2) //------------------------- умножаем матрицу, отвечающую за результат, на промежуточную матрицу
		//{
			//for(int i = 0; i < n; i++)
			//{
				//for(int j = 0; j < n; j++)
				//{   
					//long long tmp = 0;
					//for(int m = 0; m < n; m++)
					//{
							//tmp = (tmp % MOD +  ( (product_prom[i][m] % MOD) * (a_prom[m][j] % MOD) ) % MOD) % MOD;
					//}
					//product[i][j] = tmp;
				//}
			//} 
			//for(int i = 0; i < n; i++)
			//{
				//for(int j = 0; j < n; j++)
				//{
					//product_prom[i][j] = product[i][j];
				//}
			//}
		//}
			//for(int i = 0; i < n; i++) //-------- умножаем промежуточную матрицу саму на себя (возводим в квадрат)               
			//{
				//for(int j = 0; j < n; j++)
				//{   
					//long long tmp = 0;
					//for(int m = 0; m < n; m++)
					//{
							//tmp = (tmp % MOD +  ( (a_prom[i][m] % MOD) * (a_prom[m][j] % MOD) ) % MOD) % MOD;
					//}
					//a[i][j] = tmp;
				//}
			//}
			//for(int i = 0; i < n; i++)
			//{
				//for(int j = 0; j < n; j++)
				//{
					//a_prom[i][j] = a[i][j];
				//}	
			//}
			//k = k / 2; 	
		
	//}
	//cout << product[u][v];
//}
