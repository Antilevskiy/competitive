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
  vector<vector<Node>> g(n,vector<Node>());
  for(long i = 0; i < m; i++) 
  {
	  cin >> A >> B >> c;
	  A--;B--;
	  Node t1;
	  Node t2;
	  t1.ver = A;
	  t1.w = c;
	  t2.ver = B;
	  t2.w = c;
	  //if(g[A].empty())                            ----some input;
	  //{
		 //g[A].push_back(t2); 
		 //g[B].push_back(t1);
	  //}
	  //else
	  //{
		  
	  //}
  }

  //for(int i = 0; i < n; i++)
  //{
	  
	  //for(int j = 0; j < g[i].size(); j++)
	  //{
		  //cout << "hello";
		  //cout << "i:" << i<< endl;
		  //cout << "ver" << g[i][j].ver << endl;
		  //cout << "weight" << g[i][j].w << endl;
	  //}
	  //cout << i << ;endl;
  //}
  
  //cin >> u >> v;
  //u--; v--;	
  //weight[u] = 0;
  
  //while(true)
  //{
	  //unsigned long long min = 1000000000000;
	  //int counter = 0;
	  //int index_min = -1;
	  //for(int i = 0; i < n; i++)
	  //{
		  //if(visited[i])
		  //{
			  //counter++;
		  //}  
	  //}
	  //if(counter == n)
	  //{
		  //break;
	  //}
	  //else
	  //{
		  //for(int i = 0; i < n; i++)
		  //{
			  //if((weight[i] < min) && !visited[i])
			  //{
				  //min = weight[i];
				  //index_min = i;
			  //}
		  //}
		  //cout << index_min << "\n";
		  //cout << g[index_min].size() << "size" << endl;
		  //for(int i = 0; i < signed(g[index_min].size()); i++)
		  //{
			  //if(!visited[index_min] && (index_min != i) && (weight[index_min] + g[index_min][i].w < weight[i]))
			  //{
				  //weight[i] = weight[index_min] + g[index_min][i].w;
			  //}
		  //}
		  //visited[index_min] = 1;
	  //}
  //}
  //cout << weight[v];
  return 0;
}
