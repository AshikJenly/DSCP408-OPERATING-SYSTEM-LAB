#include<stdio.h>
#include<string.h>

int PAGEFRAMES[10],TOTAL_PAGES,STATUS[10];
char CONTENT[10][20];
int i,j; //for iteration
void printcont();
void demandStore();
void demandRestore();
void main()
{
     
   
    int ch;
    do {
        printf("\n1.demand paging-store\n2.demand paging-restore\n3.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch) { 
            case 1: demandStore(); break;
            case 2: demandRestore(); break;
            default: continue;
        }
    } while(ch != 3);
    return;
}
void demandStore()
{
    printf("\nEnter total number of pages : ");
    scanf("%d",&TOTAL_PAGES);

    for(i=0;i<TOTAL_PAGES;i++)
    {
        printf("\nEnter content of page %d : ",i);
        scanf("%s",CONTENT[i]);

        printf("\nEnter frame of the content : ");
        isUnique:
            scanf("%d",&PAGEFRAMES[i]);
            for ( j = 0; j < i; j++)
            {
                if(PAGEFRAMES[i]==PAGEFRAMES[j] && PAGEFRAMES[i] != -1)
                {
                    printf("\nallocated frame");
                    goto isUnique;
                }
            }
        if(PAGEFRAMES[i]<0)
            STATUS[i]=0;
        else 
            STATUS[i]=1;
            
    }

    printcont();

}

void demandRestore()
{
    int pno, i;
    printf("\n Enter page no to retrieve:");
    scanf("%d", &pno);
    if(STATUS[pno] == 1) {
        printf("page%d is already loaded \n", pno);
        // getch();
    }
    else{
        printf("\n page fault occur:");
        STATUS[pno]=1;
        PAGEFRAMES[pno] = 10;

    }
    printcont();
}
void printcont(){
     printf("\nPhysical memory\nPage No\tContent\tFrame No\tStatus ");
    for(i=0;i<TOTAL_PAGES;i++)
    {
        if(STATUS[i]==1)
                printf("\n%d\t%s\t%d\tvalid\n", i, CONTENT[i], PAGEFRAMES[i]);
        else
               printf("\n%d\t%s\tnull\tinvalid\n", i, CONTENT[i]);

    }

}
