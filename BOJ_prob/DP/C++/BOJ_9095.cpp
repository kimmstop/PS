#include <iostream>

using namespace std;

int main()
{
    int testcase_num;
    cin >> testcase_num;
    while(testcase_num){
        testcase_num--;
        int num = 0;
        cin >> num;
        int arr[11] = {0, 1, 2, 4, 7, 13, };
        for(int i = 6; i < 11; i++){
            arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
        }
        printf("%d\n", arr[num]);
    }
}
