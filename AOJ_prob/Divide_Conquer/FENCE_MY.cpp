#include <iostream>
#include <functional>


using  namespace std;

int testcase_num;
int fence[20000], fence_num;


void Get_fence_height();
int Solve(int start, int end);
int Get_mid_area(int start, int end);


int main()
{
	cin >> testcase_num;
	for(int t = 0; t < testcase_num; t++){
		Get_fence_height();
		
		int max_area = Solve(0, fence_num - 1);
		cout << max_area << "\n";
	}
}

void Get_fence_height()
{
	fill(fence, fence + 20000, 0);
	cin >> fence_num;
	for(int i = 0; i < fence_num; i++){
		cin >> fence[i];
	}
}

int Solve(int start, int end)
{
	if(start == end){
		return fence[start];
	}
	int mid = (start + end) / 2;
	int left_area = Solve(start, mid);
	int right_area = Solve(mid + 1, end);
	int mid_area = Get_mid_area(start, end);
	return max(mid_area, max(left_area, right_area));
}

int Get_mid_area(int start, int end)
{
	if(start == end)
		return fence[start];
	int mid = (start + end) / 2;
	int l = mid, r = mid + 1;
	int height = min(fence[l], fence[r]);
	int area = (r - l + 1) * height;
	while(1){
		if(l == start || r == end)
			break;
		if(fence[l - 1] < fence[r + 1]){
			r++;
			height = min(height, fence[r]);
		}
		else{
			l--;
			height = min(height, fence[l]);
		}
		
		area = max(area, (r - l + 1) * height);
	}
	if(l == start && r != end){
		while(r != end){
			r++;
			height = min(height, fence[r]);
			area = max(area, (r - l + 1) * height);
		}
	}
	else if(l != start && r == end){
		while(l != start){
			l--;
			height = min(height, fence[l]);
			area = max(area, (r - l + 1) * height);
		}
	}
	return area;
}