/*  AGGRESSIVE COWS
You are given an array 'arr' of size 'n' which denotes the position of stalls. 
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum 
distance between any two of them is the maximum possible. Find the maximum possible 
minimum distance.

OPTIMIZED SOLUTION: BINARY SEARCH

TC - O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))),
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
    bool canPlace(std::vector<int> &stalls, int cows, int dist){
        // place first cow to the first stall
        int count = 1;  // this is the first cow count 
        int lastPos = stalls[0]; // positioning the first cow to the 0th index, that is at the first stall
        // try placing the remaining ones
        for(int i=1; i<stalls.size(); i++){
            // if current stall is atleast 'dist' distance away from the last cow placed
            if(stalls[i] - lastPos >= dist){
                // then place the cow here
                count++;
                lastPos = stalls[i];
            }
            // if all the cows are placed successfully, return true
            if(count >= cows){return true;}
        }
        return false;
    }
    int aggressiveCows(std::vector<int> &stalls, int cows){
        // sorting the array
        std::sort(stalls.begin(), stalls.end());
        // get maximum possible distance
        int n = stalls.size();
        int low = 1;
        int ans=0;
        int high = stalls[n-1] - stalls[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            // if the mid distance is possible, update
            // the result and search for larger distance
            if(canPlace(stalls,cows,mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        // returning the high as high will be pointing to the possible polarity by the end of the while loop
        // as the low will be going towards the right impossible polarity
        // so at the end of the while loop, high will contain our answer
        return high; // returning the maximum valid distance
    }
};

int main(){
    std::vector<int> stalls = {0,3,4,7,9,10};
    int cow = 4;
    Solution obj;
    std::cout<<"The maximum possible minimum distance between any two cows is: "<<obj.aggressiveCows(stalls,cow);
    return 0;
}