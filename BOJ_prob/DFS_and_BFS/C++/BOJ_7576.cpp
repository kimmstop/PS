#include <iostream>
#include <queue>


using namespace std;

int box[1000][1000];
int rowlen, columnlen;
int not_ripe_tomato_num, day;

queue< pair<int ,int> > q;

void Init_box();
void Insert_already_ripe_tomato();
void Cal_day_for_ripe(int column, int row);
void One_day_after(int column, int row);
bool Is_ripe_tomato(int column, int row);
bool Is_not_ripe_tomato(int column,int row);
void Add_newly_ripe_tomato(int column, int row);
bool In_range(int column, int row);
	
int main()
{
	cin >> rowlen >> columnlen;
	
	Init_box();
	
	
	Insert_already_ripe_tomato();
	
	
	Cal_day_for_ripe(0, 0);
	
	if(not_ripe_tomato_num > 0)
		cout << "-1";
	else
		cout << day;
		
}

void Init_box()
{
	for(int i = 0; i < columnlen; i++){
		for(int j = 0; j < rowlen; j++){
			cin >> box[i][j];
			if(Is_not_ripe_tomato(i, j))
				not_ripe_tomato_num++;
		}
	}
}

void Insert_already_ripe_tomato()
{
	for(int i = 0; i < columnlen; i++){
		for(int j = 0; j < rowlen; j++){
			if(Is_ripe_tomato(i, j)){
				q.push(make_pair(i, j));
			}
		}
	}
}

void Cal_day_for_ripe(int column, int row)
{
	while( (!q.empty()) && not_ripe_tomato_num != 0){
		One_day_after(column, row);
	}
}

void One_day_after(int column, int row)
{
	int size = q.size();
	for(int i = 0; i < size; i++){
		column = q.front().first;
		row = q.front().second;
		Add_newly_ripe_tomato(column, row);
		q.pop();
	}
	
	day++;
}


void Add_newly_ripe_tomato(int column, int row)
{
	int dir_c[4] = {0, 1, 0, -1}, dir_r[4] = {1, 0, -1, 0};
	int adj_c, adj_r;
	for(int j = 0; j < 4; j++){
		adj_c = column + dir_c[j];
		adj_r = row + dir_r[j];
		if(Is_not_ripe_tomato(adj_c, adj_r) && In_range(adj_c, adj_r)){
			q.push(make_pair(adj_c, adj_r));
			not_ripe_tomato_num--;
			box[adj_c][adj_r] = 1;
		}
	}
}

bool Is_ripe_tomato(int column, int row)
{
	if(box[column][row] == 1)
		return true;
	return false;
}

bool Is_not_ripe_tomato(int column,int row)
{
	if(box[column][row] == 0)
		return true;
	return false;
}

bool In_range(int column, int row)
{
	if(0 <= column && column < columnlen && 0 <= row && row < rowlen)
		return true;
	return false;
}


/*2021-02-06
Refactoring
1. 문제에서 요구하는 토마토가 완전히 익는데 걸리는 최소 날짜를 카운트하는 방법
2. 토마토가 모두 익지 못하는 상황과 저장될 때부터 모든 토마토가 익은 상태 등의 예외 상황
이 두가지가 핵심이다. 사실 2의 모든 토마토가 이미 익은 상태는 day를 카운트를 안하면 되기
때문에 예외라고 보기 어렵고 토마토가 익지 못하는 상황에 대한 예외는 Init_box()에서
토마토의 정보를 받을 때 not_ripe_tomato_num 변수를 두어 모든 탐색 후 변수의 값이 1이상이면
익지 못하는 토마토가 있다는 것으로 판단하고 예외처리 했다.

숨바꼭질 문제와 비슷하게 정답을 언제 카운트 할 지가 중요하다. 하루가 지나면 box내의 모든 익은 토마토들이 인접한 토마토에 영향을 주기 때문이다. 현재 box에서 가장 최근에 익은 토마토의 정보를
큐에 넣고 그 큐의 size 만큼 BFS를 하면 하루가 지난 효과를 가질 수 있다. 이 과정을 One_day_after함수로 구현했다. 이렇게 하니까 구현한 코드에서 예제의 정답 + 1을 답으로 출력해냈다. 분석을 해보니 BFS과정(익은 토마토가 인접한 덜 익은 토마토에게 영향을 주는)에서 
not_ripe_tomato_num가 0이 되어도 큐에 원소가 들어있다면 One_day_after함수를 호출하게 된다.
즉 애초에 모든 토마토가 다 익은 경우에서도 One_day_after 함수를 한 번 호출하게 된다. 
그래서 큐의 상태와 함께 not_ripe_tomato_num의 수도 control 변수로 했는데 
머리가 상당히 복잡해져서 진리표를 만들어서 while문을 control했다. 
다음부턴 머리아프게 고민하지 말고 바로 진리표를 만들자.
*/

		   
