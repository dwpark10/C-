#include <iostream>
#include <queue>

using namespace std;

int N, K;
int check[200001];



int main(){
    cin >> N >> K;
    check[N] = 0;

    queue<int> q;

    q.push(N);

    int cur;

    if(N == K){
        cout << 0 << '\n';
        return 0;
    }


    while(!q.empty()){
        cur = q.front();
        q.pop();

        if(cur == K){
            cout << check[cur] << '\n';
            break;
        }

        if(cur - 1 >= 0 && check[cur-1] == 0){
            check[cur-1] = check[cur] + 1;
            q.push(cur-1);
        }
        if(cur + 1 < 200000 && check[cur+1] == 0){
            check[cur+1] = check[cur] + 1;
            q.push(cur+1);
        }
        if(cur * 2 < 200000 && check[cur*2] == 0){
            check[cur*2] = check[cur] + 1;
            q.push(cur*2);
        }
    }

    return 0;
}
