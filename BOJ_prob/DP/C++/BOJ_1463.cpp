#include <stdio.h>

int cnt = 0;
int arr[1000000]= { 0 };

int main()
{
	int num;
	scanf("%d", &num);
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for(int i = 4 ; i <= 1000000; i++){
		int temp = i;
		if(i > num)
			break;
		if(temp % 3 == 0){
				arr[temp] = arr[temp/3] + 1;
		}
		if(temp % 2 == 0){
			if(arr[temp] == 0)
				arr[temp] = arr[temp/2] + 1;
			else if(arr[temp] > arr[temp/2] + 1)
				arr[temp] = arr[temp/2] + 1;
		}
		if(arr[temp] == 0)
			arr[temp] = arr[temp - 1] + 1;
		if(arr[temp] > arr[temp - 1] + 1)
			arr[temp] = arr[temp - 1] + 1;
	
	}
	printf("%d", arr[num]);
}
