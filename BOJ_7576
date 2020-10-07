#include <stdio.h>

int M,N, map[1000][1000], numofempty = 0, numofyet = 0, numofnewtom = 0; // 가로 세로
int head=0, tail=0, mid = 0,queue[1000000] = { 0 }, visit[1000000] = { 0 };

int tmp=0;

void affect(int x, int y);
void insert(int index);
int delete();


int main()
{
	int ans=0;
 	scanf("%d %d", &M, &N);
	for(int i =0;i < N; i++){
		for(int j=0; j< M; j++){
			scanf(" %d", &map[i][j]);
			if(map[i][j] == -1)
				numofempty++;
			if(map[i][j] == 0)
				numofyet++;
			if(map[i][j] == 1){
				insert(i * M + j);
				visit[i * M + j] = 1;
				numofnewtom++;
				mid = tail;
			}
		}
	}
	int new, flag=0;
	while(numofyet!=0){
		new = delete();
		if(flag >0)
		 numofyet--;
	//	printf("@%d@ %d %d\n", numofyet, tail, head);
		affect(new / M , new % M);
		if(head == mid){
			if(head == tail){
				ans--;
			}
			ans++;
			tmp++;
			mid = tail;
			flag=1;
		}
		if(flag > 0 && head == tail){
			
			break;
		}
	}
	if(numofyet != 0){
		printf("-1");
	}
	else
		printf("%d", ans);
}

void affect(int x, int y)
{
	//위 오 아 왼
	//printf("%d  %d %d     %d\n", tmp,  x, y, queue[tail-1]);
	if(x -1 >= 0 && map[x-1][y]==0&& visit[(x-1) * M + y] == 0){
		map[x-1][y] = 1;
		insert((x-1)*M + y);
		visit[(x-1) * M + y] = 1;
	}
	if(y + 1 <= M -1 && map[x][y+1] == 0 && visit[x * M +y +1] == 0){
		map[x][y+1] = 1;
		insert(x * M +y +1);
		visit[x * M +y +1] = 1;
	}
	if(x + 1 <= N -1 && map[x+1][y] == 0 && visit[(x+1) * M +y] == 0){
		map[x+1][y] = 1;
		insert((x+1) * M +y);
		visit[(x+1) * M +y] = 1;
	}
	if(y - 1 >= 0 && map[x][y-1] == 0 && visit[x * M +y - 1] == 0){
		map[x][y-1] = 1;
		insert(x * M +y - 1);
		visit[x * M +y - 1] = 1;
	}
}



void insert(int index)
{
	//printf("%d %d\n", index / M, index % M);
	queue[tail++] = index;
}

int delete()
{
	if(head == tail)
		return -1;
	int ret = queue[head++];
	return ret;
}
