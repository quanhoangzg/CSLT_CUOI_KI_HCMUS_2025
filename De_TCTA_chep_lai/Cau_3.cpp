#include <bits/stdc++.h>
using namespace std;

//Câu a)
// Đề bài kêu trên dưới trái phải thì ta sẽ phải xét bỏ qua các phần tử ở mép
/* VD 4x4
1 2 1 1
2 9 2 1
1 2 8 2
1 1 2 1

có 9 và 8 thỏa
*/
int const MaxSize = 100;

int Hotspot(const int a[][MaxSize], int m, int n) {
    // Count như bth thôi
    // Xét cột từ 1 đến n - 2
    // Xét hàng từ 1 đến m - 2
    int count = 0;
    for (int row = 1; row < m - 1; row++) {
        for (int col = 1; col < n - 1; col++) {
            if (a[row][col] > a[row-1][col] && a[row][col] > a[row+1][col] &&
            a[row][col] > a[row][col+1] && a[row][col] > a[row][col-1]) {
                count++;
            }
        }
    }
    return count;
}

//Câu b
/*
Câu này khá đớ đề bài không cho biết các giá trị trong câu thuộc cái gì?
Nếu toàn các số dương thì coi như return cái size r
còn nếu số âm thì là câu chuyện khác, để đề bài có cái mà làm thì mình sẽ giả định có số 
âm vậy thì nó mới đỡ
Còn r1, r2, c1, c2 là cái quái j?
khó hiểu con người 
chắc 4 góc? hmmm
À không đây là địa chỉ 2 góc phải và góc cuối trái
Nếu duyệt trâu thì sẽ là bài toán expand mấy cái quỷ này
*/

// Helper functions: mình ghi cái này ra để đỡ lặp code, ko bt đi thi dc dùng min và max không
void MaxSubMatrix(const int a[][MaxSize], int nRow, int nCol, int &maxSum, int &r1, int &c1, int &r2, int &c2) {
    maxSum = -2e9; //Ccho thành số siêu nhỏ
    // Duyệt từ r1 -> nRow
    // Duyệt từ c1 -> nCol
    // Duyệt r2 từ r1 -> nRow
    // Duyệt c2 từ c1 -> nCol
    for (int row1 = 0; row1 < nRow; row1++) {
        for (int col1 = 0; col1 < nCol; col1++) {
            for (int row2 = row1; row2 < nRow; row2++) {
                for (int col2 = col1; col2 < nCol; col2++) {
                    int Sum = 0; 
                    // Giờ mới tính subMatrix
                    for (int i = row1; i <= row2; i++) {
                        for (int j = col1; j <= col2; j++) {
                            Sum += a[i][j];
                        }
                    }

                    // Check
                    if (Sum > maxSum) {
                        maxSum = Sum;
                        r1 = row1;
                        r2 = row2;
                        c1 = col1;
                        c2 = col2;
                    }
                    // Vì ta expand row từ 0 đến hết và col từ 0 đến hết nên 
                    // không cần check mấy cái smallest vì khi nó mà thỏa sum lớn hơn lần đầu thì đã thỏa smallest r, lần 2 có bằng thì ko thỏa smallest
                }
            }
        }
    }

}

// --- HÀM MAIN TEST --- (Cái này mình nhờ AI nó tạo cho chắc th chứ tư duy đúng r)
int main() {
    // Test case 1: Hotspot
    int map[MaxSize][MaxSize] = {
        {1, 2, 1, 1},
        {2, 9, 2, 1}, // Số 9 là hotspot
        {1, 2, 8, 2}, // Số 8 là hotspot
        {1, 1, 2, 1}
    };
    
    cout << "--- TEST CAU A (HOTSPOT) ---" << endl;
    cout << "So luong Hotspot: " << Hotspot(map, 4, 4) << endl; 
    // Kỳ vọng: 2 (số 9 và số 8)

    // Test case 2: Max Sub Matrix
    // Mình tạo 1 ma trận có số âm để test độ chính xác
    /*
      Ma trận:
       -1  -2   5
        4   1  -10
    */
    // Submatrix lớn nhất sẽ là [4, 1] (dòng 1, từ cột 0 đến 1) -> Tổng = 5
    // Hoặc ô số [5] (dòng 0, cột 2) -> Tổng = 5
    // Theo luật "Smallest", nó phải chọn ô [5] vì r1(0) < r1(1)
    
    int matrix2[MaxSize][MaxSize] = {
        {-1, -2, 5}, 
        {4, 1, -10}
    };

    int maxS, r1, c1, r2, c2;
    MaxSubMatrix(matrix2, 2, 3, maxS, r1, c1, r2, c2);

    cout << "\n--- TEST CAU B (MAX SUB MATRIX) ---" << endl;
    cout << "Max Sum: " << maxS << endl;
    cout << "Toa do bat dau (r1, c1): (" << r1 << ", " << c1 << ")" << endl;
    cout << "Toa do ket thuc (r2, c2): (" << r2 << ", " << c2 << ")" << endl;
    
    // Giải thích kết quả mong đợi cho Test 2:
    // Có 2 vùng có tổng bằng 5 (lớn nhất):
    // 1. Ô (0,2) giá trị 5. Start(0,2), End(0,2).
    // 2. Vùng (1,0)->(1,1) giá trị 4+1=5. Start(1,0), End(1,1).
    // Vì ưu tiên r1 nhỏ nhất -> Máy phải in ra kết quả số 1: Start(0,2)

    return 0;
}