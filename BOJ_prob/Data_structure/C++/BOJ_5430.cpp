#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

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
		int nodenum=0;
};




int T, rflag = 0;

void add_node(queue* q, int c);
void del_node(queue* q);
void reverse(queue* q);
void printq(queue* q);

int main()
{
	scanf("%d ", &T);
	for(int i =0; i< T; i++){
		rflag = 0;
		queue* q = new queue();
		char reqarr[100001];
		int reqlen = 0;
		for(int j = 0; j < 100001; j++){
			reqarr[j] = getchar();
			if(reqarr[j] == '\n'){
				reqlen = j;
				break;
			}
		}
		int num, errflag=0, intflag = 0, idx = 0, val=0;
		char c[3], tc;
		scanf(" %d ", &num);
		while(1){
			tc = getchar();
			if(tc == '[')
				continue;   
			if( tc == ',' || tc == ']'){
				if(idx == 3){
					val = (c[0] - '0') * 100;
				    val += (c[1] - '0') * 10;
					val += (c[2] - '0');
					add_node(q, val);	
				}
				else if(idx ==2){
					val = (c[0] - '0') * 10;
					val += (c[1] - '0');
					add_node(q, val);
				}
				else if(idx ==1){
					val = (c[0] - '0');
					add_node(q, val);
				}
				else
					continue;
				intflag = 0;
				idx = 0;
			}
			else if(tc == '\n'){
				break;
			}
			else{
				intflag++;
				if(intflag  > 0)
					c[idx++] = tc;
			}
		}
		for(int k =0; k < reqlen; k++){
			if(reqarr[k] == 'R'){
				rflag++;
				reverse(q);
			}
			else{
				if(q -> nodenum ==0){
					errflag = 1;
					break;
				}
				del_node(q);
			}
		}
		if(errflag == 1){
			printf("error\n");
			continue;
		}
		printq(q);
	}
}



void add_node(queue* q, int c)
{
	node* newnode = new node();
	newnode -> num = c;
	if(q -> nodenum ==0){
		q -> head = newnode;
		q -> tail = newnode;
		newnode -> next = NULL;
	   	newnode -> prev = NULL;
	}
	else{
		q -> tail -> next = newnode;
		newnode -> prev = q -> tail;
		q -> tail = newnode;
	}	
	q -> nodenum++;
}

void del_node(queue* q)
{
	if(q -> nodenum == 1){
		q -> nodenum--;
		return;
	}
	node* tmpnode = q -> head;
	if(rflag % 2 == 0){
		q -> head -> next -> prev = NULL;
		q -> head = q -> head -> next;
	}
	else{
		q -> head -> prev -> next = NULL;
		q -> head = q -> head -> prev;
	}
	q -> nodenum--;
	delete(tmpnode);
}

void reverse(queue* q)
{
	node* tmpnode = q -> head;
	q -> head = q -> tail;
	q -> tail = tmpnode;
}

void printq(queue* q)
{	printf("[");
	node* curnode = q-> head;
	for(int i=0; i < q -> nodenum; i++){
		if(i == q -> nodenum -1){
			printf("%d", curnode -> num);
		}
		else{
			printf("%d,", curnode -> num);
		}
		if( i == q ->nodenum -1){
			break;
		}
		if(rflag % 2 ==0)
			curnode = curnode -> next;
		else
			curnode = curnode -> prev;
	}
	printf("]\n");
}


/*입력으로 빈 배열을 받고 난 다음의 테스트 케이스가 잘 작동되지 않았다.
 * ->getchar가 엔터까지 받아왔기 때문이다. 개행입력을 따로 처리해 주어서 해결
 *빈 배열에 R을 하는 것은 에러가 아니다. 
 * -> 문제를 잘 읽자.
 *  노드를 방문할 때 무조건 next로 방문하면 안된다.
 *  ->rflag를 두어 뒤집어짐의 여부를 판단
 *  입력받는 정수의 범위가 100까지 이다. 단정적으로 getchar로 받으면 안된다.
 *  -> 자릿수를 counting하여 처리했다.*/
