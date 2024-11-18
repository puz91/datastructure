#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,year,month,temp;
    vector<int> d;
    cin>>n>>m;
    while(n--){
        cin>>year>>month;
        temp = -(year*100+month);
        d.push_back(temp);
    }
    sort(d.begin(),d.end());
    while(m--){
        cin>>year>>month;
        temp = -(year*100+month);
        if(temp > (*(d.end()-1)) ){
            cout<<"-1 -1 ";
        }
        else{
            auto check = lower_bound(d.begin(),d.end(),temp);
            if(*check==temp){
                cout<<"0 0 ";
            }
            else{
                year = -(*check/100);
                month = -(*check%100);
                cout<<year<<' '<<month<<' '; 
            } 
        }
        


    }
}