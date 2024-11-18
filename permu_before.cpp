#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> before;
vector<int> v;
vector<int> used;
void permu(int step){
    if(step == n){
        for(auto x:v){
            cout<<x<<' ';
        }
        cout<<endl;
    }
    else{
        for(int i=0; i<n; i++){
            if((used[i]==false) && ((before[i]==-1) || used[before[i]])){
                v[step] = i;
                used[i] = true;
                permu(step+1);
                used[i]=false;
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    before = vector<int>(n, -1);
    used.resize(n);
    v.resize(n);
    while(m--){
        int a,b;
        cin>>a>>b;
        before[b]=a;
    }
    permu(0);
}