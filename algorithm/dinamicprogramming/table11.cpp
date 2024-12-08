#include<iostream>
using namespace std;
//bottom-up ver:save-momory
int main(){
    int n;
    long long m = 100000007;
    cin >> n;
    int a0, a1;
    a0 = 1; a1 = 3;
    
    while(n--){
        int temp = a1;
        a1 = ((a1 * 2) + a0) % m;
        a0 = temp;
    }
    cout << a0;
}

//bottom-up
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     long long m = 100000007;
//     cin >> n;
//     int a[n+1];
//     a[0] = 1; a[1] = 3;
    
//     for(int i=2; i<=n; i++){
//         a[i] = ((a[i-1] * 2) + a[i-2]) % m;
//     }

//     cout << a[n];
// }