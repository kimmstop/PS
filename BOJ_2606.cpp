#include <stdio.h>

int numofv, numofe, map[101][101] = { 0 };
int queue[100000] = { 0 }, visit[101]= { 0 }, head = 0, tail = 0;


void insert(int v);
int delete();
void affect(int v);


int main()
{
	scanf("%d", &numofv);
	scanf(" %d", &numofe);
	int v1, v2;
	for(int i = 0; i< numofe; i++){
		scanf(" %d %d", &v1, &v2);
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}
	insert(1);
	visit[1] = 1;
	int newv, ans=0;
	while(1){
		newv = delete();
		if(newv == -1)
			break;
		else if(newv != 1){
			ans++;
		}
		affect(newv);
	}
	printf("%d", ans);
}


void insert(int v)
{
	queue[tail++] = v;
}

int delete()
{
	if(head == tail)
		return -1;
	int ret = queue[head++];
	return ret;
}

void affect(int v)
{
	for(int i = 1; i <= numofv; i++){
		if(map[v][i] == 1 && visit[i] == 0){
			insert(i);
			visit[i] = 1;
		}
	}
}



