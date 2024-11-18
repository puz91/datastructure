#include<iostream>
#include<vector>
using namespace std;
int n,k;
//เติม 0 1 ใน sol
bool check(vector<int> &sol,int k){
    int count=0;
    for(int i=0; i<sol.size(); i++){
        if(sol[i]==1){
            count++;
            if(count>=k){
                return true;
            }
        }
        else{
            count=0;
        }
    }
    return false;
}
void gen(vector<int> &sol,int step,int ones){
    if(step==n){
        if(check(sol,k)==true){
            for(auto &x:sol)cout<<x;
            cout<<endl;
        }
    }
    else{
        sol[step]=0;
        gen(sol,step+1,ones);

        sol[step]=1;
        gen(sol,step+1,ones+1);
    }

}
int main(){
    cin>>n>>k;
    vector<int> sol(n);
    gen(sol,0,0);

}
