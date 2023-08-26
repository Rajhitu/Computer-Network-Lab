// q4.Write a C Program to enter a number and store the number across the following structure and print the content of each member of the structure. Then aggregate each member of the structure to form the original number and print the same.

// struct pkt{
// char ch1;
// char ch2[2];
// char ch3;
// };


#include <stdio.h>
#include <string.h>

struct pkt
{
char ch1;
char ch2[2];
char ch3;
};

int main()
{
struct pkt p;
int n,r=0;

printf("\nEnter a 4 digit number:");
scanf("%d",&n);
int num=n;

p.ch1=num/1000;
p.ch3=num%10;
p.ch2[0]=(num/100)%10;
p.ch2[1]=(num%100)/10;

r=1000*p.ch1+p.ch2[0]*100+p.ch2[1]*10+p.ch3;

printf("\nThe original number:%d",r);
}