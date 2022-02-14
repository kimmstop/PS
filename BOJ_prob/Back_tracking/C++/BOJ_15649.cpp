//*
#include <iostream>
#include <stack>

using namespace std;

int N, M;
int visit[9];
int arr[8];

void DFS(int cnt);

int main()
{
    cin >> N >> M; 
    DFS(0);
}

void DFS(int cnt)
{
    if(cnt == M){
        for(int i = 0; i < cnt; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;

    }
    for(int i = 1; i <= N; i++){
        if(visit[i] == 0){
            arr[cnt] = i;
            visit[i] = 1;
            DFS(cnt + 1);
            visit[i] = 0;
        }
    }
}

