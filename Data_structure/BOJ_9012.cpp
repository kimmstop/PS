#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>


using namespace std;

int T;

int main()
{
	scanf("%d ",&T);
	char c;
	for(int i = 0; i < T; i++){
		stack<char> s;
		while(1){
			c = getchar();
			if(c == '('){
				s.push(c);
			}
			else if(c == ')'){
				if(!s.empty() && s.top() == '('){
					s.pop();
				}
				else
					s.push(')');
			}
			else if(c == '\n'){
				if(s.empty()){
					printf("YES\n");
					break;
				}
				else{
					printf("NO\n");
					break;
				}

			}
		}
	}
}
