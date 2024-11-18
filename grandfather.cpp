#include<iostream>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int N,M;
    cin>>N>>M;
    map<string,string> m;
    string father,son,n1,n2;
    for(int i=0; i<N; i++){
        cin>>father>>son;
        m[son]=father;
    }
    while(M--){
        cin>>n1>>n2;
        if(m.find(n1)!=m.end()&&m.find(n2)!=m.end()&&n1!=n2){
            if(m.find(m[n1])!=m.end()&&m.find(m[n2])!=m.end()){
                if(m[m[n1]]==m[m[n2]]){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}