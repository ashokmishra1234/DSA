class StockSpanner {
public:
    stack<int> st;
    vector<int> price;
    int ind=0;
    StockSpanner() {
        price.resize(1e5+1,0);
    }
    int prev_small_index(int curr_ind){
        int curr_ans=0;
        while(!st.empty() && price[st.top()] <= price[curr_ind]) st.pop();
        if(st.empty()) curr_ans=curr_ind+1;
        else curr_ans=curr_ind-st.top();
        st.push(curr_ind);
        return curr_ans;
    }
    int next(int val) {
        price[ind]=val;
        ind++;
        return prev_small_index(ind-1);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */