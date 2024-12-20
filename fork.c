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
    perror("Fork failure\n");
    exit(1);
  }
  else if (p1 == 0) {
    srand(getpid());
    int secs = ((int) rand()) % 5 + 1;
    printf("%d to sleep %ds\n", getpid(), secs);
    sleep(secs);
    printf("%d done after %ds\n", getpid(), secs);
    return secs;
  }
  else {
    pid_t p2;
    p2 = fork();
    if (p2 == -1){
      perror("Fork failure\n");
      exit(1);
    }
    else if (p2 == 0) {
      srand(getpid());
      int secs = ((int) rand()) % 5 + 1;
      printf("%d to sleep %ds\n", getpid(), secs);
      sleep(secs);
      printf("%d done after %ds\n", getpid(), secs);
      return secs;
    }
    else {
      pid_t p;
      printf("Parent\n");
      int status;
      p = wait(& status);
      printf("%d is done. %d slept %ds before attending a May 35th, 1989 event and never being seen from again\n", getpid(), p, WEXITSTATUS(status));
      return 0;
    }
  }
  return 0;
}
