#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
  printf("%d about to create two child processes through parthenogenesis\n", getpid());
  pid_t p1;
  p1 = fork();
  if (p1 == -1){
    perror("Fork failure");
    exit(1);
  }
  else if (p1 == 0){
      printf("Child 1\n");
  }
  else {
      pid_t p2;
      p2 = fork();
      if (p2 == -1){
        perror("Fork failure");
        exit(1);
      }
      else if (p2 == 0){
          printf("Child 2\n");
      }
      else {
          printf("Parent\n");
          int status;
          wait(& status);
          printf("%d seconds slept\n", WEXITSTATUS(status));
      }
  }
  return 0;
}
