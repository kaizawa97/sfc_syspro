#include <stdio.h>

int change(int n, int k)
{
  if (n < 0) return 0;
   if (k <= 4) return 1;
   if (k <= 9) return change(n,1) + change(n-5,5);
   if (k <= 49) return change(n,5) + change(n-10,10);
   if (k <= 99) return change(n,10) + change(n-50,50);
   if (k <= 499) return change(n,50) + change(n-100,100);
   return change(n,100) + change(n-500,500);
}

int main(){
  int i;

  for(i=0;i<=10;i++){
    printf("%d円の支払い方は%d通りです\n",i,change(i,100));
  }
}

