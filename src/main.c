#include<stdio.h>
#include<string.h>
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
int main(int argc, char **argv){
    char* stringT = argv[1];
    char* pattern = argv[2];
    return 0;

}