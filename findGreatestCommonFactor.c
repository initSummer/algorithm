/* ************************************************
 * summer 
 * 2023/2
 * get two positive integer inputs, find their greatest common factor
 * ************************************************/
#include <stdio.h>

int main()
{
  int a,b;
  printf("enter two positive integer: ");
  scanf("%d",&a);
  scanf("%d",&b);
  int temp;
  do
  {
    int bigger, smaller;
    if(a > b)
    {
      bigger = a;
      smaller = b;
    }
    else
    {
      bigger = b;
      smaller = a;
    }

    temp = a%b;
    if(temp == 0)
    {
      printf("greatest common factor: %d", b);
      return 0;
    }
    
    a = smaller;
    b = temp;
  }while(1);

  return 0;
}

