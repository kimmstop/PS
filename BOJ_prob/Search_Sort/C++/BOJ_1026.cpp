#include <iostream>
#include <algorithm>
//#include <funtional>


using namespace std;

int N;
int Arr[50], Brr[50];


bool compare1(int a, int b)
{
	return a > b;
}

bool compare2(int a, int b)
{
	return a < b;
}


int main()
{
	int num=0;
	cin >> N;
	for(int i =0;i<N;i++){
		cin >> Arr[i];
	}
	for(int i =0;i<N;i++){
		cin >> Brr[i];
	}
	sort(Arr, Arr+N, compare2);
	sort(Brr, Brr+N, compare1);
	for(int i =0;i<N;i++){
		num += Arr[i] * Brr[i];
	}
	cout << num;
}
