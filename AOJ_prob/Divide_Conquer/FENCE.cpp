#include <iostream>
#include <algorithm>


using namespace std;


int testcase_num;
int fence[20001], fence_num;
int max_area;

void Get_fence_height();
int Get_max_area(int start_idx, int end_idx);
int Get_area(int idx);
int Get_max_of_three(int l, int r, int c);
int Get_mid_area(int s, int e);

int main()
{
	
	cin >> testcase_num;
	
	for(int t = 0; t < testcase_num; t++){
		cin >> fence_num;
		Get_fence_height();
		
		
		max_area = Get_max_area(0, fence_num);
		
		cout << max_area << "\n";
		max_area = 0;
		fill(fence, fence + 20001, 0);
	}
}

void Get_fence_height()
{
	for(int i = 0; i < fence_num; i++){
		cin >> fence[i];
	}
}

int Get_max_area(int start_idx, int end_idx)
{
	int left_max_area, right_max_area, center_max_area;
	if(start_idx == end_idx){
		return fence[start_idx];
	}
	
	int mid_idx = ( end_idx + start_idx ) / 2;
	int area = max(Get_max_area(start_idx, mid_idx), Get_max_area(mid_idx + 1, end_idx));
	int mid_area = Get_mid_area(start_idx, end_idx);
	area = max(mid_area, area);
	return area;
}


int Get_mid_area(int s, int e)
{
	int mid = (s + e) / 2, area = 0;
	int low= mid, high = mid +1;
	int height = min(fence[low], fence[high]);
	area = max(area, height * 2);
	while(s < low || e > high){
		if(high < e && (low == s || fence[low -1] < fence[high+1])){
			high++;
			height = min(height, fence[high]);
		}
		else{
			low--;
			height = min(height, fence[low]);
		}
		area = max(area, height * (high - low + 1));
	}
	return area;
}