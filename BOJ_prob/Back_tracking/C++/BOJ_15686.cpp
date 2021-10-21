#include <iostream>
#include <vector>
#include <utility>
#define HOUSE 1
#define CHICKEN 2

using namespace std;

vector <pair<int,int>> loc_of_chicken;
vector <pair<int,int>> loc_of_house;
vector <pair<int,int>> loc_of_survive_chicken;
int city[50][50];
int min_chickenlength_of_city = 987654321;
int num_of_city, max_num_of_chicken;

void Get_min_chickenlength_of_city();
void Set_survive_chicken(int new_survive_chicken);
void Cal_chickenlength_of_city();
int Cal_min_chickenlength_of_house(int house);
int Cal_chickenlength_x(int house_loc_x, int chicken);
int Cal_chickenlength_y(int house_loc_y, int chicken);
	
	
int main()
{
	cin >> num_of_city >> max_num_of_chicken;
	for(int i = 0; i < num_of_city; i++){
		for(int j = 0; j < num_of_city; j++){
			cin >> city[i][j];
			if(city[i][j] == HOUSE)
				loc_of_house.push_back(make_pair(i,j));
			if(city[i][j] == CHICKEN)
				loc_of_chicken.push_back(make_pair(i,j));
		}
	}
	Get_min_chickenlength_of_city();
	cout << min_chickenlength_of_city << "\n";
}

void Get_min_chickenlength_of_city()
{
	Set_survive_chicken(0);
}

void Set_survive_chicken(int new_survive_chicken)
{
	if(loc_of_survive_chicken.size() == max_num_of_chicken){
		Cal_chickenlength_of_city();
		loc_of_survive_chicken.pop_back();
		return;
	}
	pair<int,int> tmp_chicken_loc;
	for(int survive_chicken = new_survive_chicken; survive_chicken < loc_of_chicken.size(); survive_chicken++){
		tmp_chicken_loc.first = loc_of_chicken[survive_chicken].first;
		tmp_chicken_loc.second = loc_of_chicken[survive_chicken].second;
		loc_of_survive_chicken.push_back(make_pair(tmp_chicken_loc.first, tmp_chicken_loc.second));
		Set_survive_chicken(survive_chicken + 1);
	}
	loc_of_survive_chicken.pop_back();
}

void Cal_chickenlength_of_city()
{
	int chickenlength_of_city= 0;
	for(int house= 0; house < loc_of_house.size(); house++){
		chickenlength_of_city += Cal_min_chickenlength_of_house(house);
	}
	if(min_chickenlength_of_city > chickenlength_of_city)
		min_chickenlength_of_city = chickenlength_of_city;
}

int Cal_min_chickenlength_of_house(int house)
{
	int min_chickenlength = 987654321;
	int chickenlength, chickenlength_x, chickenlength_y;
	pair<int,int> house_loc = loc_of_house[house];
	for(int chicken = 0; chicken < loc_of_survive_chicken.size(); chicken++){
		chickenlength_x = Cal_chickenlength_x(house_loc.first, chicken);
		chickenlength_y = Cal_chickenlength_y(house_loc.second, chicken);
		chickenlength = chickenlength_x + chickenlength_y;
		if(min_chickenlength > chickenlength)
			min_chickenlength = chickenlength;
	}
	return min_chickenlength;
}

int Cal_chickenlength_x(int house_loc_x, int chicken)
{
	int chicken_loc_x = loc_of_survive_chicken[chicken].first;
	return max(house_loc_x, chicken_loc_x) - min(house_loc_x, chicken_loc_x);
}

int Cal_chickenlength_y(int house_loc_y, int chicken)
{
	int chicken_loc_y = loc_of_survive_chicken[chicken].second;
	return max(house_loc_y, chicken_loc_y) - min(house_loc_y, chicken_loc_y);
}


/*
 * 중간에 변수 이름이 잠깐 헷갈렸지만 차분히 다시 정리했다. 
 *변수이름이 길어지다보니 for문의 가로 길이가 방대하게 길어지는
 경향이 있다. for문에서는 간단한 변수이름을 지어보자 
 *벡터와 pair에서 사용되는 함수 이름을 정확히 기억하자
 */
