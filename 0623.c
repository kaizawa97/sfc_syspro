#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

struct name
{
  char first[10];
  char last[10];
};

int main()
{
  int i, fd[2], n;
  char buf[BUFSIZ];
  pid_t pid;

  struct name nlist[4] =
      {
          {"Taro", "Keio"},
          {"Hanako", "Keio"},
          {"Yuichi", "Fukuzawa"},
          {"Eiichi", "Shibusawa"}};

  if (pipe(fd) != 0)
  {
    perror("pipe");
    exit(1);
  }

  printf("Now, create new process\n");
  pid = fork();
  if (pid < 0)
  {
    printf("fork error\n");
    exit(1);
  }

  if (pid == 0) // child process
  {
    close(fd[1]); // 使わないファイルディスクリプタを閉じる
    for (;;)
    {
      n = read(fd[0], buf, BUFSIZ); // pipeから読み込む
      if (n <= 0)
      {
        exit(0);
      }
      else
      {
        write(1, buf, n); // 標準出力に書き込む
      }
    }
  }
  else // parent process
  {
    int status;
    pid_t cpid;
    close(fd[0]); // 使わないファイルディスクリプタを閉じる

    for (i = 0; i < 4; i++)
    {
      write(fd[1], &nlist[i], sizeof(struct name)); // pipeに書き込む
      sleep(1); // 1秒待つ
    }
    close(fd[1]); // 使わないファイルディスクリプタを閉じる
    cpid = wait(&status); // 子プロセスの終了を待つ
    printf("\nAll process terminated\n");
    exit(0);
  }
  exit(0);
}