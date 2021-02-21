#include <iostream>
#include <cmath>

#define INF 987654321

using namespace std;

int vertex_num;
int map[100][100];
int path[100][100];

void Floyd();
void Print_path();


int main()
{
	cin >> vertex_num;
	int edge;
	for(int i = 0; i < vertex_num; i++){
		for(int j = 0; j < vertex_num; j++){
			cin >> edge;
			if(edge == 1){
				map[i][j] = 1;
			}
			else{
				map[i][j] = INF;
			}
		}
	}
	
	Floyd();
	
	Print_path();
}

void Floyd()
{
	for(int inter_v = 0; inter_v < vertex_num; inter_v++){
		for(int start_v = 0; start_v < vertex_num; start_v++){
			for(int end_v = 0; end_v < vertex_num; end_v++){
				map[start_v][end_v] = min( map[start_v][end_v], map[start_v][inter_v] + map[inter_v][end_v]);
				if(map[start_v][end_v] < INF){
					path[start_v][end_v] = 1;
				}
			}
		}
	}
}

void Print_path()
{
	for(int i = 0; i <vertex_num; i++){
		for(int j = 0; j < vertex_num; j++){
			cout << path[i][j] << " ";
		}
		cout << "\n";
	}
}

/*2021-01-23
Refactoring
정석으로 풀자면 DFS도는 BFS를 사용하여 탐색을 하면서 새로 탐색되는 vertex와 지금까지
거쳐온 vertex 모두를 경로가 있다고 표시하는 것이다. 
하지만 모든 vertex사이의 최단 경로를 구하는 Floyd알고리즘으로 이 문제를 풀 수 있다. 
내가 구현한 Floyd알고리즘은 DP방식을 사용하여 start_v -> end_v 로 가는 경로중
inter_v를 포함하는 경우와 그렇지 않은 경우를 고려하여 그 두가지 경우 중 짧은 경로를 map에 반영하는 것이다.
이때 반복문으로 inter_v가 0부터 문제에서 주어진 vertex_num까지의 상황을 모두 고려한다. 
두 vertex 사이에 경로가 없는 경우에는 매우 큰 수 (여기서는 INF)로 두었다. 
문제의 목적은 i 에서 j로 가는 경로가 있는지 여부에 대한 정보를 출력하는 것이다. 
따라서 map[start_v][end_v]의 값이 INF가 아닐 경우(보다 작을 경우)에 path[start_v][end_v]값을 1로 해주었다. 
*/
