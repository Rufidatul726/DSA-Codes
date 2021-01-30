#include<stdio.h>

int max_size(int put){
    int count=1;
    while(put!=0){
        count=count*2;
        put--;
    }
    return count;
}
int level_(int input){
        int count=1;
        while(input!=0){
            input=input/2;
            count++;
    }
    return count;
}

void space(int m){
        while(m!=0){
            printf(" ");
            m--;
        }

}


int get_right_child(int index,int tree[],int complete_node){
    if(tree[index]!=0 && ((2*index)+1)<=complete_node)return (2*index)+1;
    return -1;
}

int get_left_child(int index,int tree[],int complete_node){
    if(tree[index]!=0 && (2*index)<=complete_node)return 2*index;
    return -1;
}

int get_parent(int index,int tree[],int complete_node){
    if(tree[index]!=0 && index/2!=0)return index/2;
    else    return -1;
}

void preorder(int index,int tree[],int complete_node){
    if(index>0 && tree[index]!=0){
        printf(" %d ",tree[index]);
        preorder(get_left_child(index,tree,complete_node),tree,complete_node);
        preorder(get_right_child(index,tree,complete_node),tree,complete_node);
    }
}

void postorder(int index,int tree[],int complete_node){
    if(index>0 && tree[index]!='\0'){
        postorder(get_left_child(index,tree, complete_node),tree, complete_node);
        postorder(get_right_child(index,tree,complete_node),tree,complete_node);
        printf(" %d ",tree[index]);
}
}

void inorder(int index,int tree[],int complete_node){
    if(index>0 && tree[index]!=0){
  inorder(get_left_child(index,tree,complete_node),tree,complete_node);
  printf(" %d ",tree[index]);
  inorder(get_right_child(index,tree,complete_node),tree,complete_node);
}
}

int main(void){
    int size,level,i,op;
    int tree[100]={0};

    printf("Enter Level of the binary tree:");
    scanf("%d",&level);

    printf("Enter size of the sequence of numbers: ");
    scanf("%d",&size);

    printf("Enter numbers sequentially: ");
    for(i=1;i<=size;i++){
        scanf("%d",&tree[i]);
    }

    printf("Generating binary Tree: \n");

    int max=max_size(level),k=1;

    for(i=0;i<level;i++){
            int oper=max_size(i);
        for(op=1;op<=oper;op++){
                if(op%2!=0){
                    space(max-1);
                     printf("%d",tree[k]);
                     space(max-1);
                     k++;
                }
                else{
                    space(max/2);
                    printf("%d",tree[k]);
                    k++;
                    space(max/2);
                }
            printf(" ");
        }
        max=max/2;
        printf("\n\n");
    }

    int complete_node=max_size(level);

    printf("Preorder:\n");
    preorder(1,tree, complete_node);
    printf("\nPostorder:\n");
    postorder(1,tree,complete_node);
    printf("\nInorder:\n");
    inorder(1,tree,complete_node);
    printf("\n");
    return 0;
}
