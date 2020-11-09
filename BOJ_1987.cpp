#include <iostream>
#include <stack>
using namespace std;


int R, C;
int visit[30]={0},  map[20][20]={0};
int maxans = 0;
stack<int> s;

void DFS(int x, int y, int* ans);
int alptoidx(int x, int y);
int gridtoline(int x, int y);



int main()
{
	cin >> R >> C;
	char alpab;
	for(int i = 0; i < R; i++){
		for(int j = 0 ; j < C ; j++){
			alpab = getchar();
			if(alpab == '\n'){
				j--;
				continue;
			}
			map[i][j] = (int)alpab; /* 정수형으로 바꿔서 저장 */
		}
	}
	int ans = 1, *ansp = &ans;
	maxans = ans;
	s.push(gridtoline(0, 0));
	DFS(0, 0, ansp);
	cout << maxans << endl;
}

/* 알파벳을 숫자로 바꾸어(A->1, B->2) visit배열의 index로 사용하기 위함 */
int alptoidx(int x, int y)
{
	return map[x][y] - 65;
}

/*2차원 x, y 좌표를 1차원으로 변환 */
int gridtoline(int x, int y)
{
	return x * C + y;
}

void DFS(int x, int y, int* ans)
{
	if(*ans == 26)
		return;
	visit[alptoidx(x,y)] = 1;
	int dx[4] = {0, -1, 0 , 1}, dy[4]= {1, 0, -1, 0}; /* map에서 다음 x, y를 조사하기 위해 필요한 방향 값 */
	int newx, newy, popx, popy;
	while(!s.empty()){
		for(int i = 0; i < 4; i++){
			newx = x + dx[i], newy = y + dy[i];
			if(newx >= 0 && newx <= R-1 && newy >= 0 && newy <= C-1 && visit[alptoidx(newx,newy)] == 0){
				s.push(gridtoline(newx, newy));
				*ans += 1;
				if(maxans < *ans)
					maxans = *ans;
				if(maxans == 26)
					return;
				DFS(newx, newy, ans);
				popx = s.top() / C, popy = s.top() % C;
				visit[alptoidx(popx, popy)] = 0; /* pop된 알파벳은 방문했던 check를 해제 */
				s.pop();
				*ans -= 1;
			}
		}
		return;
	}
}


