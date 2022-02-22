//*
#include <iostream>
#include <string>

using namespace std;

string expr;

int result;
bool isMinus = false;

int main()
{
    cin >> expr;
    string num;
    for(int i = 0; i < expr.size(); i++){
       if(expr.at(i) == '+' || expr.at(i) == '-'){
           if(isMinus == true){
               result -= stoi(num);
               num = "";
           }
           else{
               result += stoi(num);
               num = "";
           }
       }
       else{
           num += expr.at(i);
       }
       if(expr.at(i) == '-')
            isMinus = true;
    }
    if(isMinus == true){
        result -= stoi(num);
        num = "";
    }
    else{
        result += stoi(num);
        num = "";
    }
    cout << result;
}

