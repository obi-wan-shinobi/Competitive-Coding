class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> barred;
        vector<int> ind;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(barred.find(num)!=barred.end()){
                ind.push_back(barred.at(num));
                ind.push_back(i);
                break;
            }
            else{
                barred[target-num]=i;
            }
        }
        return ind;

    }
};
