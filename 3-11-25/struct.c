#include <stdio.h>
struct sdata {
    int regd;
    float marks;
    char name[50];
};
int main() {
    struct sdata s[3];
    int i;
    for(i = 0; i < 3; i++) {
        printf("Enter details of students\n");
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Registration number: ");
        scanf("%d", &s[i].regd);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("\nStudent Details: \n");
    for(i = 0; i < 3; i++) {
        printf("%s\t %d\t %.2f\n", s[i].name, s[i].regd, s[i].marks);
    }

}

