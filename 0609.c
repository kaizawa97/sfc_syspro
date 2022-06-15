#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
  pid_t pid, cpid;
  int status;
  int k = 6;

  printf("Now, create new process\n");
  for (int i = 1; i < 4; i++)
  {
    pid = fork(); // 子プロセスの生成
    if (pid < 0)  //エラー処理
    {
      printf("fork error\n");
      exit(1);
    }
    if (pid == 0) // child
    {
      for (int j = 1; j < k; j++)
      {
        printf("Process %d(%d)\n", i, (int)getpid()); //子プロセスのpid表示
        sleep(1);
      }
      return 0;
    }
    k = k + 1;
  }
  for (int l = 1; l < 4; l++)
  {
    wait(&status); 
  }
  printf("All process terminated\n"); //終了
  return 0;
}