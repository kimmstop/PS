#include <iostream>
#include <stack>

using namespace std;

int N;

stack <int> s1;
int req[100000], org[100000];
char ans[200000];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> req[i];
		org[i] = i + 1;
	}
	int reqidx = 0, orgidx = 0, ansidx=0;
	while(reqidx != N && orgidx != N){
		if(org[orgidx] == req[reqidx]){
			ans[ansidx++] = '+';
			ans[ansidx++] = '-';
			reqidx++;
			if(orgidx == N-1){
				while(!s1.empty() && s1.top() == req[reqidx]){
					s1.pop();
					ans[ansidx++] = '-';
					reqidx++;
				}
				if(!s1.empty() && s1.top() != req[reqidx]){
					cout << "NO";
					return 0;
				}
			}
			else{
				while(!s1.empty() && s1.top() == req[reqidx]){
					s1.pop();
					ans[ansidx++] = '-';
					reqidx++;
				}
				if(!s1.empty() && s1.top() >  req[reqidx]){
					cout << "NO";
					return 0;
				}
			}
			orgidx++;
		}
		else if(org[orgidx] < req[reqidx]){
			s1.push(org[orgidx++]);
			ans[ansidx++] = '+';
		}
	}
	for(int i = 0; i < ansidx; i++){
		cout << ans[i] << "\n";
	}
}

/*2개의 배열, 하나는 1,2,3.... 하나는 문제에서 주어지는 수열 을 만들고 각각의 인덱스
  를 설정하여 비교하면서 진행
  -> org보다 req이 더 크면 org의 값을 스택에 넣고 같으면 스택에 있는 값을 pop하면서
  요청한 수열을 만족시킨디. 
  -> 시간초과의 원인은 44번 줄로 pop할때 스택에 있는 값이 req보다 클 경우
  애초에 불가능하여 바로 NO를 출력을 했었어야 했다.*/
