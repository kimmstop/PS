#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>

#define M 300000


using namespace std;



priority_queue<pair<int, int>, vector<pair<int, int>> > pq;


int main()
{
	ios::sync_with_stdio(false); cin.tie(0); 
	int V, E, startv;
	cin >> V >> E;
	vector < vector<pair<int,int>> > varr(V+1);
	cin >> startv;
	int v1, v2, w;
	for(int i = 0;i < E; i++){
		cin >> v1 >> v2 >> w;
		varr[v1].push_back({w,v2});
	}
	int dijarr[V+1];
	fill(dijarr, dijarr+V+1, M);	
	dijarr[startv] = 0;
	pq.push({0,startv});
	int curv, curw;
	while(!pq.empty()){
		curv = pq.top().second;
		curw = -pq.top().first;
		pq.pop();
		if(dijarr[curv] < curw){
			continue;
		}
		int nextv, nextw;
		for(int i =0;i < varr[curv].size(); i++){
			nextv = varr[curv][i].second;
			nextw = varr[curv][i].first;
			if(dijarr[nextv] > dijarr[curv] + nextw){
				dijarr[nextv] = dijarr[curv] + nextw;
				pq.push({-dijarr[nextv], nextv});
			}
		}
	}
		for(int i = 1; i<=V;i++){
		if(dijarr[i] == M){
			cout << "INF\n";
		}
		else
			cout  << dijarr[i] << "\n";

	}

}

