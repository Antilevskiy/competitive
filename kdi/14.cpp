#include <iostream>
#include <vector>
using namespace std;
void bin_martix_exp(long long a[100][100], long long product[100][100], int n, long long k);
void mul(long long a[100][100], long long b[100][100], int n);
const int MOD = 1e9 + 7;
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
          a[A][B] += 1;
          a[B][A] += 1;
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
				tmp[i][j] = (tmp[i][j] + ((a[i][k] % MOD)  * (b[k][j] % MOD)) % MOD) % MOD;
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