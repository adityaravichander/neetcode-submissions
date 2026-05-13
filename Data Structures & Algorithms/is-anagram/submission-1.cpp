class Solution {
public:
    bool isAnagram(string s, string t) {

    // first of all both strings should be equal length
    if(s.length() != t.length())
    {
        return false;
    }

// sorting method
    // APPARENTLY, strings can be sorted too. 
    // sorted strings should be equal. 

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
    }
    
// hash map method
    // hashmaps of both with letter:count should be equal. 

    // unordered_map<char, int> sLetterCount;
    // unordered_map<char, int> tLetterCount;

    // for(int index = 0; index < s.length(); index++)
    //     {
    //         sLetterCount[s[index]]++;
    //         tLetterCount[t[index]]++;
    //     }
    // return sLetterCount == tLetterCount;
    // }

};
