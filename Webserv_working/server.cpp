/*

Giải thích mã nguồn:

    Tạo Socket:

        Dòng socket(AF_INET, SOCK_STREAM, 0) tạo một socket TCP IPv4.

    Bind Socket:

        Dòng bind() gắn socket với một địa chỉ và cổng (ở đây là cổng 8080).

    Lắng nghe kết nối:

        listen() làm cho server bắt đầu lắng nghe các kết nối đến từ client.

    Chấp nhận kết nối:

        accept() chấp nhận kết nối từ client và tạo một socket mới để giao tiếp với client.

    Nhận và xử lý HTTP request:

        Server sử dụng read() để nhận yêu cầu HTTP từ client. Sau đó, server kiểm tra xem đó có phải là yêu cầu GET / hay không.

        Nếu yêu cầu là GET /, server trả về mã phản hồi 200 (OK), ngược lại trả về mã lỗi 404 (Not Found).

    Gửi phản hồi:

        Dữ liệu phản hồi HTTP được gửi lại client thông qua hàm send().

    Đóng kết nối:

        Sau khi phản hồi được gửi, server đóng kết nối với client bằng close().
*/


#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void processRequest(int new_socket) {
    char buffer[1024] = {0};
    std::string response;

    // Nhận yêu cầu từ client
    read(new_socket, buffer, 1024);

    // Hiển thị yêu cầu nhận được từ client
    std::cout << "Received HTTP request: \n" << buffer << std::endl;

    // Phân tích yêu cầu HTTP
    if (strstr(buffer, "GET / HTTP/1.1") != NULL) {
        // Nếu là yêu cầu GET với đường dẫn "/"
        response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>";
    } else {
        // Nếu không phải yêu cầu GET /, trả về lỗi 404
        response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>";
    }

    // Gửi phản hồi HTTP cho client
    send(new_socket, response.c_str(), response.length(), 0);

    // Đóng kết nối
    close(new_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Tạo socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // Nghe tất cả các địa chỉ IP
    address.sin_port = htons(PORT);  // Lắng nghe trên cổng 8080

    // Gắn socket vào địa chỉ và cổng
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return -1;
    }

    // Lắng nghe kết nối đến từ client
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return -1;
    }

    std::cout << "Server is listening on port " << PORT << "..." << std::endl;

    while (true) {
        // Chấp nhận kết nối từ client
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            return -1;
        }

        // Xử lý yêu cầu HTTP
        processRequest(new_socket);
    }

    return 0;
}
