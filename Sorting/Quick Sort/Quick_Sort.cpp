#include <iostream>
using namespace std;

int Partition(int *A, int start, int end){
    int pivot = A[end];
    int partIndex = start;
    for(int i=start; i<end; i++){
        if(A[i] <= pivot){
            swap(A[i], A[partIndex]);
            partIndex++;
        }
    }
    swap(A[partIndex], A[end]);
    return partIndex;
}

void QuickSort(int *A, int start, int end){
    if(start < end){
        int partIndex = Partition(A, start, end);
        QuickSort(A, start, partIndex-1);
        QuickSort(A, partIndex+1, end);
    }
}

int main(){
    int A[] = {77,44,2,31,43,98,5,3,54,7,23,14,1};
    int n = sizeof(A)/sizeof(A[0]);

    //Traversing the array
    cout << "Before\n";
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }cout << endl;

    QuickSort(A,0,n-1);

    //Traversing the array
    cout << "After\n";
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }cout << endl;

    return 0;
}