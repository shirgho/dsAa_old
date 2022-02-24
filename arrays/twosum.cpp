#include<bits/stdc++.h>

using namespace std;


vector<int> SortAndSearch(vector<int>& nums, int target)
{
    // Sort and Binary Search 
    // O(n) + O(n log(n)) = O(n log(n))
    // Sort array in increasing order, then binary search to find complement
    // lower bound is effectively binary search but equivilancy test necessary
    // as might return position where the element "should" be, if it couldn't find it
    vector<int> copyNums = nums;
    std::sort(copyNums.begin(), copyNums.end());

    for (auto i = copyNums.begin(); i != copyNums.end(); ++i){
        
        int complement = target - *i;
        std::cout << "complement: " << complement << endl;
                
        auto lower = std::lower_bound(copyNums.begin(), copyNums.end(), complement);

        if(lower != copyNums.end() && *lower == complement){
            std::cout << *i << " at index " << std::distance(nums.begin(), i);
            std::cout << *lower << " at index " << std::distance(nums.begin(), lower);
            // sorted array means original indices lost
            return { static_cast<int> (std::distance(nums.begin(), i)), static_cast<int> (std::distance(nums.begin(), lower)) };
        } 
        
        std::cout << '\n';    
    }
}


//two pointer solution O(n log(n))
vector<int> twoSum(vector<int>& nums, int target) {
    int front = 0, rear = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while(front < rear) {
      int sum = nums[front] + nums[rear];
      if (sum == target)
        break;
      else if (sum > target)
        rear--;
      else
        front++;
    }
    return {front, rear};
};

//brute force solution O(n²)
vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(nums[j] == target - nums[i])
                return { i, j };
        }
    }
    return {-1, -1};
};
// hash map solution O(n) but O(n) space also
// put the numbers from vector as key, and the index as value
vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> map;
      vector<int> pairs;
      for(int i = 0; i < nums.size(); i++) {
          int complement = target - nums[i];
          if(map.find(complement) != map.end()) {
              pairs.push_back(map.find(complement)->second);
              pairs.push_back(i);
              break;
          }
          map.insert(pair<int, int>(nums[i], i));
      }
      return pairs;
};

int main() {
  vector<int>nums = {1,4,3,6,5,8};
  vector<int>pair = twoSum(nums,4);
  cout << "pair indices are : " << pair[0] << " " << pair[1] << endl;
  return 0;
}