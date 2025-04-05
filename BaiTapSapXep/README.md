# Cơ sở
# Bài 3
Để biết thời gian thực hiện các thuật toán thì ta sử dụng clock trong thư viện time.h

Thuật toán	Thời gian trung bình (ms)	Độ phức tạp trung bình
Selection	  94	                      O(n2)
Insertion	  2	                        O(n2)
HeapSort	  1	                        O(nlogn)
BubbleSort	90	                      O(n2)
MergeSort	  1	                        O(nlogn)
QuickSort	  0.8	                      O(nlogn)

Nhận xét
Selection Sort có hiệu suất rất chậm với n = 10000, không phù hợp với mảng lớn.

Insertion Sort có hiệu suất nhanh hơn nhiều so với Selection và Bubble nhưng vẫn thua các thuật toán có độ phức tạp O(nlogn).

Heap Sort có hiệu suất rất nhanh, hiệu quả cho mảng lớn nhưng không phải nhanh nhất.

Bubble Sort có hiệu suất chậm, tương tự như Selection, chỉ phù hợp với mảng rất nhỏ.

Merge Sort có hiệu suất rất nhanh, tốt cho mảng lớn và ổn định.

Quick Sort có hiệu suất nhanh nhất, là lựa chọn tối ưu cho mảng lớn có dữ liệu ngẫu nhiên, vượt trội về tốc độ.

# Bài 4
So sánh hiệu suất (n=30000)

Thuật toán	Thời gian trung bình (ms)	Độ phức tạp trung bình	Nhận xét
Selection	  885	                      O(n2)	                  Chậm, số lần so sánh cố định
Insertion	  447	                      O(n2)	                  Nhanh nhất trong nhóm O(n2)
HeapSort	  3	                        O(nlogn)	              Nhanh, ổn định, ít bộ nhớ hơn Merge
BubbleSort	2224	                    O(n2)	                  Chậm, không tối ưu
MergeSort	  5	                        O(nlogn)	              Ổn định, nhanh, cần bộ nhớ phụ

