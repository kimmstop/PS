#include <iostream>
#include <vector>

using namespace std;

int k;
vector <int> v1,ans;
void setnext(int idx);

int main()
{
	while(1){
		cin >> k;
		if(k==0) break;
		int num;
		for(int i = 0; i < k; i++){
			cin >> num;
			v1.push_back(num);
		}
		for(int i = 0; i< k; i++){
			if(k - i < 6)
				break;
			ans.push_back(v1[i]);
			setnext(i);
		}
		cout << "\n";
		v1.clear();
		ans.clear();
	}
}


void setnext(int idx)
{
	if(ans.size()== 6){
		for(int i = 0; i < 6; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		ans.pop_back();
		return;
	}
	else{
		for(int i = idx + 1; i < k; i++){
			ans.push_back(v1[i]);
			setnext(i);
		}
		ans.pop_back();
	}
}


/* setnext의 함수를 재귀적으로 구현하는데 시간이 좀 걸렸다.
 * 정답이 결정되었을 경우(정답이 가능하거나 불가능할 경우) 
 * 정답이면 6개의 원소를 출력을 하고 마지막 원소를 pop.
 * 정답이 될 수 없는 경우 마지막으로 넣은 원소를 pop.
 * 넣을 원소를 탐색하는 구간은 현재원소의 다음원소부터
 * 끝까지 이다.
 * 정답 배열을 함수인자로 전달하니 call by value 처럼 작동되어
 * 위에서 pop을 하고 return할 경우 pop이 안되었다.
 * 전역으로 선언한 뒤에 테스트 케이스가 끝날 때 마다
 * clear를 해주었다.
 * idx 가 k-1과 같은지 검사해서 pop하는 조건은 굳이 따로 안빼도 된다
 * for문이 끝나는 조건과 동일하다  */
