#include <iostream>
#include <algorithm>
#include <string>
#include <queue>


using namespace std;


queue<int> q;

int main()
{
	int req, num;
	string str;
	cin >> req;
	for(int i = 0; i < req; i++){
		cin >> str;
		if(!str.compare("push")){
			cin >> num;
			q.push(num);
		}
		if(!str.compare("pop")){
			if(q.empty()){
				cout << "-1\n"; 
				continue;
			}
			cout << q.front() << endl;
			q.pop();
		}
		if(!str.compare("size")){
			cout << q.size() << endl;
		}
		if(!str.compare("empty")){
			cout << q.empty() << endl;
		}
		if(!str.compare("front")){
			if(q.empty()){
				cout << "-1\n"; 
				continue;
			}
			cout << q.front() << endl;
		}
		if(!str.compare("back")){
			if(q.empty()){
				cout << "-1\n";
				continue;
			}
			cout << q.back() << endl;
		}
	}
}
