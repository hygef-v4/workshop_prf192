Khuất Quang Hưng – HE190895

Assignments code tuần 9

1. Giới thiệu bài toán
Chương trình thao tác file CRUD quản lý username và mật khẩu của người
dùng. Cho phép thực hiện các thao tác như tạo người dùng mới, đọc danh sách
người dùng, cập nhật thông tin, xóa thông tin người dùng. Chương trình yêu
cầu người dùng đăng nhập trước khi sử dụng.
2. Chức năng bài toán
A. Giải thuật
Start:
Hiển thị màn hình đăng nhập
Nhập tên người dùng và mật khẩu
Kiểm tra xem tên người dùng và mật khẩu có khớp với các giá trị được định nghĩa
trước không
-Nếu khớp:
 Hiển thị thông báo truy cập được cấp phép
 Tiến hành đến menu chính
-Nếu không khớp:
 Hiển thị thông báo truy cập bị từ chối
 Lặp lại quá trình đăng nhập
Menu chính: Hiển thị các tùy chọn menu:
1. Tạo người dùng
2. Đọc danh sách người dùng
3. Cập nhật thông tin người dùng
4. Xóa người dùng

5. Xóa tất cả người dùng
6. Thoát
Menu hiển thị lặp lại cho đến khi người dùng chọn thoát (6).
Nhập lựa chọn nhập từ bàn phím:
Nếu là 1: Tạo người dùng
 Nếu là 2: Đọc danh sách người dùng
 Nếu là 3: Cập nhật thông tin người dùng
 Nếu là 4: Xóa người dùng
 Nếu là 5: Xóa tất cả người dùng
 Nếu là 6: Thoát chương trình
End
b. Triển khai
1. Hàm đăng nhập (login)
 Hiển thị màn hình đăng nhập.
 Nhập tên người dùng và mật khẩu.
 So sánh với giá trị người dùng và mật khẩu
 Trả về 1 nếu thông tin đúng, ngược lại trả về 0.
2. Hàm tạo người dùng (create_user)
 Nhập tên người dùng và mật khẩu mới.
 Ghi thông tin người dùng vào tệp &quot;users.txt&quot;.
3. Hàm đọc danh sách người dùng (read_users)
 Đọc tất cả thông tin người dùng từ tệp &quot;users.txt&quot;.
 Hiển thị thông tin người dùng trên màn hình.
4. Hàm cập nhật thông tin người dùng (update_user)
 Nhập tên người dùng cần cập nhật.
 Kiểm tra xem tên người dùng có tồn tại không.

 Nếu tồn tại, nhập thông tin mới và cập nhật vào tệp &quot;users.txt&quot;.
5. Hàm xóa người dùng (delete_user)
 Nhập tên người dùng cần xóa.
 Kiểm tra xem tên người dùng có tồn tại không.
 Nếu tồn tại, xóa thông tin người dùng khỏi tệp &quot;users.txt&quot;.
6. Hàm xóa tất cả người dùng (delete_all_users)
 Xóa tất cả thông tin người dùng từ tệp &quot;users.txt&quot;.
III. Kết luận
Trên đây là một chương trình CRUD đơn giản quản lý người dùng và mật khẩu sử
dụng ngôn ngữ lập trình C.
Phụ lục :
Tài liệu tham khảo: slides, stackoverflow, google

Mã nguồn :
https://github.com/hungsct1702/workshop_prf192/tree/final_project
