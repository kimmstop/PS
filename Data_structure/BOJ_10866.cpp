#include <iostream>
#include <algorithm>
#include <string>
#include <deque>


using namespace std;


deque<int> dq;

int main()
{
	int req, num;
	string str;
	cin >> req;
	for(int i = 0; i < req; i++){
		cin >> str;
		if(!str.compare("push_front")){
			cin >> num;
			dq.push_front(num);
		}
		if(!str.compare("push_back")){
			cin >> num;
			dq.push_back(num);
		}
		if(!str.compare("pop_front")){
			if(dq.empty()){
				cout << "-1\n"; 
				continue;
			}
			cout << dq.front() << endl;
			dq.pop_front();
		}
		if(!str.compare("pop_back")){
			if(dq.empty()){
				cout << "-1\n"; 
				continue;
			}
			cout << dq.back() << endl;
			dq.pop_back();
		}
		if(!str.compare("size")){
			cout <<dq.size() << endl;
		}
		if(!str.compare("empty")){
			cout << dq.empty() << endl;
		}
		if(!str.compare("front")){
			if(dq.empty()){
				cout << "-1\n"; 
				continue;
			}
			cout << dq.front() << endl;
		}
		if(!str.compare("back")){
			if(dq.empty()){
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << endl;
		}
	}
}
