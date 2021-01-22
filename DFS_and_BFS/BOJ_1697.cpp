#include <iostream>
#include <queue>

using namespace std;

int subin_pos, brother_pos;
int time_to_catch;
int pos[100001], visit[100001];

queue <int> q;


void Find_min_time_to_catch();
void Set_next_subin_pos(int next_subin_pos[], int cur_subin_pos);
bool Subin_catch_brother(int next_subin_pos[]);
bool Next_subin_pos_not_visited(int next_subin_pos[], int idx);
bool Next_subin_pos_in_range(int next_subin_pos[], int idx);

int main()
{
	cin >> subin_pos >> brother_pos;
	pos[brother_pos] = 1;
	
	q.push(subin_pos);
	visit[subin_pos] = 1;
	
	if(subin_pos == brother_pos){
		cout << time_to_catch;
		return 0;
	}
	
	Find_min_time_to_catch();
	
	cout << time_to_catch;
}


void Find_min_time_to_catch()
{	
	int next_subin_pos[3];
	int cur_subin_pos, size_of_queue = q.size();
	
	time_to_catch++;
	
	for(int i = 0; i < size_of_queue; i++){
		cur_subin_pos = q.front();
		Set_next_subin_pos(next_subin_pos, cur_subin_pos);
		
		if(Subin_catch_brother(next_subin_pos)){
			return;
		}
		
		for(int j = 0; j < 3; j++){
			if(Next_subin_pos_in_range(next_subin_pos, j) && Next_subin_pos_not_visited(next_subin_pos, j)){	
				visit[next_subin_pos[j]] = 1;
				q.push(next_subin_pos[j]);
			}
		}
		q.pop();
	}
	
	if(q.empty())
		return;
		
	Find_min_time_to_catch();
}

void Set_next_subin_pos(int next_subin_pos[], int cur_subin_pos)
{
	next_subin_pos[0] = cur_subin_pos - 1;
	next_subin_pos[1] = cur_subin_pos + 1;
	next_subin_pos[2] = cur_subin_pos * 2;
}

bool Subin_catch_brother(int next_subin_pos[])
{
	for(int i = 0; i < 3; i++){
		if(next_subin_pos[i] == brother_pos)
			return true;
	}
	return false;
}

bool Next_subin_pos_not_visited(int next_subin_pos[], int idx)
{
	if(visit[next_subin_pos[idx]] == 0)
		return true;
	return false;
}

bool Next_subin_pos_in_range(int next_subin_pos[], int idx)
{
	if(next_subin_pos[idx] <= 100000 && next_subin_pos[idx] >= 0)
		return true;
	return false;
}


/*2020-01-22
Refactoring
백트랙킹 문제인지 BFS문제인지 아직 문제만 읽고 파악이 잘 되지 않는다.
이 문제도 재귀호출 시마다 수빈의 위치와 동생의 위치를 비교하여 promising한지 안한지 검사한다는
면에서는 백트랙킹 문제 같기도 하지만 큐를 사용하여 현재 수빈의 위치에서 이동가능한 위치를 차례로 큐에 넣으면서
탐색하는 BFS로도 볼 수 있다. 
탐색방법을 잘 설정해야 문제에서 요구하는 "시간"이라는 것을 간단하게 계산 할 수 있다. 
재귀함수가 현재 수빈의 위치에서 이동가능한 경우 3가지를 모두 탐색 한 뒤 알맞은 값을 큐에 넣고
호출 되어야한다. 예를 들어 수빈의 위치가 5로 주어졌을때 처음의 top level 호출에서 4, 6, 8의 값을 큐에 넣고 
재귀함수를 호출한 뒤에는 3, (5), (8), (5), 7, 12, (7), 9, 16의 값을 큐에 넣고 호출해야한다. 단순히 
3, (5), (8)만 넣고 호출해서는 안된다. 이렇게 해야 재귀함수 호출 1번이 시간값을 1 증가시키는 효과가 있다. 
따라서 가장 바깥 반복문의 흐름을 현재 큐의 개수로 두었고 현재수빈의 위치에서 이동가능한 위치를 탐색했다면
pop해주었다. 
문제에서 위치 정보가 0부터 100000까지 이다. 인덱스를 그대로 사용하기 위해서는 배열의 크기를 100001로 두어야한다. 

처음에 수빈의 위치가 동생의 위치가 같을 경우가 있다. 
*/