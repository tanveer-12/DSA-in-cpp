// pushing the maximum to the last by adjacent swap

#include <bits/stdc++.h>

void bubblesort(int arr[], int n){
    for(int i=n-1;i>=0;i--){
        int didswap = 0;
        for(int j=0;j<=i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didswap = 1;
            }
        }
        // if the array is already sorted, just break out of the loop
        if (didswap == 0){
            break;
        }
        std::cout<<"runs\n";
    }
}

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    bubblesort(arr, n);
    for(int i=0; i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}