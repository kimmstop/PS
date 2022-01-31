#include <iostream>
#include <vector>


using namespace std;

vector<char> tree[26];

void preOrder(char cur_node);
void inOrder(char cur_node);
void postOrder(char cur_node);

int main()
{
    int node_num;
    cin >> node_num;
    for(int i = 0; i < node_num; i++){
        char parent, lc, rc;
        cin >> parent >> lc >> rc;
        tree[parent - 'A'].push_back(lc);
        tree[parent - 'A'].push_back(rc);
    }
    preOrder('A');
    printf("\n");
    inOrder('A');
    printf("\n");
    postOrder('A');
}

void preOrder(char cur_node)
{
    printf("%c", cur_node);
    if(tree[cur_node - 'A'][0] != '.')
        preOrder(tree[cur_node - 'A'][0]);
    if(tree[cur_node - 'A'][1] != '.')
        preOrder(tree[cur_node - 'A'][1]);
}

void inOrder(char cur_node)
{
    if(tree[cur_node - 'A'][0] != '.')
        inOrder(tree[cur_node - 'A'][0]);
    printf("%c", cur_node);
    if(tree[cur_node - 'A'][1] != '.')
        inOrder(tree[cur_node - 'A'][1]);
}

void postOrder(char cur_node)
{
    if(tree[cur_node - 'A'][0] != '.')
        postOrder(tree[cur_node - 'A'][0]);
    if(tree[cur_node - 'A'][1] != '.')
        postOrder(tree[cur_node - 'A'][1]);
    printf("%c", cur_node);
}