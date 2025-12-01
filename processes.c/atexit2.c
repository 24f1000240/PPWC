#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void display()
{
    printf("fn called 1st\n");
}
void display2()
{
	printf("fn called 2nd\n");
}

int main(void)
{
    int i;
    /* rest of main program goes here */
    for (i = 0; i < 5; i++) {
        sleep(1);
        printf("%d\n", i);
    }
    
    atexit(display);
    atexit(display2);
    return 0;
}

