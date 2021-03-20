#include <iostream>
#include <cstring>


using namespace std;

int testcase_num;
int row_size, column_size, ans, not_covered_num = 0;
int board[20][20];
int block[4][3][2] = {
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, 1}  },
	{ {0, 0}, {1, 0}, {1, -1}  },
	{ {0, 0}, {0, 1}, {1, 0}  }
};


void Get_board();
int Solve();
bool Cover(int block_type, int r, int c, int flag);
bool Overlapped(int r, int c);
bool In_range(int r, int c);
void Print_board();




int main(){
//	ios::sync_with_stdio(false);
	
	cin >> testcase_num;
	
	for(int t = 0; t < testcase_num; t++){
		Get_board();	
		if(not_covered_num % 3 != 0){
			cout << ans << "\n";
			not_covered_num = 0;
			continue;
		}
		ans = Solve();
		cout << ans << "\n";
		ans = 0;
		not_covered_num = 0;
	}
}

void Get_board()
{
	for(int i = 0; i < 20; i++){
		fill(board[i], board[i] + 20, 0);
	}
	cin >> row_size >> column_size;
	char c;
	for(int i = 0; i < row_size; i++){
		for(int j = 0; j < column_size; j++){
			c = getchar();
			if(c =='#')
				board[i][j] = 1;
			else if(c == '\n')
				j--;
			else{
				board[i][j] = 0;
				not_covered_num++;
			}
		}
	}
}

int Solve()
{	
	int r= -1, c= -1, flag = 0, ret = 0;
	for(int row = 0; row < row_size; row++){
		for(int column = 0; column < column_size; column++){
			if(board[row][column] == 0){
				flag = 1;
				r = row;
				c = column;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	if(r == -1 && c == -1){
		//ans++;
		return 1;
	}
	
	for(int block_type = 0; block_type < 4; block_type++){
		if(Cover(block_type, r, c, 1)){
			ret += Solve();
		}
		Cover(block_type, r, c, -1);
	}
	return ret;
}

bool Cover(int block_type, int r, int c, int flag)
{
	int new_r, new_c;
	bool covered = true;
	for(int i = 0; i < 3; i++){
		new_r = r + block[block_type][i][0];
		new_c = c + block[block_type][i][1];
		if(In_range(new_r, new_c)){
			board[new_r][new_c] += flag;
			if(Overlapped(new_r, new_c))
				covered = false;
		}
		else{
			covered = false;
		}
	}
	return covered;

}

bool Overlapped(int r, int c)
{
	if(board[r][c] > 1)
		return true;
	return false;
}

bool In_range(int r, int c)
{
	if(r >=0 && r < row_size && c >= 0 && c < column_size)
		return true;
	return false;
}
