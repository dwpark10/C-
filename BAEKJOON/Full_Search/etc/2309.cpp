#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> a;
	int sum = 0;

	int temp;

	for(int i = 0; i < 9; i++){
		cin >> temp;
		sum += temp;
		a.push_back(temp);
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < 8; i++){
		for(int j = i+1; j < 9; j++){
			if(sum - a[i] - a[j] == 100){
				for(int k = 0; k < 9; k++){
					if(k != i && k != j)
						cout << a[k] << '\n';
				}
			return 0;
			}
		}
	}

	return 0;
}
