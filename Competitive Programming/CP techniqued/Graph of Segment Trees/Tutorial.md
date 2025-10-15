Đây là một kĩ thuật được sử dụng để giải quyết các truy vấn:
  1. Nối đỉnh u đến đỉnh v
  2. Nối đỉnh u đến tất cả các đỉnh trong đoạn l->r
  3. Nối tất cả các đỉnh trong đoạn l->r đến đỉnh u
  4. (mở rộng) nối tất cả các đỉnh trong đoạn l->r đến tất cả các đỉnh đoạn l1->r1
Tất cả truy vấn được xử lí với độ phức tạp tối đa O(log(N)^2)

Ta có thể nhìn nhận kĩ thuật này như sau:
- Lối suy nghĩ xây dựng 2 segment tree cho thao tác nối từ u đến đoạn l->r và từ đoạn l->r đến v là chính xác, tuy nhiên vẫn chưa nghĩ đến việc mô hình hoá 2 segment tree thành 2 đồ thị sau đó nối với đồ thị gốc, tạo thành một đồ thị có hướng, có thể sử dụng dijkstra.
- Do quá tập trung vào suy nghĩ nối đỉnh u với từng đỉnh từ l->r và nối từng đỉnh trong l->r đến v mà nghĩ rằng đồ thị cuối cùng sẽ có N^2 cạnh, gây ra tle, không nghĩ đến việc chỉ nối cạnh đến đỉnh đại diện cho đoạn, trừ bớt đáng kể số lượng cạnh xuống chỉ gần N*logN
=> Nên nghĩ về segment tree theo kiểu, mỗi đoạn được đại diện bằng 1 hoặc nhiều đỉnh kết hợp lại, chứ không phải bằng toàn bộ đỉnh trong đoạn đó.
=> Trong một vài trường hợp, nên xem segment tree như là một đồ thị dạng cây hoàn chỉnh, không đơn thuần là một cấu trúc dữ liệu, là một mảng đơn thuần.
- Kĩ thuật này có thể được sử dụng trong các bài cần phải xây dựng đồ thị khi mà đề bài cho một đỉnh nối đến một đoạn hoặc một đoạn nối đến một đỉnh, hoặc cả hai, hoặc thậm chí là nối các đỉnh trong đoạn này đến các đỉnh trong đoạn kia (tổng quát hoá)

*Tổng quát hoá kĩ thuật:*
Xây dựng 2 đồ thị segment tree, đồ thị đầu tiên nối từ cha xuống con và từ lá xuống đỉnh, đồ thị 2 nối từ đỉnh lên lá và từ đỉnh con đến đỉnh cha trong segment tree.
* Thao tác nối đỉnh - đỉnh: cơ bản
* thao tác nối đỉnh - đoạn: Nối đỉnh trong đồ thị gốc lên các đỉnh đại diện cho đoạn đang xét trong segment tree 1
* Thao tác nối đoạn - đỉnh: Nối các đỉnh đại diện cho đoạn trong segment tree 2 xuống đỉnh trong đồ thị gốc
* Thao tác nối đoạn - đoạn: Nối các đỉnh đại diện cho đoạn trong segment tree 2 đến từng đỉnh đại diện cho đoàn còn lại trong segment tree 1

- Để minh hoạ cho kĩ thuật này, ta sẽ sử dụng bài Codeforces 786B – Legacy: https://codeforces.com/problemset/problem/786/B
- Đối với bài này, chỉ có 3 truy vấn đầu (không có truy vấn nối hai đoạn với nhau), nên code solution của bài này cũng chính là code của kĩ thuật xây dựng đồ thị segment tree với 3 truy vấn đầu tiên
