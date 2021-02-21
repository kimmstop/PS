#include <iostream>
#include <queue>


using namespace std;

int num_of_sameperiod, list_len;
int num_of_friends, num_of_friends_of_friends;
int relation[501][501], visit[501];
queue <int> q;


void Init_relation();
void Cal_num_of_friends();
void Cal_num_of_friends_of_friends();
bool Not_visit(int friend_class);
bool Is_friend(int start_class, int friend_class);
	
int main()
{
	cin >> num_of_sameperiod >> list_len;
	
	Init_relation();
	
	q.push(1);
	visit[1] = 1;
	
	Cal_num_of_friends();
	Cal_num_of_friends_of_friends();
	
	cout << num_of_friends + num_of_friends_of_friends;
}

void Init_relation()
{
	int f1, f2;
	for(int i = 0; i < list_len; i++){
		cin >> f1 >> f2;
		relation[f1][f2] = 1;
		relation[f2][f1] = 1;	
	}
}

void Cal_num_of_friends()
{
	for(int i = 2; i <= 500; i++){
		if(Not_visit(i) && Is_friend(1, i)){
			q.push(i);
			visit[i] = 1;
			num_of_friends++;
		}
	}	
}

void Cal_num_of_friends_of_friends()
{
	int first_friend = q.front();
	for(int i = 2; i <= 500; i++){
		if(Not_visit(i) && Is_friend(first_friend, i)){
			visit[i] = 1;
			num_of_friends_of_friends++;
		}
	}
	
	q.pop();
	
	if(q.empty())
		return;
	
	Cal_num_of_friends_of_friends();
}

bool Not_visit(int friend_class)
{
	if(visit[friend_class] == 0)
		return true;
	return false;
}

bool Is_friend(int start_class, int friend_class)
{
	if(relation[start_class][friend_class] == 1)
		return true;
	return false;
	
}


/*2021-02-05
Refactoring
친구와 친구의 친구를 구하는 방법이 비슷하지만 둘의 함수를 분리했다. 
같이 했다면 친구의 친구를 구하고 종료되는 조건을 설정했었어야 했다.
변수의 이름을 짓는 과정에서 "학번, 동기" 의 변수이름을 짓는 것이 힘들었다.
*/
