#include <iostream>
#include <algorithm> // next_permutation, prev_permutation header
#include <vector>

using namespace std;
/* C++ 의 STL의 algorithm 을 사용(next_permutation, prev_permutation)
 * 그게 아닐때에는 다음과 같이 구현
 * A[i-1] < A[i] 를 만족하는 가장 큰 i를 찾는다
 * j >= i 이면서 A[j] > A[i-1] 을 만족하는 가장 큰 j를 찾는다
 * A[i-1]과 A[j]를 swap한다
 * A[i]부터 순열을 뒤집는다
 */

bool next_permutation(int *a, int n){
	int i = n-1;
	while( i > 0 && a[i-1] >= a[i] ) i-=1;
	if (i <= 0) return false;

	int j = n-1;
	while( a[j] <= a[i-1] ) j-=1;
	swap(a[i-1], a[j]);
	j = n-1;
	while( i < j ){
		swap(a[i], a[j]);
		i+=1, j-=1;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	if(next_permutation(a.begin(), a.end())) {
		for( int i=0; i<n; i++) {
			cout << a[i] << ' ';
		}
	} else {
		cout << -1;
	}
	cout << endl;
	return 0;
}
