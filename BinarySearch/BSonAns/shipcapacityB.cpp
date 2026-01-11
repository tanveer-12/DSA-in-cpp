/*  CAPACITY TO SHIP PACKAGES WITHIN D DAYS
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Brute Force - Linear looping
TC - O((sum_weights - max_weight) * N), where N is the number of packages. For each capacity between max weight and total sum, we simulate shipping over N packages.
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
    int daysNeeded(std::vector<int>&weights, int capacity){
        int days = 1, load = 0;
        for(int w: weights){
            if(load + w > capacity){
                days++;
                load = w;
            }
            else{
                load += w;
            }
        }
        return days;
    }
    int minCapacity(std::vector<int>&weights, int d){
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        for(int cap = left; cap<= right; cap++){
            int daysReq = daysNeeded(weights, cap);
            if(daysReq <= d){
                return cap;
            }
        }
        return right;
    }
};

int main(){
    std::vector<int> weight = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    Solution obj;
    std::cout<<"Least Capacity: "<<obj.minCapacity(weight, days);
    return 0;
}