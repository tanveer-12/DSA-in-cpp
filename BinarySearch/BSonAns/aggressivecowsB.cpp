/*  AGGRESSIVE COWS
You are given an array 'arr' of size 'n' which denotes the position of stalls. 
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum 
distance between any two of them is the maximum possible. Find the maximum possible 
minimum distance.

BRUTE FORCE: LINEAR

TC - O(N)*O(max(stalls[])-min(stalls[])) 
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
        int maxD = stalls[n-1] - stalls[0];
        // to store ans
        int ans = 0;
        // try all possible distance from 1 to maxD
        for(int d=1; d<= maxD; d++){
            // if cows can be placed with distance d
            if(canPlace(stalls,cows ,d)){
                ans = d;
            }
        }
        return ans; // returning the maximum valid distance
    }
};

int main(){
    std::vector<int> stalls = {0,3,4,7,9,10};
    int cow = 4;
    Solution obj;
    std::cout<<"The maximum possible minimum distance between any two cows is: "<<obj.aggressiveCows(stalls,cow);
    return 0;
}