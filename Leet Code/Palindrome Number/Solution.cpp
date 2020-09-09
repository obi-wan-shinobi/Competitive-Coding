class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0)
            return false;
        if(x==0)
            return true;

        int num_digits = int(log10(x)) + 1;

        if(num_digits == 1)
            return true;
        
        int new_num = 0;


        for(int i=0; i<(num_digits/2); i++){
            int last_dig = x%10;
            x = x/10;
            new_num = new_num*10 + last_dig;
        }

        if(num_digits%2 == 1)
            x = x/10;

        if(new_num == x)
            return true;
        else
            return false;
    }
};
