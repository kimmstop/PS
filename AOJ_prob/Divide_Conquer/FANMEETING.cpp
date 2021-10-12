#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
int testcasenum, ans;
vector<int> member, fan, reverse_member;


void Get_Input();
void Print_v(vector<int> a);
vector<int> Calc(vector<int> m, vector<int> f);
vector<int> Mult(vector<int> m, vector<int> f);
vector<int> Add(vector<int> a, vector<int> b);
vector<int> Substract(vector<int> a, vector<int> b);
void Normalize(vector<int> &a);
vector<int> Merge(vector<int> z0, vector<int> z1, vector<int> z2, int digit);	





int main()
{
	scanf("%d ", &testcasenum);
	for(int t = 0; t <testcasenum; t++){
		Get_Input();
		vector<int> ret = Calc(reverse_member, fan);
		Print_v(ret);
		for(int i = reverse_member.size() - 1; i <= fan.size() -1; i++){
			if(ret[i] == 0){
				ans++;
			}
		}
		cout << ans << endl;
		ans = 0;
	}
}

void Get_Input()
{
	char c;
	while(1){
		c = getchar();
		if(c == 'F'){
			member.push_back(0);
		}
		else if(c == '\n'){
			break;	
		}
		else{
			member.push_back(1);
		}
	}
	while(1){
		c = getchar();
		if(c == 'F'){
			fan.push_back(0);
		}
		else if(c == '\n'){
			break;	
		}
		else{
			fan.push_back(1);
		}
	}
	for(int i = member.size() -1; i >=0; i--){
		reverse_member.push_back(member[i]);
	}
}

void Print_v(vector<int> a)
{
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

vector<int> Calc(vector<int> m, vector<int> f)
{
	if(f.size() == 0 || m.size() == 0){
		return vector<int>();
	}
	if(f.size() < m.size()){
		return Calc(f, m);
	}
	if(m.size() <=3 || f.size() <=3){
		return Mult(m, f);
	}
	int half = f.size() / 2;
	vector<int> a1(m.begin(), m.begin() + min<int>(m.size(), half));
	
	vector<int> a0(m.begin() + min<int>(m.size(), half), m.end());
	
	vector<int> b1(f.begin(), f.begin() + half);

	vector<int> b0(f.begin() + half, f.end());
	
/*	cout << "a1 ";
	Print_v(a1);
	cout << "a0 ";
	Print_v(a0);
	cout << "b1 ";
	Print_v(b1);
	cout << "b0 ";
	Print_v(b0);*/

	vector<int> z0 = Calc(a1, b1);
	Print_v(z0);
	vector<int> z2 = Calc(a0, b0);
	//cout << "@@" << endl;
	vector<int> z1 = Calc(Add(a1, a0), Add(b1, b0));
	
	z1 = Substract(z1, z0);
	z1 = Substract(z1, z2);
	vector<int> ret = Merge(z0, z1, z2, half);
	//Print_v(ret);
	return ret;
}


vector<int> Mult(vector<int> m, vector<int> f)
{
	vector<int> ret(m.size() + f.size());
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < f.size(); j++){
			ret[i + j] += m[i] * f[j];
		}
	}
	return ret;
}

vector<int> Add(vector<int> a, vector<int> b)
{
	int size = max(a.size(), b.size());
	vector<int> ret(size + 1, 0);
	int idx = ret.size() -1;
	for(int i = a.size() - 1; i >= 0; i --){
		ret[idx--] += a[i];
	}
	idx = ret.size() -1;
	for(int i = b.size() - 1; i >= 0; i --){
		ret[idx--] += b[i];
	}
	/*while(ret[0] == 0){
		ret.erase(ret.begin());
	}*/
//	Normalize(ret);
	cout << "add ";
	Print_v(ret);
	return ret;
}

vector<int> Substract(vector<int> a, vector<int> b)
{
	int idx = a.size() -1;
	for(int i = b.size() -1; i >=0; i--){
		a[idx] -= b[i];
		idx--;
	}
	Print_v(a);
	//Normalize(a);
	Print_v(a);
	return a;
}

void Normalize(vector<int> &a)
{
	a.push_back(0);
	for(int i = a.size() - 1; i > 0; i--){
		a[i] = a[i-1] ;
	}
	a[0] = 0;
	for(int i = a.size() - 1; i > 0; i--){
		if(a[i] < 0){
			a[i - 1] -= 1;
			a[i] += 10;
		}	
		else if(a[i] >= 10){
			a[i - 1] += a[i] / 10;
			a[i] %= 10;
		}
	}
/*	while(a[0] == 0){
		a.erase(a.begin());
	}*/
}

vector<int> Merge(vector<int> z0, vector<int> z1, vector<int> z2, int digit)
{
	for(int i = 0; i < 2 * digit; i++){
		z0.push_back(0);
	}
	for(int i = 0; i < digit; i++){
		z1.push_back(0);
	}
	z0 = Add(z0, z1);
	z0 = Add(z0, z2);
	return z0;
}