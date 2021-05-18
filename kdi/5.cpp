#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main()
{ 
  int n, A, B, u, v;
  unsigned long long m, c;
  cin >> n >> m; 
   
  vector<bool> visited(n,0);
  vector<unsigned long long> weight(n,1000000000000000000);
  vector<map<int, unsigned long long>> g(n);  // вектор map'ов: каждая вершина -- контейнер ключ-значение. ключ -- вершина, в которую ребро, значение -- вес ребра
  map<int, unsigned long long>::iterator it; //итератор
  
  //ввод ребер
  for(unsigned long long i = 0; i < m; i++) 
  {
    cin >> A >> B >> c;
    A--; B--;
    it = g[A].find(B);
    if(it == g[A].end())
    {
		g[A].insert(make_pair(B, c));
		g[B].insert(make_pair(A, c));
	}
	else if(it->second > c)
	{
		it->second = c;
		it = g[B].find(A);
		it->second = c;
	}
  }
  
  cin >> u >> v;
  u--; v--;	   
  weight[u] = 0;
  int counter = 0;

  while(counter < n)
  {
	  unsigned long long min = 1000000000000000000;
	  counter++;
	  int index_min = -1;
	 
		  for(int i = 0; i < n; i++)
		  {
			  if((weight[i] < min) && !visited[i])
			  {
				  min = weight[i];
				  index_min = i;
			  }
		  }

		  it = g[index_min].begin();
		  
		  for(int i = 0; i < signed(g[index_min].size()); i++, it++)
		  {
			  if(!visited[index_min] && (weight[index_min] + it->second < weight[it->first])) // !visited[index_min] && (index_min != i) && (weight[index_min] + g[index_min][i] < weight[i])
			  {
				        weight[it->first] = weight[index_min] + it->second;             // weight[i] = weight[index_min] + g[index_min][i];
			  }
		  }

		  visited[index_min] = 1;
  }
  
  cout << weight[v];
  return 0;
}
