class Trie {
public:
    array<Trie*, 26> d;
    bool f= false;

    void insert(string w) {
        Trie* tp= this;
        for(auto&& i : w) {
            if(!tp->d[i-'a'])
                tp->d[i-'a']= new Trie();
                
            tp= tp->d[i-'a'];
        }
        tp->f= true;
    }

    bool search(string w) {
        Trie* tp= this;
        for(auto&& i: w ) {
            if(!tp->d[i-'a'])
                return false;
            tp= tp->d[i-'a'];
        }
        if(tp->f)
            return true;
        return false;
    }

    bool startsWith(string w) {
        Trie* tp= this;
        for(auto&& i: w) {
            if(!tp->d[i-'a'])
                return false;
            tp= tp->d[i-'a'];
        }
        return true;
    }
  };