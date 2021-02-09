#include<stdio.h>

void swap(int *a, int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void MinHeapify(int A[],int n,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;

    while(l<n && A[l]<A[smallest])smallest=l;
    while(r<n && A[r]<A[smallest])smallest=r;
    if(smallest!=i){
        swap(&A[smallest],&A[i]);
        MinHeapify(A,n,smallest);
    }
}

void BuildMinHeap(int A[],int n){
    for(int i=n/2-1;i>=0;i--) MinHeapify(A,n,i);
    for (int i =n-1;i>0;i--) {
        swap(&A[0], &A[i]);
        MinHeapify(A,i, 0);
    }
}


void HeapInsertion(int A[],int n,int value){
    A[n-1]=value;
    BuildMinHeap(A,n);
}

int main(){
    int n=0,i,A[100],x;

        for(i=0;;i++){
        printf("Enter numbers: ");
        scanf("%d",&x);
        if(x==EOF) break;
        n++;

        HeapInsertion(A,n,x);
    }


    printf("The min heap:\n");
    for(i=0;i<n;i++){
        printf("%8d ",A[i]);
    }
    printf("\n");

 return 0;
}
