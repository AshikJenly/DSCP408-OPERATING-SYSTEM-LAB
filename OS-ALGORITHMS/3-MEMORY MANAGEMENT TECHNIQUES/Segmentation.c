#include<stdio.h>

typedef struct Segment
{
    char name[10];
    int limit,base;
}Segment;

Segment Seg[10];
int TOTAL_SEGMENTS;


void main(){
    void SegStore();
    void SegRestore();

    int ch;
    do{
         printf("\n1.Segment Store\n2.Segment Restore\n3.Exit\nEnter your choice:");
         scanf("%d",&ch);
         switch (ch)
         {
         case 1:
            SegStore();
            break;
         
          case 2:
            SegRestore();
            break;
        
          case 3:
            return;
         }
    }
    while(ch<3);

}
void SegStore(){

    char Check(int);
    int i; //For iteration
    int flag;

    printf("\nEnter Total number of segments : ");
    scanf("%d",&TOTAL_SEGMENTS);

    for(i=0;i<TOTAL_SEGMENTS;i++)
     {
        printf("\nEnter Segment Name : ");
        scanf("%s",Seg[i].name);

        UNIQUE_ALLOCATION:
            printf("Enter the limit of the segment : ");
            scanf("%d",&Seg[i].limit);

            printf("Enter Base of the Segment : ");
            scanf("%d",&Seg[i].base);

            flag = Check(i);

            if (!flag)
                goto UNIQUE_ALLOCATION;
            
     }
     printf("\n\tPhysical memory\nsegment name\tlimit\t\tbase\n");
      for(i = 0; i < TOTAL_SEGMENTS; i++)
      {
      printf("\n %d %s", i, Seg[i].name);
      printf("\t%d\t\t%d\n", Seg[i].limit, Seg[i].base);
      }

}
char Check(int i){

    int j,new_base,new_end;
    int seg_base,seg_end ;
    Segment NewSeg = Seg[i];
    new_base = Seg[i].base;
    new_end = Seg[i].base + Seg[i].limit;
    for(j=0;j<i;j++)
     {

        seg_base = Seg[j].base;
        seg_end = Seg[j].base + Seg[j].limit;
        if((new_end > seg_base && new_end < seg_end)|| 
          (new_base > seg_base && new_base< seg_end)||
          (new_base <seg_base && new_end > seg_end)){
            printf("\n\tHitted Mistake Bro\n");
            return 0;
        }
      
     }
     return 1;
}
void SegRestore()
{
  int seg_no;

  NOT_EXISTS:
  printf("\n Enter the segment no.to restore:");
  scanf("%d", &seg_no);

  if(seg_no >= TOTAL_SEGMENTS)
    printf("\nsegment number does not exist");
    goto NOT_EXISTS;

  printf("\n\t Segment Details\n");
  printf("\n segment name : %s\n", Seg[seg_no].name);
  printf("\n segment base : %d\n", Seg[seg_no].base);
  printf("\n segment limit: %d\n", Seg[seg_no].limit);
}