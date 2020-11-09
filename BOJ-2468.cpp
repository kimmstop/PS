#include <stdio.h>
#include <string.h>


int N, map[100][100]={0};
int queue[10000] = {0}, visit[10000]={0}, head=0,tail=0;

void insert(int v);
int delete();
void BFS(int startv, int height);


int main()
{
	int min=1000, max=0;
	scanf("%d", &N);
	for(int i =0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf(" %d", &map[i][j]);
			if(map[i][j] > max)
				max = map[i][j];
			if(map[i][j] < min)
				min = map[i][j];
		}
	}
	int maxans=0,ans=0;
	for(int i = 0; i<=max; i++){
		for(int j =0;j<N;j++){
			for(int k=0;k<N;k++){
				if(map[j][k] > i && visit[j*N+k]==0){
					visit[j*N+k] = 1;
					BFS(j*N+k, i);
					ans++;
					head=0, tail=0;
				}
			}
		}
		memset(visit,0,40000);
		memset(queue,0,40000);
		//printf("@@%d  %d\n", ans, i);
		if(maxans < ans)
		maxans = ans;
		ans=0;
	}
	printf("%d", maxans);
}


void insert(int v)
{
	queue[tail++] = v;
}

int delete()
{
	if(head == tail)
		return -1;
	return queue[head++];
}	

void BFS(int startv, int height)
{
	visit[startv] =1;
	int x = startv / N, y = startv % N;
	int dx[4] = {-1, 0, 1, 0}; //위 오 아 왼
	int dy[4] = { 0, 1, 0, -1};
	int newx, newy;
	
	for(int i = 0; i< 4;i++){
		newx = x+dx[i], newy = y +dy[i];
		if(newx <= N-1 && newx >= 0 && newy  >=0 &&newy <=N-1 &&
			 map[newx][newy] > height && visit[newx * N +newy] == 0){
			insert(newx * N + newy);
			visit[newx * N + newy] = 1;
		}
	}
	
	int newv = delete();
	if(newv == -1)
		return;
	BFS(newv, height);
}
	
	
	
	
	
	


