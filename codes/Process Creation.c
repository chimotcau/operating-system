 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("This is the child process (PID: %d)\n", getpid());
    } else {
        printf("This is the parent process (PID: %d)\n", getpid());
    }

    return 0;
}
