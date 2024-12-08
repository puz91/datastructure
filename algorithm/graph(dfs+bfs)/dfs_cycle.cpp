#include <iostream>
#include <vector>
#include <algorithm> // สำหรับการใช้ find
using namespace std;

// ฟังก์ชันเพื่อตรวจจับวงจร (cycle) ในกราฟ
void cycle(vector<vector<int>>& v, vector<int> path, bool& found, int start, int edge) {
    // ถ้าจำนวนเส้นเชื่อมไม่เพียงพอหรือพบวงจรแล้ว ให้ออกจากฟังก์ชัน
    if (edge == 0 || edge == 1) return; 
    if (found) return;

    // ถ้าเจอจุดเริ่มต้น (start) ใน path แสดงว่ามีวงจร
    if (find(path.begin(), path.end(), start) != path.end()) {
        found = true;
        return;
    }

    // เพิ่มจุดปัจจุบันเข้าไปใน path
    path.push_back(start);

    // วนซ้ำเพื่อสำรวจเพื่อนบ้าน
    for (auto next : v[start]) {
        // ตรวจสอบว่าเพื่อนบ้านที่กำลังพิจารณาไม่ใช่จุดก่อนหน้าใน path
        if (path.size() < 2 || path[path.size() - 2] != next) {
            cycle(v, path, found, next, edge); // เรียกฟังก์ชันแบบเรียกซ้ำ (recursive)
        }
    }
}

int main() {
    int T, N, E, n1, n2;
    bool found;

    // อ่านจำนวนกราฟ (T)
    cin >> T;
    while (T--) {
        // อ่านจำนวนจุดยอด (N) และจำนวนเส้นเชื่อม (E)
        cin >> N >> E;

        // สร้างกราฟแบบ Adjacency List
        vector<vector<int>> v(N); // v[i] เก็บรายชื่อเพื่อนบ้านของจุด i
        vector<int> path;        // เก็บเส้นทางที่กำลังสำรวจ
        found = false;           // ตัวแปรบอกว่าพบวงจรหรือยัง

        // อ่านเส้นเชื่อมและเพิ่มลงในกราฟ
        for (int i = 0; i < E; i++) {
            cin >> n1 >> n2;
            v[n1].push_back(n2); // เพิ่มความสัมพันธ์ระหว่าง n1 และ n2
            v[n2].push_back(n1); // กราฟไม่มีทิศทาง (undirected)
        }

        // ตรวจสอบวงจรในกราฟโดยเริ่มที่จุดยอดแต่ละจุด
        for (int i = 0; i < N; i++) {
            cycle(v, path, found, i, E);
        }

        // แสดงผลลัพธ์: "YES" ถ้าพบวงจร, "NO" ถ้าไม่พบ
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
