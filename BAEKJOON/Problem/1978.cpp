#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<bool> c(1001);
    vector<int> p;
    for(int i=2; i<=1000; i++){
        if(c[i] == false){
            p.push_back(i);
            for(int j=2*i; j<=1000; j+=i)
                c[j] = true;
        }
    }

    int n;
    int num;
    int count = 0;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;

        if(find(p.begin(), p.end(), num) != p.end() )
            count++;
    }

    cout << count << '\n';

    return 0;
}

