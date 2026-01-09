#include <bits/stdc++.h>
using namespace std;

//Câu a)
int countCodeAppearKTime(const int arr[], int n, int k) {
    
    // Tạo mảng mới để keep track
    int check[n];
    for (int i = 0; i < n; i++) {
        check[i] = 1;
    }
    
    int countK  = 0;
    for (int i = 0; i < n; i++) {
        if (check[i] != 0) {
            int count = 1;
            for (int j = i+1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    check[j] = 0;
                }
            }
            if (count == k) {
                countK++;
            }
        }
    }
    return countK;
}

// Câu b)
int Message(int arr[], int result[]) {
    return 0;
}

int main() {
    int arr[8] = {2, 3, 5, 2, 5, 7, 8, 2};
    int size = 8;
    int k = 2;
    cout << countCodeAppearKTime(arr, 8, k);
}
