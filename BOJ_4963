
#include <stdio.h>

typedef struct MAP{
	int x;
	int y;
	int val;
	int visit;
	int dir[8];
}Map;

Map queue[3000] = { 0 };
int head=0, tail=0, quenum = 0; //tail:넣을곳 //head : 꺼낼곳
void insert(int x, int y)
{
	quenum++;
	queue[tail].x = x;
	queue[tail].y = y;
	tail++;
	if(tail == 2999)
		tail = 0;
}

void delete()
{
	quenum--;
	head++;
	if(head == 2999)
		head = 0;
}

int landcnt = 0,w,h;

void find(Map map[][50], int x, int y)
{
	if(x - 1 >= 0 && map[x - 1][y].visit == 0 && map[x - 1][y].val == 1){
		map[x-1][y].visit = 1; //위
		insert(x-1,y);
	}
	if(y + 1 < w && map[x][y + 1].visit == 0 && map[x][y + 1].val == 1){
		map[x][y+1].visit = 1;
		insert(x,y+1);
	}
	if(x + 1 < h && map[x + 1][y].visit == 0 && map[x + 1][y].val == 1){
		map[x+1][y].visit = 1;
		insert(x+1,y);
	}
	if(y - 1 >= 0 && map[x][y - 1].visit == 0 && map[x][y - 1].val == 1){
		map[x][y-1].visit = 1;//왼
		insert(x,y-1);
	}
	if(x - 1 >= 0 && y + 1 < w && map[x - 1][y + 1].visit == 0 && map[x - 1][y + 1].val == 1){
		map[x-1][y+1].visit = 1;//오위
		insert(x-1,y+1);
	}
	if(x + 1 < h && y + 1 < w && map[x + 1][y + 1].visit == 0 && map[x + 1][y + 1].val == 1){
		map[x+1][y+1].visit = 1;
		insert(x+1,y+1);
	}
	if(x + 1 < h && y -1 >= 0 && map[x + 1][y - 1].visit == 0 && map[x + 1][y - 1].val == 1){
		map[x+1][y-1].visit = 1;
		insert(x+1,y-1);
	}
	if(x - 1 >= 0 && y -1 >= 0 && map[x - 1][y - 1].visit == 0 && map[x - 1][y - 1].val == 1){
		map[x-1][y-1].visit = 1;
		insert(x-1,y-1);
	}
}

void BFS(Map map[][50], int x, int y)
{
	int curx=x,cury=y;
	while(1){
		find(map, curx, cury); //insert
		map[curx][cury].visit = 1;
		if(head != tail){ // 큐에 노드가 존재하면 꺼내면서 현재노드로 설정
			curx = queue[head].x;
			cury = queue[head].y;
			delete();
		//	printf("큐에서 뺌\n");
		}
		else //큐 비었음
			break;
	}
	landcnt++;
}



int main()
{
	while(1){
		Map m[50][50] = { 0 };
		scanf(" %d %d", &w, &h);
		if(w == 0 && h == 0)
			break;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				scanf(" %d", &m[i][j].val);
			}
		}
	
		/*for(int i =0;i<h;i++){
			for(int j=0;j<w;j++){
				printf("%d ", m[i][j].val);
			}
			printf("\n");
		}*/
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(m[i][j].visit == 0 && m[i][j].val == 1){
					//printf("여기에서 탐색 시작 x:%d y:%d\n", i,j);
					BFS(m, i, j);
				}
			}
		}
       // printf("\n");
		printf("%d\n",landcnt);
		landcnt = 0;
		head=0,tail=0;
	}
}
