#include<iostream>
#include<vector>
#include<map>
using namespace std;
int insertion_sort(vector<int> &A, vector<int> &result)
{
    int ans = 0;
    for (int pos = A.size() - 2; pos >= 0; pos--)
    {
        int tmp = A[pos];
        size_t i = pos + 1;
        while (i < A.size() && A[i] < tmp)
        {
            result[A[i]]++;
            A[i - 1] = A[i];
            i++;
        }
        A[i - 1] = tmp;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m;

    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<int> result(n, 0);
    insertion_sort(A, result);

    for (int i = 0; i < m; i++)
    {
        cin >> k;
        cout << result[k] << "\n";
    }
}