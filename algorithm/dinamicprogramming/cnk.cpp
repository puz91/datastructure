#include<iostream>
using namespace std;
long long cnk(const int &n, const int &k){
    if(n == k)return 1;
    if(k == 0)return 1;
    return cnk(n-1, k-1) + cnk(n-1, k);
}
int main(){
    int n, k;
    cin >> n >> k;
    cout << cnk(n, k);
}