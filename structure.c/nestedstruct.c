#include<stdio.h>
struct date{
        int m;
        int y;
};
struct sdata{
        int regd_no;
        struct date d1;
};
int main(){
        struct sdata s1;
        s1.d1.m = 1;
        printf("Month(inside_structure) = %d\n", s1.d1.m);
        s1.regd_no = 9505;
        printf("Regd = %d\n", s1.regd_no);
}
