#include "../include/functions.hpp"

void malwareSig(){
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
}

void strCpySafe(){
    VulnerableSystem system;
    
    // Initialization
    system.isAdmin = false;
    std::cout << "--- INITIAL STATE ---" << std::endl;
    std::cout << "Is admin? " << (system.isAdmin ? "Y" : "N") << std::endl;
    std::cout << "Buffer address: " << (void*)system.usernameBuffer << std::endl;
    std::cout << "Flag address:  " << (void*)&system.isAdmin << std::endl;

    // Secure login
    // 5 characters will fit into an 8-byte buffer along with '\0')
    const char* safeInput = "User"; 
    customStrcpy(system.usernameBuffer, safeInput);
    
    std::cout << "--- AFTER SUCCESSFULLY LOGGING IN ---" << std::endl;
    std::cout << "Logged in as: " << system.usernameBuffer << std::endl;
    std::cout << "Is admin? " << (system.isAdmin ? "Y" : "N") << std::endl;
    std::cout << std::endl;
}

void strCpyButterOverflow(){
    VulnerableSystem system;
    
    // Initialization
    system.isAdmin = false;
    std::cout << "--- INITIAL STATE ---" << std::endl;
    std::cout << "Is admin? " << (system.isAdmin ? "Y" : "N") << std::endl;
    std::cout << "Buffer address: " << (void*)system.usernameBuffer << std::endl;
    std::cout << "Flag address:  " << (void*)&system.isAdmin << std::endl;

    // Buffer Overflow
    // A string that exceeds 8 bytes
    // The last characters will overwrite isAdmin flag
    const char* maliciousInput = "Hacker!!1"; 
    
    std::cout << "--- ATTACK ---" << std::endl;
    std::cout << "Copying a string: \"" << maliciousInput << "\"" << std::endl;
    customStrcpy(system.usernameBuffer, maliciousInput);

    std::cout << "Logged in as: " << system.usernameBuffer << std::endl;
    std::cout << "Is admin? " << (system.isAdmin ? "Y" : "N") << std::endl;
}

void xorCrypt(int argc, char* argv[]){
    std::string inputPath = "";
    std::string outputPath = "";
    bool triggerVuln = false;
    char xorKey = 0x5A; // letter 'Z'

    // Parse argv
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.find("--input=") == 0) {
            inputPath = arg.substr(8);
        } else if (arg.find("--output=") == 0) {
            outputPath = arg.substr(9);
        } else if (arg == "--vulnerability") {
            triggerVuln = true;
        }
    }

    if (inputPath.empty() || outputPath.empty()) {
        std::cout << "Usage: ./main --input=fileIn --output=fileOut [--vulnerability]" << std::endl;
        return;
    }

    CryptoFunctionPtr executionPtr = encryptXOR;

    if (triggerVuln) {
        vulnerability(executionPtr);
    }

    executionPtr(inputPath, outputPath, xorKey);
}

void passwordValidation(int argc, char* argv[]){
    if (argc < 2) {
        std::cout << "Usage: ./main --password=Password" << std::endl;
        return;
    }

    const char* password = argv[1];

    // TABLE of pointers
    ValidatorFunc validators[] = { hasLength, hasSpecialChar, hasDigit };
    int numValidators = 3;

    bool isPasswordValid = true;

    std::cout << "[INFO] Password verification: " << password << "\n";

    for (int i = 0; i < numValidators; ++i) {
        if (!validators[i](password)) {
            isPasswordValid = false;
            break; 
        }
    }

    if (isPasswordValid) {
        std::cout << "[SUCCESS] The password has been accepted!" << std::endl;
    } else {
        std::cout << "[REJECTED] The password does not meet security requirements." << std::endl;
    }
}

int main(int argc, char* argv[]){
    // malwareSig();

    // strCpySafe();
    // strCpyButterOverflow();
    
    // xorCrypt(argc, argv);

    //passwordValidation(argc, argv);

    return 0;
}