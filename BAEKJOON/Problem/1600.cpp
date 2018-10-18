#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
int map[201][201];
int check[201][201][31] = {false };

int n_row[4] = {0, 0, 1, -1};
int n_col[4] = {1, -1, 0, 0};

int n_k_row[8] = {-2, -2, -1, -1, 1, 1 ,2, 2};
int n_k_col[8] = {-1, 1, -2, 2, 2, -2, 1, -1};

struct Pos{
    int row;
    int col;
    int k;
    int cnt;
    Pos(int a, int b, int c, int d) : row(a), col(b), k(c), cnt(d) {}
};

int Solve(){
    queue<Pos> q;
    q.push(Pos(0, 0, K, 0));

    while( !q.empty() ){
        Pos cur = q.front();
        q.pop();

        if(cur.row < 0 || cur.col < 0 || cur.row >= H || cur.col >= W ) continue;
        if(map[cur.row][cur.col] == 1) continue;

        if(cur.row == H-1 && cur.col == W-1) return cur.cnt;

        for(int i=0; i<4; i++){
            q.push( Pos(cur.row + n_row[i], cur.col + n_col[i], cur.k, cur.cnt + 1) );
        }

        if(cur.k == 0) continue;
        for(int i=0; i<8; i++){
            q.push( Pos(cur.row + n_k_row[i], cur.col + n_k_col[i], cur.k - 1, cur.cnt + 1) );
        }
    }
}

int main()
{
    cin >> K >> W >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> map[i][j];
        }
    }

    int ans = 0;
    ans = Solve();

    cout << "Answer : " << ans << endl;
}
