#include<iostream>
using namespace std;

void SelectionSort(int A[], int n){

    //Looping from 0 to n-1, last member need not to be looped
    for(int i = 0; i < n-1 ; i++){

        //Setting "ith" element to smallest
        int iMin = i;

        //Looping from very next of "iMin" to the last element
        for(int j = i+1 ; j < n; j++){

            //Checking if there exist any number smaller then current "iMin"
            if(A[j] < A[iMin]){
                //If yes, then "iMin"(index) = that smaller number index(k)
                iMin = j;
            }
        }
        //Swapping logic
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
    }
}

int main(){
    int A[] = {3,6,1,8,4,9,5,7,2};
    int n = sizeof(A)/sizeof(A[0]);

    //Traversing the array
    cout << "Before\n";
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }cout << endl;

    SelectionSort(A,n);

    //Traversing the array
    cout << "After\n";
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }cout << endl;

    return 0;
}