#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

int main() {
    int n, e, s; // n = จำนวน node, e = จำนวนเส้นทาง, s = node ต้นทาง
    cin >> n >> e >> s;

    // กราฟในรูปแบบ adjacency list: v[node] เก็บ pair (ปลายทาง, น้ำหนักของเส้นทาง)
    vector<vector<pair<int, int>>> graph(n);

    // รับข้อมูล edge ทั้งหมด
    for (int i = 0; i < e; i++) {
        int sourceNode, destinationNode, weight;
        cin >> sourceNode >> destinationNode >> weight;
        graph[sourceNode].push_back(make_pair(destinationNode, weight));
    }

    // ระยะทางจาก node ต้นทางไปยังแต่ละ node (เริ่มต้นด้วยค่า INT_MAX)
    vector<int> distances(n, INT_MAX);
    distances[s] = 0; // ระยะทางจากต้นทางไปยังตัวเองคือ 0

    // ขั้นตอน Relaxation (ทำซ้ำ n-1 ครั้ง)
    for (int i = 0; i < n - 1; i++) {
        // วนทุก node
        for (int currentNode = 0; currentNode < n; currentNode++) {
            // ถ้า node นี้ยังไม่มีระยะทางที่แน่นอน ให้ข้ามไป
            if (distances[currentNode] != INT_MAX) {
                // ตรวจสอบเพื่อนบ้านของ currentNode
                for (auto neighbor : graph[currentNode]) {
                    int neighborNode = neighbor.first;   // ปลายทางของเส้นทาง
                    int edgeWeight = neighbor.second;   // น้ำหนักของเส้นทาง

                    // ถ้าเจอระยะทางที่สั้นกว่า ให้ปรับปรุงระยะทาง
                    if (distances[currentNode] + edgeWeight < distances[neighborNode]) {
                        distances[neighborNode] = distances[currentNode] + edgeWeight;
                    }
                }
            }
        }
    }

    // ตรวจสอบ Negative Cycle
    for (int currentNode = 0; currentNode < n; currentNode++) {
        if (distances[currentNode] != INT_MAX) {
            for (auto neighbor : graph[currentNode]) {
                int neighborNode = neighbor.first;
                int edgeWeight = neighbor.second;

                // ถ้าเจอเส้นทางที่ยังปรับปรุงระยะทางได้ แสดงว่ามี Negative Cycle
                if (distances[currentNode] + edgeWeight < distances[neighborNode]) {
                    cout << -1; // มี Negative Cycle
                    return 0;
                }
            }
        }
    }

    // พิมพ์ระยะทางจากต้นทางไปยังแต่ละ node
    for (auto distance : distances) {
        cout << distance << ' ';
    }

    return 0;
}
