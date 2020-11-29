class Solution {

    // 1668 Maximum Repeating Substring 
    int maxRepeating(string sequence, string word) {
        if(word.length() >= sequence.length())return word == sequence ? 1: 0; 
        int k =0,i = 0, len = word.length(),globalRes =0, res = 0; 
        string window = ""; 
        for(int i= 0; i+ len<= sequence.length() ; i++){
          //  window+=sequence[i]; 
            window = sequence.substr(i,len); 
            if(window == word){
                res++;
                i+=len-1; 
            }
            else res = 0; 
            globalRes = max(res, globalRes); 
        }
            
        return globalRes; 
    }
    
    
    //elegante Lösung wäre: 
    int maxRepeating(string sequence, string word){
      size_t found = sequence.find(word); 
      int res = 0; 
      string temp = word; 
      while(sequence.find(temp) != string::npos){
        res++; 
        temp+=word; 
      }
      return res; 
    }
    
    
    
    //1669. Merge In Between Linked Lists
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2){
      ListNode* t1 = list1, *t2 = list1; 
      int i; 
      for(i = 1; i < a; i++)t1 = t1->next; 
      for(i = 0; i <=b; i++)t2= t2->next; 
          t1->next = list2;  
      for(; t1 ->next!=nullptr; t1 = t1->next); 
          t1->next = t2; 
      return list1; 
    }
    
    
    
    //1670 Design Front Middle Back Queue 
    class FrontMiddleBackQueue {
    vector<int> v; 
public:
    FrontMiddleBackQueue() {
         
    }
    
    void pushFront(int val) {
        v.insert(v.begin(),val); 
    }
    
    void pushMiddle(int val) {
        v.insert(v.begin() + v.size() / 2,val); 
    }
    
    void pushBack(int val) {
        v.push_back(val); 
    }
    
    int popFront() {
        if(v.empty())return -1; 
        int res = v[0]; 
        v.erase(v.begin()); 
        return res; 
    }
    
    int popMiddle() {
        if(v.empty())return -1; 
        int res = v[(v.size() -1)/ 2]; 
        v.erase(v.begin() + (v.size() -1)/ 2); 
        return res; 
    }
    
    int popBack() {
        if(v.empty())return -1; 
        int res = v.back(); 
        v.pop_back(); 
        return res; 
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
    
    
    
    
    //1671. Minimum Number of Removals to Make Mountain Array
    //meine initiale Lösung scheiterte am 70en TestCase: 
    int lengthOfLIS(vector<int>& nums, int s, int n) {
        vector<int> res; 
        for(int i = s; i < n; i++){
            if(res.size()== 0||nums[i]>res.back())res.push_back(nums[i]); 
            else *lower_bound(res.begin(),res.end(),nums[i])=nums[i]; 
        }
        return (n-s) - res.size(); 
    }  
     
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>c= nums; 
        reverse(c.begin(), c.end()); 
        int res = nums.size(); 
         for(int i=0; i < nums.size(); i++){
              res = min(lengthOfLIS(nums,0,i+1) + lengthOfLIS(c,0, nums.size()-i), res); 
         }  
        return res; 
    }
    
    
    //korrekte Lösung: 
     int minimumMountainRemovals(vector<int>& nums) {
        int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < i; j ++) if(nums[i] > nums[j]) pre[i] = max(pre[j], pre[i]);
            pre[i] += 1;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j > i; j--) if(nums[i] > nums[j]) suf[i] = max(suf[j], suf[i]);
            suf[i] += 1;
        }
        int res = 0;
        for(int i = 0; i < n; i++) if(pre[i] >= 2 and suf[i] >= 2) res = max(res, pre[i] + suf[i] - 1);
        return n - res;
    }
};
