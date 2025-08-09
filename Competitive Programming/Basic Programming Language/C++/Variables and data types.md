- Biến có thể được hiểu là một không gian có thể chứa dữ liệu trong chương trình, trong đó giá trị của biến có thể được thay đổi hoặc đặt là hằng số (không thể thay đổi bằng các lệnh trong chương trnihf)
- Ví dụ: thay vì lúc nào cũng phải sử dụng giá trị 25 ở nhiều chỗ trong chương trình, ta có thể gán một biến "a" có giá trị là 25
- Tại sao phải đặt biến? Vì khi đó nếu phải thay đổi các giá trị được sử dụng trong chương trình, ta chỉ cần thay đổi giá trị của biến và sử dụng biến thay cho giá trị đó, khi đó, thay vì phải chỉnh sửa từng câu lệnh, ta có thể thay đổi giá trị của biến và tất cả những câu lệnh khác sẽ được thay đổi giá trị theo.
*Cách khai báo biến trong C++*
- Cú pháp khai báo biến trong C++ như sau: {kiểu dữ liệu} + {tên biến} = {giá trị};
- Ví dụ: int a = 0;
- Lưu ý: việc gán giá trị khi khai báo biến là không bắt buộc. VD: int a;
*Các kiểu dữ liệu trong C++*
- Một số kiểu dữ liệu cơ bản trong C++ bao gồm: int, long long, __int128, bool, char, string. Ngoài ra, còn có các kiểu dữ liệu khác tương đối nâng cao như: vector, map, unordered_map, set, unordered_set,...
- Trong đó, ta có thể khai báo một mảng (hay danh sách) thuộc một kiểu dữ liệu theo cú pháp: {kiểu dữ liệu} + {tên mảng}[{độ lớn của mảng}];
- VD: int a[2*100005];
- Lưu ý, nếu khai báo biến ở bên ngoài chương trình chính (int main) thì ban đầu tất cả các giá trị sẽ bằng 0.
*Mô tả và độ lớn các kiểu dữ liệu:*
- int: kiểu dữ liệu cơ bản, chứa cả số âm và dương, là kiểu dữ liệu 31 bit, có thể chứa giá trị từ -2^31 đến 2^31-1 (khoảng từ -9*10^9 đến 9*10^9)
- long long: Giống int nhưng lớn hơn, có thể chứa đến 63 bit, từ -2^63 đến 2^63-1. Tương đương từ -10^18 đến 10^18
- __int128: giống int và long long nhưng lớn hơn, có thể chứa đến 128 bit, từ -2^128 đến 2^128-1, tương đương -1.7*10^38 đến 1.7*10^38
- bool: kiểu dữ liệu logic, gồm 2 bit là giá trị đúng (true) hoặc sai (false). Tất cả các số dương trừ số 0 ra đều có giá trị là true, và số 0 là false. Do đó, khi gán một biến kiểu dữ liệu bool một giá trị số nguyên, thì sẽ được chuyển hoá thành true hoặc false. VD: bool a = 5; => a = true.
- char: kiểu dữ liệu kí tự, có thể chứa đúng 1 kí tự, giá trị được đặt trong dấu ngoặc đơn '' và chỉ có duy nhất 1 kí tự.
- string : giống char nhưng chứa được khoảng 32 bit, tương ứng với khoảng 2^31 kí tự, giá trị được đặt trong dấu ngoặc kép ""
- Ngoài ra, còn có các kiểu dữ liệu unsigned, như unsigned int, unsigned long long,... chỉ có thể chứa số nguyên dương, không thể chứa số nguyên âm, nhưng bù lại chứa được nhiều hơn bản signed của nó (như là int, long long) khoảng 1 bit. unsigned int có giới hạn khoảng từ -2^32 đến 2^32-1 và unsigned long long có giới hạn khoảng từ -2^64 đến 2^64-1
- Các kiểu dữ liệu khác như vector,... sẽ được giải thích trong bài khác, do chúng tương đối phức tạp hơn những kiểu dữ liệu cơ bản
