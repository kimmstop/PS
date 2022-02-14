#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int testcase, board_len, init_r, init_c, dest_r, dest_c;
int visit[300][300];
queue<pair<pair<int, int>, int>> q;

int BFS();
bool inRange(int next_r, int next_c);
bool isDest(int next_r, int next_c);


int main()
{
    cin >> testcase;
    while(testcase--){
        cin >> board_len;
        cin >> init_r >> init_c;
        cin >> dest_r >> dest_c;
        q.push(make_pair(make_pair(init_r, init_c), 0));
        visit[init_r][init_c] = 1;
        int ans = BFS();
        printf("%d\n", ans);
        while(!q.empty()){
            q.pop();
        }
        for(int i = 0; i < board_len; i++){
            memset(visit[i], 0, 4 * board_len);
        }
    }

}

int BFS()
{
    int dir_r[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dir_c[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    while(!q.empty()){
        int cur_r = q.front().first.first;
        int cur_c = q.front().first.second;
        int cur_cnt = q.front().second;
        if(isDest(cur_r, cur_c)){
            return cur_cnt;
        }
        q.pop();
        for(int i = 0; i < 8; i++){
            int next_r = cur_r + dir_r[i];
            int next_c = cur_c + dir_c[i];
            if(inRange(next_r, next_c) && visit[next_r][next_c] == 0){
                visit[next_r][next_c] = 1;
                q.push(make_pair(make_pair(next_r, next_c), cur_cnt + 1));
            }
        }
    }
    
}

bool inRange(int next_r, int next_c)
{
    if(0 <= next_r && next_r < board_len && 0 <= next_c && next_c < board_len){
        return true;
    }
    return false;
}

bool isDest(int next_r, int next_c)
{
    if(next_r == dest_r && next_c == dest_c){
        return true;
    }
    return false;
}