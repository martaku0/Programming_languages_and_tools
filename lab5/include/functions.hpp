#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#pragma once

extern const unsigned char* findMalwareSignature(const unsigned char* data, unsigned int dataSize, const unsigned char* signature, unsigned int signatureSize);

extern void customStrcpy(char* dest, const char* src);
struct VulnerableSystem { // Ensure that variables are stored side by side in memory
    char usernameBuffer[8]; // 7 chars + '\0'
    bool isAdmin;           // Flag located just behind the buffer
};

typedef void (*CryptoFunctionPtr)(const std::string&, const std::string&, char);
extern void encryptXOR(const std::string& inputFile, const std::string& outputFile, char key);
extern void maliciousEncryptFunction(const std::string& inputFile, const std::string& outputFile, char key);
extern void vulnerability(CryptoFunctionPtr& targetPointer);