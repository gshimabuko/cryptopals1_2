#ifndef __XOR__
#define __XOR__

#include "hex2base64.h"

unsigned char bitwiseXOR(char A, char B);
std::vector<unsigned char> fixedXOR(std::vector<unsigned char> input, std::vector<unsigned char> key);
#endif /* __XOR__ */

