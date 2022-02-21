//*
#include <iostream>

using namespace std;

int N;
int num_arr[11], op_arr[4];
int max_result = -987654321, min_result = 987654321;

void backTrack(int cnt, int result);
void updateResult(int result);
int calResult(int op, int cnt, int result);

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num_arr[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op_arr[i];
    }
    backTrack(1, num_arr[0]);
    cout << max_result << endl << min_result;
}

void backTrack(int cnt, int result)
{
    if(cnt == N){
        updateResult(result);
        return;
    }
    for(int j = 0; j < 4; j++){
        if(op_arr[j] > 0){
            op_arr[j]--;
            backTrack(cnt + 1, calResult(j, cnt, result));
            op_arr[j]++;
        }
    }
}

void updateResult(int result)
{
    if(result > max_result){
        max_result = result;
    }
    if(result < min_result){
        min_result = result;
    }
}

int calResult(int op, int cnt, int result)
{
    if(op == 0){
        return result + num_arr[cnt];
    }
    else if(op == 1){
        return result - num_arr[cnt];
    }
    else if(op == 2){
        return result * num_arr[cnt];
    }
    else{
        return result / num_arr[cnt];
    }
}