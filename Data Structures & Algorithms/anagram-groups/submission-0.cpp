class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> sortedstrGroup;

        for(const auto& s: strs)
        {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            sortedstrGroup[sortedS].push_back(s);
        }
        
        // [aht, act, act, opst, opst, opst]

        vector<vector<string>> result;
        for(auto& pair: sortedstrGroup)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
