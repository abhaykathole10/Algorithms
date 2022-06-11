#include<iostream>
using namespace std;

void merge(int *A, int *B, int *C, int a, int b){
    //Initializing and declaring indeices for each Array A,B and C resp.
    int i=0, j=0, k=0;

    //As far as the "index" of A and B are smaller than their "size"
    while(i<a && j<b){
        //if "ith" element of "A" is smaller than "jth" element of "B"
        if(A[i] < B[j]){
            //Add the smaller i.e A[i] to C[k] to maintain ascending order

            C[k] = A[i];
            //increment i to look for next index in array "A"
            i++;
        }
        else{
           //if "ith" element of "A" is greater than "jth" element of "B"
           //Add the smaller i.e B[j] to C[k] to maintain ascending order
           C[k] = B[j];

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
    while(i<a){
        C[k] = A[i];
        i++;
        k++;
    }
    //2. If A[] gets finished first and there are elements in B[]
    while(j<b){
        C[k] = B[i];
        j++;
        k++;
    }
}

//Function to print an array arr[] of size n
void printArr(int arr[], int n){
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << "  ";
    }cout << endl;
}

int main(){
    //Taking sorted array as inputs
    int A[5] = {2,6,7,9,11};
    int B[5] = {1,3,5,8,10};

    //Array inwhivh we have to merge
    int C[10];

    printArr(A, 5);
    printArr(B, 5);

    merge(A, B, C, 5, 5);

    printArr(C, 10);

    return 0;
}