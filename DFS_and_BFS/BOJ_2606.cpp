#include <iostream>
#include <list>
#include <queue>

using namespace std;

int vertex_num, edge_num, num_of_infected_vertex = 0;
int infected[101];
list<int> network[101];
queue<int> q;

void Init_network();
void Get_num_of_infected_vertex(int cur_v);
bool Not_infected(int adj_v);

int main()
{
	cin >> vertex_num >> edge_num;
		
	Init_network();
	
	Get_num_of_infected_vertex(1);
	
	cout << num_of_infected_vertex;
}

void Init_network()
{
	int v1, v2;
	for(int i = 0; i < edge_num; i++){
		cin >> v1 >> v2;
		network[v1].push_back(v2);
		network[v2].push_back(v1);
	}
	
	infected[1] = 1;
	q.push(1);
}

void Get_num_of_infected_vertex(int cur_v)
{
  list<int>::iterator iter;
	for(iter = network[cur_v].begin(); iter != network[cur_v].end(); iter++){
		if(Not_infected(*iter)){
			infected[*iter] = 1;
			num_of_infected_vertex++;
			q.push(*iter);
		}
	}
	
	q.pop();
	
	if(q.empty())
		return;
	
	cur_v = q.front();
	Get_num_of_infected_vertex(cur_v);
}

bool Not_infected(int adj_v)
{
	if(infected[adj_v] == 0)
		return true;
	return false;
}


/*2020-02-01
Refactoring
그래프의 vertex와 edge정보가 주어질때 
인접행렬로 표현할지, 인접리스트로 표현할지 매번 고민한다. 
방향이 있고 weigth가 있는 그래프라면 인접 행렬이 편하다.
vertex사이에 edge가 없다면 0, 있으면 그 weigth를 저장하면 된다.
vertex가 매우 많지만 edge가 적다면 인접리스트를 사용하는게
시간적 공간적 절약이다. 
*/


















