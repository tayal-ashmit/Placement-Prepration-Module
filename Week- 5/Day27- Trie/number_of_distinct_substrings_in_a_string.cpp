class TrieNode{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data= data;
        children= new TrieNode*[26];
        for(int i=0; i<26; i++) {
            children[i]= NULL;
        }
        isTerminal= false;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root= new TrieNode('\0');
    }

    void insert(TrieNode* root, string s){
        if(s.size()==0) {
            root->isTerminal= true;
            return;
        }

        int indx= s[0]-'a';
        TrieNode* child;
        if(root->children[indx]!=NULL)
            child= root->children[indx];
        else {
            child= new TrieNode(s[0]);
            root->children[indx]= child;
        }
        insert(child, s.substr(1));
    }

    void insert(string word) { 
        insert(root, word); 
    }

    bool search(TrieNode *root,string s) {
        if(s.size()==0){
            if(root->isTerminal==true)
                return true;
            else
                return false;
        }

        int indx=s[0]-'a';
        TrieNode *child;
        if(root->children[indx]!=NULL)
            child=root->children[indx];
        else
            return false;
        return search(child, s.substr(1));
    }

    bool search(string word) {
        return search(root, word);
    }

};

int countDistinctSubstrings(string &s) {
    Trie t;
    int count= 0;
    for(int i=0; i<s.size(); i++) {
        for(int j=i; j<s.size(); j++) {
            string temp= s.substr(i, j-i+1);
            if(t.search(temp) == false) {
                count++;
                t.insert(temp);
            }
        }
    }
    return count+1;
}

