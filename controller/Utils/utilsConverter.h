#ifndef CPUSTATS_UTILSCONVERTER_H
#define CPUSTATS_UTILSCONVERTER_H

#include "../smc.h"

class Converter {
public:
    inline static UInt32 strToUl(const char* str, int size, int base);
    inline static void ulToStr(char* str, UInt32 val);
    inline static float fltToFloat(const unsigned char *str);
    inline static void floatToFlt(float str, SMCBytes_t& returnBuffer);
    inline static int  ui16ToInteger(const unsigned char* str);
    inline static int sp78ToInteger(const SMCBytes_t bytes);
    inline static int fpe2ToInteger(const SMCBytes_t bytes);
    inline static int ui32ToInteger(const SMCBytes_t bytes);
    inline static double convertToFahrenheit(const double& celsius);
    template<typename convertedType, typename typeToConvert, size_t size>
    union template_union{
        convertedType value;
        typeToConvert buffer[size];
    };

};


UInt32 Converter::strToUl(const char *str, int size, int base) {
    UInt32 total = 0;
    for (int i = 0; i < size; i++) {
        if (base == 16)
            total += str[i] << (size - 1 - i) * 8;
        else
            total += (unsigned char)(str[i] << (size - 1 - i) * 8);
    }

    return total;
}

void Converter::ulToStr(char *str, UInt32 val) {
    str[0] = '\0';
    sprintf(str, "%c%c%c%c",
            (unsigned int)val >> 24,
            (unsigned int)val >> 16,
            (unsigned int)val >> 8,
            (unsigned int)val);
}

float Converter::fltToFloat(const unsigned char *str) {
    template_union<float, char, 4> floatType;
    for(int i =0; i< 4; i ++)
        floatType.buffer[i] = str[i];
    return floatType.value;
}

int Converter::ui16ToInteger(const unsigned char *str) {
    template_union<int, char, 2> integerType;
    integerType.buffer[0] = str[0];
    integerType.buffer[1] = str[1];
    return abs(integerType.value);
}

int Converter::sp78ToInteger(const char *bytes) {
    return (bytes[0] * 256 + (unsigned char)bytes[1]);
}

int Converter::fpe2ToInteger(const char *bytes) {
    return ((unsigned char)bytes[0] * 256 + (unsigned char)bytes[1]);
}

int Converter::ui32ToInteger(const char *bytes) {

    //if little endian
    if(BYTE_ORDER == LITTLE_ENDIAN)
        return ((unsigned char) bytes[0] << 24) |
               ((unsigned char) bytes[1] << 16) |
               ((unsigned char) bytes[2] << 8) |
               ((unsigned char) bytes[3]);
    else
        return
                ((unsigned char) bytes[0]) |
                ((unsigned char) bytes[1]) |
                ((unsigned char) bytes[2]) |
                ((unsigned char) bytes[3]);

}

double Converter::convertToFahrenheit(const double &celsius) {
    return (celsius * (9.0 / 5.0)) + 32.0;
}

void Converter::floatToFlt(float str, SMCBytes_t& returnBuffer) {
    template_union<float, unsigned char, 32> x;
    memset(&x.buffer, 0, 32);
    \
    x.value = str;
    std::cout<<"x.buffer: "<<x.buffer<<std::endl;
    memcpy(returnBuffer,(signed char *)x.buffer, 32);

    std::cout<<"returnBuffer: "<<returnBuffer<<std::endl;
}


#endif //CPUSTATS_UTILSCONVERTER_H
