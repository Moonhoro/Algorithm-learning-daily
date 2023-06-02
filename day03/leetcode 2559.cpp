class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int pre[n+1];
        pre[0]=0;
        for(int i=0;i<n;i++)
        {
         int  value=isVowelString(words[i])?1:0;
pre[i+1]=pre[i]+value;
        }
        vector<int>res;
       for (int i = 0; i < queries.size(); i++) {
        int start = queries[i][0], end = queries[i][1];
        int t = pre[end+1] - pre[start];
        res.push_back(t);
    }
        return res;
    }
     bool isVowelString(const string &word) {
        return isVowelLetter(word[0]) && isVowelLetter(word.back());
    }

    bool isVowelLetter(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
