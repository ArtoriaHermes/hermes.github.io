<img width="1481" height="809" alt="image" src="https://github.com/user-attachments/assets/752a4c6f-3d2b-4f67-8bad-a4986fd66524" />

<img width="651" height="251" alt="image" src="https://github.com/user-attachments/assets/3585d31e-10e2-4a4c-aeda-d64d91d534d1" />

  Trong bài này, ta chỉ nói đến cách để AC bài toán này. Ta thấy rằng từ giới hạn gốc: n <= 10^6 và i <= 10^15, tức là ta có thể tạo ra một dãy các số fibonacci bắt đầu từ vị trí thứ i. 
  
  Để thực hiện điều này, ta sử dụng nhân ma trận, chỉ tốn độ phức tạp O(logN). Ta cũng chỉ cần tạo ra số fibonacci thứ i và i+1 rồi tính các số fibonacci sau đó bằng phương pháp lặp rồi tình bình thường, lấy f[i] = f[i-1] + f[i-2]. 
  
  Thông qua một vài quan sát, ta có thể dễ dàng thấy được, nếu muốn chọn một dãy con có tổng chia hết cho k thì cách đơn giản nhất là chia lấy dư tất cả số fibonacci trong dãy cho k, sau đó tìm xem có dãy con nào tổng bằng k hoặc bằng 0 hay không. Do đó từ lúc tính số fibonacci thứ i và i+1 cũng như tính các số fibonacci sau đó, ta luôn chia lấy dư cho k => Giải quyết được vấn đề về độ lớn của số

  Thế vấn đề còn lại là gì? Là làm thế nào để tìm ra dãy con có tổng chia hết cho k. Từ đề bài, ta xác nhận là dãy con không cần liên tiếp, đồng thời do ta đã chia lấy dư cho k từ trước nên bài toán trở thành: tìm dãy con không liên tiếp có tổng bằng k hoặc bằng 0. Để giải bài toán này, phương pháp quy hoạch động tối ưu nhất cũng tốn mất O(n*k). Thế thì phải làm sao? Đó là lợi dụng tính chất đặc biệt của dãy fibonacci

  Ai cũng biết dãy fibonacci có từng phần tử f[i] = f[i-1] + f[i-2], vậy điều này có nghĩ là gì? Có nghĩa là mỗi phần tử đều có thể được "truy vết" và "đẩy xuống" các phần tử nhỏ hơn. Nghe khá khó hiểu nhỉ? Là thế này: f[i] = f[i-1] + f[i-2], ta lại phân tích ra f[i] = f[i-2]+f[i-3] + f[i-3]+f[i-4] = f[i-3]+f[i-4] + f[i-3] + f[i-3]+f[i-4] = 3*f[i-3] + 2*f[i-4]. Thấy gì không? Từ công thức dựa trên f[i-1] và f[i-2] lại bị "đẩy xuống" f[i-3] và f[i-4]. Tương tự, ví dụ khi ta chọn hai phần tử f[i-8], f[i-5] và f[i], rõ ràng không liên tiếp ta lại có thể phân tích tổng f[i-8] + f[i-5] + f[i] thành:
  f[i-8] + f[i-5] + f[i] = f[i-8] + f[i-6] + f[i-7] + 3*f[i-3] + 2*f[i-4] = f[i-8] + f[i-7] + f[i-6] + 3*(f[i-4]+f[i-5]) + 2*(f[i-5] + f[i-6])
  = f[i-8] + f[i-7] + f[i-6] + 2*f[i-5] + 2*f[i-6] + 3*f[i-4] + 3*f[i-5]
  = f[i-8] + f[i-7] + 3*f[i-6] + 5*f[i-5] + 3*f[i-4]

  Thấy gì không? Từ 3 số fibonacci không liên tiếp là f[i-8], f[i-5] và f[i] lại trở thành tổng liên tiếp từ f[i-8] đến f[i-4]
  => Từ đó ta nhận xét: từ mọi số fibonacci không liên tiếp đều có thể phân tích thành tổng một dãy fibonacci liên tiếp
  Từ đó ta rút ra nhận xét gì khác?
  => Nếu tồn tại một cách chọn các số fibonacci không liên tiếp có tổng chia hết cho k thì luôn có cách chọn các số fibonacci *liên tiếp* có tổng chia hết cho k

  Vậy thì lỡ như hệ số của các phần tử trong dãy liên tiếp không giống như các phần tử không liên tiếp thì sao?
  => Do đã chia lấy dư cho k nên hệ số thế nào cũng không quan trọng

  Vây nên từ đây, ta nhận thấy rằng chỉ cần sử dụng prefix sum bình thường là có thể tìm ra được dãy con có tổng chia hết cho k
