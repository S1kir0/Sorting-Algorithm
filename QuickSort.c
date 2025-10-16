#include <stdio.h>
#include <time.h>
#define MAXSIZE 10

//划分
int Partition(int arr[],int low,int high) {
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {          //high指针大于枢轴
            --high;
        }
        arr[low] = arr[high];           //high指针小于枢轴---high指针指向元素移至low指针位置
        while (low <high && arr[low] <= pivot) {            //low指针小于枢轴
            ++low;
        }
        arr[high] = arr[low];           //low指针大于枢轴---low指针指向元素移至high指针位置
    }
    arr[low] = pivot;           //当low==high,跳出while，low所指位置即为枢轴
    return low;
}

//快速排序
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(arr, low, high);
        QuickSort(arr, low, pivotpos - 1);
        QuickSort(arr, pivotpos + 1, high);
    }
}

int main() {
    int arr[MAXSIZE];
    clock_t start,end;
    double cpu_time_used;

    printf("Enter %d Array Elements (separated by spaces): ", MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0;
    int high = MAXSIZE - 1;

    start = clock();
    QuickSort(arr,low,high);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The Sorted Array is:\n");
    for (int i = 0; i < MAXSIZE; i++) {
        printf("%d ",arr[i]);
    }
    printf("Processing time:%f ms",cpu_time_used*1000);
    return 0;
}