#include <iostream>

using namespace std;

bool a[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];
bool check(int row, int col){
	// 세로 체크
	if(check_col[col]){
		return false;
	}
	// 좌상향 대각선
	if(check_dig[row+col]){
		return false;
	}
	// 우상향 대각선
	if(check_dig2[row-col+n]){
		return false;
	}
	return true;
}

int calc(int row){
	if(row == n){
		return 1;
	}
	int cnt = 0;
	for(int col=0; col<n; col++){
		if(check(row,col)){
			check_dig[row+col] = true;
			check_dig2[row-col+n] = true;
			check_col[col] = true;
			a[row][col] = true;
			cnt += calc(row+1);
			check_dig[row+col] = false;       // 다시 false 로 하는 이유 : back trace
			check_dig2[row-col+n] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	cout << calc(0) << '\n';
	return 0;
}
