#include <bits/stdc++.h>
using namespace std;

// Câu a: Định nghĩa struct Product
struct Product {
    string code;
    string productName;
    string category;
    double price;
    int quantity;
};

// Đề lỏ chắc lưu file theo định dạng <Code>|<Productname>|<Category>|<Price>|<Quantity>

// Câu b:
int readProducts(const char* infile, Product products[], int maxSize) {
    // Đề câu này thì thấy tự nhiên cho cái mảng Product hơi là nhưng chắc là để đọc file vào
    // Max size thì khả năng là số phần tử Product tối đa

    // Đọc file
    ifstream read(infile);

    // Đọc các product vào mảng
    int i = 0;
    while (i < maxSize && !read.eof()) {
        getline(read,products[i].code, '|');
        getline(read,products[i].productName, '|');
        getline(read,products[i].category, '|');
        read >> products[i].price;

         // Bỏ qua dấu '|' giữa price và quantity ---
        char dummy;
        read >> dummy; // Đọc dấu '|' vào biến rác để vứt đi

        read >> products[i].quantity;

        read.ignore(); // Bỏ qua dấu xuống dòng '\n'
        i++;
    }
    // Đóng file
    read.close();

    // Return thì đề là return một cái 1 cái int thì chắc là return số lượng đếm
    return i;
}

// Câu c:
void writePriceMax(Product products[], int size) {
    if (size == 0) return; // Ko viet j ca
    int maxIndex = 0;
    double maxPrice = products[0].price;
    
    for (int i = 1; i < size; i++) {
        if (maxPrice < products[i].price) {
            maxIndex = i;
            maxPrice = products[i].price;
        }
    }

    //Viet file
    ofstream write("maxPrice.txt");

    write << products[maxIndex].code << "|" << products[maxIndex].productName << "|"
          << products[maxIndex].category << "|" << fixed << setprecision(0) << products[maxIndex].price << "|"
          << products[maxIndex].quantity;

    // Đóng file
    write.close();
}

//Test thử:
int main() {
    int maxSize = 100;
    Product products[maxSize];
    int size = readProducts("Input_cau_1.txt", products, maxSize);
    writePriceMax(products, size);
}