#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int map[101][101];
int check[101][101];

int nnx[4] = {-1, 1, 0, 0};
int nny[4] = {0, 0, -1, 1};


int main(){
	int N, M;
	cin >> N >> M;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%1d", &map[i][j]);
		}
	}

	queue<pair<int, int> > q;

    pair<int, int> p = make_pair(1, 1);
	check[1][1] = 1;
	q.push(p);

	while(!q.empty()){
		int x, y;
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if(x == N && y == M){
			cout << check[x][y] << '\n';
			break;
		}

		for(int i = 0; i < 4; i++){
			int nx = x + nnx[i];
			int ny = y + nny[i];

			if(nx >= 1 && nx <= N && ny >= 1 && ny <= M && map[nx][ny] == 1){
				if(check[nx][ny] == 0)
				{
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return 0;
}
