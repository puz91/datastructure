#include <iostream>
#include <queue>
#include <vector>
#include <utility> // สำหรับ pair
using namespace std;

int main() {
    int n, e, k, a, b, max = 0; // กำหนดตัวแปรที่ใช้

    // รับค่า n = จำนวนจุด, e = จำนวนเส้นเชื่อม, k = ระดับเพื่อนที่ต้องการตรวจสอบ
    cin >> n >> e >> k;

    // สร้างกราฟแบบ Adjacency List
    vector<vector<int>> v(n); // v[i] เก็บรายชื่อเพื่อนบ้านของจุด i
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        v[a].push_back(b); // เพิ่มความสัมพันธ์ระหว่างจุด a และ b
        v[b].push_back(a); // กราฟไม่มีทิศทาง (undirected)
    }

    // ตรวจสอบเพื่อนระดับ k ของนักศึกษาแต่ละคน
    for (int i = 0; i < n; i++) {
        vector<bool> check(n, false); // สถานะเยี่ยมชมของแต่ละจุด
        queue<pair<int, int>> q;      // คิวสำหรับ BFS, เก็บ (จุดปัจจุบัน, ระดับปัจจุบัน)

        q.push(make_pair(i, 0));     // เริ่มต้นที่ตัวเองในระดับ 0
        check[i] = true;             // ตั้งสถานะเยี่ยมชมตัวเอง
        int mutaul = 0;              // ตัวนับจำนวนเพื่อนระดับ k

        while (!q.empty()) {
            auto current = q.front(); // ดึงข้อมูลจุดปัจจุบัน
            q.pop();

            int student = current.first;  // นักศึกษาปัจจุบัน
            int degree = current.second;  // ระดับปัจจุบัน

            if (degree <= k) {
                mutaul++; // ถ้าระดับอยู่ในช่วงที่ต้องการ ให้นับเพื่อน
            }

            if (degree < k) {
                // สำรวจเพื่อนบ้าน
                for (auto next : v[student]) {
                    if (!check[next]) { // ถ้าเพื่อนบ้านยังไม่ถูกเยี่ยมชม
                        q.push(make_pair(next, degree + 1)); // เพิ่มเพื่อนบ้านในระดับถัดไปลงในคิว
                        check[next] = true;                 // ตั้งสถานะว่าเยี่ยมชมแล้ว
                    }
                }
            }
        }

        // อัพเดตค่า max ถ้าจำนวนนับเพื่อนระดับ k ของคนนี้มากกว่า max เดิม
        if (mutaul > max) {
            max = mutaul;
        }
    }

    // แสดงผลลัพธ์: จำนวนเพื่อนระดับ k ที่มากที่สุด
    cout << max;

    return 0;
}
