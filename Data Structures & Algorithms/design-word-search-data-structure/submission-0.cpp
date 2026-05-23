class WordDictionary {
public:
    vector<string>words;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        words.push_back(word);
    }

    bool isMatched(string word1,string word2)
    {
        if(word1.size()!=word2.size())return false;
        for(int i=0;i<word1.size();i++)
        {
            if(word1[i]=='.' || word2[i]=='.')continue;
            if(word1[i]!=word2[i])return false;
        }
        return true;
    }
    
    bool search(string word) {
        for(int i=0;i<words.size();i++)
        {
            if(isMatched(words[i],word))return true;
        }
        return false;
    }
};
