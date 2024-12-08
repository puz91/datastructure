#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int w[n][n];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> w[i][j];
        }
    }
    vector<int> distance(n,INT_MAX); //ให้ระยะทางเป็น infinity
    distance[0] = 0; //ให้ระยะทางตัวเริ่มเป็น 0
    q.push(make_pair(0,0)); // ใส่ค่าให้ตัวเริ่ม
    while(!q.empty()){
        auto current = q.top(); q.pop(); 
        //cout << current.first << ' ' << current.second << endl;
        for(int i=0; i<n; i++){
            if(w[current.second][i] <= 0)continue;
            
            if(distance[i] > w[current.second][i] + current.first){
                //w[current.second][i] = น้ำหนักตัวที่เอามาใส่
                //current.first = ระยะทางปัจจุบัน 
                q.push(make_pair(w[current.second][i] + current.first,i)); 
                distance[i] = w[current.second][i] + current.first;
            }
        }

    }
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(distance[i] > max)max = distance[i];
        //cout << distance[i] << ' ';
    }
    if(max == INT_MAX){cout << -1;}
    else{cout << max;}
    return 0;
}
