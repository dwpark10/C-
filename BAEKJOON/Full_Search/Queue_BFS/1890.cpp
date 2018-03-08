#include <queue>
#include <algorithm>
#include <iostream>
#include <unistd.h>

using namespace std;

int map[100][100];
int check[100][100] = {0, };

int main()
{
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> map[i][j];

	queue<pair<int, int> > q;
	q.push(make_pair(0,0));
	check[0][0] += 1;

	while(!q.empty()){
		int x, y;
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if(x+map[x][y] < N){
			check[x+map[x][y]][y] += 1;
			if(x+map[x][y] == N-1 && y == N-1)
				continue;
			else
				q.push(make_pair(x+map[x][y], y));
		}
		if(y+map[x][y] < N){
			check[x][y+map[x][y]] += 1;
			if(x == N-1 && y+map[x][y] == N-1)
				continue;
			else
				q.push(make_pair(x, y+map[x][y]));
		}
	}

	cout << check[N-1][N-1] << '\n';
	return 0;
}

