#include <iostream>
#include <queue>


using namespace std;

class Pos{
	private:
		int h, c, r;
	public:
		Pos(int, int, int);
		int Get_height()
		{
			return h;
		}
		int Get_column()
		{
			return c;
		}
		int Get_row()
		{
			return r;
		}
	
};

Pos::Pos(int height, int column, int row)
{
	h = height, c = column, r = row;
}

int box[100][100][100];
int rowlen, columnlen, heightlen;
int not_ripe_tomato_num, day;

queue< Pos > q;

void Init_box();
void Insert_already_ripe_tomato();
void Cal_day_for_ripe(int height, int column, int row);
void One_day_after(int height, int column, int row);
bool Is_ripe_tomato(int height, int column, int row);
bool Is_not_ripe_tomato(int height, int column,int row);
void Add_newly_ripe_tomato(int height, int column, int row);
bool In_range(int height, int column, int row);
	
int main()
{
	cin >> rowlen >> columnlen >> heightlen;
	
	Init_box();
	
	
	Insert_already_ripe_tomato();
	
	
	Cal_day_for_ripe(0, 0, 0);
	
	if(not_ripe_tomato_num > 0)
		cout << "-1";
	else
		cout << day;
		
}

void Init_box()
{
	for(int k = 0; k < heightlen; k++){
		for(int i = 0; i < columnlen; i++){
			for(int j = 0; j < rowlen; j++){
				cin >> box[k][i][j];
				if(Is_not_ripe_tomato(k, i, j))
					not_ripe_tomato_num++;
			}
		}
	}
}

void Insert_already_ripe_tomato()
{
	for(int k = 0; k < heightlen; k++){
		for(int i = 0; i < columnlen; i++){
			for(int j = 0; j < rowlen; j++){
				if(Is_ripe_tomato(k, i, j)){
					Pos ripe_tomato_pos(k, i, j);
					q.push(ripe_tomato_pos);
				}	
			}
		}
	}
}

void Cal_day_for_ripe(int height, int column, int row)
{
	while( (!q.empty()) && not_ripe_tomato_num != 0){
		One_day_after(height, column, row);
	}
}

void One_day_after(int height, int column, int row)
{
	int size = q.size();
	for(int i = 0; i < size; i++){
		Pos tmp = q.front();
		height = tmp.Get_height();
		column = tmp.Get_column();
		row = tmp.Get_row();
		Add_newly_ripe_tomato(height, column, row);
		q.pop();	
	}
	
	day++;
}


void Add_newly_ripe_tomato(int height, int column, int row)
{
	int dir_c[6] = {0, 1, 0, -1, 0, 0}, dir_r[6] = {1, 0, -1, 0, 0 ,0}
	,dir_h[6] = {0, 0, 0, 0, 1, -1};
	int adj_c, adj_r, adj_h;
	for(int j = 0; j < 6; j++){
		adj_h = height + dir_h[j];
		adj_c = column + dir_c[j];
		adj_r = row + dir_r[j];
		if(In_range(adj_h, adj_c, adj_r) &&Is_not_ripe_tomato(adj_h, adj_c, adj_r)){
			Pos newly_ripe_tomato_pos(adj_h, adj_c, adj_r);
			q.push(newly_ripe_tomato_pos);
			not_ripe_tomato_num--;
			box[adj_h][adj_c][adj_r] = 1;
		}
	}
}

bool Is_ripe_tomato(int height, int column, int row)
{
	if(box[height][column][row] == 1)
		return true;
	return false;
}

bool Is_not_ripe_tomato(int height, int column,int row)
{
	if(box[height][column][row] == 0)
		return true;
	return false;
}

bool In_range(int height, int column, int row)
{
	if(0 <= height && height < heightlen && 0 <= column && column < columnlen && 0 <= row && row < rowlen)
		return true;
	return false;
}

/*2021-02-09
Refactoring
2차원 버전의 토마토 문제에서 3차원으로 바뀐 것뿐이다. 예전에 처음 풀었을 때는 2차원에서 3차원
으로 바뀐것 뿐인데도 조금 헤매었지만, 변수이름, 함수이름을 잘 지으니 편리하게 3차원을 
풀수 있었다. 추가한것은 2차원에서의 토마토 좌표를 pair를 사용했지만 3차원에서는
별도의 class를 두었다. 아직 class를 예쁘고, 제대로 사용하는 방법을 모르기에 어색했다. 

세그폴트가 나타났었는데, 125번줄에서 조건문안에서 새 좌표과 범위에 있는 것과 익지 않은 토마토인지
확인 하는 과정에서 새 좌표가 범위에 있는 것을 먼저 검사해야 익지않은 토마토를 검사하는 과정에서
세그폴트가 생기지 않는다. 2차원 토마토에도 수정을 해야한다. */