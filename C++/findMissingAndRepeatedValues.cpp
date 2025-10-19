class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      int n = grid.size();
      map<int, int> mp;
      for(int i=1;i<=n*n;i++){
        mp[i]++;
      }
      for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            mp[grid[i][j]]--;
        }
      }
      int missing =0, repeat =0;
      for(auto x:mp){
        if(x.second <0){
            repeat = x.first;
        }
        if(x.second > 0){
          missing = x.first;
        }
      }
      
      return {repeat, missing};
    }
};
