#include <stdio.h>
#include <string.h>

// Performs Modulo-2 division via bitwise XOR logic
void xorDivide(char data[], char generator[], char remainder[]) {
    int dataLen = strlen(data);
    int genLen = strlen(generator);
    char temp[100];
    
    // Copy the initial segment of data into a temporary working array
    strncpy(temp, data, genLen);
    temp[genLen] = '\0';
    
    int pointer = genLen;
    while (pointer <= dataLen) {
        // If the leading bit is '1', perform XOR with the generator polynomial
        if (temp[0] == '1') {
            for (int i = 1; i < genLen; i++) {
                temp[i - 1] = (temp[i] == generator[i]) ? '0' : '1';
            }
        } else {
            // If the leading bit is '0', XOR with all '0's (slides the frame forward)
            for (int i = 1; i < genLen; i++) {
                temp[i - 1] = (temp[i] == '0') ? '0' : '1';
            }
        }
        
        // Fetch the next bit from the data stream
        if (pointer < dataLen) {
            temp[genLen - 1] = data[pointer];
        }
        pointer++;
    }
    
    // The final remainder length is always (Generator Length - 1)
    strncpy(remainder, temp, genLen - 1);
    remainder[genLen - 1] = '\0';
}

int main() {
    char data[50], generator[20], appendedData[70], remainder[20], codeWord[70], receivedData[70];
    int i, dataLen, genLen;

    // 1. Sender Side Code Execution
    printf("--- SENDER SIDE ---\n");
    printf("Enter Raw Data Bits: ");
    scanf("%s", data);
    printf("Enter Generator Polynomial Bits: ");
    scanf("%s", generator);

    dataLen = strlen(data);
    genLen = strlen(generator);

    // Seed appendedData with original data bits
    strcpy(appendedData, data);
    
    // Append (N - 1) zeros to the data bits stream
    for (i = 0; i < genLen - 1; i++) {
        appendedData[dataLen + i] = '0';
    }
    appendedData[dataLen + genLen - 1] = '\0';

    // Compute the CRC Checksum
    xorDivide(appendedData, generator, remainder);
    printf("Generated CRC Checksum: %s\n", remainder);

    // Construct final codeword: original data + calculated remainder
    strcpy(codeWord, data);
    strcat(codeWord, remainder);
    printf("Codeword Transmitted over Network: %s\n\n", codeWord);

    // 2. Receiver Side Verification Simulation
    printf("--- RECEIVER SIDE ---\n");
    printf("Enter Received Codeword Stream: ");
    scanf("%s", receivedData);

    char receiverRemainder[20];
    xorDivide(receivedData, generator, receiverRemainder);
    printf("Resulting Remainder: %s\n", receiverRemainder);

    // Check if any error bits ('1') exist in the resulting remainder
    int errorDetected = 0;
    for (i = 0; i < genLen - 1; i++) {
        if (receiverRemainder[i] == '1') {
            errorDetected = 1;
            break;
        }
    }

    if (errorDetected) {
        printf("Status: ERROR DETECTED! The received codeword is corrupted.\n");
    } else {
        printf("Status: SUCCESS! Data received flawlessly with zero errors.\n");
    }

    return 0;
}