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
*/

// Helper functions: mình ghi cái này ra để đỡ lặp code, ko bt đi thi dc dùng min và max không
int max(int num1, int num2) {
    if (num2 > num1) return num2;
    else return num1;
}

int min(int num1, int num2) {
    if (num2 < num1) return num2;
    else return num1;
}

void MaxSubMatrix(const int a[][MaxSize], int nRow, int nCol, int &maxSum, int &r1, int &c1, int &r2, int &c2) {

}