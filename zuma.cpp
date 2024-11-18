#include<iostream>
#include<list>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,v,z,cr=0,cl=0,r=0;
    bool first=true;
    cin>>n>>k>>v;
    list<int> l;
    for(int i=0; i<n; i++){
        cin>>z;
        l.push_back(z);
    }
    auto it = next(l.begin(), k);
    it = l.insert(it,v);

    while(!l.empty()){
        cr=0,cl=0;
        auto itr=it;
        auto itl=it;
        while(next(itr) != l.end() && *itr == *(++itr)){
            cr++;
        }
        while(itl != l.begin() && *itl == *(--itl)){
            cl++;
        }
        ++itl;
        r=cr+cl+1;
        if( r>=3 && (first||cl>=1) ){
            while(r--){
                itl=l.erase(itl);
            }
        }
        else{break;}
        first=false;
    }
    for(auto &zu:l){
        cout<<zu<<' ';
    }
    cout << '\n';
    
}