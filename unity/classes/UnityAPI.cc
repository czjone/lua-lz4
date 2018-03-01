#include <string>
#include "cellsLz4.h"
#include "buffer.h"
#include "base64.h"

#if _WINDOWS
#	define UNITY_API  extern "C" _declspec(dllexport) 
#else
#	define UNITY_API extern "C"
#endif
#define LZ4_VERSION "0.0.4"

UNITY_API char * UnityLz4Version(){
    size_t len = strlen(LZ4_VERSION);
    char * c = (char*)malloc(len);
    memcpy(c, LZ4_VERSION, len);
    return c;
}

UNITY_API int UnityLz4Compress(  char* unCompressData,int len,char* outData){
    buffer inbufer(unCompressData,len); inbufer.rePos();
    buffer outbuffer;
    int ret =(int)CellsLz4::lz4_compress(inbufer, outbuffer);
    if(ret !=0) return ret;
    memcpy(outData, outbuffer.getPtr(), outbuffer.getLen());
    return (int)(outbuffer.getLen());
}

UNITY_API int Unitylz4Decompress(  char* compressData,int len,char *outData){
    buffer inbuffer(compressData,len);inbuffer.rePos();
    buffer outbuffer;
    int ret =(int) CellsLz4::lz4_decompress(inbuffer, outbuffer);
    if(ret !=0) return ret;
    memcpy(outData, outbuffer.getPtr(), outbuffer.getLen());
    return (int)(outbuffer.getLen());
}

UNITY_API int UnityLuaLz4Init(void* inL ){
//    lua_State * L = static_cast<lua_State*>(inL);
//    return luaopen_lz4(L);
    return -1;

}

