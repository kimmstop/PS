#include <iostream>
#include <cstdio>
#include <queue>



using namespace std;

int square_len, num_of_total_apt_complex = 0;
int map[26][26];

queue< pair<int, int> > q;
priority_queue< int, vector<int>, greater<int> > num_of_apt_in_complex;


void Init_map();
void Search_map();
bool Not_visited(int column, int row);
void Add_num_of_total_apt_complex();
int Cal_num_of_apt_in_complex(int column, int row, int num_of_apt);
bool In_range(int column, int row);
void Print_ans();

int main()
{
	cin >> square_len;
	
	Init_map();
	
	Search_map();
	
	Print_ans();
}

void Init_map()
{
	for(int i = 0; i < square_len; i++){
		for(int j = 0; j < square_len; j++){
			scanf(" %1d", &map[i][j]);
		}
	}
}


void Search_map()
{
	for(int i = 0; i < square_len; i++){
		for(int j = 0; j < square_len; j++){
			if(Not_visited(i,j)){
				Add_num_of_total_apt_complex();
				q.push(make_pair(i, j));
				map[i][j] = 0;
				num_of_apt_in_complex.push(Cal_num_of_apt_in_complex(i, j, 1));
			}
		}
	}
}

bool Not_visited(int column, int row)
{
	if(map[column][row] > 0)
		return true;
	return false;
}

void Add_num_of_total_apt_complex()
{
	num_of_total_apt_complex++;
}

int Cal_num_of_apt_in_complex(int column, int row, int num_of_apt)
{
	int dir_c[4] = {1, 0 , -1, 0}, dir_r[4] = {0, 1, 0, -1};
	int adj_c, adj_r;
	for(int i = 0; i < 4; i++){
		adj_c = column + dir_c[i];
		adj_r = row + dir_r[i];
		if(Not_visited(adj_c, adj_r) && In_range(adj_c, adj_r)){
			map[adj_c][adj_r] = 0;
			num_of_apt++;
			q.push(make_pair(adj_c, adj_r));
		}
	}
	
	q.pop();
	
	if(q.empty())
		return num_of_apt;
	
	column = q.front().first;
	row = q.front().second;
	
	return Cal_num_of_apt_in_complex(column, row, num_of_apt);
}

bool In_range(int column, int row)
{
	if(0<= column && column < square_len && 0 <= row && row < square_len)
		return true;
	return false;
}

void Print_ans()
{
	printf("%d\n", num_of_total_apt_complex);
	int size = num_of_apt_in_complex.size();
	for(int i = 0; i < size; i++){
		printf("%d\n", num_of_apt_in_complex.top());
		num_of_apt_in_complex.pop();
	}
}
 

/*2020-02-01
Refactoring
공백이 없는 입력이 주어질 때 getchar를 사용하지 않고
scanf("%1d")를 이용하여 좀 더 간단하게 입력을 받을 수 있다.
지금까지 풀었던 문제들과 매우매우 비슷하다. 
단지를 탐색하고 탐색의 반환값인 단지내 집의 수를 우선순위 큐에 넣으면
정렬된 상태를 유지할 수 있다. 
*/
 


