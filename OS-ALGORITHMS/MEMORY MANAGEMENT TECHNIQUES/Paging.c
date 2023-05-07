#include<stdio.h>

typedef struct PageMag
{
    struct page
    {
        char content[10];
    }page[10];

}PageMag;
PageMag PageSeg[10];

int PAGE_SIZE,PROCESS_SIZE,TOTAL_PAGES,PAGE_FRAME[10];


void main(){
    void PageStore();
    void PageRestore();

    int ch;

    
    do{
         printf("\n1.Page Store\n2.Page Restore\n3.Exit\nEnter your choice:");
         scanf("%d",&ch);
         switch (ch)
         {
         case 1:
            PageStore();
            break;
         
          case 2:
            PageRestore();
            break;
        
          case 3:
            return;
         }
    }
    while(ch<3);

}

void PageStore(){

    int LogicalMemorySize,terminate=0;
    int i,j; //To iterate loop

    // Getting data
    do{
        printf("\nEnter Logical Memory Size : ");
        scanf("%d",&LogicalMemorySize);

        printf("\nEnter Process size : ");
        scanf("%d",&PROCESS_SIZE);

        printf("\nEnter Page size : ");
        scanf("%d",&PAGE_SIZE);

    }while(( LogicalMemorySize%2!=0) && (PAGE_SIZE%2!=0) );

    TOTAL_PAGES = PROCESS_SIZE / PAGE_SIZE;

    if (PROCESS_SIZE%PAGE_SIZE != 0)
            TOTAL_PAGES ++;

    for(i=0;i<TOTAL_PAGES;i++)
    {

        printf("\nEnter content of Page [%d]\n",i+1);
        for(j=0;j<PAGE_SIZE;j++)
            {
               printf("\tEnter content [%d] : ",j+1);
               scanf("%s",PageSeg[i].page[j].content);
               terminate ++;

               if(terminate == PROCESS_SIZE)
                    break;
            
            }
    }

    //Getting Frame Number
    printf("\n__ Enter Frame numbers for Corresponding to the Page numbers __\n");
    for(i=0;i<TOTAL_PAGES;i++)
      {
        UNIQUE:
            printf("\nEnter the Frame number of page %d : ",i+1);
            scanf("%d",&PAGE_FRAME[i]);

            // Check whether the Frame number is already given
            for(j=0;j<i;j++){
                if(PAGE_FRAME[i] == PAGE_FRAME[j])
                    goto UNIQUE;
            }
      }

     //Printing Physical Memory
    terminate=0;
    printf("\n\tPhysical Memory\n");

    for(i=0;i<TOTAL_PAGES;i++){
        printf("\nContent of Page[%d]",i+1);
        printf("\nFrame No : %d",PAGE_FRAME[i]);

        for(j=0;j<PAGE_SIZE;j++)
        {
            printf("\n\tContent : %s ",PageSeg[i].page[j].content);
            terminate++;
            if(terminate == PROCESS_SIZE)
                break;
        }
    }

}
void PageRestore(){

    int page_no,cont_no;

    printf("\nEnter the Page Number : ");
    scanf("%d",&page_no);
    printf("\nEnter content index : ");
    scanf("%d",&cont_no);

    printf("\nPage No : %d",page_no);
    printf("\nFrame No : %d",PAGE_FRAME[page_no]);
    printf("\nContent : %s",PageSeg[page_no].page[cont_no].content);
}