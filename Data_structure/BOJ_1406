#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

list <char> l;


int main()
{
	list<char>::iterator cursor,tmp;
	int reqnum;
	char inputc, req;
	while(1){
		inputc = getchar();
		if(inputc =='\n')
			break;
		l.push_back(inputc);
	}
	cin >> reqnum;
	cursor = l.end();
	for(int i = 0; i < reqnum; i++){
		cin >> req;
		if(req =='L'){
			if(cursor == l.begin())
				continue;
			cursor--;
		}
		if(req == 'D'){
			if(cursor == l.end())
				continue;
			cursor++;
		}
		if(req == 'B'){
			if(cursor == l.begin())
				continue;
			if(cursor == l.end()){
				l.pop_back();
				cursor ==l.end();
				continue;
			}
			cursor--;
			cursor = l.erase(cursor);
		}
		if(req == 'P'){
			cin >> inputc;
			if(l.size() == 0){
				l.push_back(inputc);
				cursor = l.end();
				continue;
			}
			if(cursor == l.end()){
				l.push_back(inputc);
				cursor = l.end();
				continue;
			}
			l.insert(cursor, inputc);
		}
	}
	list<char>::iterator iter;
	for(iter = l.begin(); iter != l.end(); iter++){
		cout << *iter;
	}
}
