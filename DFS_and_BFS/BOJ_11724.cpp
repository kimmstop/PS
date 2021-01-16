#include <iostream>
#include <list>

#define ZERO 0;

using namespace std;

int num_of_v, num_of_e;
int num_of_connected_component;
int visit[1001];
list <int> adj_list[1001];

void Count_connected_component();
void Is_there_connected_componet(int v);

int main()
{
	int v1, v2;
	cin >> num_of_v >> num_of_e;
	for(int i = 0; i < num_of_e; i++){
		cin >> v1 >> v2;
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
	}
	
	Count_connected_component();
	cout << num_of_connected_component << endl;
}


void Count_connected_component()
{
	for(int v = 1; v <= num_of_v; v++){
		if(adj_list[v].size() >= 0 && visit[v] == 0){
			Is_there_connected_componet(v);
			num_of_connected_component++;
		}
	}
}


void Is_there_connected_componet(int v)
{
	int next_v;
	list<int>::iterator iter;
	for(iter = adj_list[v].begin(); iter != adj_list[v].end(); iter++){
		next_v = *iter;
		if(visit[next_v] == 0){
			visit[next_v] = 1;
			Is_there_connected_componet(next_v);
		}
	}

}

/*2020-01-16
Refactoring
문제를 정확히 읽고 똑바로 이해하자
간선이 없는 독립적인 1개의 vertex도 1개의 연결요소로 봐야했다.
문제의 조건을 잘보자
vertex의 최대 개수는 1000개이지만 넘버링이 1부터이다.
따라서 visit이나 adj_list배열을 [1000]으로 할 경우
out of bound 에러가 나온다.
*/
