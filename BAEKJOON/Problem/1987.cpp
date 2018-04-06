#include <iostream>

#define DEBUG

using namespace std;

char map[21][21];
int R, C;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool visited[26];
int ans = -1;
int count = 0;

void Solve(int x, int y){
	visited[map[x][y]-'A'] = true;
	count += 1;

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx >= 0 && nx < R && ny >= 0 && ny < C){
			if(visited[map[nx][ny] - 'A'] == true){
				if(count >= ans)
					ans = count;
				continue;
			}else{
				Solve(nx, ny);
			}
		}
	}

	visited[map[x][y] - 'A'] = false;
	count -= 1;

	return;
}





int main(){
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> map[i][j];
		}
	}

	Solve(0, 0);

	cout << ans << '\n';

	return 0;
}
