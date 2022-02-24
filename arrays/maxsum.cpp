#include<bits/stdc++.h>

using namespace std;



    // using Kadane's scanning algorithm O(n)
    int maxSubArrayK(vector<int>& nums) {
        int curSum = 0, bestSum = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            curSum = max(nums[i], curSum + nums[i]);
            bestSum = max(curSum, bestSum);
        }
        
        return bestSum;
    }
    
    int maxSubArrayDCH(vector<int>& nums, int l, int u){
        if (l > u) return INT_MIN;
        if (l == u) return nums[l];
        
        // get mid point
        int m = (l + u) / 2;
        
        int lmax = INT_MIN, sum = 0;
        //calculate sum from mid into left side
        for(int i = m; i >= l; i--){
            sum += nums[i]; //-2
            lmax = max(lmax, sum); // -2
        }
        
        int rmax = INT_MIN;
        sum = 0;
        //calculate sum from mid into right side
        for(int i = m+1; i <= u; i++){
            sum += nums[i]; // -1
            rmax = max(rmax, sum); // -1
        }
        
        //call function recursively, passing it the mc, ml, mu
        // -3, (-2), (-1)
        return max({lmax + rmax, maxSubArrayDCH(nums, l, m), maxSubArrayDCH(nums, m+1, u)});
    }
    
    // using divide and conquer O(n log(n))
    int maxSubArrayDC(vector<int>& nums) {
        return maxSubArrayDCH(nums, 0, nums.size() - 1);
    }
    
     
    
    
    // using dynamic programming
    int maxSubArrayDP(vector<int>& nums) {

    }
    

int main() {
  vector<int>nums = {1,4,3,6,5,8};

  cout << "max sum is: " << maxSubArrayK(nums) << endl;
  return 0;
}