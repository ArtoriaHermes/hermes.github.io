Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=897

Tóm tắt: Cho ba số N, M và K, đồng thời cho N phần tử, mỗi phần tử có độ dài v[i] và thuộc "phân loại" t[i], sau đó ta có M dòng, mỗi dòng chứa một trong các chữ số in hoa e[i] từ A -> B. Với mỗi dòng trong M dòng, ta phải chọn các phần tử trong N phần tử, sao cho tổng các độ dài v[i] của các phần tử được chọn là k, đồng thời các dòng có cùng loại e[i] có phần tử cuối cùng thuộc cùng một "phân loại". Ngoài ra, các dòng có e[i] khác nhau không nhất thiết phải kết thúc bằng 2 phần tử khác phân loại.

Test mẫu:

Input:
3 3 10
3 1
4 1
3 2
A
B
A

Ouput:
960

Phân tích test: Cho n=3, m=3 và k=10, tức là có m dòng và mỗi dòng phải chọn các phần tử sao cho tổng độ dài v[i] của tất cả phần tử là 10. Hai dòng 1 và 3 có cùng e[i] là A, do đó hai dòng này phải kết thúc bằng 2 phần tử có cùng phân loại, ví dụ như phần tử thứ 1 và 2 (có cùng phân loại t[i] = 1).

*SOLUTION* 
-- Chỉ đọc khi không thể làm được nữa

Ta thấy rằng, các dòng có cùng e[i] thì kết thúc bằng 2 phần tử cùng phân loại, thế thì suy ra ta có thể đếm số cách chọn các phần tử sao cho tổng độ dài v[i] bằng k, đồng thời kết thúc bằng một phần tử nào đó thuộc phân loại j, sau đó ta lại lấy số cách này luỹ thừa lên số lần e[i] xuất hiện trong M dòng => Vậy là ta đã có thể tính số cách chọn các phần tử cho từng dòng thuộc một loại e[i] nào đó sao cho tất cả các dòng đều kết thúc bằng các phần tử thuộc cùng một phân loại

Cụ thể hơn, ta gọi max_class là giá trị t[i] (giá trị phân loại) tối đa, gọi dp[i][j] là số cách để chọn các phần tử sao cho tổng độ dài v[i] của tất cả phần tử bằng i và phần tử đứng cuối trong cách lựa chọn hiện tại thuộc phân loại j. Với một phân loại j nhất định sao cho j >= 1 và j <= max_class, thì cách chọn các phần tử sao cho tổng độ dài bằng k và kết thúc với một phần tử thuộc phân loại j là dp[k][j]

Ta thấ rằng: max_class <= N, mà theo giới hạn của đề bài thì N <= 5000 và K <= 5000 => K*N <= 5000^2 => Không TLE

Vậy nên việc ta cần làm là tìm dp[k][j] với mọi 1 <= j <= max_class, sau đó với từng e[i], gọi x là số lần xuất hiện e[i] trong M dòng, thì số cách chọn cho tất cả các dòng có loại e[i], gọi là res, sẽ là tổng của mọi dp[k][j]^x với 1 <= j <= max_class. Gọi biến ans là kết quả cuối cùng, biến ans ban đầu bằng 1, thì ans sẽ bằng tích của tất cả res tương ứng với từng e[i], nói cách khác: ans = res1 * res2 * res3 *...

dp[k][j]^x sẽ được tính trong độ phức tạp O(logx) với thuật toán luỹ thừa nhị phân
