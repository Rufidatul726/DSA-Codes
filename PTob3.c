#include<stdio.h>

int in[100]={0},pre[100]={0},tree[100]={0},post[100]={0};
int size,count=1,flag=1,element=1;



void f(int start, int end,int flag){
    int i;
    if(start>end || count>size || flag>element-1)return;
    tree[flag]=pre[count];
    for(i=start;i<=end;i++){
        if(pre[count]==in[i]){
                count++;
            f(1,i-1,2*flag);
            f(i+1,end,2*flag+1);
        }
    }

}

int main (void){
    int i,choose=1,h;

    printf("What do you want to do: \n\t1. Preorder & Inorder To generate binary tree\n\t2. Postorder & Inorder To generate binary tree\n");
    scanf("%d",&choose);

    printf("Enter height of the array: ");
    scanf("%d",&h);

    for(i=1;i<=h;i++)element=element*2;

    printf("Enter Size of the array: ");
    scanf("%d",&size);
    printf("Enter Inorder array: ");
    for(i=1;i<=size;i++){scanf("%d",&in[i]);}

     if(choose==1){
        printf("Enter preorder array: ");
        for(i=1;i<=size;i++){scanf("%d",&pre[i]);}
     }

     else if(choose==2){
        printf("Enter postorder array: ");
        for(i=size;i>0;i--){scanf("%d",&pre[i]);}
     }
    else return 0;

    f(1,size,1);

    for(i=1;i<=element;i++)printf("%d ",tree[i]);
    return 0;
}
