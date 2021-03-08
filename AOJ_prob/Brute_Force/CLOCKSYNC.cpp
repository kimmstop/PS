#include <iostream>
#include <functional>
#include <vector>


using namespace std;

int INF = 9999, SWITCHES = 4, CLOCKS = 16;

char linked[4][17] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	/*"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x..",*/
};



void Push(vector<int>& clocks,int swtch);
bool Arealigned(vector<int>& clocks);
int Solve(vector<int>& clocks, int swtch);
	
	
int main() 
{
	int testcase_num, val, ans;
	
	
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		vector<int> clocks;
		for(int i = 0; i < 16; i ++){
			cin >> val;
			clocks.push_back(val);
		}
		ans = Solve(clocks, 0);
		if(ans >= INF)
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
	
	
}

void Push(vector<int>& clocks,int swtch) 
{
	//cout << "pushed swtch " << swtch << "  ";
	for(int clock = 0; clock < CLOCKS; clock++){
		if(linked[swtch][clock] == 'x')
			clocks[clock] += 3;
		if(clocks[clock] == 15)
			clocks[clock] = 3;
	}
	
}

int Solve(vector<int>& clocks, int swtch) 
{
	if(swtch == SWITCHES)
		return Arealigned(clocks) ? 0 : INF;
	
	int ret = INF;
	for(int cnt = 0; cnt < 4; cnt++){
		ret = min(ret, cnt + Solve(clocks, swtch + 1));
		Push(clocks, swtch);
	}
	return ret;
}

bool Arealigned(vector<int>& clocks)
{
	for(int i = 0; i < CLOCKS; i++){
		if(clocks[i] != 12)
			return false;
	}
	return true;
}