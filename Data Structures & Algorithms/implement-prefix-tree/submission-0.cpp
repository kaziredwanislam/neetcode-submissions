class PrefixTree {
public:
    vector<string>prefixes;
    PrefixTree() {
        
    }
    
    void insert(string word) {
        prefixes.push_back(word);
    }
    
    bool search(string word) {
        for(int i=0;i<prefixes.size();i++)
        {
            if(word==prefixes[i])return true;
        }
        return false;
    }

    bool isPrefix(string sub,string word)
    {
        if(word.size()<sub.size())return false;
        for(int i=0;i<sub.size();i++)
        {
            if(word[i]!=sub[i])return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        for(int i=0;i<prefixes.size();i++)
        {
            string word=prefixes[i];
            if(isPrefix(prefix,word))return true;
        }
        return false;
    }
};
