#include <stdio.h>

int queue[10000] = { 0 };
int visit[500] = { 0 };
int tail = 0, head = 0;

void insert(int index)
{
	queue[tail++] = index;
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

int BFS(int Map[][500], int n)
{
	int start_idx = 0;
	int numof1f = 0, numof2f = 0;
	
		for(int i = start_idx; i < n; i++){
			if(Map[start_idx][i] == 1 && i != start_idx){
				insert(i);
				numof1f++;
				visit[i] = 1;
			}
		}
		visit[0] = 1;
		for(int i = numof1f; i > 0; i--){
			start_idx = delete();
			for(int j = 0; j < n; j++){
				if(Map[start_idx][j] == 1 && visit[j] != 1 && j != start_idx){
					numof2f++;
                   visit[j] = 1;
				}
			}
		}
	return numof1f + numof2f;
}

int main()
{
	int n,m;
	int Map[500][500] = { 0 };
	scanf(" %d\n%d", &n, &m);
	int f1,f2;
	for(int i = 0; i < m; i++){
		scanf(" %d %d", &f1, &f2);
		Map[f1-1][f2-1] = 1;
		Map[f2-1][f1-1] = 1;
		Map[f1-1][f1-1] = 1;
		Map[f2-1][f2-1] = 1;
	}	
	
	printf("%d\n",BFS(Map, n));

}
