#include <iostream>
#include <functional>

using namespace std;

int testcase_num;
int switch_cnt[10], clock_status[16], ans, minans = 987654321, ansflag, org_status[16];
int switch_info[10][16] = {
	{0, 1, 2, -1},
	{3, 7, 9, 11, -1},
	{4, 10, 14, 15, -1},
	{0, 4, 5, 6, 7, -1},
	{6, 7, 8, 10, 12, -1},
	{0, 2, 14, 15, -1},
	{3, 14, 15, -1},
	{4, 5, 7, 14, 15, -1},
	{1, 2, 3, 4, 5, -1},
	{3, 4, 5, 9, 13, -1}
};




void Init_clock_status();
bool Clock_sync();
void Set_switch_cnt(int switch_val);
void Print_switch();
void Move_clock();
void Print_clock();
void Return_to_org();
	
	
int main() 
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		Init_clock_status();
		
		for(int i = 0; i < 1024 * 1024; i++){
			Set_switch_cnt(i);
			
			Move_clock();
			if(Clock_sync()){
				ansflag = 1;
				if(minans > ans){
					minans = ans;
				}
			}
			Return_to_org();
			ans = 0;
		}
		if(ansflag == 0)
			cout << "-1\n";
		else
			cout << minans << "\n";
		minans = 987654321;
		ansflag = 0;
		fill(switch_cnt, switch_cnt + 10, 0);
	}
}

void Init_clock_status()
{
	for(int i = 0; i < 16; i++){
		cin >> clock_status[i];
		org_status[i] = clock_status[i];
	}
}


void Set_switch_cnt(int switch_val)
{
	int idx = 0;
	while(switch_val > 0){
		switch_cnt[idx] = switch_val % 4;
		switch_val /= 4;
		idx++;
	}
}

void Move_clock()
{
	for(int switch_num = 0; switch_num < 10; switch_num++){
		int movement_val = 3 * switch_cnt[switch_num];
		ans += switch_cnt[switch_num];
		if(movement_val == 0)
			continue;
		int clock_idx = 0;
		while(switch_info[switch_num][clock_idx] != -1){
			clock_status[switch_info[switch_num][clock_idx]] += movement_val;
			if(clock_status[switch_info[switch_num][clock_idx]] > 12)
				clock_status[switch_info[switch_num][clock_idx]] %= 12;
			clock_idx++;
		}
	}
}

bool Clock_sync()
{
	for(int i = 0; i < 16; i++){
		if(clock_status[i] != 12)
			return false;
	}
	return true;
}


void Return_to_org()
{
	for(int i = 0; i < 16; i++){
		clock_status[i] = org_status[i];
	}
}