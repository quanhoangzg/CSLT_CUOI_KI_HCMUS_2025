#include <bits/stdc++.h>
using namespace std;

bool TravelSpiral(int **a, int i, int j, int height, int width) {
    int top = i;
    int bottom = height - 1;
    int left = j;
    int right = width - 1;
    int preNum = -1;
    while (top <= bottom && left <= right) {
        // 1. Trái -> Phải
        for (int i = left; i <= right; i++) {
            if (a[top][i] > preNum){
                preNum = a[top][i];
            } else {
                return false;
            }
        }
        top++;

        // 2. Trên -> Dưới
        
        for (int i = top; i <= bottom; i++) {
            if (a[i][right] > preNum){
                preNum = a[i][right];
            } else {
                return false;
            }
        }
        right--;

        // 3. Phải -> Trái 
        // Phải kiểm tra xem còn hàng để duyệt không (top <= bottom)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                if (a[bottom][i] > preNum){
                    preNum = a[bottom][i];
                } else {
                    return false;
                }
            }
            bottom--;
        }

        // 4. Dưới -> Trên 
        // Phải kiểm tra xem còn cột để duyệt không (left <= right)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (a[i][left] > preNum){
                    preNum = a[i][left];
                } else {
                    return false;
                }
            }
            left++;
        }
    }
    return true;
}

//Bài giải
int** largestIncreasingSpiral(int **a, int m, int n, int &rows, int &cols) {
    rows = 0;
    cols = 0;
    if (a == nullptr) {
        return nullptr;
    }
    int maxI = 0;
    int maxJ = 0;
    // Hai vòng lặp for lồng nhau để luôn test vị trí để mở rộng
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Hai vòng lặp để mở rộng size
            for (int height = i+1; height <= m; height++) {
                for (int width = j+1; width <= n; width++) {
                    if (TravelSpiral(a, i, j, height, width)) {
                        if (rows*cols < height*width) {
                            rows = height;
                            cols = width;
                            maxI = i;
                            maxJ = j;
                        }
                    }
                }
            }
        }
    }

    // tạo con trỏ cấp 2 để return
    int **res = new int*[rows];
    for (int i = 0; i < rows; i++) {
        res[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            res[i][j] = res[i+maxI][j+maxJ];
        }
    }
    return res;
}


//Test1
int main() {
    int m = 3, n = 4;
    // Tạo mảng các con trỏ hàng
    int **a = new int*[m];
    int num = 1;
    for(int i = 0; i < m; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = num;
            num++;
        }
    }

    // Gán giá trị... (hoặc copy từ mảng tĩnh)
    
    //TravelSpiral(a, m, n);

    // Đừng quên giải phóng bộ nhớ!
    for(int i = 0; i < m; i++) delete[] a[i];
    delete[] a;
}

