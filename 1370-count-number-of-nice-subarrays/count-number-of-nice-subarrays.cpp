class Solution {
public:
    int atmost(vector<int>& nums, int k){
        if(k<0) return 0;
        int r=0;
        int l=0;
        int sum=0;
        int count=0;
        
        while(r<nums.size()){
            sum+=nums[r];
            //cout<<"sum="<<sum<<endl;
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            //cout<<"count="<<count<<endl;
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &it:nums){
            it=it%2;
        }
        return atmost(nums,k)-atmost(nums,k-1);
    }
};