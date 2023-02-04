class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int result = 1;
        int n = prizePositions.size();
        
        vector<int> max_ending_till(n);
        max_ending_till[0] = 1;
        
        for (int end = 1; end < n; end ++) {
            int min_value = prizePositions[end] - (k + 1) + 1;
            int start = 
                upper_bound(prizePositions.begin(), prizePositions.begin()+end, min_value - 1) - prizePositions.begin();
            
            max_ending_till[end] = max (max_ending_till[end-1], end - start + 1);      
            result = max (
                result, 
                (start > 0? max_ending_till[start-1] : 0) + (end - start + 1)
            );
        }
        return result;
    }
};
