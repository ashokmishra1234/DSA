class Solution {
public:
    
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=LLONG_MAX;
        if(cost1 + cost2 < costBoth){
            long long cum_sum=cost1+cost2;
            long long curr_ans=cum_sum*(min(need1,need2));
            if(need1 > need2){
                curr_ans+=1LL*(need1-need2)*cost1;
            }else curr_ans+=1LL*(need2-need1)*cost2;
            ans=min(ans,curr_ans);
        }
        else{
            long long cum_sum=costBoth;
            long long curr_ans=cum_sum*(min(need1,need2));
            if(need1 > need2){
                if(cost1 > costBoth){
                    curr_ans+=1LL*(need1-need2)*costBoth;
                }else{
                    curr_ans+=1LL*(need1-need2)*cost1;
                }
            }else{
                if(cost2 > costBoth){
                    curr_ans+=1LL*(need2-need1)*costBoth;
                }else{
                    curr_ans+=1LL*(need2-need1)*cost2;
                }
            }
            ans=min(ans,curr_ans);
        }
        return ans;
    }
};