#include <iostream>
#include <vector>

using namespace std;

int N, S, ans;
int set[20];
vector<int> subset;

void check_sum(int* sum, int idx);




int main()
{
	cin >> N >> S;
	for(int i = 0; i< N; i++){
		cin >> set[i];
	}
	int sum = 0;
	int* sump = &sum;
	for(int i = 0; i< N; i++){
		subset.push_back(set[i]);
		*sump = set[i];
		check_sum(sump, i);
		*sump = 0;
	}
	cout << ans << endl;
}


void check_sum(int* sum, int idx)
{
	if(*sum == S){
		ans++;
	}
	if(idx == N -1){
			*sum -= subset.back();
			subset.pop_back();
		}
		else{
			for(int i = idx + 1; i < N; i++){
				*sum += set[i];
				subset.push_back(set[i]);
				check_sum(sum, i);
			}
			*sum -= subset.back();
			subset.pop_back();
		}
}

/*6603번 "로또"와 상당히 비슷하다. 코드는 거의 똑같다.
 * 다른점은 정답의 개수를 증가시키는(부분집합의 합이 S) 경우에
 * 기존 로또에서는 pop을 하고 리턴을 했지만 여기서는 
 * 정답이 나왔어도 뒤에 원소를 추가 하면서 추가적으로
 * 정답이 가능한 경우가 발생할 수 있기에 리턴을 해서는 안된다.*/
