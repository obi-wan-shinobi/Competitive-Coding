class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int i=0; i<=rowIndex; i++){
            if(i==0 || i==rowIndex)
                result.push_back(1);
            else{
                result.push_back(result[i-1]*(rowIndex-i+1)/i);
            }
        }
        return result;
    }
};
