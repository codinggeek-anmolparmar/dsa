class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count=0;
        int sum=0;
        int extra=0;
        unordered_set<int> anmol(banned.begin(),banned.end());
        for(int i=1;i<=n;i++)
        {
            if(anmol.count(i))
            {
             extra=1;
            }
            else if(sum+i>maxSum)
            {
                extra=2;
            }
            else{
                count++;
                sum+=i;
            }
        }
        return count;
        
    }
};
