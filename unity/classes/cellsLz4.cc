

#include "cellsLz4.h"

char* CellsLz4::getError(size_t r) {
    return (char*)LZ4F_getErrorName(r);
}
    
 bool CellsLz4::isError(size_t r){
    return LZ4F_isError(r);
}
    
 size_t CellsLz4::lz4_compress(buffer &inbuf,buffer &outbuf)
    {
        size_t in_len, bound, r;
        //LZ4F_preferences_t stack_settings;
        LZ4F_preferences_t *settings = NULL;
        
        in_len = inbuf.getLen();
        bound = LZ4F_compressFrameBound(in_len, settings);
        {
            char* out = (char*)(malloc(bound));
            r = LZ4F_compressFrame(out, bound, (const void*)inbuf.getPtr(), in_len, settings);
            if (LZ4F_isError(r)) {
                FREE(out);
                return r;
            }
            outbuf.write(out, r);
            FREE(out);
        }
        
        return 0;
    }
    
 size_t CellsLz4::lz4_decompress(buffer &inbuf,  buffer& outbuf)
    {
        size_t in_len;
        const char *p = inbuf.getPtr();
        size_t p_len = in_len = inbuf.getLen();
        
        LZ4F_decompressionContext_t ctx = NULL;
        LZ4F_frameInfo_t info;
        LZ4F_errorCode_t code;
        
        code = LZ4F_createDecompressionContext(&ctx, LZ4F_VERSION);
        if (LZ4F_isError(code)) return code;
        {
            #define OUT_BUFFER_SIZE 65536 //64k
            char *out = (char*)(malloc(OUT_BUFFER_SIZE));
            while (p_len > 0)
            {
                size_t out_len = OUT_BUFFER_SIZE; //64k
                size_t advance = p_len;
                code = LZ4F_decompress(ctx, out, &out_len, p, &advance, NULL);
                if (LZ4F_isError(code)) {
                    FREE(out);
                    goto decompression_failed;
                }
                if (out_len == 0) {
                    free(out);
                    break;
                }
                p += advance;
                p_len -= advance;
                outbuf.write(out, out_len);
            }
            FREE(out);
        }
        
        LZ4F_freeDecompressionContext(ctx);
        return 0;
        
    decompression_failed:
        if (ctx != NULL) LZ4F_freeDecompressionContext(ctx);
        return code;
    }
