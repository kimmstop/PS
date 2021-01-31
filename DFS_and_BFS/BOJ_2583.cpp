#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>


using namespace std;


int grid[100][100];
int rowlen, columnlen, rect_num;
int region_size;
priority_queue<int, vector<int>, greater<int>> pq;
queue< pair<int, int> > q;


void Set_rect(int left_up_row, int left_up_col, int rigth_bot_row, int rigth_bot_col);
bool Loc_not_marked(int column, int row);
void Set_start_loc_marked_and_push_q(int column, int row);
int Get_size_of_region(int column, int row);
bool Adj_loc_not_marked(int adj_loc_c, int adj_loc_r);
bool Adj_loc_in_range(int adj_loc_c, int adj_loc_r);
void Push_to_priority_queue(int region_size);
void Print_answer();


int main()
{
	cin >> columnlen >> rowlen >> rect_num;
	int left_up_row, left_up_col, rigth_bot_row, rigth_bot_col;
	for(int i = 0; i < rect_num; i++){
		cin >> left_up_row >> left_up_col >> rigth_bot_row >> rigth_bot_col;
		Set_rect(left_up_row, left_up_col, rigth_bot_row, rigth_bot_col);
	}
	
	for(int i = 0; i < columnlen; i++){
		for(int j = 0; j < rowlen; j++){
			if(Loc_not_marked(i, j)){
				Set_start_loc_marked_and_push_q(i, j);
				region_size = 1;
				Push_to_priority_queue(Get_size_of_region(i, j));
			}
		}
	}
	
	Print_answer();
}

void Set_rect(int left_up_row, int left_up_col, int rigth_bot_row, int rigth_bot_col)
{
	for(int i = left_up_col; i < rigth_bot_col; i++){
		for(int j = left_up_row; j < rigth_bot_row; j++){
			grid[i][j] = 1;
		}
	}
}

bool Loc_not_marked(int column, int row)
{
	if(grid[column][row] == 0)
		return true;
	return false;
}

void Set_start_loc_marked_and_push_q(int column, int row)
{
	grid[column][row] = 1;
	q.push(make_pair(column, row));
}

int Get_size_of_region(int column, int row)
{
	
	int dir_r[4] = {0, 1, 0, -1}, dir_c[4] = {1, 0, -1, 0};
	int adj_loc_c, adj_loc_r;
	for(int i = 0; i < 4; i++){
		adj_loc_c = column + dir_c[i];
		adj_loc_r = row + dir_r[i];
		if(Adj_loc_in_range(adj_loc_c, adj_loc_r) && Loc_not_marked(adj_loc_c, adj_loc_r)){
			grid[adj_loc_c][adj_loc_r] = 1;
			region_size++;	
			q.push(make_pair(adj_loc_c, adj_loc_r));
		}
	}
	
	q.pop();
	
	if(q.empty())
		return region_size;
	
	column = q.front().first;
	row = q.front().second;
	
	return Get_size_of_region(column, row);
}

bool Adj_loc_in_range(int adj_loc_c, int adj_loc_r)
{
	if(0 <= adj_loc_c && adj_loc_c < columnlen && 0 <= adj_loc_r && adj_loc_r < rowlen)
		return true;
	return false;
}

void Push_to_priority_queue(int region_size)
{
	pq.push(region_size);
}


void Print_answer()
{
	int region_num = pq.size();
	cout << region_num << "\n";
	for(int i = 0; i < region_num; i++){
		cout << pq.top() << " ";
		pq.pop();
	}
	
}

/*2020-01-31
Refactoring
배열의 좌표 인덱스와 문제에서 주어지는 좌표의 기준이 달라서 
기준을 맞추는 과정이 필요했다. 손으로 하는게 빠르다.
결국에는 문제에서 주어진 그림을 x축 대칭 시킨 그림으로 input을 받았다.
정답에는 영향이 없다. 
문제에서 주어진 직사각형과 나머지 영역을 탐색하면서 방문한 좌표는 grid[][] = 1로 mark했다. 
나머지 영역의 크기를 구하고 그 값을 우선순위 큐에 넣어서 정렬된 상태를 유지했고 마지막에 정답을 출력했다.
BFS탐색에서 큐가 비었는지 확인 하는 코드의 위치를 잘 못 넣어서 애를 먹었다. 
pop을 하고 다음 호출에 필요한 좌표를 front를 통해 업데이트 하는 과정에서 pop을 하고 empty검사를 하지 않으면
큐가 빈 경우에도 front를 참조하는 잘못된 흐름이 발생한다. 
*/
