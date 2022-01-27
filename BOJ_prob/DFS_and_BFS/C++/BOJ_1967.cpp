#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int node_num;
vector<pair<int, int>> adj_list[10001];
int max_node, max_weight;
int visit[10001];
void DFS(int start_node, int weight);


int main()
{
    cin >> node_num;
    
    for(int i = 0; i < node_num - 1; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj_list[v1].push_back(make_pair(v2, w));
        adj_list[v2].push_back(make_pair(v1, w));
    }

    for(int i = 1; i <= node_num; i++){
        if(visit[i] == 0){
            DFS(i, 0);
            memset(visit, 0, sizeof(int) * 10001);
            DFS(max_node, 0);
        }
    }
    printf("%d", max_weight);
}

void DFS(int start_node, int weight)
{
     if(max_weight < weight){
        max_node = start_node;
        max_weight = weight;
    }
    visit[start_node] = 1;
    for(int i = 0; i < adj_list[start_node].size(); i++){
        if(visit[adj_list[start_node][i].first] == 0){
            DFS(adj_list[start_node][i].first, weight + adj_list[start_node][i].second);
        }
    }
   
}