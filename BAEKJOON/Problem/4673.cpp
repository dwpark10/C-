#include <iostream>

using namespace std;

bool check[10001];

int main(){
	int sum;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 10; k++){
				for(int l = 0; l < 10; l++){
					for(int m = 0; m < 10; m++){
						sum = i*10000 + j*1000 + k*100 + l*10 + m + i+j+k+l+m;
						if(sum > 10000)
							break;
						else
							if(!check[sum])
								check[sum] = true;
					}
				}
			}
		}
	}
	for(int i=1; i<=10000; i++){
		if(check[i] == false)
			cout << i << '\n';
	}
	return 0;
}

