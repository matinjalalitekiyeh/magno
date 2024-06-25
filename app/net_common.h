#ifndef NET_COMMON_H
#define NET_COMMON_H

#include <memory>
#include <thread>
#include <mutex>
#include <deque>
#include <optional>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdint>

#ifdef _WIN32
#define _WIN32_WINNT 0X0A00
#endif

#define ASIO_STANDLONE
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

#endif // NET_COMMON_H
