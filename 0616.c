#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name
{
  char first[10];
  char last[10];
};

// compare name
int compare(const void *a, const void *b)
{
  int tmp;
  struct name *lastname = (struct name *)a;
  struct name *firstname = (struct name *)b;

  tmp = strcmp(lastname->last, firstname->last);
  if (tmp == 0) // 姓が同じ場合は名を比較
  {
    return strcmp(lastname->first, firstname->first);
  }
  return strcmp(lastname->last, firstname->last);
}

int main()
{
  int i;
  struct name nlist[4] =
  {
    {"Taro", "Keio"},
    {"Hanako", "Keio"},
    {"Yuichi", "Fukuzawa"},
    {"Eiichi", "Shibusawa"}
  };
  printf("Before\n");
  for (i = 0; i < 4; i++)
  {
    printf("%s %s\n", nlist[i].first, nlist[i].last); // 構造体の名前を表示
  }
  printf("----------------\n");
  qsort((void *)nlist, 4, sizeof(struct name), (void *)compare); //qsortを行う
  printf("After\n");
  for (i = 0; i < 4; i++)
  {
    printf("%s %s\n", nlist[i].first, nlist[i].last); // 並び替えた後の構造体の名前を表示
  }
}