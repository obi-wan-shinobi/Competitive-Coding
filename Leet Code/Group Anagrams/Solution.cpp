class Solution {
public:
    /*
        ["eat","tea","tan","ate","nat","bat"]

        sort individual words
        eat -> aet
        tea -> aet

        map the sorted words with list words
        aet -> [eat, tea, ate]

        1. Create a hash_map for maintaining the lists
        2. Loop over the list and maintain a pair of sorted and original word string
        3. If sorted string doesn't exist in the hash_map, insert it and map it with a vector containing the original word
        4. If sorted string exists in the hash_map, push_back the original string into the mapped vector
        5. Create a result vector of vectors, iterate through the values in map and push_back the vectors
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hash_map;

        for(string str: strs){
            string temp = str;
            sort(str.begin(), str.end());
            vector<string> mapped_vector;
            if(hash_map.find(str) == hash_map.end()){
                mapped_vector.push_back(temp);
                hash_map.insert(pair<string,vector<string>>(str,mapped_vector));
            }
             else{
                 hash_map[str].push_back(temp);
             }
        }

         vector<vector<string>> result;
         for(map<string,vector<string>>::iterator it = hash_map.begin(); it!=hash_map.end(); it++){
             result.push_back(it->second);
         }

        return result;
    }
};
