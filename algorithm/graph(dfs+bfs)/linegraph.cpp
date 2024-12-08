#include <iostream>
#include <vector>
using namespace std;

bool dfs(const vector<vector<int>> &v, vector<bool> &visited, int start) {
    visited[start] = true; // ทำเครื่องหมายว่าจุดนี้ถูกเยี่ยมชมแล้ว
    for (auto next : v[start]) {
        if (v[next].size() > 2) return false; // ถ้าดีกรีของจุดถัดไปเกิน 2 ไม่เป็นกราฟเส้นตรง
        if (!visited[next] && (dfs(v, visited, next) == false)) {
            return false;
        }
    }
    return true; // ถ้าตรวจสอบทั้ง component แล้วไม่มีปัญหา
}

int main() {
    int n, e;
    cin >> n >> e; // รับจำนวนจุดยอด (n) และจำนวนเส้นเชื่อม (e)

    vector<vector<int>> v(n); // กราฟในรูปแบบ adjacency list
    vector<bool> visited(n, false); // สถานะเยี่ยมชมของแต่ละจุดยอด

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b; // รับข้อมูลเส้นเชื่อม
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int count = 0; // ตัวนับจำนวนกราฟเส้นตรง
    for (int i = 0; i < n; i++) {
        if (!visited[i] && v[i].size() <= 1 && dfs(v, visited, i) == true) {
            count++;
        }
    }

    cout << count << endl; // แสดงผลลัพธ์
    return 0;
}
