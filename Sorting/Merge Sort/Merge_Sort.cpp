#include<iostream>
using namespace std;

void merge(int A[], int start, int mid, int end){

    //Getting the size from "start->mid" and "mid+1->end"
    int a = mid - start + 1;
    int b = end - mid;

    //Creating Arrays of resp. size "a" and "b"
    int X[a];
    int Y[b];

    //Inserting the elements from the main Array "A" into these sub Arrays "X" and "Y"
    for(int i = 0; i < a; i++){
        X[i] = A[start + i];
    }

    for(int j = 0; j < b; j++){
        Y[j] = A[mid + 1 + j];
    }

    //Now we got two Arrays that need to be "merged", So we will apply merge procedure to these two Arrays "X" and "Y"
    //NOTE: Array with single element is "Sorted"

    //Initializing and declaring indeices for each Array A,B and C resp.
    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    //As far as the "index" of A and B are smaller than their "size"
    while(i < a && j < b){
        //if "ith" element of "A" is smaller than "jth" element of "B"
        if(X[i] <= Y[j]){
            //Add the smaller i.e A[i] to C[k] to maintain ascending order
            A[k] = X[i];
            //increment i to look for next index in array "A"
            i++;
        }
        else{
           //if "ith" element of "A" is greater than "jth" element of "B"
           //Add the smaller i.e B[j] to C[k] to maintain ascending order
           A[k] = Y[j];
           //increment i to look for next index in array "A"
           j++;
        }
        //increment "k" for both the above conditions
        k++;
    }

    //If one of the array finishes before the other, there are elements in the other
    //Obviously, the elements in other will be in ascending order and no elemnet left in former
    //So add every element of unfinished array to C[k]

    //1. If B[] gets finished first and there are elements in A[]
    while(i < a){
        A[k] = X[i];
        i++;
        k++;
    }
    //2. If A[] gets finished first and there are elements in B[]
    while(j < b){
        A[k] = Y[j];
        j++;
        k++;
    }
}

void MergeSort(int A[], int start, int end){

    if(start < end){

        int mid = (start + end) / 2;

        MergeSort(A, start, mid);
        MergeSort(A, mid + 1, end);

        merge(A, start, mid, end);
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

    MergeSort(A, 0, n-1);

    cout << "After\n";
    printArr(A, n);

    return 0;
}