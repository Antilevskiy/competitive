#include <iostream>
#include <vector>
using namespace std;
void output(long long a[100][100], int n);
void exponent(long long a[100][100], long long res[100][100], int n, long long l);

#define MOD 1000000007
int main()
{ 
  int n, m, u, v;
  long long l;
  cin >> n >> m >> u >> v >> l;
  u--, v--;
  long long  a[100][100] = {0}; //adjacency_matrix
  long long res[100][100] = {0};
  for(int i = 0; i < m; i++)
  {
     int A,B;
     cin >> A >> B;
     A--;
     B--;
     if(A == B)
     {
		 a[A][B] += 2;
		 res[A][B] += 2;
	 }
	 else
	 {
         a[A][B]++;
         a[B][A]++;
         res[A][B]++;
         res[B][A]++;
     }
  }
    //output(a, n);
    exponent(a,res,n,l);
	
    //output(res, n);
    cout << res[u][v]; 
  return 0;
}

void exponent(long long a[100][100], long long res[100][100], int n, long long l)
{
	long long t[100][100];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			t[i][j] = res[i][j];
		}
	}
	for(int k = 0; k < l - 1; k++)
	{
		for(int i = 0; i < n; i++)
		{
            for(int j = 0; j < n; j++)
            {   
				long long tmp = 0;
				for(int m = 0; m < n; m++)
				{
             			tmp = (tmp +  ( (a[i][m] % MOD) * (res[m][j] % MOD) ) % MOD) % MOD;
                }
                t[i][j] = tmp;
            }
		}
		
   	    for(int i = 0; i < n; i++)
	    {
 		    for(int j = 0; j < n; j++)
		    {
			    res[i][j] = t[i][j];
		    }
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
