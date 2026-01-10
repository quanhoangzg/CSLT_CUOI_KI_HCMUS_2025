#include <bits/stdc++.h>
using namespace std;

// Câu 1
void printMultiplicationTable(int range, int num) {
    for (int i = 1; i <= range; i++) {
        cout << num << " * " << i << " = " << i*num << endl;
    }
}

int main() {
    printMultiplicationTable(10,5);
    return 0;
}