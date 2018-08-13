// 정수 삼각형

#include <iostream>

using namespace std;

int map[500][500];

int main()
{
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < i+1; j++){
            cin >> map[i][j];
        }
    }

    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(map[i][j] < map[i][j+1]){
                map[i-1][j] += map[i][j+1];
            }else{
                map[i-1][j] += map[i][j];
            }
        }
    }

    cout << map[0][0] << endl;

    return 0;
}
