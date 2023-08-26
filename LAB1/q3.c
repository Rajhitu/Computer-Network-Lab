// q3.Write a C program to extract each byte from a given number and store them in separate character variables and print the content of those variables.

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     long int n = 53;
//     char ch1, ch2, ch3, ch4;
//     ch1 = (char)((n >> (0 * 8)) & 0x000000FF);
//     ch2 = (char)((n >> (1 * 8)) & 0x000000FF);
//     ch3 = (char)((n >> (2 * 8)) & 0x000000FF);
//     ch4 = (char)((n >> (3 * 8)) & 0x000000FF);
//     printf("%d %d %d %d", ch1, ch2, ch3, ch4);
// }

#include <stdio.h>

typedef unsigned char BYTE;

int main()
{
    unsigned int value=0x11223344; //4 Bytes value
     
    BYTE a,b,c,d; //to store byte by byte value
     
     
    a=(value&0xFF); //extract first byte
    b=((value>>8)&0xFF); //extract second byte
    c=((value>>16)&0xFF); //extract third byte
    d=((value>>24)&0xFF); //extract fourth byte

    printf("a= %02X\n",a);
    printf("b= %02X\n",b);
    printf("c= %02X\n",c);
    printf("d= %02X\n",d);
    return 0;
}