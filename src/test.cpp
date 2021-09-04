#include <iostream>
#include <vector>
#include "hex2base64.h"
#include "XOR.h"

int defaultTest()
{
    std::string origin = "1c0111001f010100061a024b53535009181c";
    std::string keyString = "686974207468652062756c6c277320657965";
    std::vector<unsigned char> input(origin.begin(), origin.end());
    std::vector<unsigned char> key(keyString.begin(), keyString.end());
    std::vector<unsigned char> hexOutput;
    for (long unsigned int i = 0; i < input.size(); i++)
    {
        std::cout << input[i];
    }
    std::cout << "\n";
    for (long unsigned int i = 0; i < key.size(); i++)
    {
        std::cout << key[i];
    }
    std::cout << "\n";
    hexOutput = fixedXOR(input, key);
    for (long unsigned int i = 0; i < hexOutput.size(); i++)
    {
        std::cout << hexOutput[i];
    }
    std::cout << "\n";
    return(0);
}
int expectedOutputTest()
{
    std::string origin;
    std::string destin;
    std::vector<unsigned char> base64String;
    

    std::cout << "Please, enter the Input String in hex: \n";
    std::cin >> origin;
    std::cout << "Please, enter the expected output in base 64: \n";
    std::cin >> destin;
    
    std::vector<unsigned char> hexString(origin.begin(), origin.end());
    std::vector<unsigned char> expectedOutput(destin.begin(), destin.end());

    base64String = bin2base64(hex2bin(hexString));

    std::cout << "The output generated was: \n";
    for (long unsigned int i = 0; i < base64String.size(); i++)
    {
        std::cout << base64String[i];
    }
    std::cout << "\n";

    if (base64String == expectedOutput)
    {
        std::cout << "The output is correct.\n";
    }
    else
    {
        std::cout << "the output is incorrect.\n";
    }
    return(0);
}
int main(){
    defaultTest();
    //expectedOutputTest();
    return(0);
}
