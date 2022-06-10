#include<iostream>
using namespace std;

void BubbleSort(int A[], int n){

    //Setting flag to "0"
    int flag = 0;

    for(int k=0 ; k<n-1 ; k++){

        for(int j=0 ; j<n-k-1 ; j++){

            //Checking if an current element is greater then the successor
            if(A[j] > A[j+1]){

                //Swapping algorithm
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;

                //Now that a change is made set flag to "1"
                flag = 1;
            }

        }

        //If flag is still "0" i.e no changes were made, so break immediately
        if(flag == 0){
            cout << "Already Sorted\n";
            break;
        }
    }
}

int main(){
    int A[5] = {5,4,3,2,1};
    int n = sizeof(A)/sizeof(A[0]);

    //Traversing the array
    cout << "Before\n";
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }cout << endl;

    BubbleSort(A,n);

    //Traversing the array
    cout << "After\n";
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }cout << endl;

    return 0;
}