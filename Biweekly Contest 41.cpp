class Solution {

//1684. Count the Number of Consistent Strings
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        vector<bool>vals(words.size(), true); 
        for (int i = 0; i < words.size(); i++) {
            for(auto c : words[i]) {
                if(!(allowed.find(c) != std::string::npos)) vals[i] = false; 
            }
        }
        for(const auto& i: vals) {
            if(i) res++;
        } 
        return res; 
    }
    
    
    
    
//	1685 Sum of Absolute Differences in a Sorted Array 
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int s = 0, sum = accumulate(nums.begin(), nums.end(), 0); 
        vector<int>res; 
        for(int i = 0; i < nums.size(); i++) {
            sum -= nums[i]; 
            res.push_back(s + (i * nums[i]) - (nums.size() - i - 1) * nums[i] + sum); 
            s -= nums[i]; 
        }
        return res;  
  }
    
    
    
    
//1686 Stone Game VI    
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int res = 0; 
        vector<pair<int, int>> s; 
        for (int i = 0; i < bobValues.size(); i++) {
            s.push_back({aliceValues[i] + bobValues[i] ,i});    
        }
        sort(s.begin(), s.end(), [&](pair<int,int>& a, pair<int,int>&b){
            return a.first > b.first; 
        }); 
        for (int i = 0; i < s.size(); i++) {
            int j = s[i].second; 
            if(i & 1){
                res -= bobValues[j]; 
            }
            else {
                res += aliceValues[j]; 
            }
        }
        if (res == 0) return 0;
        return res > 0 ? 1: -1; 
         
    }




//1687. Delivering Boxes from Storage to Ports


};
