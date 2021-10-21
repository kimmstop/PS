#include <iostream>

using namespace std;

int N, ans=0, idx=1;
int queen_col[15];

void set_queen(int row);
bool check_queen(int row, int col);

int main()
{
	cin >> N;
	for(int i=0; i < N; i++){
		queen_col[0] = i;
		idx = 1;
		set_queen(1);
	}
	cout << ans << endl;
}



void set_queen(int row)
{
	if(idx == N){
		idx--;
		ans++;
		return;
	}
	for(int i = row; i< N; i++){
		for(int j = 0; j < N; j++){
			if(check_queen(i,j)){
				queen_col[idx++] = j;
				set_queen(row+1);
			}
		}
		idx--;
		return;
	}
		
}

bool check_queen(int row, int col)
{
	for(int q_row = 0; q_row < idx; q_row++){
		if(queen_col[q_row] == col || row - q_row == queen_col[q_row] - col ||
		   row - q_row == (queen_col[q_row] - col) * -1){
			return false;
			}
	}
	return true;
}



/* 알고리즘을 공부하고 푸니가 훨 낫다. 보드판에 N개의 퀸을 놓으려면
 * 각 row에 퀸을 1개씩 놓아야한다고 생각하여 각 row에 퀸을 놓을 위치
 * 를 정하고 그 위치를 queen_col[]에 저장했다. queen_col[i]는 i번째 row의
 * 퀸의 col 값이 저장되어있다. check_queen함수는 새로운 지점에 대해서
 * 이전의 모든 퀸의 위치와 공격 불가능한위치가 되는지 판단하는 함수이고
 * 퀸의 위치를 확정할 때 마다 idx를 증가시키고 백트랙킹 할 때에는 감소시켰다. 
 * 시작할때 idx를 1로 초기화 했다. */
