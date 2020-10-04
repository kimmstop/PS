#include <stdio.h>
#include <stdlib.h>

int N, top=0, stack[1000]={ 0 }, visit[1000]={ 0 };
int sorted_arr[1000] = { 0 }, ans_num = 0;

char map[26][26];

int find(int index);
void push(int index);
void pop();
void DFS(int startidx, int* num_of_apt);

void add_arr(int ans);

int compare(const void* a, const void* b);

int main()
{
	int apt_num = 0, group_num = 0;
	int * apt_num_p;
	apt_num_p = &apt_num;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			map[i][j] = getchar();
			if(map[i][j] == '\n')
				j--;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j] == '1' && visit[i * N + j] == 0){
				DFS(i*N+j, apt_num_p);
				group_num++;
				add_arr(*apt_num_p);
				*apt_num_p = 0;
			}
		}
	}
	printf("%d\n", group_num);
	qsort(sorted_arr, ans_num, 4, compare);
	for(int i=0;i<ans_num;i++)
		printf("%d\n", sorted_arr[i]);
}



void push(int index)
{
	stack[top++] = index;
}

void pop()
{
	top--;
}

void DFS(int startidx, int* num_of_apt)
{
	push(startidx);
	(*num_of_apt)++;
	visit[startidx] = 1;
	int i = startidx / N, j = startidx % N;
	//위 오 아 왼
	if(i - 1 >= 0 && map[i - 1][j] == '1' && visit[(i - 1) * N + j] == 0)
		DFS((i - 1) * N + j, num_of_apt);
	if(j + 1 <= N - 1 && map[i][j + 1] == '1' && visit[i * N + j + 1] == 0)
		DFS(i * N + j + 1, num_of_apt);
	if(i + 1 <= N - 1 && map[i + 1][j] == '1' && visit[(i + 1) * N + j] == 0)
		DFS((i + 1) * N + j, num_of_apt);
	if(j - 1 >= 0 && map[i][j - 1] == '1' && visit[i * N + j - 1] == 0)
		DFS(i * N + j - 1, num_of_apt);
}

void add_arr(int ans)
{
	sorted_arr[ans_num++] = ans;
}


int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if(num1 < num2)
		return -1;
	if(num1 == num2)
		return 0;
	return 1;
}

