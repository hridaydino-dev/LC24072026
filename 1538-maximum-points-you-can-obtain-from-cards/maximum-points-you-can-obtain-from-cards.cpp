class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int tot=0;
        for(int i=0;i<k;i++){
            tot+=cardPoints[i];
        }
        int ans=tot;
        for(int i=0;i<k;i++){
            tot-=cardPoints[k-1-i];
            tot+=cardPoints[n-1-i];
            ans=max(ans,tot);
        }
        return ans;
    }
};