#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<bool> v(2000001,false);
    vector<int> num;
    int n,m;
    cin>>n>>m;
    int k;
    for(int i=0; i<n; i++){
        cin>>k;
        num.push_back(k);
    }
    for(int i=0; i<num.size(); i++){
        for(int j=i+1; j<num.size(); j++){
            k=num[i]+num[j];
            v[k]=true;
            //cout<<num[i]<<' '<<num[j]<<endl;
        }
    }
    for(int i=0; i<m; i++){
        cin>>k;
        if(v[k]==false){cout<<"NO"<<endl;}
        else{cout<<"YES"<<endl;}
    }
}