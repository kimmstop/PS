#include <iostream>
#include <cmath>


using namespace std;

int numofinput;
int num_of_prime_in_input;

void Isprime(double numtocheck_isprime);
bool Isremain_zero(double numtocheck_isprime, int devider);
bool Is_numtocheck_is_one(double numtocheck_isprime);
void Increase_num_of_prime_in_input();

int main()
{
	cin >> numofinput;
	double numtocheck_isprime;
	for(int i =0; i < numofinput; i++){
		cin >> numtocheck_isprime;
		if(Is_numtocheck_is_one(numtocheck_isprime) == true)
			continue;
		Isprime(numtocheck_isprime);
	}
	
	cout << num_of_prime_in_input;
}

void Isprime(double numtocheck_isprime)
{
	int root_of_numtocheck = static_cast<int>(sqrt(numtocheck_isprime));
	bool flag_to_check_num_isprime = true;
	for(int devider = 2; devider <= root_of_numtocheck; devider++){
		if(Isremain_zero(numtocheck_isprime, devider) == true){
			flag_to_check_num_isprime = false;
		}
	}
	if(flag_to_check_num_isprime == true){
		cout << numtocheck_isprime;
		Increase_num_of_prime_in_input();
	}
}

bool Isremain_zero(double numtocheck_isprime, int devider)
{
	if(static_cast<int>(numtocheck_isprime) % devider == 0){
		return true;
	}
	return false;
}

void Increase_num_of_prime_in_input()
{
	num_of_prime_in_input++;
}

bool Is_numtocheck_is_one(double numtocheck_isprime)
{
	if(static_cast<int>(numtocheck_isprime == 1))
		return true;
	return false;
}

/* 
2부터 인풋으로 주어진 수의 제곱근 까지를 일일이 나누어 보아서 소수인지 판별

오늘 부터 Clean Code를 읽기시작했다. 코드를 나만 알아보도록 빨리 짜는 것은 의미가
없다. 이 책을 읽으면서 알게된 내용을 최대한 녹여서 코딩을 하자.
책 읽는 시간이 추가되어서 예전만큼 백준을 풀지는 못할...
함수는 한 가지 기능을 해야하고 그것먼을 잘해야 한다. 
-> 최대한 작은 함수를 만들어 함수가 한 가지 기능만을 하도록 만들었다.
변수의 이름은 변수의 용도, 의미, 목적에 맞게 지어야한다.
-> 아직 함수와 변수, 지역변수와 전역변수를 구분하는 나만의 방법을 
정립하지 못해서 코드를 짜는 동안 변수 이름으로 헷갈렸다. 
전역과 지역을 구분할때, 전역은 앞에 "g_"를 붙였다.*/

/*2020-12-14
 * 변수 앞에 변수의자료형니나 특서을 붙이는 헝가리식 표기법은 좋지 않다
 * -> 전역변수, 인자로 넘겨주는 변수에 헝가리식 표기법을 제거 했다.
 *  sed -i 's/변경해야하는내용/변경할 내용/g' file 
 *  */
