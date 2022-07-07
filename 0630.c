#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

#define MAXCOMLEN 1024

void handler(int sig)
{
  fprintf(stderr, "signal(%s) caught.\n", strsignal(sig));
}

int main(int argc, char *argv[], char *envp[])
{
  int status;
  char *args[MAXCOMLEN];
  struct sigaction act;
  pid_t pid, cpid;

  act.sa_handler = handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_RESTART;
  if (sigaction(SIGINT, &act, NULL) < 0)
  {
    perror("sigaction");
    exit(1);
  }

  pid = fork();
  if (pid < 0)
  {
    perror("fork");
  }
  if (pid == 0)
  {
    for (int i = 1; i < 100; i++)
    {
      sleep(1);
      printf("%d\n", i);
    }
    act.sa_handler = SIG_DFL;
    if (sigaction(SIGINT, &act, NULL) < 0)
    {
      perror("sigaction");
    }
    if (execvp(args[0], args) < 0)
    {
      perror(args[0]);
      exit(1);
    };
  }
  else
  {
    sleep(5);
    kill(pid, SIGSTOP);
    sleep(3);
    kill(pid, SIGCONT);
    sleep(3);
    kill(pid, SIGTERM);
    cpid = wait(&status);
  }
  exit(0);
}