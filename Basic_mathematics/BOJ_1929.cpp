#include <iostream>
#include <cmath>

using namespace std;


int min_val_of_search, max_val_of_search;

bool Isprime_or_Isone(int num_to_check_prime_or_one);
bool Isprime(int num_to_check_prime);
bool Isone(int num_to_check_one);

int main()
{
	cin >> min_val_of_search >> max_val_of_search;
	for(int num_to_check_prime_or_one = min_val_of_search; num_to_check_prime_or_one < max_val_of_search;
	    num_to_check_prime_or_one++){
		if(Isprime_or_Isone(num_to_check_prime_or_one) == true)
			cout << num_to_check_prime_or_one << endl;
	}
}

bool Isprime_or_Isone(int num_to_check_prime_or_one)
{
	if(Isone(num_to_check_prime_or_one) == true)
		return false;
	else{
		if(Isprime(num_to_check_prime_or_one) ==  true){
			return true;
		}
		else{
			return false;
		}
			
	}	
}
	
bool Isone(int num_to_check_one)
{
	if(num_to_check_one == 1)
		return true;
	return false;
}
	
bool Isprime(int num_to_check_prime)
{
	int root_of_num_to_check_prime = static_cast<int>(sqrt(num_to_check_prime));
	bool prime_flag = true;
	for(int devider = 2; devider <= root_of_num_to_check_prime; devider++){
		if(num_to_check_prime % devider == 0){
			prime_flag = false;
			return false;
		}
	}
	return prime_flag;
}
	

/* 변수의 이름을 결정하는데 예전보다 시간이 오래 걸렸다. 
그래도 나중에 다시 볼 때 이 변수가 어떤 의미를 갖고, 어디에 쓰이는지 쉽게 알 수 있었고
디버깅도 쉬웠다. 각 함수가 한 가지의 기능만 하도록 만들었다. 25번째, 28번째 line의 함수를
호출 할 때 인자로 넘겨주는 변수의 이름이 num_to_check_prime_or_one 인게 약간 아쉬웠지만
만약 이렇게 하지 않고 따로 나눈다면 동일한 값을 가지는 이름만 다른 2개의 변수가 만들어니다.
더 고민해보자. */
	