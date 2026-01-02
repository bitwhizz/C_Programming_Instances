#include<stdio.h>
#include<stdlib.h>


/*
Memory is allocated from the heap and can be released as necessary.
The scope is restricted to the pointer or pointers that reference the memory.
it exist until it is released.
*/
int main(){

  size_t *arr[5];  //size_t created to provide a safe type of sizes

  int i = 0;


  printf("%d \n",sizeof(arr)/sizeof(arr+0));

  for (i=0; i<(sizeof(arr)/sizeof(arr+0)); i++){
    arr[i]= (int *)malloc(sizeof(int));
    *arr[i]=i;
  }

  printf("%d \n",arr);
  printf("%d \n",arr+1);
  printf("%d \n",*(arr+1)); //arr[i]
  printf("%d \n",**(arr+1)); //*arr[i]

  return 0;
}
