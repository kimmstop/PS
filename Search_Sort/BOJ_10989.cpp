#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main()
{
	scanf("%d", &N);
	int cnt[10000] = {0}, num = 0;
	for(int i = 0; i < N; i++){
		scanf(" %d", &num);
		cnt[num]++;
	}
	for(int i = 0;i < 10000; i++){
		for(int j = 0; j < cnt[i]; j++){
			printf("%d\n", i);
		}
	}
}
