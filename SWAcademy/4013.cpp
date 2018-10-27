#include <iostream>
#include <cstdlib>

using namespace std;

int arr[4][8] = {0, };

void DoProcess(int num, int dir){
	int status[4] = {0, 0, 0, 0};

	status[num-1] = dir;

	// Right
	if(num < 4){
		for(int i = num; i < 4; i++){
			if(arr[i-1][2] + arr[i][6] == 1){
				status[i] = status[i-1] * -1;
			}else{
				status[i] = 0;
			}
		}
	}
	// Left
	if(num > 1){
		for(int i = num-2; i >= 0; i--){
			if(arr[i+1][6] + arr[i][2] == 1){
				status[i] = status[i+1] * -1;
			}else{
				status[i] = 0;
			}
		}
	}
	// Rotate
	for(int i = 0; i < 4; i++){
		if(status[i] == 0){
			continue;
		}else if(status[i] == 1){
			int temp;
			temp = arr[i][7];
			for(int j = 7; j > 0; j--){
				arr[i][j] = arr[i][j-1];
			}
			arr[i][0] = temp;
		}else{
			int temp;
			temp = arr[i][0];
			for(int j = 0; j < 7; j++){
				arr[i][j] = arr[i][j+1];
			}
			arr[i][7] = temp;
		}
	}

	return;
}

int main(){
	int T, K;
	int num, dir;
	int score;

	cin >> T;

	for(int k = 1; k <= T; k++){
		memset(arr, 0, sizeof(int)*4*8);
		score = 0;

		cin >> K;

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 8; j++){
				cin >> arr[i][j];
			}
		}

		while(K--){
			cin >> num >> dir;
			DoProcess(num, dir);
		}

		score = arr[0][0] * 1 + arr[1][0] * 2 + arr[2][0] * 4 + arr[3][0] * 8;

		cout << "#" << k << " " << score << '\n';
	}

	return 0;
}
