#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void cycle(vector<vector<int> >&v, vector<int> path, bool &found, int start, int &pos){
    //if(egde==0||egde==1)return;
    if(found)return;
    if(find(path.begin(), path.end(), start)!=path.end()){
        found = true;
        pos = path.size() - (find(path.begin(), path.end(), start) - path.begin());
        return;
    }
    path.push_back(start);
    for(auto next : v[start]){
        if(path[path.size()-2] != next){
            cycle(v, path, found, next, pos);
        }
    }
}
int main(){
    int n, a, b, m;
    vector<int> path;
    bool found = false;
    int pos = 0;
    cin >> n;
    m = n;
    vector<vector<int> >v(n);
    //cout<<n;
    while(n--){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        //cout<<n;
    }
    //cout<<n;
    for(int i = 0; i < m; i++){
        //cout<<i<<' ';
        cycle(v, path, found, i, pos);
    }
    cout<<pos;
}