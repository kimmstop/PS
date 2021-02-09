#include <iostream>
#include <vector>
#include <list>

using namespace std;


vector <int> set_of_root_node;
vector <int> adj_node[50];


int num_of_nodes, num_of_leaf_nodes;
int parent_node_num, deleted_node_num;

void Count_leaf_node(int root_node_num);
void Delete_node(int root_node_num);
bool Is_delete_node_is_root(int idx);
void Set_root_node_invalid(int idx);
bool Root_node_is_not_invalid(int idx);

int main()
{
	cin >> num_of_nodes;
	for(int i = 0; i < num_of_nodes; i++){
		cin >> parent_node_num;
		if(parent_node_num == -1){
			set_of_root_node.push_back(i);
		}
		else{
			adj_node[parent_node_num].push_back(i);
		}
	}
	
	cin >> deleted_node_num;
	
	for(int i = 0; i < set_of_root_node.size(); i++){
		if(Is_delete_node_is_root(i))
			Set_root_node_invalid(i);
	}
	
	
	
	int root_node_num;
	for(int i = 0; i < set_of_root_node.size(); i++){
		if(Root_node_is_not_invalid(i)){
			root_node_num = set_of_root_node[i];
			Delete_node(root_node_num);
			Count_leaf_node(root_node_num);
		}
	}
	
	cout << num_of_leaf_nodes << endl;
}


bool Is_delete_node_is_root(int idx)
{
	if(set_of_root_node[idx] == deleted_node_num)
		return true;
	return false;
}

void Set_root_node_invalid(int idx)
{
	set_of_root_node[idx] = -2;
}


bool Root_node_is_not_invalid(int idx)
{
	if(set_of_root_node[idx] != -2)
		return true;
	return false;
}

void Delete_node(int root_node_num)
{
	vector<int>::iterator iter = adj_node[root_node_num].begin();
	for(; iter != adj_node[root_node_num].end(); iter++){
		if(*iter == deleted_node_num){
			adj_node[root_node_num].erase(iter);
			return;	
		}
		Delete_node(*iter);
	}
}


void Count_leaf_node(int root_node_num)
{
	if(adj_node[root_node_num].size() == 0){
		num_of_leaf_nodes++;
	}
	for(int i = 0; i < adj_node[root_node_num].size(); i++){
		Count_leaf_node(adj_node[root_node_num][i]);
	}
}



/*2021-01-13
Refactoring
문제에서 만들어 질 수 있는 트리의 개수, 부모노드가 가질 수 있는
자식노드의 최대 개수 등의 조건이 세부적으로 명시되지 않았다. 
즉 여러개의 트리가 만들어 질 수도 있고, 부모노드가 엄청 많은 자식노드를 가질 
수도 있다. 
문제에서는 노드의 번호 순서대로 그 노드의 부모 노드의 번호가 주어진다.
직접 node클래스를 만들어서 문제에서 주어지는데로 트리를 만들 수도 있지만
이렇게 할 경우 노드를 추가할 때마다 해당하는 부모노드를 탐색해야 한다. 
그래서 vector 배열을 만들어 인접리스트 형식으로 트리를 나타내었다.
adj_node[부모노드의 번호]배열에 해당하는 자식 노드 번호를 하나씩 추가하는 방식이다.
문제는 root 노드라는 정보가 -1 로 주어진다는 것이다. adj_node[-1]이 될 수는 없으므로
root노드만 저장하고 있는 vector set_of_root_node를 별도로 두어서 나중에 탐색의 출발 노드로
사용했다. 
노드의 삭제 : 삭제는 3가지로 나눌 수 있다. 리프 노드의 삭제, 중간 노드의 삭제, root 노드의 삭제
root 노드의 삭제 같은 경우 먼저 set_of_root_node vector에 삭제해야할 노드 번호가 있는지 확인하고
있다면 그 값을 -2로 바꿔준다. 탐색을 할 필요 없다는 일종의 표시이다.
리프노드와 중간노드의 삭제는 똑같다. 삭제해야 할 노드를 포함하고 있는 부모노드 vector에서 삭제해야 할 노드를
삭제하면 된다. 이 부분에서 DFS탐색 방법을 사용했다.*/

