#include <stdio.h>
 

int N, K, head=0,tail=0,queue[100001] = { 0 }, visit[100001] = { 0 };

void insert(int loc);
int delete();
void select(int loc);


int main()
{
	int newloc=0, mid = 0, ans=0;
	scanf("%d %d", &N, &K);
	insert(N);
	visit[N] = 1;
	mid = tail;
	while(1){
		newloc = delete();
		if(newloc == K)
			break;
		select(newloc);
		if(head == mid){
			ans++;
			mid = tail;
		}
		if(newloc == -1){
			//printf("no val in queue\n");
		}
	}
	printf("%d", ans);
}


void insert(int loc)
{
	queue[tail++] = loc;
}

int delete()
{
	if(head == tail)
		return -1;
	int ret = queue[head++];
	
	return ret;
}

void select(int loc)
{
	int walk1, walk2, teleport;
	walk1 = loc - 1;
	walk2 = loc + 1;
	teleport = 2 * loc;
	if(walk1 >= 0 && visit[walk1] == 0){
		insert(walk1);
		visit[walk1] = 1;
	}
	if(walk2 <= 100000 && visit[walk2] == 0){
		insert(walk2);
		visit[walk2] = 1;
	}
	if(teleport <= 100000 && visit[teleport] == 0){
		insert(teleport);
		visit[teleport] = 1;
	}
}
