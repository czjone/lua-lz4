#ifndef CellsLz4_hpp
#define CellsLz4_hpp

#include <stdio.h>
#include "buffer.h"
extern "C" {
#   include "lz4.h"
#   include "lz4frame.h"
}

class CellsLz4 {
public:
    static char* getError(size_t r);

    static bool isError(size_t r);

    static size_t lz4_compress(buffer &inbuf,buffer &outbuf);

    static size_t lz4_decompress(buffer &inbuf,buffer& outbuf);
};

#endif /* CellsLz4_hpp */
