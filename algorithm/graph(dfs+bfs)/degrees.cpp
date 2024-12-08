#include<iostream>
#include<vector>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,k;
    int max = 0;
    cin >> n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            cin >> k;
            if(k==1)count++;
        }
        if(count > max)max = count;
        v[count]++;
    }
    for(int i=0; i<=max; i++){
        cout << v[i] << ' ';
    }
}