class Solution {
public:
    int reverse(int x) {

        string num = to_string(x);

        bool neg_flag = false;

        if(num[0] == '-'){
            neg_flag = true;
            for(int i = 1,j=0; i<num.length(); i++,j++)
                num[j] = num[i];
            num.pop_back();
        }

        int ans=0;

        int dig = 7;

        if(neg_flag)
            dig = 8;

        for(int i=num.length()-1; i>=0; i--){
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && num[i] < dig))
                return 0;
            ans = ans*10 + (num[i]-'0');
        }
        if(neg_flag)
            ans = -1*ans;

        return ans;
    }
};
