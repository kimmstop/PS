#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj_list[20001];
int visit[20001] = {0};

bool visited(int v)
{
    if(visit[v] != 0){
        return true;
    }
    return false;
}

bool bfs(int start_v)
{
    queue <int> q;
    visit[start_v] = 1;
    q.push(start_v);
    while(!q.empty()){
        int cur_v = q.front();
        int cur_state = visit[cur_v];
        q.pop();
        for(int i = 0; i < adj_list[cur_v].size(); i++){
            int next_v = adj_list[cur_v][i];
            if(!visited(next_v)){
               q.push(next_v);
               visit[next_v] = -1 * cur_state;
              // printf("%d:%d\n", next_v, visit[next_v]);
            }
            else if(visit[next_v] == cur_state){
                return false;
            }
        }
    }
    return true;
}

void print_ans(bool isbipartite)
{
    if(isbipartite) printf("YES\n");
    else printf("NO\n");
}

void clean_data(int vertex_num)
{
    for(int i = 0; i <= vertex_num; i++){
        visit[i] = 0;
        adj_list[i].clear();
    }
}

int main()
{
    int testcase_num;
    cin >> testcase_num;
    while(testcase_num != 0){
        testcase_num--;
        bool isbipartite = true;
        int vertex_num, edge_num;
        cin >> vertex_num >> edge_num;
        for(int i = 0; i < edge_num; i++){
            int v1, v2;
            cin >> v1 >> v2;
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }
        for(int i = 1; i <= vertex_num; i++){
            if(!visited(i)){
                isbipartite = bfs(i);
                if(isbipartite == false) break;
            }
        }
        print_ans(isbipartite);
        clean_data(vertex_num);
    }
}