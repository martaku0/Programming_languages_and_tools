#include "../include/functions.hpp"

void encryptXOR(const std::string& inputFile, const std::string& outputFile, char key) {
    std::cout << "[INFO] Implementing the original encryptXOR function..." << std::endl;

    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile || !outFile) {
        std::cerr << "[ERROR] Unable to open files!" << std::endl;
        return;
    }

    const unsigned int SIZE = 1024;
    char* buffer = new char[SIZE]; // Dynamic buffer allocation

    while (inFile.read(buffer, SIZE) || inFile.gcount() > 0) {
        std::streamsize bytesRead = inFile.gcount();
        
        // Encryption using the XOR operation
        for (std::streamsize i = 0; i < bytesRead; ++i) {
            buffer[i] ^= key;
        }
        
        outFile.write(buffer, bytesRead);
    }

    delete[] buffer; // Clear memory
    std::cout << "[SUCCESS] File encrypted." << std::endl;
}