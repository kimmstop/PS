#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class node{
	public:
		int num;
		int prior;
		node* next;
		node* prev;
};

class circle_queue{
	public:
		node* head;
		node* tail;
		node* curnode;
		int nodenum;
};


void insert_node(circle_queue* cirq, int num, int prior);
void delete_node(circle_queue * cirq);
void printq(circle_queue* cirq);
void move_node(circle_queue* cirq, int maxprior);



int T, N, M;


int main()
{
	cin >> T;
	int priority, reqnum;

	for(int i = 0; i < T; i++){
		cin >> N >> M;
		priority_queue<int> pq;
		int ans = 1;
		circle_queue *cirq = new circle_queue();
		for(int i = 0; i < N; i++){
			cin >> priority;
			pq.push(priority);
			insert_node(cirq, i, priority);
		}
		int maxprior = pq.top();
		for(int i = 0; i < N; i++){
			move_node(cirq, maxprior);
			if(cirq -> curnode -> num == M){
				cout << ans << endl;
				ans = 1;
				break;
			}
			delete_node(cirq);
			ans++;
			pq.pop();
			maxprior = pq.top();
		}
	}

}



void insert_node(circle_queue* cirq, int num, int priority)
{
	node* newnode = new node();
	newnode -> num = num;
	newnode -> prior = priority;
	if(cirq -> nodenum == 0){
		cirq -> head = cirq -> tail = newnode;
		cirq -> tail -> next = cirq -> head;
		cirq -> head -> prev = cirq -> tail;
		cirq -> curnode = cirq -> head;
	}
	else{
		cirq -> tail -> next = newnode;
		newnode -> prev = cirq -> tail;
		cirq -> tail = newnode;
		cirq -> tail -> next = cirq -> head;
		cirq -> head -> prev = cirq -> tail;
	}
	cirq -> nodenum += 1;
}

void delete_node(circle_queue* cirq)
{
	node* tmpnode = cirq -> curnode;
	tmpnode -> prev -> next = tmpnode -> next;
	tmpnode -> next -> prev = tmpnode -> prev;
	cirq -> curnode = cirq -> curnode -> next;
	if(tmpnode == cirq -> head){
		cirq -> head = cirq -> curnode;
	}
	if(tmpnode == cirq -> tail){
		cirq -> tail = cirq -> tail -> prev;
	}
	delete(tmpnode);
}



void move_node(circle_queue* cirq, int maxprior)
{
	while(cirq -> curnode -> prior != maxprior){
		cirq -> curnode = cirq -> curnode -> next;
	}
}


void printq(circle_queue* cirq) /*디버깅 용*/
{
	node* curnode = cirq -> curnode;
	int totnum = cirq -> nodenum;
	for(int i = 0; i < totnum; i++){
		if(i == totnum -1)
			break;
		curnode = curnode -> next;
	}
}


/* 앞서 풀었던 요세푸스 문제와 거의 똑같이 풀었다. 구현도 매우 비슷하다.
 * class를 사용해보는 연습을 하려고 private, public을 처음에 나눠 봤지만
 * 너무 코드가 난해해 져서 다 public으로 풀었다.....*/
