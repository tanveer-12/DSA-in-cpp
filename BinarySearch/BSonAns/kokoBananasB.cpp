/*  KOKO EATING BANANAS
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] 
bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some 
pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, 
she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before 
the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

BRUTE FORCE - LINEAR SEARCH APPROACH
TC - O(N*MAX(ARR[]))
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
    // Function to calculate total hours for given speed
    int calculateTotalHours(std::vector<int>& a, int hourly) {
        int totalHours = 0;
        for (int pile : a) {
            // Add hours using ceil
            totalHours += (pile + hourly - 1) / hourly;
        }
        return totalHours;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(std::vector<int>& a, int h) {
        // Find maximum pile size
        int maxVal = *max_element(a.begin(), a.end());

        // Try every possible speed
        for (int i = 1; i <= maxVal; i++) {
            int hours = calculateTotalHours(a, i);

            // If hours fit within h
            if (hours <= h) {
                return i;
            }
        }
        return maxVal;
    }
};

int main(){
    std::vector<int> nums = {3,6,7,11};
    int hours = 8;
    Solution obj;
    std::cout<<"minimum bananas/hr are: "<<obj.minEatingSpeed(nums, hours);
    return 0;
}