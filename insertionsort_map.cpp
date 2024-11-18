#include<iostream>
#include<map>
void insertion_sort(vector<T> &A, map<int,int> &result) {
    int ans = 0;
    for (int pos = A.size()-2;pos >= 0;pos--) {
        int tmp = A[pos];
        size_t i = pos + 1;
        while (i < A.size() && A[i] < tmp) {
            result[A[i]]++;
            A[i-1] = A[i]; //Big o(n^2 log n)
            i++;
        }
        A[i-1] = tmp;
    }
    return ans;
}

int main(){
    int n,m,k;
    cin>>n>>m;

    vector<int> A(n);

    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    map<int, int> result;
    insertion_sort(A, result);

    for(int i=0; i<m; i++){
        cin>>k;
        cout<<result[k]<<endl;
    }
}