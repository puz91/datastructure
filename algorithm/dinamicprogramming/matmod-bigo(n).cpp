#include<iostream>
#include<vector>
using namespace std;
void matrix(int a, int b, int c, int d, vector<vector<int> > &v, int n, int k){
    for(int i = 2; i < n; i++){
        v[i][0] = (v[i-1][0]*a)%k + (v[i-1][1]*c)%k;
        v[i][1] = (v[i-1][0]*b)%k + (v[i-1][1]*d)%k;
        v[i][2] = (v[i-1][2]*a)%k + (v[i-1][3]*c)%k;
        v[i][3] = (v[i-1][2]*b)%k + (v[i-1][3]*d)%k;
    }
}
int main(){
    int n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    vector<vector<int> > v(n+1, vector<int>(4, 0)); // n แถว, 4 คอลัมน์, ค่าเริ่มต้นเป็น 0
    a%=k; b%=k; c%=k; d%=k;
    v[0][0] = a;
    v[0][1] = b;
    v[0][2] = c;
    v[0][3] = d;

    v[1][0] = (v[0][0]*a)%k + (v[0][1]*c)%k;
    v[1][1] = (v[0][0]*b)%k + (v[0][1]*d)%k;
    v[1][2] = (v[0][2]*a)%k + (v[0][3]*c)%k;
    v[1][3] = (v[0][2]*b)%k + (v[0][3]*d)%k;

    matrix(a, b, c, d, v, n, k);

    for(int i=0; i<4; i++){
        cout << v[n-1][i] % k << ' ';
    }

}