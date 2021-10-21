#include <iostream>
#include <algorithm>

using namespace std;

int firstnum, secondnum;

int Get_gcd();
bool Is_cd(int devider);
int Get_lcm();
bool Is_cm(int multipler);

int main()
{
	cin >> firstnum >> secondnum;
	int gcd = Get_gcd();
	int lcm = Get_lcm();
	cout << gcd << "\n" << lcm;
}

int Get_gcd()
{
	int smallernum_of_input = min(firstnum, secondnum);
	int gcd;
	for(int devider = 1; devider <= smallernum_of_input; devider++){
		if(Is_cd(devider) == true)
			gcd = devider;
	}
	return gcd;
}

bool Is_cd(int devider)
{
	if(firstnum % devider == 0 && secondnum % devider == 0)
		return true;
	return false;
}


int Get_lcm()
{
	int greaternum_of_input = max(firstnum, secondnum);
	int mult_of_input = firstnum * secondnum;
	int lcm;
	for(int multipler = greaternum_of_input; multipler < mult_of_input; multipler +=greaternum_of_input){
		if(Is_cm(multipler) == true){
			lcm = multipler;
			break;
		}
	}
	return lcm;
}

bool Is_cm(int multipler)
{
	if(multipler % firstnum == 0 && multipler % secondnum == 0){
		return true;
	}
	return false;
}

/* 이제 함수를 작게, 한 가지 기능만 하도록 하는게 왜 편한지
조금 느낄 수 있게되었다. 변수이름이 무조건 길수록 좋은게 아니라
의미를 모두 포함한다면 짧은게 좋다...*/