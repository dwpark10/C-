#include <iostream>
#include <vector>

using namespace std;

#define SUCCESS 0
#define FAIL 1

//#define DEBUG

char dir[4] = {'N', 'E', 'S', 'W'};
int _dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int map[101][101];

int A, B;
int N, M;

struct ROBOT{
    int num;
    int x;
    int y;
    int dir;    // index;
};

vector<ROBOT> v;

int DoProcess(int num, char act, int count){
    int index = num - 1;

    while(count--){
        switch(act){
        case 'L':
            v[index].dir = (v[index].dir + 3)%4;
            break;
        case 'R':
            v[index].dir = (v[index].dir + 1)%4;
            break;
        case 'F':
            int nx, ny;
            nx = v[index].x + _dir[v[index].dir][0];
            ny = v[index].y + _dir[v[index].dir][1];
            if(nx < 1 || nx > A || ny < 1 || ny > B){
                cout << "Robot " << v[index].num << " crashes into the wall\n";
                return FAIL;
            }
#ifdef DEBUG
            cout << "robot num : " << v[index].num << "robot x : " << v[index].x << "robot y : " << v[index].y << "robot dir : " << v[index].dir << '\n';
            cout << "nx : " << nx << "ny : " << ny << '\n';
#endif
            if(map[nx][ny] != 0){
                cout << "Robot " << v[index].num << " crashes into robot " << map[nx][ny] << '\n';
                return FAIL;
            }else{
                map[v[index].x][v[index].y] = 0;
                map[nx][ny] = v[index].num;
                v[index].x = nx;
                v[index].y = ny;
            }
            break;
        default:
            break;
        }
    }

    return SUCCESS;
}

int main(){

    cin >> A >> B;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        ROBOT temp;
        temp.num = i;
        cin >> temp.x;
        cin >> temp.y;
        char d;
        cin >> d;
        switch(d){
        case 'N':
            temp.dir = 0;
            break;
        case 'E':
            temp.dir = 1;
            break;
        case 'S':
            temp.dir = 2;
            break;
        case 'W':
            temp.dir = 3;
            break;
        default:
            break;
        }
        v.push_back(temp);

        map[temp.x][temp.y] = temp.num;
    }

    while(M--){
        int num;
        char act;
        int count;
        int ret;

        cin >> num >> act >> count;
        ret = DoProcess(num, act, count);
        if(ret == FAIL)
            break;
    }

    if(M == -1)
        cout << "OK" << '\n';

    return 0;
}
