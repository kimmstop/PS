#include <iostream>
#include <vector>


using namespace std;

int board[9][9], idx = 0;
int pos_x_to_insert, pos_y_to_insert;
vector<pair<int,int>> pos_to_insert;


void Find_suit_num();
bool Is_suit(int num_to_insert);
bool Is_suit_garo(int x, int num_to_insert);
bool Is_suit_square(int x, int y, int num_to_insert);
bool Is_suit_sero(int y, int num_to_insert);
void Set_next_pos();
void Set_prev_pos();
	
int main()
{
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> board[i][j];
			if(board[i][j] == 0)
				pos_to_insert.push_back(make_pair(i,j));
		}
	}
	pos_x_to_insert = pos_to_insert[0].first;
	pos_y_to_insert = pos_to_insert[0].second;
	Find_suit_num();
}


void Find_suit_num()
{
	if(idx == pos_to_insert.size()){
		for(int i = 0; i < 9; i ++){
			for(int j =0; j < 9; j++){
				cout << board[i][j] << "  ";
			}
			cout << "\n";
		}
		exit(0);
	}
		
	for(int num_to_insert = 1; num_to_insert <= 9; num_to_insert++){
		if(Is_suit(num_to_insert) == true){
			board[pos_x_to_insert][pos_y_to_insert] = num_to_insert;
			Set_next_pos();
			Find_suit_num();
		}
	}
	board[pos_x_to_insert][pos_y_to_insert] = 0;
	Set_prev_pos();
	return;
	
}

bool Is_suit(int num_to_insert)
{
	if(Is_suit_garo(pos_x_to_insert, num_to_insert) == false)
		return false;
	if(Is_suit_sero(pos_y_to_insert, num_to_insert) == false)
		return false;
	if(Is_suit_square(pos_x_to_insert, pos_y_to_insert, num_to_insert) == false)
		return false;
	return true;
}

bool Is_suit_garo(int x, int num_to_insert)
{
	for(int i = 0; i < 9; i++){
		if(num_to_insert == board[x][i])
			return false;
	}
	return true;
}

bool Is_suit_square(int x, int y, int num_to_insert)
{
	int left_top_x_of_square = (x / 3) * 3;
	int left_top_y_of_square = (y / 3) * 3;
	for(int i = left_top_x_of_square; i < left_top_x_of_square + 3; i++){
		for(int j =left_top_y_of_square; j < left_top_y_of_square +3; j++){
			if(board[i][j] == num_to_insert)
				return false;
		}	
	}
	return true;
}

bool Is_suit_sero(int y, int num_to_insert)
{
	for(int i = 0; i < 9; i++){
		if(num_to_insert == board[i][y])
			return false;
	}
	return true;
}

void Set_next_pos()
{
	idx++;
	pos_x_to_insert = pos_to_insert[idx].first;
	pos_y_to_insert = pos_to_insert[idx].second;
}

void Set_prev_pos()
{
	idx--;
	pos_x_to_insert = pos_to_insert[idx].first;
	pos_y_to_insert = pos_to_insert[idx].second;
	
}

/* 무작정 재귀함수를 만들지 않고 재귀함수의 특징을 이용해서
   전체 과정을 작고 반복적인 과정으로 나누고 base case를
   먼저 가정하여 구현했더니 훨 편했다. 마지막에 정답을 1번만
   출력해야하는 부분과 idx와 pos_to_insert.szie의 크기를 비교
   하는 과정에서 애를 먹었다. 조건 계산을 잘하자.
   스도쿠의 3가지 조건을 모두 만족하면 board에  숫자를 기입하고
   나중에 불가능한 경우를 만났을때 board에 넣었던 숫자를 0
   으로 만들고 이전에 방문했던 board의 위치로 이동 한다.
   다음 위치와 이전위치를 설정하는 함수에서 idx의 크기를
   언제 조정하냐가 좀 중요했다. */