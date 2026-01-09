#include <bits/stdc++.h>
using namespace std;

int main() {
    // Hệ 32 bit
    int x = 2026;
    int *p = &x;
    int y = *p + 1;

    // On chuong pointer va advance pointer
    cout << p << endl; // FF0A
    cout << &y << endl; //FF06 // Vì x và y là biến cục bộ nên sẽ lưa vào stack memory
    // Stack memory trên hệ x86 như máy tính hiện nay thì nó sẽ ưu tiên biến tạo trước địa chỉ cao
    // Và biến sau địa chỉ thấp vì sizeof(int) = 4 bytes nên địa chỉ y sẽ cách địa chỉ x đơn vị
    cout << y << endl; // 2027

    // Mỗi byte của x:
    // 11101010 00000111 00000000 00000000  
    //  234       7          0        0    
}