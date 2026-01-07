/*  FINDING A SQRT OF A NUMBER USING BS
You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n). 

TC - O(logN)
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
 // This function returns the floor value of the square root of a number
    int findSqrt(int nums){
        // Handle small numbers directly
        if (nums < 2) return nums;
        int low = 1, high = nums/2;
        int ans = 0;
        while(low <= high){
            long long mid = low + (high - low) /2 ;
            if(mid * mid <= nums){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    int num;
    std::cout<<"Enter the number: ";
    std::cin>>num;
    Solution obj;
    std::cout<<"Sqrt of "<<num<<" is: "<<obj.findSqrt(num);
    return 0;
}