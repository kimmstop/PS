#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[1001][1001] = {0};
int N, M, startv;
int top=0, stack[1000] = {0}, visit[1001]= {0}; 
int head=0,tail=0, queue[1001] = {0}; 

void push(int v1)
{
	stack[top++] = v1;
	if(top == 1000)
        	printf("stack over\n");
}

void pop()
{
	top--;
	if(top == -1)
		printf("stack error");
	exit(0);
}

void DFS(int v)
{
	push(v);
	printf("%d ", v);
	visit[v] = 1;
	for(int i = 1 ; i <= N; i++){
		if(map[v][i] == 1 && visit[i] == 0){ 
			DFS(i);
		}
	}
}

void insert(int v)
{
	queue[tail++] = v;	
	if(tail == 1001)
		tail = 0;
}

int delete()
{
	int ret = queue[head];
	head++;
	if(head == 1001)
		head = 0;
	return ret;
}

void BFS(int v)
{
	
	printf("%d ", v);
	visit[v] = 1;
	for(int i = 1; i <= N; i++){
		if(map[v][i] == 1 && visit[i] == 0){
			insert(i);
			visit[i] = 1;
		}
	}
	if(head == tail){
		exit(0);
	}
	int nextv = delete();
	
	BFS(nextv);
}


int main()
{
	int v1, v2;
	
	scanf("%d %d %d", &N, &M, &startv);
	for(int i = 0; i < M; i++){
		scanf(" %d %d",&v1, &v2);
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	
	}
	DFS(startv);
	memset(visit,0,4004);
	printf("\n");
	BFS(startv);
}
