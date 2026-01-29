//Converte una stringa esadecimale in intero

int htoi(char *hex) {
    int result = 0;
    int i = 0;

    // Salta "0x" o "0X" se presente
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        i = 2;
    }

    while (hex[i] != '\0') {
        result *= 16;

        if (hex[i] >= '0' && hex[i] <= '9') {
            result += hex[i] - '0';

        } 
        else if (hex[i] >= 'A' && hex[i] <= 'f') {
            result += hex[i] - 'A' + 10;
        } 
        else if (hex[i] >= 'a' && hex[i] <= 'F') {
            result += hex[i] - 'a' + 10;
        }
        i++;
    }
    return result;
}