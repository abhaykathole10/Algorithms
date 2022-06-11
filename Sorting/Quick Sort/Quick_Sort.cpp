#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

int partitionEle(int A[], int start, int end){

    //Setting pivot to rightmost element of the array i.e "end"
    int pivot = A[end];

    //Setting "i" to "start-1" i.e "to nothing"
    int i = start-1;

    //Iterarting from start to end till the pivot
    for(int j = start ; j < end ; j++){

        //If an element is smaller than pivot
        if(A[j] <= pivot){

            //Step 1: increase "i"
            i++;

            //Step 2: Swap the "smaller element" with current "i" i.e the "just incremented i"
            swap(&A[j] , &A[i]);

        }

    }
    //When no element is samller than the pivot

    //Step 3: Swap Pivot with the "i + 1 th" element
    swap(&A[i + 1], &A[end]);

    //Return the next index to "i" i.e "the just swapped"
    return (i + 1);
}

void QuickSort(int A[], int start, int end){

    if(start < end){

        //Partition "pi" will return the point from which the Array will be divided to search further
        int pi = partitionEle(A, start, end);

        //Running Quick sort on the left subarray
        QuickSort(A, start, pi - 1);

        //Running Quick sort on the right subarray
        QuickSort(A, pi + 1, end);
    }

}

//Function to print an array arr[] of size n
void printArr(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << "  ";
    }cout << endl;
}

int main(){
    //Taking "Unsorted" array as inputs
    int A[] = {32,45,13,67,59,96,21,32,15,7,44,70,5,30};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Before\n";
    printArr(A, n);

    //Passing the First and the last element
    QuickSort(A, 0, n-1);

    cout << "After\n";
    printArr(A, n);

    return 0;
}