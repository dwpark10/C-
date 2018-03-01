#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculate(vector<int> &a) {
	int sum = 0;
	for(int i=1; i<a.size(); i++) {   // 0 ~ a.size()-1 이 아닌 1 ~ a.size() 를 하는 이유
									  //      : a.size() 의 return 값이 unsigned 형이기 때문에 
									  //        -1 연산을 하였을때 혹시 잘못될 가능성이 있음
		sum+= abs(a[i] - a[i-1]);
	}
	return sum;
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 0;

	do{
		int temp = calculate(a);
		ans = max(ans,temp);
	}while(next_permutation(a.begin(), a.end()));

	cout << ans << '\n';
	return 0;
}
