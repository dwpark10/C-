#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		int temp = i;
		int sum = i;
		while( temp ){
			sum += (temp%10);
			temp/=10;
		}
		if(sum == N){
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}
