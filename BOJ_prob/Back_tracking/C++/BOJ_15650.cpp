#include <iostream>


using namespace std;

int N, M;
int arr[8];
int visit[9];

void DFS(int cnt, int idx);

int main()
{
    cin >> N >> M;
    DFS(0, 1);
}

void DFS(int cnt, int idx)
{
    if(cnt == M){
        for(int i = 0; i < cnt; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    for(int i = idx; i <= N; i++){
        if(visit[i] == 0){
            arr[cnt] = i;
            visit[i] = 1;
            DFS(cnt + 1, i + 1);
            visit[i] = 0;
        }
    }
}