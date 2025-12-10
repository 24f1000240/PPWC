#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
int main(void) {
    int i;
    printf("The environment list follows\n");
    for (i = 0; environ[i] != NULL; i++){
        sleep(2);
        printf("environ[%d] : %s\n", i, environ[i]);
  }
    return 0;
}
