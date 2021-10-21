#include <iostream>
#include <algorithm>

using namespace std;


int N;

int main()
{
	cin >> N;
	int cnt[2001] = { 0 }, num;
	for(int i = 0; i < N; i++){
		cin >> num;
		if(num < 0){ // -1 > idx 2002 -1000 -> 1001
			num = num + 2001;
			cnt[num]++;
		}
		else{
			cnt[num]++;
		}
	}
	for(int i = 1001; i < 2001; i++){
		if(cnt[i] > 0)
			cout << i - 2001 << " ";
	}
	for(int i =0;i <= 1000; i++){
		if(cnt[i] > 0)
			cout << i << " ";
	}
}
