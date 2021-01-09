#include <stdio.h>

typedef struct NODE{
	int parent;
	int numofchild;
}Node;

int head=0,tail=0,queue[1000] ={ 0 };

void insert(int val)
{
	queue[tail++] = val;
	if(tail == 999)
		tail = 0;
}

int N;

int delete(int delnode)
{
	
	if(head == 999)
		head = 0;
	if(head == tail)
		return delnode;
	int ret = queue[head++];
	return ret;
}


void Nodedel(Node orgarr[], int delnode)
{
	
	for(int i = 0; i  < N; i++){
		if(orgarr[i].parent == delnode){
			insert(i);
		}
	}
	int tmp= delete(delnode);
	if(delnode == tmp){
		orgarr[delnode].numofchild = -1;
		return;
	}
	else{
		Nodedel(orgarr, tmp);
	}
	//printf("delnode : %d\n", delnode);
	orgarr[delnode].numofchild = -1;
}


int main()
{
	int totalchild=0, delnode;
	scanf(" %d ", &N);
	Node orgarr[50];
	for(int i=0;i<N;i++)
		orgarr[i].numofchild = 0;
	for(int i=0;i<N;i++){
		scanf(" %d", &orgarr[i].parent);
		if(orgarr[i].parent != -1){
			orgarr[orgarr[i].parent].numofchild++;
		}
	}
	scanf(" %d", &delnode);
	Nodedel(orgarr, delnode);

	for(int i=0;i<N;i++){
		if(orgarr[i].numofchild==0){
			totalchild++;
		}
	}
	if(orgarr[orgarr[delnode].parent].numofchild == 1)
		totalchild++;
	printf("%d\n", totalchild);
}
