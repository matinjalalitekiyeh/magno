//#include <iostream>

////#ifdef _WIN32
////#define _WIN32_WINNT 0X0A00
////#endif

////#define ASIO_STANDLONE
////#include <boost/asio.hpp>
////#include <boost/asio/ts/buffer.hpp>
////#include <boost/asio/ts/internet.hpp>
////#include <thread>

//int main(int argc, char **argv)
//{

//    boost::system::error_code ec;

//    // create a "context" - essentially the platform spec interface.
//    boost::asio::io_context context;

//    // get the address of somewhere we wish to connect to
//    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("51.38.81.49", ec), 80);

//    // create socket, the context will deliver the impl
//    boost::asio::ip::tcp::socket socket(context);

//    socket.connect(endpoint, ec);

//    if (!ec) {
//        std::cout << "Connected!" << std::endl;
//    }else{
//        std::cout << "Failed to connect to address\n" << ec.message() << std::endl;
//    }

//    if (socket.is_open()) {

//        std::string sRequest =
//                "Get /index.html HTTP/1.1\r\n"
//                "Host: example.com\r\n"
//                "Connection: close\r\n\r\n";

//        socket.write_some(boost::asio::buffer(sRequest.data(), sRequest.size()), ec);

//        using namespace std::chrono_literals;
//        std::this_thread::sleep_for(5s);

//        size_t bytes = socket.available();
//        std::cout << "Bytes available: " << bytes << std::endl;

//        if (bytes > 0) {
//            std::vector<char> vBuffer(bytes);
//            socket.read_some(boost::asio::buffer(vBuffer.data(), vBuffer.size()), ec);

//            for (auto c : vBuffer)
//                std::cout << c;
//        }
//    }

//    return 0;
//}

#include "message.h"

enum class Custom_msg_type : uint32_t {
    FireBullet,
    MovePlayer
};

int main() {

    magno::net::mpi::message<Custom_msg_type> msg;
    msg.header.id = Custom_msg_type::FireBullet;


    int a = 1;
    bool b = true;
    float c = 3.14159f;

    struct {
        float x,y;
    } d[5];

    msg << a << b << c << d;

    a = 99;
    b = false;
    c = 99.0f;


    msg >> d >> c >> b >> a;



    std::cout << "salam\n";



}




















