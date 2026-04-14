#include <iostream>
#pragma once

extern const unsigned char* findMalwareSignature(const unsigned char* data, unsigned int dataSize, const unsigned char* signature, unsigned int signatureSize);

extern void customStrcpy(char* dest, const char* src);
struct VulnerableSystem { // Ensure that variables are stored side by side in memory
    char usernameBuffer[8]; // 7 chars + '\0'
    bool isAdmin;           // Flag located just behind the buffer
};