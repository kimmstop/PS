//*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int r, c, minr, minc;
int map[1000][1000];
string result;

void traverse1();
void traverse2();
void removeMin();
void traverse3();

int main()
{
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
        }
    }
    if((r % 2 != 0 && c % 2 != 0) || (r % 2 != 0 && c % 2 == 0)){
        traverse1();
    }
        
    else if(r % 2 == 0 && c % 2 != 0){
        traverse2();
    }
        
    else{
        removeMin();
        traverse3();
    }
    cout << result << endl;
}

void traverse1()
{
    for(int i = 0; i < r; i++){
        if(i % 2 == 0){
            for(int j = 0; j < c - 1; j++){
                result+=("R");
            }
        }
        else{
            for(int j = 0; j < c - 1; j++){
                result+=("L");
            }
        }
        if(i != r - 1)
            result+=("D");
    }
}

void traverse2()
{
    for(int i = 0; i < c; i++){
        if(i % 2 == 0){
            for(int j = 0; j < r - 1; j++){
                result+=("D");
            }
        }
        else{
            for(int j = 0; j < r - 1; j++){
                result+=("U");
            }
        }
        if(i != c - 1)
            result+=("R");
    }
}

void removeMin()
{
    
    int minval = 987654321;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
                if((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0)){
                if(map[i][j] < minval){
                    minr = i;
                    minc = j;
                    minval = map[i][j];
                }
            }  
        }
    }
}

void traverse3()
{
    for(int i = 0; i < minc /2 ; i++){
        for(int j = 0; j < r - 1; j++){
            result+=("D");
        }
        result+=("R");
        for(int j = 0; j < r - 1; j++){
            result+=("U");
        }
        result+="R";
    }
    int cur_r = 0, cur_c = minc / 2 * 2;
    int max_c = cur_c + 1;
    while(!(cur_r == r - 1 && cur_c == max_c)){
        if(!(cur_r == minr && cur_c + 1 == minc) && cur_c < max_c){
            result+=("R");
            cur_c++;
        }
        else if(cur_c == max_c && !(cur_r == minr && cur_c - 1 == minc)){
            result+=("L");
            cur_c--;
        }
        if(cur_r < r - 1){
            result+=("D");
            cur_r++;
        }
    }

    for(int i = 0; i < (c - minc - 1) / 2; i++){
        result+=("R");
        for(int j = 0; j < r - 1; j++){
            result+=("U");
        }
        result+=("R");
        for(int j = 0; j < r - 1; j++){
            result+=("D");
        }
    }
    
}
