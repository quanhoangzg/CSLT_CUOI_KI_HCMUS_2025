#include <iostream>
using namespace std;

int findNumberKTimesPerRow(int a[][100], int M, int N, int K) {
    // Vậy tìm ở dòng đầu cái xuất hiện k lần thôi
    
    int check[N] = {0};
    for (int i = 0; i < N; i++) {
        if (check[i] == 0) {
            int count = 0;
            for (int j = i; j < N; j++) {
                if (a[0][i] == a[0][j]) {
                    count++;
                    check[j] = 1;
                }
            }
            if (count == K) {
                return a[0][i];
            }
        }
    }
    return 0;
}

int main() {
    int a[100][100] = {
        {1, 2, 3, 4, 5, 1, 6},
        {2, 7, 1, 1, 3, 5, 9},
        {8, 5, 1, 9, 0, 1, 3}
    };
    cout << findNumberKTimesPerRow(a, 3, 7, 2) << endl;
}