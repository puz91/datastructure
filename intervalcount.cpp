#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int n,m;
    long long k,num,p;
    cin >> n >> m >> k;
    vector<long long> setofnum;
    while(n--){
        cin>>num;
        setofnum.push_back(num);
    }
    sort(setofnum.begin(),setofnum.end());
    // for(auto e : setofnum){
    //     cout << e << endl;
    // }
    cout << endl;
    while(m--){
        cin>>p;
        auto start=lower_bound(setofnum.begin(),setofnum.end(),p-k);
        // auto end=lower_bound(setofnum.begin(),setofnum.end(),p+k);
        // end--;
        auto end=upper_bound(setofnum.begin(),setofnum.end(),p+k);
        //cout << "low "<< p-k << " up " << p+k << endl;

        //cout << *start << " " << *end << endl;
        cout<<end-start<<' ';
    }


}