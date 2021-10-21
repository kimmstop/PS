#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>


using namespace std;

int N;

bool compare(pair<int,int> a, pair<int,int> b)
{
	if(a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main()
{
	cin >> N;
	vector<pair<int,int>> loc;
	int x,y;
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		loc.push_back(make_pair(x,y));
	}
	sort(loc.begin(), loc.end(), compare);

	for(int i =0; i< N; i++){
		cout << loc[i].first << " " << loc[i].second << "\n";
	}
}
