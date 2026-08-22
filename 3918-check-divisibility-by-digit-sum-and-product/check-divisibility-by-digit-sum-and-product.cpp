class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1;
        int temp=n;
        while(n > 0){
            int dig=n%10;
            n=n/10;
            sum+=dig;
            prod*=dig;
        }
        if(temp%(sum + prod)==0) return true;
        return false;
    }
};