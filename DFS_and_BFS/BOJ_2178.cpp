#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int rowlen, columnlen;
int map[101][101], visit[101][101], movement[101][101];
int movement_val = 1;
queue < pair<int, int> > q;

void Move(int cur_c, int cur_r);
bool Arrive_endpoint(int cur_c, int cur_r);
void Update_min_movement_val(int adj_loc_c, int adj_loc_r, int movement_val);
bool Adj_loc_not_visited(int adj_loc_c, int adj_loc_r);
bool Adj_loc_in_range(int adj_loc_c, int adj_loc_r);
bool Adj_loc_avail(int adj_loc_c, int adj_loc_r);


int main()
{
	scanf("%d %d", &columnlen, &rowlen);
	char c;
	for(int i = 0; i < columnlen; i++){
		for(int j = 0; j < rowlen; j++){
			c = getchar();
			if(c == '1')
				map[i][j] = 1;
			if(c == '\n'){
				j--;
				continue;
			}
		}
	}
	
	
	visit[0][0] = 1;
	for(int i = 0; i < 100; i++){
		fill(movement[i], movement[i] + 101, 987654321);
	}
	movement[0][0] = 1;
	q.push(make_pair(0, 0));
	Move(0, 0);
	
	printf("%d", movement[columnlen - 1][rowlen - 1]);
}

void Move(int cur_c, int cur_r)
{
	if(Arrive_endpoint(cur_c, cur_r))
		return;
	
	movement_val = movement[cur_c][cur_r];
	
	int dir_c[4] = {-1, 0, 1, 0}, dir_r[4] = {0, 1, 0, -1};
	int adj_loc_c, adj_loc_r;
	for(int i = 0; i < 4; i++){
		adj_loc_c = cur_c + dir_c[i];
		adj_loc_r = cur_r + dir_r[i];
		if(Adj_loc_in_range(adj_loc_c, adj_loc_r) && Adj_loc_not_visited(adj_loc_c, adj_loc_r) && Adj_loc_avail(adj_loc_c, adj_loc_r)){
			visit[adj_loc_c][adj_loc_r] = 1;
			Update_min_movement_val(adj_loc_c, adj_loc_r, movement_val + 1);
			q.push(make_pair(adj_loc_c, adj_loc_r));
		}
	}

	if(q.empty())
		return;
	
	q.pop();
	cur_c = q.front().first;
	cur_r = q.front().second;
	
	
	Move(cur_c, cur_r);
}

bool Arrive_endpoint(int cur_c, int cur_r)
{
	if(cur_c == columnlen - 1 && cur_r == rowlen - 1)
		return true;
	return false;
}

void Update_min_movement_val(int adj_loc_c, int adj_loc_r, int movement_val)
{
	if(movement[adj_loc_c][adj_loc_r] > movement_val)
		movement[adj_loc_c][adj_loc_r] = movement_val;
}

bool Adj_loc_in_range(int adj_loc_c, int adj_loc_r)
{
	if(0 <= adj_loc_c && adj_loc_c < columnlen && 0 <= adj_loc_r && adj_loc_r < rowlen)
		return true;
	return false;
}

bool Adj_loc_not_visited(int adj_loc_c, int adj_loc_r)
{
	if(visit[adj_loc_c][adj_loc_r] == 0)
		return true;
	return false;
}

bool Adj_loc_avail(int adj_loc_c, int adj_loc_r)
{
	if(map[adj_loc_c][adj_loc_r] == 1)
		return true;
	return false;
}

/*2021-01-31
Refactoring 
DFS를 이용하면 모든 경로에 대한 시작-도착 까지의 이동한 칸의 수를 다 구하고 그 중 최소를 구하게 되는데
시간초과가 걸렸다. BFS를 이용해서 각 Move단계에서 인접한 loc의 movement_val을 설정해주는 방식으로 다시 구현했다.
movement[i][j] = min( movement[i-1][j], movement[i+1][j], movement[i][j+1], movement[i][j-1] ) + 1이다. 
도착지인 우측 하단의 movement[columnlen - 1][rowlen - 1]의 값이 정답이다. 
*/
