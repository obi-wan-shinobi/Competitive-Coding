class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int len = citations.size();
        vector<int> h_ind(len+1, 0);

        for(int i=0; i<len; i++)
            h_ind[min(len,citations[i])] += 1;


        int sum = 0;

        for(int i = len; i>0; i--){
            sum +=h_ind[i];
            if(sum>=i)
                return i;
        }

        return 0;
    }
};
