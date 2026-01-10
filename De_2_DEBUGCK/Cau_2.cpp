#include <bits/stdc++.h>
using namespace std;

int* kthLargestSubarray(int a[], int n, int k, int &subSize) {
    //Số mảng con = n(n+1)/2
    int subArrayMaxSize = n*(n+1)/2;

    if (k > subArrayMaxSize) {
        subSize = 0;
        return nullptr;
    }

    int sumSub[subArrayMaxSize];

    // Duyệt lần 1 để tính
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int start = i; start <= j; start++) {
                sum += a[start];
            }
            sumSub[index] = sum;
            index++;
        }
    }

    // Sort cái sumSub theo chiều giảm dần
    for (int i = 0; i < subArrayMaxSize; i++) {
        for (int j = 0; j < subArrayMaxSize - i - 1; j++) {
            if (sumSub[j] < sumSub[j+1]) {
                int temp = sumSub[j];
                sumSub[j] = sumSub[j+1];
                sumSub[j+1] = temp;
            }
        }
    }

    int sumDesire = sumSub[k-1]; 

    // Duyệt lần 2 để tìm ra mảng con và subSize
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int start = i; start <= j; start++) {
                sum += a[start];
            }
            if (sum == sumDesire) {
                subSize = j - i + 1;
                return &a[i];
            }
        }
    }
}

//Test
int main() {
    int a[] = {1,-2,3};
    int n = 3;
    int subSize = 0;
    int* mang = kthLargestSubarray(a, 3, 2 , subSize);

    for (int i = 0; i < subSize; i++) {
        cout << mang[i] << " ";
    }
    cout << endl;
    cout << "Size la: " << subSize << endl;

    return 0;
}