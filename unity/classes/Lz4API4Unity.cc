#include <string>



    extern "C" int UnityLz4Version(){
        return 001;
    }
    
    extern "C" char * UnityLz4Compress( char* unCompressData){
        size_t len = strlen(unCompressData);
        char * c = (char*)malloc(len);
        memcpy(c, unCompressData, len);
        return c;
    }

    extern "C" char * Unitylz4Decompress( char* compressData){
         size_t len = strlen(compressData);
         char * c = (char*)malloc(len);
         memcpy(c, compressData, len);
         return c;
    }

