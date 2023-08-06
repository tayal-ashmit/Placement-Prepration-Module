#include <bits/stdc++.h> 

class Trie{
    class hash{
    public:
        hash * node[26];
        bool flag=false;
        int count=0;
        int precount=0;
    };
    hash* root= new hash();

public:
    Trie() {}

    void insert(string &word) {
        hash* tmp= root;

        for(int i=0; i<word.size(); i++) {
            if(tmp->node[word[i]-'a'] == NULL) {
                hash* next= new hash();
                tmp->node[word[i]-'a']= next;
                tmp= next;
            }
            else {
                tmp= tmp->node[word[i]-'a'];
            }
            tmp->precount++;
        }
        tmp->flag=true;
        tmp->count++;
    }

    int countWordsEqualTo(string &word) {
        hash* tmp= root;
        for(int i=0; i<word.size(); i++) {
            if(tmp->node[word[i]-'a'] == NULL) {
                tmp=NULL;
                break;
            }
            else {
                tmp=tmp->node[word[i] - 'a'];
            }
        }

        if(tmp==NULL)
            return 0;
        return tmp->count;
    }

    int countWordsStartingWith(string &word) {
        hash* tmp= root;
        for(int i=0; i<word.size(); i++) {
            if(tmp->node[word[i]-'a'] == NULL) {
                tmp= NULL;
                break;
            }
            else {
                tmp= tmp->node[word[i] - 'a'];
            }
        }

        int ans=0;
        if(tmp==NULL)
            return 0;
        return tmp->precount;
    }

    void erase(string &word) {
        hash* tmp= root;

        for(int i=0;i<word.size();i++){
            if(tmp->node[word[i]-'a'] == NULL) {
                tmp= NULL;
                break;
            }
            else {
                tmp= tmp->node[word[i]-'a'];
            }
            tmp->precount--;
        }

        if (tmp!=NULL && tmp->flag == true) {
            tmp->flag= false;
            tmp->count--;
        }
    }

};

 