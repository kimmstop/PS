#include <iostream>
#include <cstdio>
#include <cstring>
#include <functional>
using namespace std;

int testcase_num, word_num;
char board[5][5];
string word[10], ans[10];
string cur_word;
int word_idx, find_flag;

void Find_word();
bool Is_same_char(char w, char b);
void Search(int b_r, int b_c, int word_char_idx);
bool In_range(int adj_r, int adj_c);
void Print_ans();




int main()
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			board[i][j] = getchar();
			if(board[i][j] == '\n')
				j--;
		}
	}

	fill(ans, ans + 10, "NO");
		
	cin >> word_num;
	for(int i = 0; i < word_num; i++){
		cin >> word[i];
	}
	
	

	for(int i = 0; i < word_num; i++){
		cur_word = word[i];
		word_idx = i;
		Find_word();
		find_flag = 0;
	}
	
	Print_ans();
	}
}

void Find_word()
{
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(Is_same_char(cur_word[0], board[i][j])){
				Search(i, j, 1);
			}
			if(find_flag == 1)
				return;
		}
	}
	
	
}

bool Is_same_char(char w, char b)
{
	if(w == b)
		return true;
	return false;
}

void Search(int b_r, int b_c, int word_char_idx)
{
	if(word_char_idx == cur_word.length()){
		ans[word_idx] = "YES";
		find_flag = 1;
		return;
	}
	int dir_r[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int dir_c[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int adj_r, adj_c;
	for(int i = 0; i < 8; i++){
		adj_r = dir_r[i] + b_r;
		adj_c = dir_c[i] + b_c;
		if(In_range(adj_r, adj_c) && Is_same_char(cur_word[word_char_idx], board[adj_r][adj_c])){
			Search(adj_r, adj_c, word_char_idx + 1);
		}
		if(find_flag == 1)
			return;
	}
	
}

bool In_range(int adj_r, int adj_c)
{
	if(adj_r >= 0 && adj_r < 5 && adj_c >= 0 && adj_c < 5)
		return true;
	return false;
}

void Print_ans()
{
	for(int i = 0; i < word_num; i++){
		cout << word[i] << " " << ans[i] << "\n";
	}
}



/*6장만 읽고 시간초과가 걸렸다. 8장을 읽고 다시해보자*/
/*Seach함수를 재귀적 방식으로 호출할때 기저 사례를 잘 파악하고 호출하자
기본적인 기저사례로는 
1. (r,c)에 있는 문자가 원하는 단어의 첫 글자가 아닌 경우 실패
2. (1이 아닐때) 원하는 단어가 한 글자인 경우 성공
추가적으로 범위를 벗어나거나 잘못된 입력에 대해서도 기저사례로 선택하는 것이 좋다.
1. (r,c)가 보드 범위를 벗어나면 실패








