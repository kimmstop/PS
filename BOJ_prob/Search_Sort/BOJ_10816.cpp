#include <iostream>
#include <algorithm>

using namespace std;

int N, M;



int cnt[20000003] = { 0 };

int main()
{
	cin >> N;
	int num;
	for(int i =0;i < N; i++){ // 0 -> 0 10,000,000 -> 10,000,000  -10000000 -> 10000001
		cin >> num;
		if(num < 0){
			cnt[num + 20000001]++;
		}
		else{
			cnt[num]++;
		}
	}
	cin >> M;
	int req[M];
	for(int i =0; i < M; i++){
		cin >> num;
		req[i] = num;
	}
	for(int i = 0; i < M; i++){
		if(req[i] < 0){
			if(cnt[req[i] + 20000001] >= 1){
				cout << cnt[req[i] + 20000001] << " ";
			}
			else{
				cout << "0 ";
			}
		}	
		else{
			if(cnt[req[i]] >= 1){
				cout << cnt[req[i]] << " ";
			}
			else{
				cout << "0 ";
			}
		}
	}

}
