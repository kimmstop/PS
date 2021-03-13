#include <iostream>
#include <functional>
#include <string>
using namespace std;

int testcase_num, image_size, len;
string image;
//string::iterator iter;

void Get_image();
string Get_reversed(string::iterator &iter);

int main() 
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		Get_image();

		string::iterator iter = image.begin();
		string reversed_image(Get_reversed(iter));
		
		cout << reversed_image << endl;
	}
}

void Get_image()
{
	cin >> image;
}


string Get_reversed(string::iterator& iter)
{
	char c = *iter;
	iter++;
	if(c != 'x'){
		return string(1, c);
	}
	
	string upleft(Get_reversed(iter));
	string uprigth(Get_reversed(iter));
	string downleft(Get_reversed(iter));
	string downrigth(Get_reversed(iter));

	
	return "x" + downleft + downrigth + upleft + uprigth;
}


