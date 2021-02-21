#include <iostream>
#include <stack>
#include <functional>
using namespace std;

int testcase_num, student_num, friends_pair_num, ans;
int students[10][10], student_pair[10], already_paired_stuedents[10]; 
stack <pair <int, int> > s;

void Get_input();
void Make_pair(int student_idx);
void Backtrack();
bool Is_friends(int student_idx1, int student_idx2);
bool Not_paired(int student_idx);
void Init_var();

int main()
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		Get_input();
		Make_pair(0);
		cout << ans << "\n";
		Init_var();
	}
}

void Get_input()
{
	int f1, f2;
	cin >> student_num >> friends_pair_num;
	for(int i = 0; i < friends_pair_num; i++){
		cin >> f1 >> f2;
		students[f1][f2] = 1;
		students[f2][f1] = 1;
	}
}

void Make_pair(int student_idx)
{
	if(student_idx == student_num){
		Backtrack();
		ans++;
		return;
	}
	if(already_paired_stuedents[student_idx]){
		Make_pair(student_idx + 1);
		return;
	}
	for(int p = 0; p < student_num; p++){
		if(Is_friends(p, student_idx) && Not_paired(p)){
			s.push(make_pair(p, student_idx));
			already_paired_stuedents[p] = 1;
			already_paired_stuedents[student_idx] = 1;
			Make_pair(student_idx + 1);
		}
	}
	if(s.empty())
		return;
	Backtrack();
}

void Backtrack()
{
	int f1 = s.top().first;
	int f2 = s.top().second;
	s.pop();
	already_paired_stuedents[f1] = 0;
	already_paired_stuedents[f2] = 0;
}

bool Is_friends(int student_idx1, int student_idx2)
{
	if(students[student_idx1][student_idx2] == 1){
		return true;
	}
	return false;
}

bool Not_paired(int student_idx)
{
	if(already_paired_stuedents[student_idx] == 0)
		return true;
	return false;
}

void Init_var()
{
	for(int i = 0; i < 10; i++){
		fill(students[i], students[i] + 10, 0);
	}
	fill(student_pair, student_pair + 10, 0);
	fill(already_paired_stuedents, already_paired_stuedents + 10, 0);
	ans = 0;
}