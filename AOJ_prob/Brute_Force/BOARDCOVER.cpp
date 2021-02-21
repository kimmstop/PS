#include <iostream>
#include <functional>
#include <stack>

using namespace std;



int testcase_num, rowlen, columnlen, ans, blank_num;
int board[20][20];

int block[4][3][2] = {
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1} }
};


void Get_input();
int Count_cover();
bool Set(int c, int r, int dir, int flag);
bool In_range(int c, int r);
bool Is_avail(int c, int r);
void Init_board();


int main()
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		cin >> columnlen >> rowlen;
		Get_input();
		if(blank_num % 3 != 0){
			cout << ans << "\n";
			continue;
		}
		ans = Count_cover();
		cout << ans << "\n";
		Init_board();
	}
	
	
}

void Get_input()
{
	char c;
	for(int i = 0; i < columnlen; i++){
		for(int j = 0; j < rowlen; j++){
			c = getchar();
			if(c == '\n')
				j--;
			else if(c == '#')
				board[i][j] = 1;
			else {
				board[i][j] = 0;	
				blank_num++;
			}
		}
	}
}

int Count_cover()
{
	int c = -1, r = -1, ret = 0;
	int f = 0;	
	for(int i = 0; i < columnlen; i++){
		for(int j = 0; j < rowlen; j++){
			if(board[i][j] == 0){
				f = 1;
				c = i;
				r = j;
				break;
			}
		}
		if(f == 1)
			break;
	}
	
	if(c == -1 && r == -1){
		return 1;
	}
	for(int i = 0; i < 4; i++){
		if(Set(c, r, i, 1)){
			ret += Count_cover();
		}
		Set(c, r, i, -1);
	}
	
	return ret;
}

bool Set(int c, int r, int dir, int flag)
{
	bool covered = true;
	for(int i =0; i < 3; i++){
		int nc = c + block[dir][i][0];
		int nr = r + block[dir][i][1];
		if(In_range(nc, nr)){
			if((board[nc][nr] += flag) > 1)
				covered = false;
		}
		else{
			covered = false;
		}
	}
	return covered;
}


bool In_range(int c, int r)
{
	if(c >= 0 && c < columnlen && r >= 0 && r < rowlen)
		return true;
	return false;
}

bool Is_avail(int c, int r)
{
	if(board[c][r]== 0)
		return true;
	return false;
}

void Init_board()
{
	for(int i = 0; i < 20; i++){
		fill(board[i], board[i] + 20, 0);
	}
}