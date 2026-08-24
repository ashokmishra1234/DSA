class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0,r=0;
        int min_sum=INT_MAX,sum=0;
        while( r < n){
            sum+=cardPoints[r];
            if( l < r && r-l+1 > n-k){
                sum-=cardPoints[l];
                l++;
            }
            if(r-l+1==n-k){
                min_sum=min(min_sum,sum);
            }
            r++;
        }
        int total_sum=accumulate(cardPoints.begin(),cardPoints.end(),0);

        return total_sum- (min_sum==INT_MAX?0:min_sum);
    }
};