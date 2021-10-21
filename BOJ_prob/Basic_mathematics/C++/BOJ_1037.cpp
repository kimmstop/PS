#include <iostream>
#include <algorithm>


using namespace std;

int N;

int main()
{
	cin >> N;
	int arr[N];
	for(int i = 0 ; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr+ N);
	cout << arr[0] * arr[N-1] << endl;
}
