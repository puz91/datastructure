#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    queue<int> k;
    int n,m,current,left,right,count=0;
    cin>>n>>m;
    if(m==0){
        cout<<0;
    }
    else{
        q.push(m);
        while(!q.empty()){
            current=q.front();
            count++;
            k.push(current);
            q.pop();
            left=(current*2)+1;
            right=(current*2)+2;
            if(left<n)q.push(left);
            if(right<n)q.push(right);

        }
        // while(!k.empty()){
        //     cout<<k.front()<<' ';
        //     k.pop();
        // }
        cout<<n-count<<endl;
        for(int i=0; i<n; i++){
            if(i==k.front()){
                k.pop();
            }
            else{
                cout<<i<<' ';
            }
        }
    }
}