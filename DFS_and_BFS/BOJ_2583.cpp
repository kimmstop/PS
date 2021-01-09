#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>


using namespace std;




void BFS(int x, int y, int*  pareasize);

queue<int> q;
priority_queue < int, vector<int>, greater<int>  > pq;
int M, N, K;
int map[100][100], visit[10000];

int main()
{
	cin >> M >> N >> K;
	for(int i=0;i<M;i++)
		fill(map[i],map[i]+N, 0);
	fill(visit, visit+M*N, 0);
	int x1,y1,x2,y2;
	for(int i=0;i<K;i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j = y1; j < y2; j++){
			for(int k = x1; k < x2; k++){
				map[j][k] = 1;
			}
		}
	}
	int area = 0, areasize=0;
	int * pareasize = &areasize;
	for(int i =0;i<M;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]==0 && visit[i * N + j] == 0){
				BFS(i, j, pareasize);
				area++;
				pq.push(*pareasize);
				*pareasize = 0;
			}
		}
	}
	cout << area << endl;
	for(int i =0; i<area; i++){
		cout << pq.top()<< " ";
		pq.pop();
	}
}


void BFS(int x, int y, int* pareasize)
{
	q.push(x * N + y);
	*pareasize += 1;
	visit[x *N + y] =1;
	int dx[4] = { 0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
	int newv, newx, newy;
	while(!q.empty()){
		for(int i =0;i < 4; i++){
			newx = x +dx[i], newy = y + dy[i];
			if(newx >=0 && newx <= M -1 && newy >=0 && newy <= N-1 && map[newx][newy] == 0 && visit[newx * N + newy] == 0){
				q.push(newx *N + newy);
				*pareasize += 1;
				visit[newx *N + newy] =1;
			}
		}
		q.pop();
		newv = q.front();
		x = newv / N;
		y = newv % N;
	}

}
