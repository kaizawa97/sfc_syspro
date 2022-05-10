#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

struct kotae
{
  unsigned int tsuru;
  unsigned int kame;
};

int solve(unsigned int atama, unsigned int ashi, struct kotae *p)
{
  if (ashi % 2 == 1)
  {
    return 0;
  }

  if (ashi < atama * 2)
  {
    return 0;
  }

  p->kame = (ashi / 2) - atama;
  p->tsuru = atama - p->kame;
  return 1;
};

int main()
{
  int ret, goukei, foot, sloveans;
  char input[MAXLINE];
  struct kotae ans;

  fgets(input, MAXLINE, stdin);
  ret = sscanf(input, "%d,%d", &goukei, &foot);
  if (ret != 2)
  {
    printf("Error: 引数を2個にまたコンマ区切りで指定してください。\n");
    exit(1);
  }

  sloveans = solve(goukei, foot, &ans);
  if (sloveans == 0)
  {
    printf("%d\n", sloveans);
    printf("Answer: 答えが見つかりませんでした\n");
    exit(0);
  }
  printf("%d\n", sloveans);
  printf("Answer: 鶴：%d, 亀：%d\n", ans.tsuru, ans.kame);
  exit(0);
};
