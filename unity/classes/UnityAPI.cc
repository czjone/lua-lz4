#include <string>
#include "cellsLz4.h"
#include "buffer.h"
#include "base64.h"


#define UNITY_API extern "C"
#define LZ4_VERSION "0.0.4"
/*
 
 #define BASE_64_STRING 0 //enable base64 data each control.
 
inline  char * convert_buffer_2_unitystring(buffer & buffer){
#if(BASE_64_STRING>0)
    Base64 base;
    std::string ret = base.Encode(buffer.getPtr(), buffer.getLen());
    size_t len = ret.length();
    char * c = (char*)malloc(len + 1);
    bzero(c, len + 1);
    memcpy(c, ret.c_str(), len); //maby memory leaks.
#else
    size_t len = buffer.getLen();
    char * c = (char*)malloc(len + 1);
    bzero(c, len + 1);
    memcpy(c, buffer.getPtr(), len); //maby memory leaks.
#endif
    
    return c;
}

UNITY_API  char * UnityLz4Version(){
    size_t len = strlen(LZ4_VERSION);
    char * c = (char*)malloc(len);
    memcpy(c, LZ4_VERSION, len);
    return c;
}

UNITY_API  char * UnityLz4Compress(  char* unCompressData,int len){
#if(BASE_64_STRING>0)
    Base64 base;
    std::string str = base.Decode(unCompressData, len);
    unCompressData = (char*)str.c_str();
    len = (int)str.length();
#endif
    buffer inbufer(unCompressData,len); inbufer.rePos();
    buffer outbuffer;
    CellsLz4::lz4_compress(inbufer, outbuffer);
    outbuffer.rePos();
    return convert_buffer_2_unitystring(outbuffer);
}

UNITY_API  char * Unitylz4Decompress(  char* compressData,int len){
#if(BASE_64_STRING>0)
    Base64 base;
    std::string str = base.Decode(compressData, len);
    compressData = (char*)str.c_str();
    len = (int)str.length();
#endif
    buffer inbuffer(compressData,len);inbuffer.rePos();
    buffer outbuffer;
    CellsLz4::lz4_decompress(inbuffer, outbuffer);
    outbuffer.rePos();
    return convert_buffer_2_unitystring(outbuffer);
}

//UNITY_API int UnityLuaLz4Init(void* inL ){
////    lua_State * L = static_cast<lua_State*>(inL);
////    return luaopen_lz4(L);
//    return -1;
//
//}
*/

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

