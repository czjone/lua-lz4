#ifndef __CORE_BASE64
#define __CORE_BASE64 1
#include <string>
using namespace std;

class Base64{
private:
    std::string _base64_table;
    static const char base64_pad = '=';
public:
    Base64();
    std::string Encode(const char * str,size_t size);
    std::string Decode(const char *str,size_t size);
};

#endif
