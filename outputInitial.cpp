#include <iostream>
#include <vector>
using namespace std;
void output(long long a[100][100], int n);

#define MOD 1000000007
int main()
{ 
  int n, m, u, v, l;
  cin >> n >> m >> u >> v >> l;
  long long  a[100][100] = {0}; //adjacency_matrix
  for(int i = 0; i < m; i++)
  {
     long long A,B;
     cin >> A >> B;
     A--;
     B--;
     a[A][B] = 1;
     a[B][A] = 1;
  }
    output(a, n); 
  return 0;
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
