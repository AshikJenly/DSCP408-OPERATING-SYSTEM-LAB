#include<stdio.h>
#include<math.h>
#include<malloc.h>

void GetRequests(int * ,int);
int GetHeadIndex(int *,int ,int);
void sort(int *,int);
void main(){

//Getting Data 
   int * arr,n,total=0,head,cor_index;
   printf("\nEnter Number of Requests : ");
   scanf("%d",&n);
   arr=(int*)malloc(n*sizeof(int));
   GetRequests(arr,n);

   printf("\nEnter the starting point : (0 - 200) : ");
   scanf("%d",&head);

   sort(arr,n);
   cor_index=GetHeadIndex(arr,n,head);
   total+=abs(199-head);
   total+=abs(199-arr[0]);

   printf("\nSCAN TECHNIQUE:");
   printf("\nDISK QUEUE:\t%d",head);

   int i;
   for(i=0;i<n;i++)
      printf("\t%d",arr[i]);

   printf("\nACCESS ORDER:\t%d",head);
   for(i=cor_index;i<n;i++)
    printf("\t%d",arr[i]);

   for(i=0;i<cor_index;i++)
    printf("\t%d",arr[i]);

  printf("\nTotal no of head movements : %d ",total);
}

void GetRequests(int * p,int n){
  int i;
  for(i=0;i<n;i++){
    arr:
    printf("\nEnter request %d : ",i+1);
    scanf("%d",&p[i]);
    if (p[i]<0 || p[i]>200)
        {
          printf("\nEnter values between (0 and 200)");
          goto arr;
        }
    }
}
void sort(int *p,int n){
  int i,j,temp;
  for(i=0;i<n;i++){
    for(j=0;j<n-i-1;j++){
      if(p[j]>p[j+1]){
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
    }
  }
}
int GetHeadIndex(int *p,int n,int head){
  int i=0;
  for(i=0;i<n;i++){
    if(p[i]>head)
      break;
  }
  return i;
}
