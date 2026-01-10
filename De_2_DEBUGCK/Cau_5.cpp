#include <bits/stdc++.h>
using namespace std;

// Tạo struct để lưu cho dễ
struct Drink {
    string name;
    int quantity;
    int price;
};

//Câu 5.1
int totalRevenue(const char* filename) {
    ifstream f(filename);

    //Đếm số lượng để tạo mảng drinks chứa các data type Drink
    string temp;
    int size = 0;
    while (getline(f, temp)) {
        size++;
    }

    // Quay lại đầu file
    f.clear(); // Xóa trạng thái lỗi hết file
    f.seekg(0, ios::beg); // quay về đầu file

    //Tạo mảng drinks
    Drink *drinks = new Drink[size];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        getline(f, drinks[i].name, '|');
        f >> drinks[i].quantity;
        f.ignore(); //Để loại dấu '|' rồi mới tới cái lấy tiếp
        f >> drinks[i].price;
        f.ignore(); // Loại bỏ dấu '\n'

        sum+= drinks[i].quantity * drinks[i].price;
    }
    f.close();
    delete[] drinks;
    return sum;
}

// Câu 5.2
void printQuantity(const char* filename) {
    ifstream f(filename);

    //Đếm số lượng để tạo mảng drinks chứa các data type Drink
    string temp;
    int size = 0;
    while (getline(f, temp)) {
        size++;
    }

    // Quay lại đầu file
    f.clear(); // Xóa trạng thái lỗi hết file
    f.seekg(0, ios::beg); // quay về đầu file

    //Tạo mảng drinks
    Drink *drinks = new Drink[size];

    int checkInx = 0;
    for (int i = 0; i < size; i++) {
        Drink drink = Drink();
        getline(f, drink.name, '|');
        f >> drink.quantity;
        f.ignore(); //Để loại dấu '|' rồi mới tới cái lấy tiếp
        f >> drink.price;
        f.ignore(); // Loại bỏ dấu '\n'
        int equal = false;
        for (int j  = 0; j < checkInx; j++) {
            if (drinks[j].name == drink.name) {
                drinks[j].quantity += drink.quantity;
                equal = true;
            }
        }
        if (!equal) {
            drinks[checkInx] = drink;
            checkInx++;
        }
    }

    for (int i = 0; i < checkInx; i++) {
        cout << drinks[i].name << ": " << drinks[i].quantity << " ly" << endl;
    }

    f.close();
    delete[] drinks;
}




//Câu 5.3
void highestProfit(const char* filename) {
    ifstream f(filename);

    //Đếm số lượng để tạo mảng drinks chứa các data type Drink
    string temp;
    int size = 0;
    while (getline(f, temp)) {
        size++;
    }

    // Quay lại đầu file
    f.clear(); // Xóa trạng thái lỗi hết file
    f.seekg(0, ios::beg); // quay về đầu file

    //Tạo mảng drinks
    Drink *drinks = new Drink[size];

    // Đặt biến tạm để tìm doanh thu cao nhất và index của món đó
    int maxprofit = 0;
    int maxProIndx = 0;

    int checkInx = 0;
    for (int i = 0; i < size; i++) {
        Drink drink = Drink();
        getline(f, drink.name, '|');
        f >> drink.quantity;
        f.ignore(); //Để loại dấu '|' rồi mới tới cái lấy tiếp
        f >> drink.price;
        f.ignore(); // Loại bỏ dấu '\n'
        int equal = false;
        for (int j  = 0; j < checkInx; j++) {
            if (drinks[j].name == drink.name) {
                drinks[j].quantity += drink.quantity;
                equal = true;
            }
        }
        if (!equal) {
            drinks[checkInx] = drink;
            checkInx++;
        }
    }

    int newSize = checkInx;
    for (int i = 0; i < newSize; i++) {
        int profit = drinks[i].quantity * drinks[i].price;
        if (maxprofit < profit) {
            maxprofit = profit;
            maxProIndx = i;
        }
    }

    cout << "Món doanh thu cao nhất: " << drinks[maxProIndx].name << " ("
         << maxprofit << " VND)" << endl;

    f.close();
    delete[] drinks;
}

// Câu 5.4
void print2ormore(const char* filename) {
    ifstream f(filename);

    //Đếm số lượng để tạo mảng drinks chứa các data type Drink
    string temp;
    int size = 0;
    while (getline(f, temp)) {
        size++;
    }

    // Quay lại đầu file
    f.clear(); // Xóa trạng thái lỗi hết file
    f.seekg(0, ios::beg); // quay về đầu file

    //Tạo mảng drinks
    Drink *drinks = new Drink[size];

    int checkInx = 0;
    for (int i = 0; i < size; i++) {
        Drink drink = Drink();
        getline(f, drink.name, '|');
        f >> drink.quantity;
        f.ignore(); //Để loại dấu '|' rồi mới tới cái lấy tiếp
        f >> drink.price;
        f.ignore(); // Loại bỏ dấu '\n'
        int equal = false;
        for (int j  = 0; j < checkInx; j++) {
            if (drinks[j].name == drink.name) {
                drinks[j].quantity += drink.quantity;
                equal = true;
            }
        }
        if (!equal) {
            drinks[checkInx] = drink;
            checkInx++;
        }
    }

    for (int i = 0; i < checkInx; i++) {
        if (drinks[i].quantity >= 2) {
            cout << drinks[i].name << "|" << drinks[i].quantity << "|" 
                 << drinks[i].price << "|" << drinks[i].quantity * drinks[i].price << endl;
        }
    }

    f.close();
    delete[] drinks;
}

//Câu 5.5
void sortProfitDesc(const char* filename) {
    ifstream f(filename);

    //Đếm số lượng để tạo mảng drinks chứa các data type Drink
    string temp;
    int size = 0;
    while (getline(f, temp)) {
        size++;
    }

    // Quay lại đầu file
    f.clear(); // Xóa trạng thái lỗi hết file
    f.seekg(0, ios::beg); // quay về đầu file

    //Tạo mảng drinks
    Drink *drinks = new Drink[size];

    int checkInx = 0;
    for (int i = 0; i < size; i++) {
        Drink drink = Drink();
        getline(f, drink.name, '|');
        f >> drink.quantity;
        f.ignore(); //Để loại dấu '|' rồi mới tới cái lấy tiếp
        f >> drink.price;
        f.ignore(); // Loại bỏ dấu '\n'
        int equal = false;
        for (int j  = 0; j < checkInx; j++) {
            if (drinks[j].name == drink.name) {
                drinks[j].quantity += drink.quantity;
                equal = true;
            }
        }
        if (!equal) {
            drinks[checkInx] = drink;
            checkInx++;
        }
    }

    // Sort mình dùng bubble sort nha
    for (int i = 0; i < checkInx; i++) {
        for (int j = 0; j < checkInx - i - 1; j++) {
            if (drinks[j].quantity * drinks[j].price < drinks[j+1].quantity * drinks[j+1].price) {
                Drink temp = drinks[j];
                drinks[j] = drinks[j+1];
                drinks[j+1] = temp;    
            }
        }
    }

    ofstream w("output.txt");
    for (int i = 0; i < checkInx; i++) {
        if (drinks[i].quantity >= 2) {
            w << drinks[i].name << "|" << drinks[i].quantity << "|" 
                 << drinks[i].price << "|" << drinks[i].quantity * drinks[i].price << endl;
        }
    }

    f.close();
    delete[] drinks;
    w.close();
}

// Test
int main() {
    cout << totalRevenue("bill.txt") << endl;

    highestProfit("bill.txt");
    printQuantity("bill.txt");
    print2ormore("bill.txt");
    sortProfitDesc("bill.txt");
    return 0;
}