#include <stdio.h>
#include <stdlib.h>
int main()
{
    long int n = 53;
    char ch1, ch2, ch3, ch4;
    ch1 = (char)((n >> (0 * 8)) & 0x000000FF);
    ch2 = (char)((n >> (1 * 8)) & 0x000000FF);
    ch3 = (char)((n >> (2 * 8)) & 0x000000FF);
    ch4 = (char)((n >> (3 * 8)) & 0x000000FF);
    printf("%d %d %d %d", ch1, ch2, ch3, ch4);
}