#include <stdio.h>
struct account {
    int ac_no;
    char name[50];
    float balance;
};

int main() {
    struct account a[3];
    int i;
    for(i = 0; i < 3; i++) {
        printf("Enter details of account holder\n");
        printf("Name: ");
        scanf("%s", a[i].name);
        printf("Account number: ");
        scanf("%d", &a[i].ac_no);
        printf("Balance: ");
        scanf("%f", &a[i].balance);
    }
    printf("\nAccounts with balance greater than 500 is(are):\n\n");
    for(i = 0; i < 3; i++) {
        if(a[i].balance > 500) {
            printf("Name: %s \nAccount No: %d \nBalance: %.2f\n\n", a[i].name, a[i].ac_no, a[i].balance);
        }
    }
}

