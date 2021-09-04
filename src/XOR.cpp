#include <iostream>
#include <vector>
#include "hex2base64.h"

unsigned char bitwiseXOR(char A, char B)
{
    unsigned char C;
    if(A == B)
    {
        C = '0';
    }
    else if((A == '1') || (B == '1'))
    {
        C = '1';
    }
    else
    {
        C = '0';
    }
    return(C);
}
std::vector<unsigned char> fixedXOR(std::vector<unsigned char> input, std::vector<unsigned char> key)
{
    std::vector<unsigned char> binString;
    std::vector<unsigned char> binKey;
    std::vector<unsigned char> binXOR;
    std::vector<unsigned char> hexXOR;
    binString = hex2bin(input);
    binKey = hex2bin(key);
    std::cout << "\n";
    for (long unsigned int i = 0; i < binString.size(); i++)
    {
        binXOR.push_back(bitwiseXOR(binString[i], binKey[i]));
        //std::cout << binXOR[i] << " ";
    }
    //std::cout << "\n";
    hexXOR = bin2hex(binXOR);
    return(hexXOR);
}

