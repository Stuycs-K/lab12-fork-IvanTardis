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

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}

int main(){
  printf("%d about to create 2 child processes\n", getpid());
  // wait(WIFEXITED( status ));

  int x,y;
  int random = open("/dev/random", O_RDONLY, 0300);
  if(random==-1)err();
  read(random, &x, sizeof(int));
  read(random, &y, sizeof(int));
  x = abs(x)%5+1;
  y = abs(x)%5+1;
  // printf("X: %d   Y: %d\n", x, y);

  pid_t p1, p2;
  p1 = fork();
  if(p1<0){
    perror("fork fail");//output to stderr instead of stdout
    exit(1);
  } else if ( p1 == 0){
    printf("%d %dsec\n", getpid(), x);
    sleep(x);
    printf("%d finished after %dsec\n", getpid(), x);
    exit(x);
    // printf("Hello from Child! PID: %d\n", getpid());
  }else{
    p2 = fork();
    if ( p2 == 0){
      printf("%d %dsec\n", getpid(), y);
      sleep(y);
      printf("%d finished after %dsec\n", getpid(), y);
      exit(y);
      // printf("Hello from Child! PID: %d\n", getpid());
    }
    else{
      int status;
      int hold = wait(&status);
      if( WIFEXITED(status) ){
        printf("Main Process %d is done. Child %d slept for %dsec\n", getpid(), hold, WEXITSTATUS(status));
      }
      // printf("Hello from Parent! PID: %d\n", getpid());
    }
  }
  return 0;
}
