#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    // อ่านค่า cost ของแต่ละบล็อก
    vector<vector<int>> cost(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> cost[i][j];
        }
    }

    // Min-heap สำหรับ Dijkstra's Algorithm
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(0, make_pair(0, 0))); // เริ่มที่ (0, 0) ค่าผ่านทาง 0
    vector<vector<int>> dist(r, vector<int>(c, 1e9)); // dist[i][j] ค่าผ่านทางต่ำสุด
    dist[0][0] = 0;
    
    // ทิศทางที่สามารถเดินได้ (ขวา, ซ้าย, ลง, ขึ้น)
    int movei[4] = {0, 0, 1, -1};
    int movej[4] = {1, -1, 0, 0};

    // ดำเนินการ Dijkstra
    while (!pq.empty()) {
        auto temp = pq.top(); pq.pop();
        int w = temp.first; // ค่าผ่านทางปัจจุบัน
        int icurrent = temp.second.first; // ตำแหน่งแถว
        int jcurrent = temp.second.second; // ตำแหน่งคอลัมน์

        // สำรวจ 4 ทิศทาง
        for (int i = 0; i < 4; i++) {
            int newi = icurrent + movei[i];
            int newj = jcurrent + movej[i];

            // ตรวจสอบตำแหน่งที่อยู่ในกรอบ
            if (newi >= 0 && newi < r && newj >= 0 && newj < c) {
                // อัปเดตค่า dist ถ้าเจอเส้นทางที่ดีกว่า
                if (w + cost[newi][newj] < dist[newi][newj]) {
                    dist[newi][newj] = w + cost[newi][newj];
                    pq.push(make_pair(dist[newi][newj], make_pair(newi, newj))); // ใส่ใน PQ
                }
            }
        }
    }

    // แสดงผลลัพธ์ (ค่าผ่านทางต่ำสุดสำหรับแต่ละตำแหน่ง)
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }

}
