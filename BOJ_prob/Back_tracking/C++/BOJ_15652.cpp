#include <iostream>

using namespace std;

int N, M;
int arr[8];

void backTrack(int start_idx, int cnt);

int main()
{
    cin >> N >> M;
    backTrack(1, 0);
}

void backTrack(int start_idx, int cnt)
{
    if(cnt == M){
        for(int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = start_idx; i <= N; i++){
        arr[cnt] = i;
        backTrack(i, cnt + 1);
    }
}