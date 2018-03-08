#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;

	vector<pair<int, int> > v;

	while(N--){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	for(auto it : v){
		int count = 1;
		for(auto it_1 : v){
			if( (it_1 != it) && (it.first < it_1.first) && (it.second < it_1.second) )
				count++;
		}
		cout << count << ' ';
	}
	cout << '\n';

	return 0;
}

