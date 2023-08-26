// WAP TO SWAP 2 VARIABLE ENTERED THROUGH COMAAND LINE USING FUNCTION AND POINTER
#include <stdio.h>

void swap(char *a, char *b)
{

    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char **argv)
{
    printf("You have to entered %d arguments\n", argc);

    swap(argv[1], argv[2]);

    printf("No.s ater swapping is\n");
    printf("%c %c", *argv[1], *argv[2]);

    return 0;
}
