class Solution {
  //1662. Check If Two String Arrays are Equivalent
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first, sec;
        for(auto i: word1){
            first +=i; 
        }
        for(auto i: word2){
            sec +=i; 
        }
        return first == sec; 
    }
    
    
    //1663. Smallest String With A Given Numeric Value
    string getSmallestString(int n, int k) {
      string res(n,'a'); 
      k-=n; 
      int len = n-1; 
      while(k){
        int add = min(k, 25); 
        res[len--] += add; 
        k-=add; 
      }
      return res; 
    } 


  //1664. Ways to Make a Fair Array
    int waysToMakeFair(vector<int>& nums) {
        int left[2] = {}, right[2] = {}; 
        for(int i = 0; i < nums.size(); i++){
            right[i % 2] += nums[i]; 
        }
        int res = 0; 
        for(int i= 0; i < nums.size(); i++){
            right[i % 2] -= nums[i]; 
            res += left[0] + right[1] == left[1] + right[0]; 
            left[i % 2] += nums[i]; 
        }
        return res; 
    }
    
    
    //1665. Minimum Initial Energy to Finish Tasks
        int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0]; 
        });  
        int res = 0, val = 0; 
        for(const auto& i: tasks){
            res= max(res, val + i[1]); 
            val += i[0]; 
        }
        return res; 
    }
    
};
