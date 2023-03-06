#include<stdio.h>
#include<math.h>
#include<malloc.h>
void main(){
  int st,req;
  int i,sum=0;
  int *arr,*dd;
  st:
    printf("\nEnter the block number between 0 and 200: ");
    scanf("%d",&st);
    if ((st<=0)||(st>=200))
        goto st;

  printf("\nOur disk head is on the %d block",st);

  printf("\nEnter no of requests : ");
  scanf("%d",&req);
  arr=(int*)malloc((req+1)*sizeof(int));
  dd=(int*)malloc((req+1)*sizeof(int));

  arr[0]=st;
  printf("\nEnter requests : ");
  for(i=1;i<=req;i++){

      arr:
      printf("\nEnter %d request : ",i);
      scanf("%d",&arr[i]);

      if((arr[i]>200)||(arr[i]<0))
      {
      printf("\nBlock number must be between 0 and 200!");
      goto arr;
      }

  }

    for(i=0;i<=req;i++)
        dd[i]=arr[i];

    printf("\n\t\tFIRST COME FIRST SERVE: ");
    printf("\nDISK QUEUE:");
    
    for(i=0;i<=req;i++)
        printf("\t%d",arr[i]);

    printf("\n\nACCESS ORDER:");
    for(i=0;i<=req;i++)
    {
      printf("\t%d",dd[i]);
      if(i!=req)
        sum+=abs(dd[i]-dd[i+1]);
    }
   
    printf("\n\nTotal no. of head movements: %d",sum);
}