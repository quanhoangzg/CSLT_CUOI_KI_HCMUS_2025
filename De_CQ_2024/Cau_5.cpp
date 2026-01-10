#include <bits/stdc++.h>
using namespace std;


// Tạo cái struct để dễ store data
struct Product {
    string code;  // Chứa tối đa 19 ký tự + ký tự kết thúc \0
    string name; 
    int price;
};

void findProducts(char* filePath, char* keyword) {
    ifstream f(filePath);

    int countSize = 0;
    string temp;
    while(getline(f, temp)) {
        countSize++;
    }

    // Quay về đầu file
    // 1. Xóa các cờ trạng thái lỗi (như eofbit)
    f.clear();
    // 2. Di chuyển con trỏ về vị trí 0 tính từ đầu file
    f.seekg(0, ios::beg); 

    // Tạo mảng Products
    Product* products = new Product[countSize];
    int index = 0;
    while (index < countSize) {
        getline(f, products[index].code, ',');
        getline(f, products[index].name, ',');
        f >> products[index].price;
        f.ignore(1000, '\n');                   // Bỏ qua ký tự xuống dòng
        index++;
    }
    string keyWord = keyword;

    for (int i = 0; i < countSize; i++) {
        if (products[i].name.find(keyWord) != string::npos) {
            cout << products[i].code << ";;" << products[i].name
                 << ";;" << products[i].price << endl;
        }
    }

    delete[] products;
    f.close();
}

int main() {
    char file[] = "sanpham.txt";
    char keyword[] = "iPhone";
    findProducts(file, keyword);
    return 0;
}