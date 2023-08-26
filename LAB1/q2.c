// 2. Write a C program to assign values to each members of the following
// structure. Pass the populated structure to a function Using call-by-value and
// another function using call-by-address and print the value of each member of
// the structure.
// struct s_info{
// int roll_no;
// char name[50];
// float CGPA;
// struct dob age;
// };

#include <stdio.h>
#include <string.h>
struct dob
{
   int day;
   char month[20];
   int year;
};
struct s_info
{
   char name[30];
   int roll;
   float cgpa;
   struct dob d;
};

void func_value(struct s_info s)
{
printf("\n USING CALL BY VALUE\n");

   printf("Name---->%s\n", s.name);
   printf("Roll---->%d\n", s.roll);
   printf("Cgpa---->%f\n", s.cgpa);
   printf("Dob---->%d %s %d\n", s.d.day, s.d.month, s.d.year);
}
void func_address(struct s_info *s)
{
printf("\n USING CALL BY ADDRESS\n");
   printf("Name---->%s\n", s->name);
   printf("Roll---->%d\n", s->roll);
   printf("Cgpa---->%f\n", s->cgpa);
   printf("Dob---->%d %s %d\n", s->d.day, s->d.month, s->d.year);
}

int main()
{
   struct s_info s;
   strcpy(s.name, "Hitu  raj");
   s.roll = 2005025;
   s.cgpa = 9;
   s.d.day = 10;
   strcpy(s.d.month, "october");
   s.d.year = 2001;
   func_value(s);
   func_address(&s);
}