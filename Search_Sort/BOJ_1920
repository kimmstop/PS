#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;



int N, M;

int main()
{
	scanf("%d ", &N);
	int arr[N];
	for(int i = 0; i < N; i++){
		scanf(" %d ", &arr[i]);
	}
	sort(arr, arr + N);
	scanf(" %d", &M);
	int find;
	for(int i = 0; i < M; i++){
		scanf(" %d", &find);
		if(!binary_search(arr, arr + N, find)){
			puts("0");
		}
		else
			puts("1");
	}
}
