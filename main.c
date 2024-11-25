#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <sys/wait.h>

int main(){
  printf("%d about to create 2 child processes\n", getpid());

  pid_t p1, p2;
  p1 = fork();
  if(p1<0){
    perror("fork fail");//output to stderr instead of stdout
    exit(1);
  } else if ( p1 == 0){
    int rand;
    printf("%d %dsec\n", getpid(), rand);
    // printf("Hello from Child! PID: %d\n", getpid());
  }else{
    p2 = fork();
    if ( p2 == 0){
      int rand;
      printf("%d %dsec\n", getpid(), rand);
      // printf("Hello from Child! PID: %d\n", getpid());
    }
    else{
      // printf("Hello from Parent! PID: %d\n", getpid());
    }
  }
}
