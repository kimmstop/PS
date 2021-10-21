#include <iostream>
#include <cmath>
#include <cstring>

#define ENOUGH_LARGE_NUM 999999;
using namespace std;


int num_of_member, num_of_member_in_team;
int total_member[20], first_team_member[10], second_team_member[10];
int first_team_member_idx, second_team_member_idx;
int ability[20][20];
int first_team_ability, second_team_ability, min_differ_of_ability = ENOUGH_LARGE_NUM;
int pair_in_first_team[2], pair_in_second_team[2], pair_idx;

void Make_team();
void Set_first_team_and_fill_second_team(int member_to_insert);
void Get_team_ability_and_cal_diff_of_ability();
void Get_Each_team_ability(int member_to_pair);
void Fill_second_team();
bool Isremain_member(int member);
void Calculate_diff_of_ability();

int main()
{
	cin >> num_of_member;
	num_of_member_in_team = num_of_member / 2;
	for(int i = 0; i < num_of_member; i++){
		for(int j = 0; j < num_of_member; j++){
			cin >> ability[i][j];
		}
	}
	Make_team();
	cout << min_differ_of_ability << "\n";
}

void Make_team()
{
	pair_idx = 0;
	Set_first_team_and_fill_second_team(0);
}

void Set_first_team_and_fill_second_team(int member_to_insert)
{
	if(first_team_member_idx == num_of_member_in_team){
		Fill_second_team();
		first_team_member_idx--;
		total_member[first_team_member[first_team_member_idx]] = 0; 
		return;
	}
	for(int firstmember_in_firstteam = member_to_insert; firstmember_in_firstteam < num_of_member; firstmember_in_firstteam++){
		first_team_member[first_team_member_idx++] = firstmember_in_firstteam;
		total_member[firstmember_in_firstteam] = 1;
		Set_first_team_and_fill_second_team(firstmember_in_firstteam + 1);
	}
	first_team_member_idx--;
	total_member[first_team_member[first_team_member_idx]] = 0; 
}

void Fill_second_team()
{
	for(int member = 0; member < num_of_member; member++){
		if(Isremain_member(member) == true){
			second_team_member[second_team_member_idx++] = member;
		}
	}
	Get_team_ability_and_cal_diff_of_ability();
	second_team_member_idx = 0;
	memset(second_team_member, num_of_member_in_team, 0);
}

void Get_team_ability_and_cal_diff_of_ability()
{
	Get_Each_team_ability(0);
	pair_idx = 0;
	Calculate_diff_of_ability();
}

void Get_Each_team_ability(int member_to_pair)
{
	if(pair_idx == 2){
		first_team_ability += ability[pair_in_first_team[0]][pair_in_first_team[1]];
		first_team_ability += ability[pair_in_first_team[1]][pair_in_first_team[0]];
		second_team_ability += ability[pair_in_second_team[0]][pair_in_second_team[1]];
		second_team_ability += ability[pair_in_second_team[1]][pair_in_second_team[0]];
		pair_idx--;
		return;
	}
	for(int member = member_to_pair; member < num_of_member_in_team; member++){
		pair_in_first_team[pair_idx] = first_team_member[member];
		pair_in_second_team[pair_idx] = second_team_member[member];
		pair_idx++;
		Get_Each_team_ability(member + 1);
		
	}
	pair_idx--;
}

bool Isremain_member(int member)
{
	if(total_member[member] == 0){
		return true;
	}
	return false;
}

void Calculate_diff_of_ability()
{
	int differ_of_ability = max(first_team_ability, second_team_ability) - min(first_team_ability,second_team_ability);
	if(min_differ_of_ability > differ_of_ability)
		min_differ_of_ability = differ_of_ability;
	first_team_ability = 0;
	second_team_ability = 0;
}
