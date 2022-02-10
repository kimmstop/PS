//*
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int r, c;
int map[1000][1000];
bool visit[1000][1000][2];
int dist[1000][1000];
queue<pair<pair<int, int>, pair<int, bool>>> q;


void BFS();
bool inRange(int next_r, int next_c);
void updateDist(int next_r, int next_c, int new_dist);
void updateMinDist(int cur_dist);


int main()
{
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int c;
            scanf("%1d", &c);
            map[i][j] = c;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            dist[i][j] = 987654321;
        }
    }
    BFS();

    if(dist[r - 1][c - 1] == 987654321){
        printf("-1");
    }
    else{
        printf("%d", dist[r - 1][c - 1]);
    }
}

void BFS()
{
    visit[0][0][0] = true;
    visit[0][0][1] = true;
    dist[0][0] = 1;
    q.push(make_pair(make_pair(0, 0), make_pair(1, false)));
    while(!q.empty()){
        int cur_r = q.front().first.first;
        int cur_c = q.front().first.second;
        int cur_dist = q.front().second.first;
        //printf("#%d\n", cur_dist);
        bool isdestwall = q.front().second.second;
        q.pop();
        int dir_r[4] = {0, 1, 0, -1};
        int dir_c[4] = {1, 0, -1, 0};
        for(int i = 0; i < 4; i++){
            int next_r = cur_r + dir_r[i];
            int next_c = cur_c + dir_c[i];
            if(inRange(next_r, next_c)){
                if(isdestwall){
                    if(visit[next_r][next_c][1] == false && map[next_r][next_c] == 0){
                        q.push(make_pair(make_pair(next_r, next_c), make_pair(cur_dist + 1, true)));
                        visit[next_r][next_c][1] = true;
                        updateDist(next_r, next_c, cur_dist + 1);
                        
                    }
                }
                else{
                    if(visit[next_r][next_c][0] == false && map[next_r][next_c] == 0){
                        q.push(make_pair(make_pair(next_r, next_c), make_pair(cur_dist + 1, false)));
                        visit[next_r][next_c][0] = true;
                        updateDist(next_r, next_c, cur_dist + 1);
                        
                    }
                    else if(visit[next_r][next_c][1] == false && map[next_r][next_c] == 1){
                        q.push(make_pair(make_pair(next_r, next_c), make_pair(cur_dist + 1, true)));
                        visit[next_r][next_c][1] = true;
                        updateDist(next_r, next_c, cur_dist + 1);
                        //printf("%d %d\n", next_r, next_c);
                    }
                }
            }
        }
    }
}

bool inRange(int next_r, int next_c)
{
    if(0 <= next_r && next_r < r && 0 <= next_c && next_c < c){
        return true;
    }
    return false;
}

void updateDist(int next_r, int next_c, int new_dist)
{
    if(dist[next_r][next_c] > new_dist){
        dist[next_r][next_c] = new_dist;
    }
}

