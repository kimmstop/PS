#include <iostream>
#include <cstring>
using namespace std;

int word_num, ans;
string word[100];

bool isGroupWord(string w);

int main()
{
    cin >> word_num;
    for(int i = 0; i < word_num; i++){
        cin >> word[i];
        if(isGroupWord(word[i])){
            ans+=1;
        }
    }
    printf("%d", ans);
}

bool isGroupWord(string w)
{
    for(int i = 0; i < w.size(); i++){
        int idx = w.find(w.at(i), i + 1);
        if(idx - 1 == i || idx == -1){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}