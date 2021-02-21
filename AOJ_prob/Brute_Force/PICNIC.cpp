#include <iostream>
#include <functional>
using namespace std;

int testcase_num, student_num, friends_pair_num, ans;
int students[10][10], student_pair[10]; 

void Get_input();
int Count_pair(int already_paired_stuedents[10]);
bool Is_friends(int student_idx1, int student_idx2);
void Init_var();

int main()
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		Get_input();
		int already_paired_stuedents[10];
		fill(already_paired_stuedents, already_paired_stuedents +10, 0);
		ans = Count_pair(already_paired_stuedents);
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

int Count_pair(int already_paired_stuedents[10])
{
	int first_not_paired = -1;
	for(int i = 0; i < student_num; i++){
		if(already_paired_stuedents[i] == 0){
			first_not_paired = i;
			break;
		}			
	}
	
	if(first_not_paired== -1){
		return 1;
	}
	
	int ret = 0;
	for(int i = first_not_paired + 1; i < student_num; i++){
		if(Is_friends(first_not_paired, i) && already_paired_stuedents[i] == 0){
			already_paired_stuedents[first_not_paired] = 1;
			already_paired_stuedents[i] = 1;
			ret += Count_pair(already_paired_stuedents);
			already_paired_stuedents[first_not_paired] = 0;
			already_paired_stuedents[i] = 0;
		}
	}
	return ret;
}


bool Is_friends(int student_idx1, int student_idx2)
{
	if(students[student_idx1][student_idx2] == 1){
		return true;
	}
	return false;
}


void Init_var()
{
	for(int i = 0; i < 10; i++){
		fill(students[i], students[i] + 10, 0);
	}
	fill(student_pair, student_pair + 10, 0);
}