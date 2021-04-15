class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> count;
        sort(nums.begin(),nums.end());
        int i,j,temp;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                count[nums[i] * nums[j]] ++ ;
            }
        }
        int ans=0;
        for(auto it: count)
        {
            temp = (it.second * (it.second -1))/2;
            temp *= 8;
            ans+=temp;
        }
        return ans;
    }
};
