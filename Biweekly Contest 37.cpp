class Solution {
    //1619. Mean of Array After Removing Some Elements 
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        int len = arr.size(), d= 5* len/100;
        double res = 0; 
        for(int i = d; i < (arr.size() - d); i++){
            res +=arr[i];
        }
        return res/(len-2* d); 
    }
    
    
 //1620. Coordinate With Maximum Network Quality --> observation from discussion: optimal point isn't actually a tower 
 // TestCase doesn't work : [[1,0,2],[0,1,2],[2,1,2],[1,2,2]] 1
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
      if(!towers.size()) return {}; 
      sort(towers.begin(), towers.end(), [](vector<int>&a, vector<int>&b){             
          if(a[0] < b[0])return true; 
          else if(a[0] == b[0]) return a[1] < b[1]; 
          return false; 

      }); 

  pair<int,int> BestTower = {0,0};
  int res = INT_MIN;
  for(int i = 0; i < towers.size(); i++){
      int bestVal= 0; 
      for(int j = 0; j < towers.size(); j++){
          double distX = abs(towers[i][0] - towers[j][0]), distY = abs(towers[i][1] - towers[j][1]);
          double euclideanDistance = sqrt(distX * distX + distY * distY); 
          if(euclideanDistance <= radius){
              bestVal += towers[j][2] / (1 + euclideanDistance); 
          }
      }
      if(bestVal > res){
          res = bestVal; 
          BestTower.first = towers[i][0], BestTower.second = towers[i][1]; 
      }

  }

  return {BestTower.first, BestTower.second}; 

  }
  
  //TO DO: 
  //1621. Number of Sets of K Non-Overlapping Line Segments
   //combinatoric problem: multiplicative Inverse may be used : C(n+k-1,2k) mod 1e9+7 is our result;     
   
   
  //1622. Fancy Sequence - Design an API 

};
