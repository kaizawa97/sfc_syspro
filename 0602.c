#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define NUM_THREADS 8
#define NUM_MAX 1000

void *do_calc(void *);
pthread_t tid[NUM_THREADS];

struct param { 
  int sum; // 加算の和が入る変数
  pthread_mutex_t mutex; // 排他制御のためのロック用の変数
};

int main()
{
  int i;
  struct param p;
  p.sum = 0; //初期化
  pthread_mutex_init(&p.mutex, NULL); // ロック用の変数を初期化

  for (i = 0; i < NUM_THREADS; i++)
  {
    pthread_create(&tid[i], NULL, do_calc, &p); //スレッドの生成
  }
  for (i = 0; i < NUM_THREADS; i++)
  {
    pthread_join(tid[i], NULL); //スレッドの終了待機
  }
  printf("Sum %d\n", p.sum);
  pthread_mutex_destroy(&p.mutex); //スレッドの解放
  return 0;
}

void *do_calc(void *arg)
{
  int i;
  struct param *chill = arg; //代入

  usleep(random() % 10000); // 待ち時間を入れる
  for (i = 1; i <= NUM_MAX; i++)
  {
    pthread_mutex_lock(&chill->mutex); //mutexロック
    usleep(random() % 5000); // 待ち時間を入れる
    chill->sum += i;
    usleep(random() % 5000); // 待ち時間を入れる
    pthread_mutex_unlock(&chill->mutex); //mutexロック解除
  }
  pthread_exit(NULL); //スレッドの終了
}