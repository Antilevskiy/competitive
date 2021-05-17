#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main()
{ 
  int n, A, B, u, v;
  long long m, c;
  cin >> n >> m; 
   
  vector<bool> visited(n,0);
  vector<long long> weight(n,1000000000);
  vector<map<int, long long>> g(n);  // вектор map'ов: каждая вершина -- контейнер ключ-значение. ключ -- вершина, в которую ребро, значение -- вес ребра
  map<int, long long>::iterator it; //итератор
  
  
  //ввод ребер
  for(long i = 0; i < m; i++) 
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
	  long long min = 1000000000000;
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
		  for(int i = 0; it != g[index_min].end(), i < signed(g[index_min].size()); i++, it++)
		  {
			  if(!visited[index_min] && index_min != i) // !visited[index_min] && (index_min != i) && (weight[index_min] + g[index_min][i] < weight[i])
			  {
				                                    // weight[i] = weight[index_min] + g[index_min][i];
			  }
		  }
		  visited[index_min] = 1;
	  
  }
  
  cout << weight[v];
  return 0;
}
