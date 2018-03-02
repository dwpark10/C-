#include <iostream>

using namespace std;

bool check[1001];

void fill(){
	int count;
	int res;
	int a, b, c;
	for(int i = 1; i<100; i++)
		check[i] = true;

	for(int i=1; i<10; i++){
		for(int j=-4; j<=4; j++){
			a = i;
			b = i+j;
			c = i+j+j;
			if( b < 0 || c < 0 || b > 9 || c > 9 )
				break;
			else{
				res = a*100 + b*10 + c;
				check[res] = true;
			}
		}
	}
}

int main(){
	fill();
	int n;
	cin >> n;
	int count = 0;
	for(int i=1; i<=n; i++){
		if(check[i] == true)
			count +=1;
	}
	cout << count << '\n';
}

