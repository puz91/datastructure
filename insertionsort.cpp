#include<iostream>
using namespace std;
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

    for (int i = 0; i < m; i++)
    {
        cin >> k;
        int result = 0;
        int idx = 0;
        while (true)
        {
            if (A[idx] == k)
            {
                break;
            }
            if (A[idx] > k)
            {
                result++;
            }
            idx++;
        }
        cout << result << "\n";
    }
}