#include <iostream>
#include <string>

using namespace std;

int testcase_num;
string picture, reversed_picture;
int idx = 0;

string Solve();

int main()
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		cin >> picture;
		
		string reversed_picture= Solve();
		
		cout << reversed_picture << "\n";
		idx = 0;
	}
}

string Solve()
{
	string upleft;
	string upright;
	string bottomleft;
	string bottomright;
	if(picture[idx] != 'x'){
		string ret(1, picture[idx]);
		return ret;
	}
	idx++;
    upleft = Solve();
	idx++;
	upright = Solve();
	idx++;
	bottomleft = Solve();
	idx++;
	bottomright = Solve();
	return "x" + bottomleft + bottomright + upleft + upright;

	
}