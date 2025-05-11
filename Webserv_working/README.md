🧭 Project Overview

You're going to implement a basic HTTP server (like a mini NGINX or Apache) in C++98:

    Accept and parse HTTP requests

    Send back proper HTTP responses

    Serve files like HTML from a directory

    Be compatible with browsers (curl, Chrome, etc.)

    No crash allowed, must be memory safe

    No external libraries (no Boost!)

🏁 Where to Start
🔹 1. Understand How HTTP Works

You need to know:

    HTTP request/response structure

    Methods: GET, POST, DELETE

    Status codes: 200 OK, 404 Not Found, etc.

👉 Check this MDN HTTP Overview, or I can explain in simple terms.
🔹 2. Learn Basic Socket Programming

This project is essentially network programming. You should get familiar with:

    socket(), bind(), listen(), accept()

    recv() / send() for communication

    poll() or select() for handling multiple clients

💡 If you’ve never written an echo server before, start there.
🔹 3. Prepare for C++98 Constraints

This project uses C++98, meaning:

    No auto, no nullptr, no unordered_map, no regex, etc.

    You’ll rely on basic STL: std::map, std::vector, std::string

    You must write a clean Makefile

✅ Keep code modular using .hpp and .cpp files.
🔹 4. Understand the Config File Parsing

You must support a config file with server details like this:

server {
    listen 8080;
    server_name localhost;
    location / {
        root www/;
        index index.html;
    }
}

You'll need to write your own parser to understand and use these settings in your server logic.
🔹 5. Break Down the Project into Stages
Stage	What to do
1	Build a basic echo server using poll()
2	Understand how browsers send HTTP requests
3	Design Request, Response, Client, ServerConfig classes
4	Implement GET support and serve static files
5	Implement config file parsing
6	Add support for POST, DELETE, error pages
7	(Bonus) Handle CGI execution if required
🔹 6. Test with curl and a Browser

Use curl to simulate requests:

curl -v http://localhost:8080/index.html

Also test in a browser to make sure your server returns correct content and headers.
🧰 Tools You Should Use

    Valgrind or AddressSanitizer → check memory leaks

    GDB → debug crashes

    Wireshark or tcpdump → inspect HTTP traffic (optional but cool)

    lsof / netstat → see open sockets/ports

✅ Final Tip:

Think of this project as building:

    A networking app (low-level sockets)

    A protocol parser (for HTTP)

    A filesystem reader (serve files)

    A mini web framework

If you'd like, I can help you:

    Set up your folder structure

    Write your first echo server

    Create a simple config parser


🧭 Tổng quan dự án

Bạn cần viết một HTTP server giống như NGINX hoặc Apache ở mức cơ bản:

    Nhận và xử lý request HTTP

    Trả về response HTTP

    Chạy được trong trình duyệt thật

    Tuân thủ C++98 (rất hạn chế)

    Không được dùng thư viện ngoài (Boost, v.v.)

🏁 Bắt đầu từ đâu?
🔹 1. Hiểu cơ bản về HTTP

Nếu bạn chưa rõ:

    Cách hoạt động của HTTP (Request/Response)

    Các phương thức: GET, POST, DELETE

    Các status code: 200 OK, 404 Not Found, 500 Internal Server Error

👉 Hãy đọc Mozilla HTTP Overview hoặc mình có thể giải thích đơn giản cho bạn.
🔹 2. Ôn lại / học về Socket Programming

Vì bạn đang viết server, bạn phải hiểu:

    socket(), bind(), listen(), accept()

    recv() và send()

    select(), poll() hoặc epoll() (hoặc kqueue nếu macOS)

    Nếu bạn chưa viết một "echo server" bằng C/C++ thì nên bắt đầu từ đó trước.

🔹 3. Cấu trúc chương trình và C++98

C++98 không có:

    std::unordered_map, std::regex, auto, range-based for, nullptr...

Nên bạn cần:

    Tổ chức rõ class, header .hpp, .cpp

    Dùng các STL cũ (std::map, std::vector, std::string)

    Viết Makefile đúng chuẩn

🔹 4. Đọc kỹ yêu cầu trong file cấu hình

Bạn sẽ phải parse một file cấu hình giống như:

server {
    listen 8080;
    server_name localhost;
    location / {
        root www/;
        index index.html;
    }
}

Bạn cần tự viết parser để hiểu file này và dùng nó để cấu hình server.
🔹 5. Chia nhỏ bài toán
🧱 Gợi ý tiến trình thực hiện:
Giai đoạn	Nội dung chính
1	Viết echo server đơn giản bằng poll()
2	Phân tích HTTP request từ browser
3	Tạo cấu trúc Request, Response, Client, ServerConfig, Router, v.v.
4	Viết bộ xử lý response GET
5	Viết parser cho file cấu hình
6	Xử lý POST, DELETE, Error page
7	Xử lý CGI (nếu có trong bonus)
🔹 6. Test với curl và browser

Dùng lệnh curl để gửi request từ terminal:

curl -v http://localhost:8080/index.html

🧰 Công cụ hỗ trợ

    tcpdump hoặc Wireshark – để quan sát gói tin HTTP

    valgrind hoặc ASan – để kiểm tra memory leak

    gdb/lldb – để debug

Nếu bạn muốn, mình có thể:

    Tạo cho bạn một kế hoạch từng bước

    Giải thích chi tiết cách viết poll() server

    Review code bạn đã có




	🎯 MỤC TIÊU CUỐI CÙNG

Tạo một web server có thể:

    Nhận và phân tích các yêu cầu HTTP (GET, POST, DELETE,...)

    Trả về nội dung HTML (hoặc các tệp khác) tới trình duyệt

    Hoạt động ổn định, không crash, không rò rỉ bộ nhớ

    Không dùng thư viện bên ngoài, chỉ dùng C++98 và các system call


****	

🧭 LỘ TRÌNH TỪNG BƯỚC
🔰 BƯỚC 1: Viết echo server dùng poll()

👉 Mục tiêu:

    Lắng nghe kết nối từ nhiều client

    Gửi lại dữ liệu client gửi đến (giống chat đơn giản)

✅ Kiến thức cần học:

    socket(), bind(), listen(), accept()

    recv(), send()

    poll() để xử lý nhiều client

🛠️ Sau bước này, bạn sẽ hiểu rõ cách server hoạt động với client.

🔰 BƯỚC 2: Phân tích yêu cầu HTTP

👉 Mục tiêu:

    Nhận và phân tích HTTP request từ trình duyệt hoặc curl

Ví dụ yêu cầu:

GET /index.html HTTP/1.1
Host: localhost:8080
User-Agent: curl/7.68.0

✅ Viết class Request để lưu:

std::string method;
std::string path;
std::string version;
std::map<std::string, std::string> headers;
std::string body;

🧪 Dùng curl -v http://localhost:8080/index.html để test.

🔰 BƯỚC 3: Gửi phản hồi HTTP cơ bản

👉 Mục tiêu:

    Gửi phản hồi với nội dung HTML đơn giản

Ví dụ:

HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: 35

<html><body>Hello</body></html>

✅ Viết class Response để build phản hồi dựa vào yêu cầu.

🔰 BƯỚC 4: Phục vụ file tĩnh từ thư mục

👉 Mục tiêu:

    Khi client yêu cầu /index.html, server tìm và trả nội dung tệp thật.

✅ Sử dụng open(), read() hoặc ifstream để đọc file.
✅ Xác định kiểu file (HTML, JPG, PNG) từ phần mở rộng .html, .css,...
🔰 BƯỚC 5: Phân tích file cấu hình

👉 Mục tiêu:

    Đọc file .conf để lấy thông tin:

        listen, server_name, root, index, error_page,...

✅ Viết class ServerConfig hoặc ConfigParser.

Ví dụ file config:

server {
  listen 8080;
  server_name localhost;
  root www/;
  index index.html;
}

🔰 BƯỚC 6: Hỗ trợ nhiều phương thức (POST, DELETE)

✅ POST: nhận nội dung từ client và lưu vào file
✅ DELETE: xóa file khỏi hệ thống
✅ Trả về các mã lỗi phù hợp: 404, 500, 403,...
🔰 BƯỚC 7: Cấu trúc lại project bằng class

👉 Mục tiêu:

    Quản lý logic rõ ràng hơn bằng các class như:

Class	Chức năng
Server	Quản lý socket, lắng nghe
Client	Thông tin kết nối client
Request	Lưu thông tin HTTP request
Response	Tạo phản hồi HTTP
Router	Xử lý logic route và config
ConfigParser	Phân tích file config


***

