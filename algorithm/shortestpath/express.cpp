#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9; // ค่าที่แทน "อนันต์" สำหรับระยะทางที่ยังไม่เชื่อมต่อ
int main() {
    int n;
    cin >> n; // รับจำนวนจุดในกราฟ
    // สร้างตารางค่าใช้จ่ายเริ่มต้น
    vector<vector<int>> c(n + 1, vector<int>(n + 1, inf));
    // ตั้งค่าเริ่มต้น: ระยะทางจากจุด i ไปจุด i (ไปหาตัวเอง) เป็น 0
    for (int i = 1; i <= n; i++) {
        c[i][i] = 0; //ตารางเริ่มที่ 1 จบที่ n
    }
    // รับระยะทางระหว่างจุด 1 และ 2
    cin >> c[1][2];
    c[2][1] = c[1][2]; // กราฟไม่มีทิศทาง
    // รับข้อมูลการเชื่อมต่อสำหรับจุดอื่น ๆ
    vector<int> k(n + 1); // เก็บจำนวนการเชื่อมต่อของแต่ละจุด
    for (int i = 3; i <= n; i++) {
        cin >> k[i]; // รับจำนวนจุดที่เชื่อมกับจุด i
        for (int j = 0; j < k[i]; j++) {
            int t, p;
            cin >> t >> p;      // t = จุดปลายทาง, p = ค่าใช้จ่าย
            c[t][i] = c[i][t] = p; // ตั้งค่าใช้จ่ายในกราฟ
        }
    }
    // เริ่มต้น Floyd-Warshall Algorithm
    for (int b = 3; b <= n; b++) { // พิจารณาใช้จุด b เป็นตัวกลาง 
        for (int i = 1; i <= n; i++) {      // ตรวจสอบจากจุด i
            for (int j = 1; j <= n; j++) {  // ไปยังจุด j
                // อัปเดตระยะทางที่สั้นที่สุด
                c[i][j] = min(c[i][j], c[i][b] + c[b][j]);
            }
        }
        // แสดงผลระยะทางสั้นที่สุดระหว่างจุด 1 และ 2 ในแต่ละขั้นตอน
        cout << c[1][2] << " ";
        //เริ่มที่ b = 3 เพราะคิดปีที่ 3 เป็นต้นไป
    }

    return 0;
}