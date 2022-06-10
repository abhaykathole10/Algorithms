//BINARY SEARCH ALGORITHM
#include <iostream>
using namespace std;

int binarySearch(int a[], int beg, int end, int val){
    int mid;

    if(end >= beg){

        mid = beg+end/2;

        if(a[mid] == val){
            return mid+1;
        }
        else if(val < a[mid]){
            end = mid-1;
            return binarySearch(a, beg, end, val);
        }
        else{
            return binarySearch(a, mid+1, end, val);
        }
    }
    return -1;
}

int main(){
    int arr[10] = {2,5,8,13,16,21,25,29,33,40};
    int key, beg, end, res, n;

    n = sizeof(arr)/sizeof(arr[0]);

    beg = 0;
    end = n-1;

    cout << "Enter Key: ";
    cin >> key;

    res = binarySearch(arr, beg, end, key);

    if(res==-1){cout << "Not Found";}
    else{cout << "The element is present at position " << res;}

    return 0;
}

/*
Also called "Divide and Conquer Algorithm"
Array should be "Sorted"
Worst case time complexity is O(log n)
*/