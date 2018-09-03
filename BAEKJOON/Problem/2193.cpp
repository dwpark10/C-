#include <iostream>

using namespace std;

long long arr[2][101];

int main(){
    arr[0][0] = 0;
    arr[1][0] = 0;

    arr[0][1] = 0;
    arr[1][1] = 1;

    arr[0][2] = 1;
    arr[1][2] = 0;

    for(int i = 3; i <= 100; i++){
        arr[0][i] = arr[0][i-1] + arr[1][i-1];
        arr[1][i] = arr[0][i-1];
    }

    int N;

    cin >> N;

    cout << arr[0][N] + arr[1][N] << '\n';

    return 0;
}
