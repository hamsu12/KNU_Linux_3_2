#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int child, pid, status;
    pid = fork();
    if (pid == 0) { /* 자식 프로세스 */
        execlp(argv[1], argv[1], NULL);
        fprintf(stderr, "Error in execclp: %s\n", argv[1]);
    } else { /* 부모 프로세스 */
        child = wait(&status);
        printf("child %d is terminated\n", pid);
        printf("\twith status %d\n", status>>8);
    }
    return 0;
}

