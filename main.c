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
  pid_t p;
  p = fork();
  if(p<0){
    perror("fork fail");//output to stderr instead of stdout
    exit(1);
  } else if ( p == 0){
      printf("Hello from Child!\n");
  }else{
      printf("Hello from Parent!\n");
  }   
}
