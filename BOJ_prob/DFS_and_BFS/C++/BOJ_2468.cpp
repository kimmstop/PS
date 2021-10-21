#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int size_of_map;
int h_flood;
int max_h_region, h_region;
int max_num_of_safe_region, num_of_safe_region;
int map[100][100], visit[100][100];

queue< pair<int,int> > q;


void Search_num_of_safe_loc();
bool Loc_is_not_sunk(int loc_x, int loc_y);
bool Loc_is_not_visited(int loc_x, int loc_y);
void Search_adj_safe_loc(int loc_x, int loc_y);
bool Loc_is_in_range(int loc_x, int loc_y);
void Update_max_num_of_safe_region();	
	
	
int main()
{
	cin >> size_of_map;
	for(int i =0; i < size_of_map; i++){
		for(int j =0; j < size_of_map; j++){
			cin >> map[i][j];
			if(max_h_region < map[i][j])
				max_h_region = map[i][j];
		}
	}
	
	
	for(h_flood = 0; h_flood <= max_h_region; h_flood++){
		Search_num_of_safe_loc();
	}
	
	cout << max_num_of_safe_region;
}


void Search_num_of_safe_loc()
{
	for(int loc_x = 0; loc_x < size_of_map; loc_x++){
		for(int loc_y = 0; loc_y < size_of_map; loc_y++){
			if(Loc_is_not_sunk(loc_x, loc_y) && Loc_is_not_visited(loc_x, loc_y)){
				num_of_safe_region++;
				visit[loc_x][loc_y] = 1;
				Search_adj_safe_loc(loc_x, loc_y);
			}
		}
	}
	
	Update_max_num_of_safe_region();
	for(int i = 0; i < size_of_map; i++){
		fill(visit[i], visit[i] + size_of_map, 0);
	}
	num_of_safe_region = 0;
	
}

bool Loc_is_not_sunk(int loc_x, int loc_y)
{
	if(map[loc_x][loc_y] > h_flood)
		return true;
	return false;
}

bool Loc_is_not_visited(int loc_x, int loc_y)
{
	if(visit[loc_x][loc_y] == 0)
		return true;
	return false;
}


void Search_adj_safe_loc(int loc_x, int loc_y)
{
	int dir_x[4] = {-1, 0 , 1 , 0}, dir_y[4] = {0, 1, 0, -1};
	int adj_x, adj_y;
	for(int i = 0; i < 4; i++){
		adj_x = loc_x + dir_x[i];
		adj_y = loc_y + dir_y[i];
		if(Loc_is_in_range(adj_x, adj_y) && Loc_is_not_sunk(adj_x, adj_y) && Loc_is_not_visited(adj_x, adj_y)){
			visit[adj_x][adj_y] = 1;
			q.push(make_pair(adj_x, adj_y));
		}
	}
	
	
	if(q.empty())
		return;
	
	loc_x = q.front().first;
	loc_y = q.front().second;
	q.pop();
	Search_adj_safe_loc(loc_x, loc_y);
}


bool Loc_is_in_range(int loc_x, int loc_y)
{
	if(loc_x >=0 && loc_x < size_of_map && loc_y >=0 && loc_y < size_of_map)
		return true;
	return false;
}


void Update_max_num_of_safe_region()
{
	if(max_num_of_safe_region < num_of_safe_region)
		max_num_of_safe_region = num_of_safe_region;
}


/*2021-01-09
Refactoring
변수이름과 함수이름, 기능 등 총체적으로 다시 구현했다.
맨 처음구현할 때에도 이름과 기능 분리로 애를 먹었다. 
큐에 넣을때 방문 체크를 해야한다. 
*/
