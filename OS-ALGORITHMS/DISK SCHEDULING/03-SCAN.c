#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
void sort(int *,int );
int insert(int *,int ,int);
void main(){
  int head,n,cur_pos;
  int i,sum=0;
  int *arr,*dd;
   

    head:
    printf("\nEnter the block number between 0 and 200: ");
    scanf("%d",&head);
    if ((head<=0)||(head>=200))
        goto head;

  printf("\nOur disk head is on the %d block",head);

  printf("\nEnter no of requests : ");
  scanf("%d",&n);
  arr=(int*)malloc((n+1)*sizeof(int));
  dd=(int*)malloc((n+1)*sizeof(int));
 


 
  printf("\nEnter requests : ");
  for(i=0;i<n;i++){

      arr:
      printf("\nEnter %d request : ",i+1);
      scanf("%d",&arr[i]);

      if((arr[i]>200)||(arr[i]<0))
      {
      printf("\nBlock number must be between 0 and 200!");
      goto arr;
      }

  }
  for(i=0;i<n;i++)
    dd[i]=arr[i];
  
  sort(dd,n);
  cur_pos =insert(dd,n,head);

  printf("\nSCAN TECHNIQUE:");
  printf("\nDISK QUEUE  : %d\t",head);
  for(i=0;i<n;i++)
    printf("%d\t",arr[i]);


  printf("\nACCESS ORDER: ");
  for(i=cur_pos;i<=n;i++){
    printf("%d\t",dd[i]);
  }
  for(i=cur_pos-1;i>=0;i--){
    printf("%d\t",dd[i]);
  }
  sum+=abs(199-dd[cur_pos]);
  sum+=abs(199-dd[0]);

  printf("\nSEEK TIME : %d ",sum);
}
int insert(int *arr,int n,int x){

  int i, j;
    // Find the index where x should be inserted
    for (i = 0; i < n; i++) {
        if (arr[i] > x) {
            break;
        }
    }
    // Shift the elements to make space for x
    for (j = n; j > i; j--) {
        arr[j] = arr[j-1];
    }
    // Insert x
    arr[i] = x;

    return i;
}
void sort(int * p,int n){
  int i=0,j=0;
  for(i=0;i<n;i++){
    for(j=0;j<n-i-1;j++){
      if(p[j]>p[j+1]){
        int temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
    }
  }
}