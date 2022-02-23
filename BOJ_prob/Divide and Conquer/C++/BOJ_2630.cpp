#include <iostream>

using namespace std;

int entire_len;
int paper[128][128];
int paper_type[2];

void isUnified(int cur_r, int cur_c, int cur_len);


int main()
{
    cin >> entire_len;
    for(int i = 0; i < entire_len; i++){
        for(int j = 0; j < entire_len; j++){
            cin >> paper[i][j];
        }
    }
    isUnified(0, 0, entire_len);
    cout << paper_type[0] << endl << paper_type[1] << endl;
}

void isUnified(int cur_r, int cur_c, int cur_len)
{
    int color = paper[cur_r][cur_c];
    bool unifiedflag = true;
    for(int i = cur_r; i < cur_r + cur_len; i++){
        for(int j = cur_c; j < cur_c + cur_len; j++){
            if(color != paper[i][j]){
                unifiedflag = false;
                isUnified(cur_r, cur_c, cur_len / 2);
                isUnified(cur_r + cur_len / 2, cur_c, cur_len / 2);
                isUnified(cur_r, cur_c + cur_len / 2, cur_len / 2);
                isUnified(cur_r + cur_len / 2, cur_c + cur_len / 2, cur_len / 2);
                return;
            }
        }
    }
    if(unifiedflag == true)
        paper_type[color]++;
}
