#include<stdlib.h>
#include<stdio.h>

int nearest_ele(int q[],int n,int head_pos)
{
    int min=9999,nearest=-1;
    
    for(int i=0;i<n;i++){
        if(q[i]!=-1){
            int x=abs(head_pos-q[i]);
            if( x < min){
                min=x;
                nearest=i;
            }
        }
    }
    return nearest;
    
  

}
void main(){
    int head_pos;
    int q[20],n,dist[20];
    int total_head_movement=0;
    printf("\nEnter no of request >> ");
    scanf("%d",&n);
    printf("\nEnter the rq below. \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    
    
    printf("\nEnter the initial head position >> ");
    scanf("%d",&head_pos);
    
    for(int i=0;i<n;i++){
        dist[i]=0;
    }
    
    for(int i=0;i<n;i++){
        int nearest = nearest_ele(q,n ,head_pos);
        dist[i] = abs(head_pos - q[nearest]);
        head_pos=q[nearest];
        q[nearest]=-1;
        }
    
    for(int i=0;i<n;i++){
            total_head_movement +=dist[i];    
            }
    printf("\nTotal head movement is >> %d",total_head_movement);

}