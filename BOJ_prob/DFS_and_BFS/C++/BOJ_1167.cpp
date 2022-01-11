#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

struct Node
{
    int num;
    int dist;
};

int vertex_num;
int longest_dist;
int longest_vertex;
bool visit[100001];
vector <Node> tree[100001];

bool isvisit(int num)
{
    if(visit[num] == true) return true;
    else return false;
}

void dfs(int num, int cur_dist)
{
    visit[num] = true;
    for(int i = 0; i < tree[num].size(); i++){
        if(!isvisit(tree[num][i].num)){
            dfs(tree[num][i].num, cur_dist + tree[num][i].dist);
        }
    }
    if(cur_dist > longest_dist){
        longest_dist = cur_dist;
        longest_vertex = num;
    }
}

void init_visit()
{
    for(int i = 1; i <= vertex_num; i++){
        visit[i] = false;
    }
}

int main()
{
    cin >> vertex_num;
    for(int i = 0; i < vertex_num; i++){
        int v1, v2;
        cin >> v1;
        while(1){
            cin >> v2;
            if(v2 == -1) break;
            int dist = 0;
            cin >> dist;
            tree[v1].push_back({v2, dist});
            tree[v2].push_back({v1, dist});
        }
    }
    /*
    for(int i = 1; i < vertex_num; i++){
        for(int j = 0; j < tree[i].size(); j++){
            printf("%d :", i);
            printf("| %d, %d |", tree[i][j].num, tree[i][j].dist);
        }
    }
    */
    for(int i = 1; i <= vertex_num; i++){
        if(visit[i] == 0){
            dfs(i, 0);
            init_visit();
            dfs(longest_vertex, 0);
        }
    }
    printf("%d", longest_dist);
}