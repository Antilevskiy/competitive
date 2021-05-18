#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, bool used[10000], vector<int> g[10000]);
int main()
{ 
  int n, m;
  cin >> n >> m;
  vector<int> g[10000];
  int component = 0;
  bool used[10000] = {0};
  for(int i = 0; i < m; i++)
  {
     int l,r;
     cin >>l >> r;
     l--; r--;
     //cout << l << " " << r << "\n";
     g[l].push_back(r);
     g[r].push_back(l); 
  }
  //for(int i = 1; i <= n; i++)
  //{
	  //if(g[i].empty())
	  //{
		  //cout << "this vertex is separate" << "\n";
	  //}
	  //else
	  //{
		//for(int j = 0; j < g[i].size(); j++)
		//{
			//cout << g[i][j] << " ";
		//}  
	  //}
	  //cout << "\n";
  //}
  
  for(int i = 0; i < n; i++)
  {
	  if(g[i].empty())
	  {
		  component++;
		  used[i] = 1;
	  }
	  else
	  {
		  if(!used[i])
		  {
			dfs(i, used, g);
			component++;  
		  }
	  }
  }
  cout << /*"component: "<< */ component - 1;
   
  return 0;
}

void dfs(int v, bool used[10000], vector<int> g[10000])
{
	used[v] = 1;
	//cout << "hello g["<<v<<"]" << '\n';
    for(int j = 0; j < g[v].size(); j++)
    {   
       if(!used[ g[v][j] ])
       {
		   dfs(g[v][j], used, g);
	   }
    }
}
