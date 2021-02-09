#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l=2*i+1;
    int r=2*i+2;

    if (l < n && arr[l] > arr[largest])largest = l;
    if (r < n && arr[r] > arr[largest])largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

int main(void){
    int array[100]={0};
    int i,j,k,size;

    printf("Enter size of the array: ");
    scanf("%d",&size);

    printf("Enter array: ");
    for(i=0;i<size;i++)scanf("%d",&array[i]);

    for (int i=size/2 - 1;i>=0;i--)heapify(array, size, i);
    for (int i =size-1;i>0;i--) {
        swap(&array[0], &array[i]);
        heapify(array,i, 0);
    }

    for(i=0;i<size;i++){
        printf("%d ",array[i]);
    }


}
