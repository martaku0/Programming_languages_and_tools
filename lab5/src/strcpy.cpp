void customStrcpy(char* dest, const char* src) {
    if (dest == nullptr || src == nullptr) return;

    // Move the pointers until the end-of-chain marker reached ('\0')
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    // Add a null terminator at the end
    *dest = '\0'; 
}