#include <stdio.h>
#include <string.h>


int T, M, N, K, map[50][50] = { 0 }; // 가로 세로 배추 위치 개수 == 배추개수
int visit[2500] = { 0 }, queue[2500] = { 0 }, head = 0, tail = 0;


void insert(int v);
int delete();
void affect(int v);

int main()
{
	int x, y, ans = 0;
	scanf("%d", &T);
	while(T > 0){
		scanf(" %d %d %d", &M, &N, &K);
		
		for(int i = 0; i < K; i++){
			scanf(" %d %d", &x, &y);
			map[y][x] = 1;
		}
	
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(map[i][j] == 1 && visit[i * M + j] == 0){
					insert(i * M + j);
					visit[i * M + j] = 1;
					affect(i * M + j);
					ans++;
					//printf("ans:%d\n", ans);
				}
			}
		}
		printf("%d\n", ans);
		ans = 0;
    for(int i= 0; i< N; i++){
      memset(map[i],0,4 * 50);
    }
		memset(visit,0,4*2500);
    memset(queue,0,4*2500);
		head =0;
		tail=0;
		T--;
	}
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
	int garo = v % M, sero = v / M;
	
	//위 오 아 왼
	if(sero - 1 >= 0 && map[sero - 1][garo] == 1 && visit[v - M] == 0){
		insert(v - M);
		visit[v - M] = 1;
	}
	if(garo + 1 <= M- 1 && map[sero][garo + 1] == 1 && visit[v+1] == 0){
		insert(v +1);
		visit[v +1] = 1;
	}
	if(sero + 1 <= N-1 && map[sero + 1][garo] == 1 && visit[v + M] == 0){
		insert(v + M);
		visit[v + M] = 1;
	}
	if(garo - 1 >= 0 && map[sero][garo - 1] == 1 && visit[v - 1] == 0){
		insert(v - 1);
		visit[v - 1] = 1;
	}
	int newv = delete();
	if(newv == -1){
		return;
	}
	affect(newv);
	
}


