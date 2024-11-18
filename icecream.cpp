#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v(100001);
    int n,m,start;
    cin>>n>>m>>start;
    while(n--){
        int a,x;
        cin>>a>>x;
        v[a]=x;
    }
    v[0]=start;
    for(int i=1; i<=100001; i++){
        v[i] = (start = v[i] ? v[i] : start) + v[i-1];
    }
    while(m--){
        int p,g;
        cin>>p>>g;
        if(v[g]>=p){
            cout<<(lower_bound(v.begin(),v.begin()+g+1,p))-v.begin()<<" ";
        }
        else{
            cout<<(lower_bound(v.begin()+g,v.end(),p+v[g]))-v.begin()<<" ";
        }
    }
}