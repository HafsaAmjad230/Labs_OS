#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process: replace with "date" command
        execlp("date", "date", NULL);
        // If execlp fails:
        perror("execlp failed");
    } else if (pid > 0) {
        // Parent process: wait for child to finish
        wait(NULL);
        printf("Child finished\n");
    } else {
        // Fork failed
        perror("fork failed");
    }

    return 0;
}
