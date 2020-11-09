#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int N;


bool compare(string a, string b)
{
	int size1 = a.size();
	int size2 = b.size();
	if(size1 < size2)
		return true;
	else if(size1 > size2)
		return false;
	else{
		for(int i = 0; i < size1; i++){
			if(a.at(i) < b.at(i))
				return true;
			else if(a.at(i) > b.at(i))
				return false;
		}
		return false;
	}
}


int main()
{
	cin >> N;
	string word[20000];
	for(int i = 0; i < N; i++){
		cin >> word[i];
	}
	sort(word, word + N, compare);
	for(int i = 0; i < N; i++){
		if(i != 0 && !word[i-1].compare(word[i]))
			continue;
		cout << word[i] << endl;
	}

}
