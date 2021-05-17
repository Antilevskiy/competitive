#include <iostream>
#include <vector>
using namespace std;
void d(int u, vector<int> g[10000], bool visited[10000]);
int main()
{
	 int n, m;
	 cin >> n >> m;
	 bool visited[10000] = {0};
	 vector<int> g[10000];
	 
	 for(int i = 0; i < m; i++)
	 {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	 }
	 int component = 0;
	 for(int i = 0; i < n; i++)
	 {
		 if(!visited[i])
		 {
			 d(i, g, visited);
			 component++;
		 }
	 }
	 if(component == 1)
	 {
		 cout << m - n + 1;
	 }
	 else
	 {
		 cout<< -1;
	 }
	 
	return 0;
}
void d(int u, vector<int> g[10000], bool visited[10000])
{
	visited[u] = 1;
	for(int i = 0; i < g[u].size(); i++)
	{
		if(!visited[g[u][i]])
		{
			d(g[u][i], g, visited);
		}
	}
}
