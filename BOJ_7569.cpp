#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, H; // 가로, 세로, 높이
int numofyet=0, numofcomp=0, numofempty=0, ans=0;
int map[1000000] = { 0 };
queue<int> q;

int loctoline(int x, int y, int z);
void linetoloc(int loc, int* x, int* y, int* z);

void BFS(int startv, int* datcntp);
void affect(int v);


int main()
{
	cin >> M  >> N >> H;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				cin >> map[(i * M * N) + (j * M) + k];
				if( map[(i * M * N) + (j * M) + k] == 1){
					numofcomp++;
					q.push(loctoline(j, k, i));
				}
				if( map[(i * M * N) + (j * M) + k] == 0)
					numofyet++;
			}
		}
	}
	int daycnt =q.size(), startv = q.front(); /* daycnt는 실제로 날짜(답의 수)가 올라가는 지점을 결정하기 위함이다 */
	int *daycntp = &daycnt;  
	BFS(startv, daycntp);
	if(numofyet > 0){
		cout << -1 << endl;
	}
	else
		cout << ans-1 << endl;
}


int loctoline(int x, int y, int z) /* 3차원의 x,y,z 좌표를 1차원 좌표로 변환 */
{
	return (z * M * N) + (x * M) + y;
}

void affect(int v)
{
	int curx, cury, curz;
	int temp = v;
	curz = temp / (M*N);
	temp %=(M*N);
	curx = temp / M;
	cury = temp % M;	
	int dx[4] = { 0 , 1, 0, -1}, dy[4] = {1, 0, -1, 0}, dz[4] = {-1, 1};
	int newx, newy, newz;
	for(int i = 0; i < 4; i++){ /* 같은 층 내에서 동,서,남,북 을 탐색 */
		newx = curx + dx[i], newy = cury + dy[i];
		if(newx >=0 && newx<=N-1 && newy >=0 && newy <= M-1 && map[loctoline(newx,newy,curz)] == 0){
			q.push(loctoline(newx, newy, curz));
			numofyet--;
			map[loctoline(newx,newy, curz)] = 1;
		}
	}
	for(int i = 0; i< 2; i++){ /* 현재 위치에서 위, 아래 층을 탐색 */
		newz = curz + dz[i];
		if(newz >= 0 && newz <= H-1 && map[loctoline(curx, cury, newz)] == 0){
			q.push(loctoline(curx, cury, newz));
			numofyet--;
			map[loctoline(curx, cury, newz)] = 1;		
		}
	}
}


void BFS(int startv, int* daycntp)
{
	int popv;
	while(!q.empty()){
		for(int i = 0; i < *daycntp; i++){ /* 하루동안 익어가는 토마토를 설정 */
			popv = q.front();
			q.pop();
			affect(popv);
		}	
		ans++;
		*daycntp = q.size();
	}
}


