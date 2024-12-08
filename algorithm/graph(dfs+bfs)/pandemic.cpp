#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int main(){
    int r,c,t;
    cin >> r >> c >> t;
    int a[r][c];
    queue<pair<int ,int> > q;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                q.push(make_pair(i,j));
            }  
        }
    }
    int virus = q.size();
    for(int i = 0; i < t; i++){
        int sz = q.size();

        for(int i=0; i<sz; i++){
            auto pos = q.front();
            q.pop();
            int x = pos.first;
            int y = pos.second;
            if(a[x-1][y] == 0 && x-1 >= 0){a[x-1][y]=1; q.push(make_pair(x-1,y)); virus++;}
            if(a[x+1][y] == 0 && x+1 < r){a[x+1][y]=1; q.push(make_pair(x+1,y)); virus++;}
            if(a[x][y-1] == 0 && y-1 >= 0){a[x][y-1]=1; q.push(make_pair(x,y-1)); virus++;}
            if(a[x][y+1] == 0 && y+1 < c){a[x][y+1]=1; q.push(make_pair(x,y+1)); virus++;}
            
        }
        
    }
    cout << virus;
    
}