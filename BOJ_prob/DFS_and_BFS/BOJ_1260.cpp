#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

stack <int> v_stack;
queue <int> v_queue;
list <int> adj_list[1001];



int num_of_v, num_of_e, start_v;
int graph[1001][1001];
int visit[1001];

void Do_DFS(int start_v);
void Do_BFS(int start_v);
void Reset_visited_vertex();
bool Is_there_path(int v1, int v2);
bool Is_v_not_visited(int v);

int main()
{
	cin >> num_of_v >> num_of_e >> start_v;
	int v1, v2;
	for(int i = 1; i <= num_of_e; i++){
		cin >> v1 >> v2;
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	v_stack.push(start_v);
	visit[start_v] = 1;
	Do_DFS(start_v);
	
	cout << "\n";
	
	Reset_visited_vertex();
	
	
	v_queue.push(start_v);
	cout << start_v << " ";
	visit[start_v] = 1;
	Do_BFS(start_v);
}

void Reset_visited_vertex()
{
	fill(visit, visit + 1001, 0);
}


bool Is_there_path(int v1, int v2)
{
	if(graph[v1][v2] == 1)
		return true;
	return false;
}

bool Is_v_not_visited(int v)
{
	if(visit[v] == 0)
		return true;
	return false;
}


void Do_DFS(int start_v)
{
	cout << start_v << " ";

	int next_v;
	for(int next_v = 1; next_v <= num_of_v; next_v++){
		if(Is_there_path(start_v, next_v) && Is_v_not_visited(next_v)){
			visit[next_v] = 1;
			v_stack.push(next_v);
			Do_DFS(next_v);
		}
	}	
	
	if(v_stack.empty())
		return;
	
	v_stack.pop();
}


void Do_BFS(int start_v)
{
	int next_v;
	for(int next_v = 1; next_v <= num_of_v; next_v++){
		if(Is_there_path(start_v, next_v) && Is_v_not_visited(next_v)){
			visit[next_v] = 1;
			cout << next_v << " ";
			v_queue.push(next_v);
		}
	}
	
	if(v_queue.empty())
		return;
	
	v_queue.pop();
		
	next_v = v_queue.front();
	Do_BFS(next_v);
}


/*2021-01-16
Refactoring
DFS와 BFS에서 종료되는 기저 조건 코드를 어디에 위치 시켜야 할 지
고민했다. 상관없다. 맨 위에만 놓지 않으면 된다. */
