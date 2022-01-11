//*
#include <iostream>
#include <vector>

using namespace std;

int row, col;
int arr[101][101];
long long max_result;
int getsum(int lr, int lc, int rr, int rc)
{
    int sum = 0;
    for(int i = lr; i <= rr; i++){
        for(int j = lc; j <= rc; j++){
            sum += arr[i][j];
        }
    }
    return sum;
}


int main()
{
    int num;
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%1d", &arr[i][j]);
           // rect[i].push_back(num);
        }
    }
//1
    for(int i = 0; i < row - 2; i++){
        for(int j = i + 1; j < row - 1; j++){
            long long first_rect = getsum(0, 0, i, col - 1);
            long long second_rect = getsum(i + 1, 0, j, col - 1);
            long long third_rect = getsum(j + 1, 0, row - 1, col - 1);
            max_result = max(max_result, first_rect * second_rect * third_rect);
        }
    }
//2
    for(int i = 0; i < col - 2; i++){
        for(int j = i + 1; j < col - 1; j++){
            long long first_rect = getsum(0, 0, row - 1, i);
            long long second_rect = getsum(0, i + 1, row - 1, j);
            long long third_rect = getsum(0, j + 1, row - 1, col - 1);
            max_result = max(max_result, first_rect * second_rect * third_rect);
        }
    }
//5
    for(int i = 0; i < row - 1; i++){
        for(int j = 0; j < col - 1; j++){
            long long first_rect = getsum(0, 0, i, col - 1);
            long long second_rect = getsum(i + 1, 0, row - 1, j);
            long long third_rect = getsum(i + 1, j + 1, row - 1, col - 1);
            max_result = max(max_result, first_rect * second_rect * third_rect);
        }
    }
    //4
    for(int i = 0; i < col - 1; i++){
        for(int j = 0; j < row - 1; j++){
            long long first_rect = getsum(0, 0, row - 1, i);
            long long second_rect = getsum(0, i + 1, j, col - 1);
            long long third_rect = getsum(j + 1, i + 1, row - 1, col - 1);
            max_result = max(max_result, first_rect * second_rect * third_rect);
        }
    }
//
    for(int i = row - 1; i > 0; i--){
        for(int j = 0; j < col - 1; j++){
            long long first_rect = getsum(i, 0, row - 1, col - 1);
            long long second_rect = getsum(0, 0, i - 1, j);
            long long third_rect = getsum(0, j + 1, i - 1, col - 1);
            max_result = max(max_result, first_rect * second_rect * third_rect);
        }
    }
//3
    for(int i = col - 1; i > 0; i--){
        for(int j = 0; j < row - 1; j++){
            long long first_rect = getsum(0, i, row - 1, col - 1);
            long long second_rect = getsum(0, 0,  j, i - 1);
            long long third_rect = getsum(j + 1, 0, row - 1, i - 1);
            max_result = max(max_result, first_rect * second_rect * third_rect);
        }
    }
    cout << max_result << endl;
}