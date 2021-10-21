#include <iostream>
int N, K;
using namespace std;

class node{
	public:
		int num;
		node* next;
		node* prev;
};

class queue{
	public:
		node* head;
		node* tail;
		node* curnode;
		int nodenum = 0;
};

queue* cirq = new queue();
int ans[5000], idx = 0;


void insnode(int num);
int delnode();
void movenode(int num);
void printq();



int main()
{
	cin >> N >> K;
	for(int i =1; i <= N; i++){
		insnode(i);
	}
	int delnum = K -1;
	for(int i = 0; i < N; i++){
		movenode(delnum);	
		ans[idx++] = delnode();
	}
	cout << "<";
	for(int i = 0; i< N; i++){
		if(i == N-1)
			cout << ans[i] << ">";
		else
			cout << ans[i] << ", ";
	}
}

void insnode(int num)
{
	node* newnode = new node();
	newnode -> num = num;
	if(cirq -> nodenum == 0){
		cirq -> curnode = newnode;
		cirq ->	head = cirq -> tail = newnode;
		cirq -> curnode -> next = cirq -> curnode;
		cirq -> curnode -> prev = cirq -> curnode;
		cirq -> tail -> next = cirq -> head;
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

int delnode()
{
	if(cirq -> nodenum == 1){
		int ret = cirq -> curnode -> num;
		delete(cirq -> curnode);
		return  ret;
	}
	node* tmpnode = new node();
	tmpnode = cirq -> curnode;
	int ret = tmpnode -> num;
	tmpnode -> prev -> next = tmpnode -> next;
	tmpnode -> next -> prev = tmpnode -> prev;
	cirq -> curnode = cirq -> curnode -> next;
	cirq -> nodenum -= 1;
	if(tmpnode == cirq -> head)
		cirq -> head = cirq -> head -> next;
	if(tmpnode == cirq -> tail)
		cirq -> tail = cirq -> tail -> prev;
	delete(tmpnode);
	return ret;
}

void printq()
{
	node* tmpnode = cirq -> head;
	int num = cirq -> nodenum;
	for(int i = 0; i < num; i++){
		cout << tmpnode -> num;
		if(i == num -1)
			break;
		tmpnode = tmpnode -> next;
	}

}

void movenode(int num)
{
	for(int i=0;i<num;i++){
		cirq -> curnode = cirq -> curnode ->  next;
	}
}

/*아무리 생각해도 이 원형 더블 연결리스트 말고는 생각이 나지 않았다. 
 *배열로 바로 접근 하고 싶었지만 결국 탐색시간이 상당히 소요되어야 한다.
 */
