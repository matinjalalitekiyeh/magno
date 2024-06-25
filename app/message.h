#ifndef MESSAGE_H
#define MESSAGE_H

#include "net_common.h"

namespace magno::mpi {


template <typename T>
struct message_header {
    T id {};
    uint32_t size = 0;
};

template <typename T>
struct message {
    message_header<T> header;
    std::vector<uint8_t> body;

    //!
    //! \brief size return size of entire message packet in bytes.
    //! \return size of entire message packet in bytes.
    //!
    size_t size() const {
        return sizeof (message_header<T>) + body.size();
    }

    //!
    //! \brief operator << override for std::cout compatiblity - produces friendly description message.
    //!
    friend std::ostream& operator<<(std::ostream& os, const message<T>& msg) {
        return os << "ID: " << int(msg.header.id) << " Size: " << msg.header.size;
    }

    //!
    //! \brief pushes any pod data into the message buffer.
    //!
    template <typename DataType>
    friend message<T>& operator<<(message<T>& msg, const DataType& data) {

        static_assert (std::is_standard_layout<DataType>::value, "Data is too complex - not standard layout.");
        static_assert (std::is_trivial<DataType>::value, "Data is not trivial.");

        // cache current size of vector, as this will be the point we insert the data.
        size_t i = msg.body.size();

        // resize the vector by the sizeof the data being pushed.
        msg.body.resize(msg.body.size() + sizeof (DataType));

        // physically copy the data into the newly allocated vector space.
        std::memcpy(msg.body.data() + i, &data, sizeof (DataType));

        // reallocate the message size.
        msg.header.size = msg.size();

        return msg;
    }

    template <typename DataType>
    friend message<T>& operator>>(message<T>& msg, DataType& data) {

        static_assert (std::is_standard_layout<DataType>::value, "Data is too complex - not standard layout.");
        static_assert (std::is_trivial<DataType>::value, "Data is not trivial.");

        // cache the location towards the end of the vector where the pulled data starts.

        // shrink the vector to remove read bytes, and reset end position.

        // realocate the message size


        return msg;
    }


};





}


#endif // MESSAGE_H
