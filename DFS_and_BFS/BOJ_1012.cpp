#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int testcase_num, field_garo_len, field_sero_len, total_cabbage_num;
int whiteworm_num;
int field[50][50], visit[50][50];

stack <int> whiteworm_loc;

int Grid_to_line(int garo, int sero);
void Line_to_Grid(int line_pos, int *garo, int *sero);
void Place_whiteworm(int line_pos);
void Search_adj_loc(int line_pos);
bool Pos_in_range(int pos_garo, int pos_sero);
bool Thereis_cabbage(int line_pos);

int main()
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		cin >> field_garo_len >> field_sero_len >> total_cabbage_num;
	
		int cabbage_loc_garo, cabbage_loc_sero;
		for(int i = 0; i < total_cabbage_num; i++){
			cin >> cabbage_loc_garo >> cabbage_loc_sero;
			field[cabbage_loc_sero][cabbage_loc_garo] = 1;
		}
	
		for(int i = 0; i < field_sero_len; i++){
			for(int j = 0; j < field_garo_len; j++){
				if(field[i][j] == 1 && visit[i][j] == 0){
					Place_whiteworm(Grid_to_line(j, i));
				}
			}
		}
	
		
		for(int i = 0; i < field_sero_len; i++){
			fill(visit[i], visit[i] + field_garo_len, 0);
			fill(field[i], field[i] + field_garo_len, 0);
		}
		
		cout << whiteworm_num << endl;
		whiteworm_num = 0;
	}
}

int Grid_to_line(int garo, int sero)
{
	return sero * field_garo_len + garo;
}

void Line_to_Grid(int line_pos, int *garo, int *sero)
{
	*sero = line_pos / field_garo_len;
	*garo = line_pos % field_garo_len;
}

void Place_whiteworm(int line_pos)
{
	int whiteworm_sero, whiteworm_garo;
	int *whiteworm_sero_p = &whiteworm_sero, *whiteworm_garo_p = &whiteworm_garo;
	Line_to_Grid(line_pos, whiteworm_garo_p, whiteworm_sero_p);
	
	visit[whiteworm_sero][whiteworm_garo] = 1;
	whiteworm_num++;
	whiteworm_loc.push(line_pos);
	
	Search_adj_loc(line_pos);
}

void Search_adj_loc(int line_pos)
{
	if(whiteworm_loc.empty())
		return;
	
	int dir_sero[4] = {-1, 0, 1, 0}, dir_garo[4] = {0, 1, 0, -1};
	
	int cur_sero, cur_garo;
	int *cur_sero_p = &cur_sero, *cur_garo_p = &cur_garo;
	Line_to_Grid(line_pos, cur_garo_p, cur_sero_p);
	
	int adj_sero, adj_garo;
	for(int i = 0; i < 4; i++){
		adj_sero = cur_sero + dir_sero[i];
		adj_garo = cur_garo + dir_garo[i];
		if(Pos_in_range(adj_garo, adj_sero)){
			line_pos = Grid_to_line(adj_garo, adj_sero);
		}
		else
			continue;
		
		
		if(Thereis_cabbage(line_pos)&& visit[adj_sero][adj_garo] == 0){
			whiteworm_loc.push(line_pos);
			visit[adj_sero][adj_garo] = 1;
			Search_adj_loc(line_pos);
		}
	}
	
	whiteworm_loc.pop();
	
}

bool Pos_in_range(int pos_garo, int pos_sero)
{
	if(pos_garo >=0 && pos_garo < field_garo_len && pos_sero >=0 && pos_sero < field_sero_len){
		return true;
	}
	
	return false;
}



bool Thereis_cabbage(int line_pos)
{
	int pos_sero, pos_garo;
	int *pos_sero_p = &pos_sero, *pos_garo_p = &pos_garo;
	Line_to_Grid(line_pos, pos_garo_p, pos_sero_p);
	
	
	if(field[pos_sero][pos_garo] == 1)
		return true;
	
	return false;
}


/*2021-01-13
Refactoring
옛날에 처음 문제를 풀었을 때 문제에서 주어진 가로, 세로와
직접 구현한 배열의 x, y를 혼동하여 애를 먹었다. 
이름이 조금 길어졌지만 의미있는 이름을 사용하니
구현이 더 편해졌다.
2차원배열의 인덱스와 1차원 배열의 인덱스를 서로 변환 해주는 걸 만들었는데
인접한 위치를 확인하는 과정에서 인접한 위치가 배열의 범위 안에 있는지 먼저
확인을 한 후에 배추가 있는지, 방문을 했는지 확인해야한다. 
*/
