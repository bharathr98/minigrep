#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const char ascii_table[] = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

int char_to_ascii(int ch)
{
    const char *p = strchr(ascii_table, ch);
    return p ? p - ascii_table + 32 : 0;
}

int ascii_to_char(int a)
{
     return (a >= 32 && a < 128) ? ascii_table[a-32] : 0;
}

void preprocess(char* pattern, int *lookup, int length){
    for (int i = 0; i < 256; i++){
        lookup[i] = length;
    }
    for (int i = 0; i < length - 1; i++){
        lookup[char_to_ascii(pattern[i])] = length - 1 - i;
    }
    lookup[char_to_ascii(pattern[length - 1])] = length;
}

int main(int argc, char **argv){
    char* stringT = argv[1];
    char* pattern = argv[2];
    int stringLength = strlen(stringT);
    int patternLength = strlen(pattern);

    // This creates the Boyer-Moore-Horspool lookup table
    int lookup[256] = {0};
    preprocess(pattern, lookup, patternLength);

    // We start matching the pattern to the string T from the last character of pattern
    int t = patternLength - 1;
    bool stringMatch;
    while(t < stringLength){
        printf("%d", t);
        for(int i = 0; i < patternLength; i++){
            printf("%c",pattern[patternLength - i - 1]);
            printf("%c",stringT[t - i]);
            printf("\n");
            if (pattern[patternLength - i - 1] == stringT[t - i]){
                stringMatch = true;
            }
            else{
                stringMatch = false;
                // t = t + lookup[char_to_ascii(stringT[t - i])];
                t = t + lookup[char_to_ascii(pattern[patternLength - 1 - i])];
                break;
            }
        }
        if (stringMatch){
            break;
        }
    } 
    if (stringMatch){
        printf("Found the pattern");
    }

    
    return 0;

}