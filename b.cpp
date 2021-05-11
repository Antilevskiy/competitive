#include <iostream>
#include <vector>
using namespace std;
struct Node{
	int ver;
	long long w;
};

int main()
{ 
  int n, A, B, u, v;
  long long m, c;
  cin >> n >> m;
  vector<bool> visited(n,0);
  vector<unsigned long long> weight(n,1000000000);
  vector<vector<long long>> g(n,vector<long long>(n,0));
  for(long i = 0; i < m; i++) 
  {
	  cin >> A >> B >> c;
	  A--;B--;
	  if(g[A][B] == 0)
	  {
	     g[A][B] = c;
	     g[B][A] = c;
	  }
	  else if(c < g[A][B])
	  {
		 g[A][B] = c;
	     g[B][A] = c;
	  }
  }
  cin >> u >> v;
  u--; v--;	
  weight[u] = 0;
  
  while(true)
  {
	  unsigned long long min = 1000000000000;
	  int counter = 0;
	  int index_min = -1;
	  for(int i = 0; i < n; i++)
	  {
		  if(visited[i])
		  {
			  counter++;
		  }  
	  }
	  if(counter == n)
	  {
		  break;
	  }
	  else
	  {
		  for(int i = 0; i < n; i++)
		  {
			  if((weight[i] < min) && !visited[i])
			  {
				  min = weight[i];
				  index_min = i;
			  }
		  }
		  for(int i = 0; i < n; i++)
		  {
			  if(!visited[index_min] && (index_min != i) && (weight[index_min] + g[index_min][i] < weight[i]))
			  {
				  weight[i] = weight[index_min] + g[index_min][i];
			  }
		  }
		  visited[index_min] = 1;
	  }
  }
  cout << weight[v];
  return 0;
}

