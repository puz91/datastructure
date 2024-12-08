#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int n; // จำนวน node ในกราฟ
    cin >> n;

    int weightMatrix[n][n]; // เมทริกซ์น้ำหนักของเส้นทางระหว่าง node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; 
    // ใช้ min-heap (priority_queue) สำหรับเลือก node ที่มีระยะทางสั้นที่สุดในแต่ละรอบ

    // รับค่าเมทริกซ์น้ำหนักของกราฟ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weightMatrix[i][j];
        }
    }

    vector<int> distances(n, INT_MAX); // ระยะทางจาก node เริ่มต้นไปยังแต่ละ node (ค่าเริ่มต้นคือ infinity)
    distances[0] = 0; // ระยะทางจาก node เริ่มต้น (node 0) ไปยังตัวเองคือ 0
    minHeap.push(make_pair(0, 0)); // เพิ่ม (ระยะทาง, node) เริ่มต้นเข้าสู่ min-heap

    // เริ่มกระบวนการ Dijkstra
    while (!minHeap.empty()) {
        auto current = minHeap.top(); 
        minHeap.pop(); 

        int currentDistance = current.first;  // ระยะทางจากต้นทางถึง node ปัจจุบัน
        int currentNode = current.second;    // node ปัจจุบันที่กำลังพิจารณา

        // วนลูปตรวจสอบทุก node ที่เชื่อมต่อกับ currentNode
        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (weightMatrix[currentNode][neighbor] <= 0) 
                continue; // ข้ามถ้าไม่มีเส้นทาง (น้ำหนัก <= 0)

            // คำนวณระยะทางใหม่: ระยะทางปัจจุบัน + น้ำหนักเส้นทาง
            int newDistance = currentDistance + weightMatrix[currentNode][neighbor];

            // ถ้าพบระยะทางที่สั้นกว่า ให้ปรับปรุง
            if (distances[neighbor] > newDistance) {
                distances[neighbor] = newDistance; 
                minHeap.push(make_pair(newDistance, neighbor)); // เพิ่มเพื่อนบ้านเข้าสู่ min-heap
            }
        }
    }

    // หา node ที่มีระยะทางไกลที่สุด (max distance)
    int maxDistance = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (distances[i] > maxDistance) {
            maxDistance = distances[i];
        }
    }

    // ถ้ามี node ที่ไม่สามารถเข้าถึงได้ ให้แสดงผล -1
    if (maxDistance == INT_MAX) {
        cout << -1;
    } else {
        cout << maxDistance;
    }

    return 0;
}
