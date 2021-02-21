#include <iostream>
#include <stack>
#include <functional>

using namespace std;


int width, height, num_of_islands = 0;
int map[50][50];
stack < pair<int, int> > s;



bool Last_input();
void Init_map();
void Cal_num_of_islands();
bool Is_land(int h, int w);
void Add_num_of_islands();
void Init_setting_for_search(int h, int w);
void Search_adj_land(int h, int w);
bool In_range(int adj_h, int adj_w);
void Print_ans();


int main()
{
	while(true){
		cin >> width >> height;
		
		if(Last_input())
			return 0;
		
		Init_map();
		
		Cal_num_of_islands();
		
		Print_ans();
	}
	
	
}


bool Last_input()
{
	if(width == 0 && height == 0)
		return true;
	return false;
}


void Init_map()
{	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			cin >> map[i][j];
		}
	}
	
	num_of_islands = 0;
}

void Cal_num_of_islands()
{
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(Is_land(i, j)){
				Add_num_of_islands();
				
				Init_setting_for_search(i, j);
				
				Search_adj_land(i, j);	
			}
		}
	}
}

bool Is_land(int h, int w)
{
	if(map[h][w] == 1)
		return true;
	return false;
}

void Add_num_of_islands()
{
	num_of_islands++;
}

void Init_setting_for_search(int h, int w)
{
	s.push(make_pair(h, w));
	map[h][w] = 0;
}

void Search_adj_land(int h, int w)
{
	int dir_h[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
	int dir_w[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int adj_h, adj_w;
	
	for(int i = 0; i < 8; i++){
		adj_h = h + dir_h[i];
		adj_w = w + dir_w[i];
		if(Is_land(adj_h, adj_w) && In_range(adj_h, adj_w)){
			s.push(make_pair(adj_h, adj_w));
			map[adj_h][adj_w] = 0;
			Search_adj_land(adj_h, adj_w);
		}
	}
	
	s.pop();
	
	if(s.empty())
		return;
}


bool In_range(int adj_h, int adj_w)
{
	if(0 <= adj_h && adj_h < height && 0 <= adj_w && adj_w < width)
		return true;
	return false;
}


void Print_ans()
{
	cout << num_of_islands << "\n";
}

/*2021-02-02
Refactoring
섬을 탐색하면서 map[i][j]의 값을 0으로 만들어줘서 "섬"을 "바다"
로 만들었다. 방문을 확인하는 배열을 만들지 않아도 된다.
또한 fill(map[i], map[i] + 50, 0)으로 매 테스트 케이스마다
map을 0으로 초기화 할 필요가 없어졌다.
(테스트케이스가 끝나면 map은 모두 0으로 되어있다.)

코드를 의미 단위로 한 줄씩 띄어서 작성하니까 보기가 좀 나아졌다. 
*/



