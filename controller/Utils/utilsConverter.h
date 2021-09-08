#ifndef CPUSTATS_UTILSCONVERTER_H
#define CPUSTATS_UTILSCONVERTER_H
class Converter {
public:
    inline static void ultostr(char* str, UInt32 val);
    inline static float fltToFloat(const unsigned char *str);
    inline static int  ui16ToInteger(const unsigned char* str);
    inline static int sp78ToInteger(const SMCBytes_t bytes);
    inline static int fpe2ToInteger(const SMCBytes_t bytes);
    inline static int ui32ToInteger(const SMCBytes_t bytes);

    template<typename convertedType, typename typeToConvert, size_t size>
    union template_union{
        convertedType value;
        typeToConvert buffer[size];
    };

};

void Converter::ultostr(char *str, UInt32 val) {
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
    return ((unsigned char) bytes[0] << 24) |
           ((unsigned char) bytes[1] << 16) |
           ((unsigned char) bytes[2] << 8) |
           ((unsigned char) bytes[3]);


}


#endif //CPUSTATS_UTILSCONVERTER_H
