#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define DEBUG

using namespace std;

int map[101][101];
int M, N;
int K;
int total;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void Fill(int x, int y, int num){
    map[x][y] = num;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < M && ny >= 0 && ny < N){
            if(map[nx][ny] != 0){
                continue;
            }else{
                Fill(nx, ny, num);
            }
        }
    }

    return;
}



int main(){
    cin >> M >> N >> K;

    for(int i = 0; i < K; i++){
        int x_1, x_2, y_1, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for(int j = x_1; j < x_2; j++){
            for(int k = y_1; k < y_2; k++){
                map[k][j] = -1;
            }
        }
    }

    int fill_count = 1;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0){
                Fill(i, j, fill_count);
                fill_count += 1;
            }
        }
    }

    vector<int> v(fill_count-1, 0);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] > 0){
                v[map[i][j]-1] += 1;
            }
        }
    }

    sort(v.begin(), v.end());

    cout << fill_count-1 << '\n';
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << ' ';
    }
    cout << '\n';

    return 0;
}
