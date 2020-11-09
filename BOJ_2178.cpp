#include <stdio.h>
#include <stdlib.h>
int N, M, head=0,tail=0, cnt=1; 
int visit[10000] = { 0 };
char map[10000] ={ '0' };
int ans[10000] = { 0 };
int queue[10000] = { 0 };

void insert(int loc)
{
	queue[tail++] = loc;
	if(tail == 9999)
		tail = 0;
}

int delete()
{
	int ret = queue[head++];
	if(head == 9999)
		head = 0;
	return ret;
}


void find(char map[], int index)
{
	if(index - M >= 0 && map[index-M] == '1' && visit[index-M] == 0){
		insert(index - M);
		ans[index-M] = cnt+1;
	}
	if((index % M) + 1 < M && map[index+1] == '1' && visit[index+1] == 0){ //right
		insert(index+1);
		ans[index+1] = cnt+1;
	}
	if((index % M) > 0 && map[index-1] == '1' && visit[index-1] == 0){
		insert(index-1);
		ans[index-1] = cnt+1;
	}
	if(index + M < N*M && map[index+M] == '1' && visit[index+M] == 0){ //down
		insert(index+M);
		ans[index+M] = cnt+1;
	}
	
}

void BFS(char map[])
{
	int index= 0, tmp=0;
	while(1){
		if(visit[index] == 0){
			find(map, index);
			visit[index] = 1;
		//	printf("현재 위치: %d, cnt :%d\n", index, cnt);
			if(index == N*M -1)
				break;
		}
		index = delete();
		cnt = ans[index];
	}
}



int main()
{
	scanf(" %d %d ", &N,&M);
	for(int i = 0; i < N * M; i++){
		map[i] = getchar();
		if(map[i]=='\n')
			i--;
	}
	BFS(map);
	printf("%d", ans[N*M-1]);
}
