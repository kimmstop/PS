#include <iostream>

using namespace std;

long long oilprice[100000], dist[100000];
int city_num;
long long min_oil_price = 1000000001;
long long result;

int main()
{
    cin >> city_num;
    for(int i = 0; i < city_num - 1; i++){
        cin >> dist[i];
    }
    for(int i = 0; i < city_num; i++){
        cin >> oilprice[i];
        if(oilprice[i] < min_oil_price){
            min_oil_price = oilprice[i];
        }
        else if(min_oil_price < oilprice[i]){
            oilprice[i] = min_oil_price;
        }
    }
    for(int i = 0; i < city_num - 1; i++){
        result += oilprice[i] * dist[i];
    }
    cout << result;
}