#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(const vector<vector<int> > &v, vector<bool> &visited, int start){
    visited[start] = true;
    for(auto next:v[start]){
        if(visited[next]==false){
            dfs(v, visited, next);
        }
    }
}
void bfs(const vector<vector<int> > &v, vector<bool> &visited, int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        for(auto next:v[q.front()]){
            if(visited[next]==false){
                q.push(next);
                visited[next] = true;
            }
        }
        q.pop();
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    vector<vector<int> > v(n+1);
    vector<bool> visited(n+1,false);
    int count = 0;
    for(int i=0; i<e; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(visited[i]==false)count++;
        bfs(v, visited, i);
    }

    cout << count;
}