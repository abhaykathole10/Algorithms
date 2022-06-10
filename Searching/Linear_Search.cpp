//LINEAR SEARCH ALGORITHM C++
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int val){
    for(int i=0; i<n; i++){
        if(arr[i] == val){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int num[10] = {14,5,9,2,45,7,58,31,6};
    int n, k, res;

    n = sizeof(num)/sizeof(num[0]);

    cout << "Enter key: ";
    cin >> k;

    res = linearSearch(num, n, k);

    if(res == -1){cout << "Not Found";}
    else{cout << "The element is present at position " << res;}

    return 0;
}

/*
Also called "Sequential Search Algorithm"
Generally used for unsorted array
Worst case time complexity is O(n)
*/