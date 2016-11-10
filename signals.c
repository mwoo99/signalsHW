#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  umask(0);
  if (signo == SIGINT){
    char msg[] = "exiting";
    int file = open("file.txt", O_APPEND);
    write(file, msg, sizeof(msg));
    close(file);
    exit(0);
    }
    if (signo == SIGUSR1) printf("PPID: %d\n", getppid());
}


int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    sleep(1);
    printf("PID: %d\n",getpid());
  } 
}