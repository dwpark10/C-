#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int map[101][101];
int N, L;

bool Check_X(int i){
	vector<pair<int, int>> v;

	v.push_back(make_pair(map[i][0], 1));

	for(int j = 1; j < N; j++){
		if(map[i][j-1] == map[i][j])
			v.back().second += 1;
		else
			v.push_back(make_pair(map[i][j], 1));
	}

	for(auto it = v.begin(); it != v.end()-1; it++){
		if(it->first > (it+1)->first){
			if((it->first - (it+1)->first) > 1){
				return false;
			}else{
				if((it+1)->second < L){
					return false;
				}else{
					(it+1)->second -= L;
				}
			}
		}else{
			if(((it+1)->first - it->first) > 1){
				return false;
			}else{
				if(it->second < L){
					return false;
				}else{
					it->second -= L;
				}
			}
		}
	}

	return true;
}

bool Check_Y(int i){
	vector<pair<int, int>> v;

	v.push_back(make_pair(map[0][i], 1));

	for(int j = 1; j < N; j++){
		if(map[j-1][i] == map[j][i])
			v.back().second += 1;
		else
			v.push_back(make_pair(map[j][i], 1));
	}

	for(auto it = v.begin(); it != v.end()-1; it++){
		if(it->first > (it+1)->first){
			if((it->first - (it+1)->first) > 1){
				return false;
			}else{
				if((it+1)->second < L){
					return false;
				}else{
					(it+1)->second -= L;
				}
			}
		}else{
			if(((it+1)->first - it->first) > 1){
				return false;
			}else{
				if(it->second < L){
					return false;
				}else{
					it->second -= L;
				}
			}
		}
	}

	return true;
}

int main(){
	bool ret;
	int count = 0;

	cin >> N >> L;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];

	for(int i = 0; i < N; i++){
		ret = Check_X(i);
		if(ret == true)
			count += 1;

		ret = Check_Y(i);
		if(ret == true)
			count += 1;

	}

	cout << count << '\n';

	return 0;
}
