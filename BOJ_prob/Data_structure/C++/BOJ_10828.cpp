#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


stack<int> s;


int main()
{
	int req, num;
	string str;
	cin >> req;
	for(int i = 0; i < req; i++){
		cin >> str;
		if(!str.compare("push")){
			cin >> num;
			s.push(num);
		}
		if(!str.compare("top")){
			if(s.empty()){
				cout << "-1"<<endl;
				continue;
			}
			cout << s.top()<<endl;
		}
		if(!str.compare("size")){
			cout << s.size()<<endl;
		}
		if(!str.compare("empty")){
			cout << s.empty()<<endl;
		}
		if(!str.compare("pop")){
			if(s.empty()){
				cout << "-1" << endl;
				continue;
			}
			cout << s.top() << endl;
			s.pop();
		}
	}
}
