// Giai thich
const char* myPointer[] = { "Hello World", "C++", "Final Exam", "FITUS" };
// Index 0: "Hello World" (độ dài 11)
// Index 1: "C++" (độ dài 3)
// Index 2: "Final Exam" (độ dài 10)
// Index 3: "FITUS" (độ dài 5)
/*
a) Có hợp lệ, vì khi đó thằng myPointer[0] và myPointer[1] cùng chỉ về  "C++" trong bộ nhớ.
Có nghĩa là myPointer[0] copy địa chỉ của "C++" từ myPointer[1];

b)myPointer[0] = "h" hợp lệ vì "h" là một chuỗi ký tự tĩnh 
(string literal), nó được lưu ở vùng nhớ hằng số (Code segment/Read-only data).
mà myPointer là mảng lưu các chuỗi hằng nên hoàn toàn hợp lệ khi gán myPointer[0] = "h"

c)
kết quả in ra: 
C++
FITUS
Final Exam
Hello World
*/