#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdio>

using namespace std;

deque<int> dq[4];

void DoProcess(int num, int dir){
    int status[4] = {0, 0, 0, 0};

    status[num-1] = dir;

    // Right
    for(int i = num; i < 4; i++){
        if(dq[i-1][2] + dq[i][6] == 1){
            status[i] = status[i-1] * -1;
        }else{
            status[i] = 0;
        }
    }

    // Left
    for(int i = num-2; i >= 0; i--){
        if(dq[i+1][6] + dq[i][2] == 1){
            status[i] = status[i+1] * -1;
        }else{
            status[i] = 0;
        }
    }

    // Rotate
    for(int i = 0; i < 4; i++){
        if(status[i] == 0){
            continue;
        }else if(status[i] == 1){
            int temp;
            temp = dq[i].back();
            dq[i].pop_back();
            dq[i].push_front(temp);
        }else{
            int temp;
            temp = dq[i].front();
            dq[i].pop_front();
            dq[i].push_back(temp);
        }
    }

    return;
}

int main(){
    int n;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            scanf("%1d", &n);
            dq[i].push_back(n);
        }
    }

    int K;
    int num, dir;

    cin >> K;

    while(K--){
        cin >> num >> dir;

        DoProcess(num, dir);
    }

    int score;

    score = dq[0][0] * 1 + dq[1][0] * 2 + dq[2][0] * 4 + dq[3][0] * 8;

    cout << score << '\n';

    return 0;
}
