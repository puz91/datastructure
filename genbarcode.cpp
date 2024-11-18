#include<iostream>
#include<vector>
using namespace std;
int n,k;
//เติม 0 1 ใน sol
void gen(vector<int> &sol,int step,int ones){
    if(step==n){
        for(auto &x:sol)cout<<x;
        cout<<endl;
    }
    else{
        if(step-ones < n-k){
            sol[step]=0;
            gen(sol,step+1,ones);
        }
        if(ones < k){
            sol[step]=1;
            gen(sol,step+1,ones+1);
        }
    }

}
int main(){
    //cin>>k>>n;
    k = 2, n = 5;
    vector<int> sol(n);
    gen(sol,0,0);

}