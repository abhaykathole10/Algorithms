#include<iostream>
using namespace std;

void InsertionSort(int A[], int n){
    for(int i=1 ; i<n ; i++){
        int value = A[i];
        int hole = i;

        while(hole > 0 && A[hole-1] > value){
            A[hole] = A[hole-1];
            hole = hole-1;
        }
        A[hole] = value;
    }
}

int main(){
    int A[5] = {5,4,3,2,1};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Before\n";
    for(int i=0; i<n; i++){
        cout << A[i] << "  ";
    }

    InsertionSort(A, n);

    cout << "\nAfter\n";
    for(int i=0; i<n; i++){
        cout << A[i] << "  ";
    }

    return 0;
}