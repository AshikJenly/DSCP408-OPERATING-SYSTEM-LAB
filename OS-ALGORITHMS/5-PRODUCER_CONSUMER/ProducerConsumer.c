#include<stdio.h>
#include<string.h>

typedef struct Product
{
    int top,wait_size;
    char name[20][20];
    char wait[20][20];
}Product;
Product prod = {0,0};

void main(){
    void Produce();
    void Consume();
    int ch;
    do{
         printf("\n1.produce\n2.consume\n3.Exit\nEnter your choice:");
         scanf("%d",&ch);
         switch (ch)
         {
         case 1:
            Produce();
            break;
         
          case 2:
            Consume();
            break;
        
          case 3:
            return;
         }
    }
    while(ch<3);
}
void Produce()
{
    
    // Get Product Name
    int i,j,k,isMoved=0;//for iteration

    char product_name[20];
    printf("\nEnter Process name : ");
    scanf("%s",product_name);

    for(i=0;i<=prod.top;i++)
    {
        //check whether the process was already available
        if(strcmp(prod.name[i],product_name) == 0)
            {
            printf("\n\tProcess already exists");
            return;
            }
        //check whether the process in waiting list ,if it is then remove it from waiting list
        if(strcmp(prod.wait[i],product_name) == 0)
            {
             printf("\n\tProcess %s has been Consumed\n",product_name);
             for(k=i;k<=prod.wait_size;k++)
                if(k<20)
                    strcpy(prod.wait[k],prod.wait[k+1]);
            prod.wait_size --;
            return;
            }
    }

    strcpy(prod.name[prod.top++],product_name);

    printf("\n\tList Of All Produced Process => ");
    for(i=0;i<=prod.top;i++)
        printf("\n%s",prod.name[i]);

}
void Consume()
{
    char product_name[20];
    int i,j,isMoved=0,isConsumed=0;
    printf("\nEnter process name to consume : ");
    scanf("%s",product_name);

    for(i=0;i<=prod.top;i++)
    {
        if(strcmp(product_name,prod.name[i]) == 0)
        {
            printf("\nProcess %s has been Consumed",product_name);
            isConsumed = 1;
            for(j=i;j<=prod.top;j++)
            {
                if(j<20){
                    strcpy(prod.name[j],prod.name[j+1]);
                    isMoved=1;
                    }
            }
        }
    }
    if (isMoved)
        prod.top --;
    if(isConsumed ==0)
    {
        strcpy(prod.wait[prod.wait_size++],product_name);

        printf("\n\tList of all waiting process =>");
        for(i=0;i<prod.wait_size;i++)
            printf("\n%s",prod.wait[i]);
    }

}
