#include <stdio.h>
#include <unistd.h>
#define MSGSIZE 19

char *msg1 = "PPWC";
char *msg2 = "2E2";
char *msg3 = "Anurag";

int main()
{
    char inbuf[MSGSIZE];
    int p[2];
    int i;

    /* create pipe */
    if (pipe(p) < 0)
        return 1;

    /* write pipe */
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);

    /* read pipe */
    for (i = 0; i < 3; i++)
    {
        read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
    }

    return 0;
}

