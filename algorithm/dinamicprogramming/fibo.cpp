#include<iostream>
#include<vector>
using namespace std;
vector<int> v(10000,-1);
//top-down
int fibo(int n){
    v[0] = 0;
    v[1] = 1;
    if(n<2) return v[n];
    else{
        if(v[n] != -1)return v[n];
        else v[n] = fibo(n-1) + fibo(n-2);
    }
    return v[n];    
}
int main(){
    int n;
    cin >> n;
    cout << fibo(n); //top-down
    v[0]=0; v[1]=1;
    for(int i=2; i<=n; i++){
        v[i] = v[i-1]+v[i-2];
    }
    cout << v[n]; //bottom-up
}
