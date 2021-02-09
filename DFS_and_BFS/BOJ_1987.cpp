#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int rowlen, columnlen;
int board[20][20];
int visited_alphabet[100];
int max_movement_val, movement_val= 1;
stack < pair<int, int> > s;

void Move(int cur_c, int cur_r);
void Update_max_movement_val();
bool Adj_loc_in_range(int adj_loc_c, int adj_loc_r);
bool Adj_loc_alpabet_not_visited(int alphabet);
	
int main()
{
	char c;
	scanf("%d %d ", &columnlen, &rowlen);
	for(int i = 0; i < columnlen; i++){
		for(int j = 0; j < rowlen; j++){
			c = getchar();
			if(c == '\n'){
				j--;
				continue;
			}
			board[i][j] = c;
		}
	}
	s.push(make_pair(0, 0));
	visited_alphabet[board[0][0]] = 1;
	Move(0, 0);
	
	cout << max_movement_val;
}


void Move(int cur_c, int cur_r)
{
	
	Update_max_movement_val();
	
	int dir_c[4] = {0, 1, 0, -1}, dir_r[4] = {1, 0, -1, 0};
	int adj_loc_c, adj_loc_r, alphabet;
	for(int i = 0; i < 4; i++){
		adj_loc_c = cur_c + dir_c[i];
		adj_loc_r = cur_r + dir_r[i];
		alphabet = board[adj_loc_c][adj_loc_r];
		if(Adj_loc_in_range(adj_loc_c, adj_loc_r) && Adj_loc_alpabet_not_visited(alphabet)){
			visited_alphabet[alphabet] = 1;
			movement_val++;
			s.push(make_pair(adj_loc_c, adj_loc_r));
			Move(adj_loc_c, adj_loc_r);
		}
	}
	
	visited_alphabet[board[cur_c][cur_r]] = 0;
	s.pop();
	movement_val--;
	
	if(s.empty())
		return;
	
	
	
}

void Update_max_movement_val()
{
	if(max_movement_val < movement_val)
		max_movement_val = movement_val;
}

bool Adj_loc_in_range(int adj_loc_c, int adj_loc_r)
{
	if(0 <=adj_loc_c && adj_loc_c < columnlen && 0 <= adj_loc_r && adj_loc_r < rowlen){
		return true;
	}
	return false;
}

bool Adj_loc_alpabet_not_visited(int alphabet)
{
	if(visited_alphabet[alphabet] == 0)
		return true;
	return false;
}




/*2021-01-30
Refactorig
알파벳의 아스키 코드를 참조해서 visited_alphabet배열을 필요한 만큼만 
사용하려 했지만, 알파벳이 아스키 코드로 얼마인지 외우고 있지 않아서
넉넉히 할당했다. 검색해보니 대문자는 65 ~ 90이고 소문자는 97 ~ 122이다.
출력을 통해서 알 수도 있었지만 넉넉히 할당해서 배열의 인덱스 값을 조정할 필요없이
사용하는것도 나쁘지 않은거 같다. 다른 DFS문제와의 차이점은 스택에서 pop을 할때 방문했던 
알파벳을 방문해제 해주는 것이다. 
다른 경로(더 많이 이동한 뒤에)를 통해 그 알파벳을 방문할 수도 있기때문이다. 
*/
