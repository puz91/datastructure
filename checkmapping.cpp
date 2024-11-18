#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k;
    vector<int> v;
    bool check=true;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        if(v[i]!=i+1){check=false;}
    }
    if(check==true){cout<<"YES";}
    else{cout<<"NO";}
}