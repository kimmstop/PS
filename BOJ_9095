#include <stdio.h>

int arr[1000] = { 0 };

int main()
{
	int T;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for(int i = 4; i < 11; i++)
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	scanf(" %d", &T);
	for(int i = 0; i < T; i++){
		int num;
		scanf(" %d", &num);
		printf("%d\n",arr[num]);
	}
}
