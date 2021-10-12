#include <iostream>
#include <functional>
#include <algorithm>


using namespace std;

int have_num, select_num;
int have[1000], selected[1000], digit[1000];


void Solve();
void Select_num();
void Print_select();

int main()
{
	cin >> have_num >> select_num;
	for(int i = 0; i < have_num; i++){
		cin >> have[i];
	}
	
	sort(have, have + have_num);
	
	Solve();
}


void Solve()
{
	Select_num();
	
	
	Print_select();
}

void Select_num()
{
	int num_of_overlapped = select_num - have_num;
	int idx = 0;
	for(int i = 0; i < num_of_overlapped; i++){
		selected[idx++] = have[have_num - 1];
	}
	for(int i = 0; i < have_num; i++){
		selected[idx++] = have[have_num - 1 - i];
	}
}

void Print_select()
{
	for(int i = 0; i < select_num; i++){
		cout << selected[i] << " ";
	}
}

