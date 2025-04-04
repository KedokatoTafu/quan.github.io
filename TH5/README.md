# Bài 005
Số lượng nút một con trong cây nhị phân bằng 1 cộng số lượng nút một con trong cây nhị phân con trái cộng số lượng nút một con trong cây nhị phân con phải nếu nút gốc có một con. Ngược lại số lượng nút một con trong cây nhị phân bằng số lượng nút một con trong cây nhị phân con trái cộng số lượng nút một con trong cây nhị phân con phải.

# Bài 006
•	Số nút trong cây nhị phân tìm kiếm bằng số nút trong cây nhị phân tìm kiếm trong cây con trái cộng số nút trong cây nhị phân tìm kiếm trong cây con phải cộng 1.
•	Tổng giá trị các nút trong cây tìm kiếm bằng tổng giá trị các nút trong cây nhị phân tìm kiếm con trái cộng tổng giá trị các nút trong cây nhị phân tìm kiếm con phải cộng giá trị tại nút gốc.

# Bài 33
•	Duyệt cây nhị phân (NLR) dùng Stack:
Khởi tạo stack rỗng và push node gốc vào, lặp khi stack không rỗng:
-	Pop node đầu stack, in giá trị (N).
-	Push nhánh phải trước (R).
-	Push nhánh trái sau (L).
Do stack là LIFO (Last In First Out), nhánh trái sẽ được xử lý trước nhánh phải, đúng thứ tự NLR.

•	Duyệt cây nhị phân theo mức dùng Queue:
Khởi tạo queue rỗng và enqueue node gốc, lặp khi queue không rỗng:
-	Dequeue node đầu queue, in giá trị.
-	Enqueue nhánh trái (nếu có).
-	Enqueue nhánh phải (nếu có).
Do queue là FIFO (First In First Out), các node ở cùng mức được xử lý trước khi sang mức tiếp theo.

