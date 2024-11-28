#include "caesar_cipher.h"

void encoder(const char* secret, int rule)
{
    
    int length = (int)strlen(secret);
    
    char res[length + 2]; 
    
    for (int i = 0 ; i < length; i++)
    {
        if(secret[i] >= 97 && secret[i] <= 122)
            res[i] = (secret[i]-97+rule)%26+97;
        else if(secret[i] >= 65 && secret[i] <= 90)
            res[i] = (secret[i]-65+rule)%26+65;
        else
            res[i] = secret[i];
    }
    res[length] = rule+97;
    res[length+1] = '\0';
    printf("Original Text : %s\n", secret);
    printf("Result of Encoding : %s\n", res);
}

void decoder(const char* secret)
{
    int length = (int)strlen(secret);
    
    int rule = secret[length-1]-97;
    
    char res[length];
    
    for (int i = 0 ; i < length-1; i++)
    {
        if(secret[i] >= 97 && secret[i] <= 122)
            res[i] = (secret[i]-97+26-rule)%26+97;
        else if(secret[i] >= 65 && secret[i] <= 90)
            res[i] = (secret[i]-65+26-rule)%26+65;
        else 
            res[i] = secret[i];
    }
    res[length-1] = '\0';
    printf("Original Text : %s\n", secret);
    printf("Result of Decoding : %s\n", res);
}
