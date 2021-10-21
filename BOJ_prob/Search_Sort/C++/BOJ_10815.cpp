#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main()
{
	scanf("%d", &N);
	int card[N], req[N];
	for(int i = 0; i < N; i++){
		scanf(" %d", &card[i]);
	}
	sort(card, card + N);
	scanf(" %d", &M);
	for(int i = 0; i < M; i++){
		scanf(" %d", &req[i]);
	}
	for(int i = 0; i < M; i++){
		if(!binary_search(card, card+N, req[i])){
			printf("0\n");
		}
		else
			printf("1\n");
	}
}
