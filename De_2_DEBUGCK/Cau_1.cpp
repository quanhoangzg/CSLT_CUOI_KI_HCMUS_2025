#include <bits/stdc++.h>
using namespace std;

// Câu 1.1
void hollowPyramid(int h) {
    if (h < 3) return;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= 2*h - 1; j++) {
            if (i == h|| j ==  h+1-i|| j == h-1+i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Câu 1.2
/*
Quá trình thay đổi:
q trỏ đến 4, *p = a[1] + a[2] = 5 + 1 = 6 -> a[3] = 6;
a[2] = *p + a[0] = 6 + 2 = 8;
p = &a[a[0]] = &a[2] -> p trỏ đến a[2] = 8
*p = a[2] - a[1] = 8 - 5 = 3; -> a[2] = 3

Output: 2 5 3 6 3
*/

int main() {
    hollowPyramid(6);
    return 0;
}