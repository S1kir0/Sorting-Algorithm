#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#define MAXSIZE 10

int swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//冒泡排序---从大到小
void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool flag = false;
        for (int j = size - 1; j > i; j--) {
            if (arr[j] > arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
                flag = true;
            }
        }
        if (flag == false) {
            return;
        }
    }
}
int main() {
    int arr[MAXSIZE];
    double_t start,end;
    double cpu_time_used;

    printf("Enter %d Array Elements (separated by spaces): ", MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++) {
        scanf("%d",&arr[i]);
    }

    start = clock();
    BubbleSort(arr, MAXSIZE);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The Sorted Array is:\n");
    for (int i = 0; i < MAXSIZE; i++) {
        printf("%d ",arr[i]);
    }
    printf("\nProcessing time:%f ms",cpu_time_used*1000);
    return 0;
}