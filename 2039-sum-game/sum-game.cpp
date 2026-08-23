class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int left_sum=0,left_q=0;
        int right_sum=0,right_q=0;
        for(int i=0;i<n;i++){
            if(i < n/2){
                if(num[i]=='?') left_q+=1;
                else left_sum+=(num[i]-'0');
            }else{
                if(num[i]=='?') right_q+=1;
                else right_sum+=(num[i]-'0');
            }
        }
        if(left_q==0 && right_q==0) return left_sum==right_sum?false:true;
        if((left_q+right_q)%2) return true;
        int left=2*left_sum + 9*left_q;
        int right=2*right_sum + 9*right_q;
        return left==right?false:true;
        
    }
};