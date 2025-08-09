Trong bài viết này, mình sẽ giải thích về thuật toán đường đi Euler một cách đơn giản nhất có thể

*Cây là gì?*
  - Giải thích một cách đơn giản thì, một đồ thị *vô hướng và liên thông* có N đỉnh được gọi là cây khi nó có N-1 cạnh. Để dễ hình dung thì, trong đồ thị cây, từ một đỉnh luôn có thể đi đến những đỉnh còn lại, và có chính xác N-1 cạnh.
  - Nhờ định nghĩa này mà ta có một số nhận xét khá thú vị, trước hết ta sẽ hình dung một đồ thị cây theo kiểu "tầng lớp", để dễ hinh dung hơn có thể nhìn hình ở phía dưới:

  <img width="528" height="528" alt="graph (1)" src="https://github.com/user-attachments/assets/a5bea1e8-280c-459e-9478-50b23d34f4c5" />

  - Dễ dàng thấy rằng, cây có một cấu trúc "tầng", trong ảnh trên thì đỉnh 1 là tầng 1, đỉnh 2 và 5 là tầng 2 và đỉnh 3, 4 là tầng 3, trong một cây thì mỗi đỉnh chỉ có 1 tổ tiên trực tiếp, hay còn gọi là cha, chính là đỉnh nối trực tiếp với đỉnh đó và nhỏ hơn đỉnh đó 1 tầng
  - Ta sẽ gọi các đỉnh trong đồ thị cây là "nốt"
  - Trừ các nốt ở tầng thấp nhất ra, mỗi nốt khác đều có các nốt con, là các nốt có cạnh trực tiếp với nốt đó và lớn hơn nốt đó 1 tầng
  - Khi có nốt con, thì nốt hiện tại sẽ được gọi là một "cây con", còn nốt không có nốt cha thì sẽ là "gốc cây" (root). Xét ảnh trên thì nốt 1 là gốc cây, và nốt 2 là một cây con, chứa nốt 3 và 4. Tất nhiên, một cây con có thể chứa nhiều cây con.
  - 
*Thuật toán đường đi Euler*
  - Đường đi Euler, hay còn gọi là Euler tour, là một thuật toán dùng để "dàn phẳng" một đồ thị hình cây thành một dãy 1 chiều, mô tả lại quá trình duyệt qua đồ thị cây
  - Vẫn lấy ví dụ là hình ảnh trên, đường đi euler sẽ được mô tả như sau:
    + Xuất phát từ nốt 1, ta đi xuống nốt 2
    + Từ nốt 2, ta đi xuống nốt 3, sau đó vòng lên nốt 2 lại
    + Sau khi vòng lên nốt 2, ta đi xuống nốt 4 rồi lại vòng lên nốt 2
    + Sau khi duyệt qua hết các nốt con trong cây con có gốc là 2, ta vòng lên nốt 1, còn là gốc cây
    + Từ nốt 1, ta đi xuống nốt 5 rồi lại vòng lên nốt 1
    + Lúc này, do đã duyệt qua tất cả các cây con nên đường đi euler đến đây là kết thúc
  - Sau quá trình đó, ta sẽ có mảng đường đi euler chính là: [1, 2, 3, 2, 4, 2, 1, 5, 1], lúc này thì bắt đầu từ 1, chỉ số i trong mảng đường đi euler chính là "Thời điểm" duyệt đến nốt có chỉ số i trong đường đi euler. Số lượng phần tử trong mảng đường đi euler được tính bằng công thức 2N-1, với N là số đỉnh trong cây.
  - Hiện tại ta sẽ có thêm 2 hàm, đầu tiên là first[x], chính là thời điểm duyệt qua nốt x đầu tiên và last[x] chính là thời điểm cuối cùng duyệt qua nốt x trong đường đi euler.
  - 
*Ứng dụng của đường đi euler?*
  - Hiện tại, có một số tính chất của đường đi euler mà ta có thể áp dụng, một trong những tính chất quan trọng nhất có thể được miêu tả như thế này:
    + Nốt v nằm trong cây con có gốc là nốt u *khi và chỉ khi* first[u] <= first[v] <= last[v] <= last[u]
  - Tính chất này có thể giúp giải quyết các bài toán yêu cầu xác định xem nốt v có thuộc cây con gốc u không trong độ phức tạp thời gian O(1), với khâu tiền xử lí tốn độ phức tạp chính xác là O(2N-1), có thể quy gọn thành O(N), rất nhanh.
  - 
*Áp dụng vào bài toán tìm tổ tiên chung gần nhất (LCA)*
  - Nếu có tổ tiên trực tiếp thì cũng có tổ tiên xa. Tổ tiên xa v của nốt u là nốt có tầng có giá trị thấp hơn giá trị của tầng của u, và không có cạnh nối trực tiếp với u, đồng thời u có thể đến được v thông qua các cạnh nối trực tiếp giữa các nốt và chỉ có thể đi lên các tầng có giá trị thấp hơn, không được đi xuống các tầng có giá trị cao hơn.
  - Vẫn áp dụng ảnh trên, một trong tổ tiên xa của nốt 4 là nốt 1, tuy nhiên nốt 5 không phải tổ tiên xa của nốt 4 dù có tầng giá trị thấp hơn.
  - Tổ tiên chung gần nhất, Lowest Common Ancestor, viết tắt là LCA của 2 đỉnh u và v, là tổ tiên (trực tiếp hoặc xa) của cả u và v sao cho có tầng có giá trị thấp nhất. Ví dụ, ở hình trên, LCA của 3 và 4 là 2, và LCA của 4 và 5 là 1. Có thể hiểu LCA là cây con đầu tiên, xét từ tầng dưới lên, chứa cả u và v.
  - Thường thì để tìm LCA của u và v trong mỗi truy vấn, cần phải dùng thuật toán *nhảy nhị phân*, thường tốn độ phức tạp O(logN) mỗi truy vấn. Nhưng ta có thể dùng Euler Tour để tiền xử lí trong O(NlogN), và xử lí mỗi truy vấn trong O(1).
  - Để thực hiện điều này, ta cần kết hợp *Euler tour* và cấu trúc dữ liệu *Bảng thưa (Sparse Table)*, sẽ đề cập trong một bài viết khác
  - Cụ thể thì, để tìm LCA của u và v, ta cần lấy first[u] và first[v], tạo thành một đoạn từ min(first[u], first[v]) đến max(first[u], first[v]), lúc này ta sẽ tìm nốt có tầng có giá trị thấp nhất và có thời điểm duyệt nằm trong đoạn min(first[u], first[v]) đến max(first[u], first[v]). Nốt đó chính là LCA của u và v.
  - 
*Tại sao cách này đúng?*
  - Giả sử ta duyệt đến u trước v (first[u] < first[v]). Ta biết rằng khi thực hiện đường đi euler, ta sẽ phải "vòng ngược lên" các nốt có tầng có giá trị thấp hơn, lúc này khi thực hiện đường đi euler từ u đến v, ta cũng sẽ "đi qua" LCA của u và v.
  - Nói cách khác, first và last của LCA không cần nằm trong đoạn giữa first[u] và first[v], chỉ cần ta duyệt đến đỉnh LCA lúc duyệt từ nốt u đến nốt v là được.
  - Tại sao lại phải lấy nốt có độ sâu có giá trị thấp nhất? Đó là vì nốt đó chính là cây con chứa cả u và v. Ta xem lại định nghĩa về tổ tiên xa, để đến tổ tiên xa v của nốt u, nốt u cần phải đi lên chứ không được đi xuống. Nói cách khác thì đường đi đến LCA của u và v, bắt đầu từ v, chỉ có thể theo kiểu, từ u "leo" dần lên LCA, sau đó mới "leo" xuống v.
  - Nếu ta chọn một nốt có tầng không phải giá trị thấp nhất trong đoạn đó, đồng nghĩa với việc sau đó ta lại phải leo lên nốt có tầng là giá trị thấp nhất, rồi mới có thể hạ xuống v => Không đúng.
  - Để tìm đỉnh có tầng giá trị thấp nhất, ta có thể dùng bảng thưa để tìm trong O(1).
