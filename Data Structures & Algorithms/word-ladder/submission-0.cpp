class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // bfs problem

        // node - each word
        // edge - connect words differ by one char
        // precompute adj matrix
        // bfs - shortest path 

        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()
            || beginWord == endWord)
            {
                return 0;
            }

        // word to index map
        int n = wordList.size();
        int m = wordList[0].size();
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[wordList[i]] = i;
        }

        // form adj matrix by checking nodes which differ by 1 char
        vector<vector<int>> adj(n);

        for(int i = 0; i< n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int count = 0;
                for(int k = 0; k < m; k++)
                {
                    if(wordList[i][k] != wordList[j][k])
                        count++;
                }
                if( count == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // adj matrix is formed
        // do bfs of adj matrix

        queue<int> q;
        int result = 1;
        unordered_set<int> visit;

        for(int i = 0; i < m; i++)
        {
            for(char c = 'a'; c <= 'z'; c++)
            {
                if(c == beginWord[i])
                    continue;
                string word = beginWord.substr(0,i) + c + beginWord.substr(i+1);
                if(mp.find(word) != mp.end() && visit.find(mp[word]) == visit.end())
                {
                    q.push(mp[word]);
                    visit.insert(mp[word]);
                }
            }
        }

        while(!q.empty())
        {
            result++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                if(wordList[node] == endWord)
                    return result;
                
                for(int nei: adj[node])
                {
                    if(visit.find(nei) == visit.end())
                    {
                        visit.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }

        return 0;
    
    }
};
