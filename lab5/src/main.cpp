#include "../include/functions.hpp"

int main(){
    unsigned char memory[] = { 0x90, 0xDE, 0xAD, 0xBE, 0xEF, 0x33, 0xC0, 0x90 };
    unsigned int memSize = sizeof(memory);

    unsigned char malwareSig[] = { 0xDE, 0xAD, 0xBE, 0xEF };
    unsigned int sigSize = sizeof(malwareSig);

    const unsigned char* result = findMalwareSignature(memory, memSize, malwareSig, sigSize);

    if (result) {
        std::cout << "The reference number found at: " << (void*)result << std::endl;
        std::cout << "Offset: " << (result - memory) << " bytes." << std::endl;
    } else {
        std::cout << "No reference number found." << std::endl;
    }

    return 0;
}