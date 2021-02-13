#include <iostream>
#include <functional>
#include <queue>
#include <list>

#define INF 987654321

using namespace std;

struct cmp{
	bool operator()(pair<int, int> parentnode, pair<int, int> newnode){
		return parentnode.second > newnode.second;
	}
};


int vertex_num, edge_num, start_v;
priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> edge_len;
list <pair<int, int>> adj_list[20001];
int shortest_len[20001];


void Init_graph();
void Cal_shortest_len();
int Get_newarest_v();
int Get_newarest_v_len();
void Update_shortest_len(int new_v);
void Print_ans();


int main()
{
	ios_base :: sync_with_stdio(false);
	cin >> vertex_num >> edge_num;
	cin >> start_v;

	Init_graph();
	
	fill(shortest_len, shortest_len + 20001, INF);
	
	shortest_len[start_v] = 0;
	Update_shortest_len(start_v);
	
	Cal_shortest_len();
	
	Print_ans();
}

void Init_graph()
{
	int src, dst, len;
	for(int i = 0; i < edge_num; i++){
		cin >> src >> dst >> len;
		adj_list[src].push_back(make_pair(dst, len));
	}
}

void Cal_shortest_len()
{
	while(!edge_len.empty()){
		int new_v = Get_newarest_v();
		int new_edge_len = Get_newarest_v_len();
		edge_len.pop();
		if(new_edge_len > shortest_len[new_v])
			continue;
		Update_shortest_len(new_v);
		visit[new_v] = 1;
	}
}

int Get_newarest_v()
{
	return edge_len.top().first;
}

int Get_newarest_v_len()
{
	return edge_len.top().second;
}

void Update_shortest_len(int new_v)
{
	int adj_v, adj_v_len;
	list<pair<int, int>>::iterator iter;
	
	for(iter = adj_list[new_v].begin(); iter != adj_list[new_v].end(); iter++){
		adj_v = (*iter).first;
		adj_v_len = (*iter).second;
		if(shortest_len[adj_v] > shortest_len[new_v] + adj_v_len){
			shortest_len[adj_v] = shortest_len[new_v] + adj_v_len;
			edge_len.push(make_pair(adj_v,shortest_len[adj_v]));
		}
	}
}


void Print_ans()
{
	for(int i = 1; i <= vertex_num; i++){
		if(shortest_len[i] == INF)
			cout << "INF\n";
		else
			cout << shortest_len[i] << "\n";
	}
}

/*2021-02-13
Refactoring
다익스트라 알고리즘을 공부하고 다시 풀었다.
몇 가지 잘못알고 있었던 점이 있어 애를 먹었다.
다익스트라 알고리즘을 양의 가중치를 가지는 방향 그래프에서 한 vertex로부터 다른 모든
vertex로의 최단경로(값)을 구하는 알고리즘이다.
그리디 방식으로 진행된다. 시작 vertex를 포함한 vertex집합 Y를 두고
Y에 포함되지 않은 인접한 vertex중에서 len이 최소인 vertex와 그 edge를 선택하고
Y에 추가한뒤 추가된 Y집합의 인접한 vertex들의 최단경로(값)을 업데이트 한다. 

매 단계에서 인접한 vertex중 len이 최소인 vertex를 구하는 과정에 우선순위 큐를 쓰면
단순히 pop과정으로 구할 수 있다. 물론 새로운 값을 우선순위 큐에 넣을때 복잡도가 증가한다.
위의 코드도 우선순위 큐를 이용해서 구현했다. 

우선순위 큐에서 cmp함수를 적용하는 법을 배웠다. 
*/
