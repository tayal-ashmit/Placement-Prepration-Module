struct Node{
    int key;
    int val;
    int freq;
    Node *prev, *next;

    Node(int k, int v) {
        key= k;
        val= v;
        freq= 1;
    }
};

struct List{
    int size;
    Node *head, *tail;

    List() {
        head= new Node(0,0);
        tail= new Node(0,0);
        head->next= tail;
        tail->prev= head;
        size=0;
    }

    void addnode(Node* newnode) {
        Node* temp= head->next;
        newnode->next= temp;
        newnode->prev= head;
        head->next= newnode;
        temp->prev= newnode;
        size++;
    }

    void deletenode(Node* delnode) {
        Node* delnext= delnode->next;
        Node* delprev= delnode->prev;
        delprev->next= delnext;
        delnext->prev= delprev;
        size--;
    }
};

class LFUCache {
public:
    map<int, Node*> keynode;
    map<int, List*> freqlistmap;
    int maxcachesize;
    int minfreq;
    int currsize;

    LFUCache(int capacity) {
        maxcachesize= capacity;
        minfreq= 0;
        currsize= 0;
    }

    void update(Node* node) {
        keynode.erase(node->key);
        freqlistmap[node->freq]->deletenode(node);
        if(node->freq == minfreq && freqlistmap[node->freq]->size == 0) {
            minfreq++;
        }

        List* higherlist= new List();
        if(freqlistmap.find(node->freq+1) != freqlistmap.end()) {
            higherlist=freqlistmap[node->freq+1];
        }

        node->freq += 1;
        higherlist->addnode(node);
        freqlistmap[node->freq]= higherlist;
        keynode[node->key]= node;
    }
    
    int get(int key) {
        if(keynode.find(key) != keynode.end()) {
            Node* ans= keynode[key];
            int ansval= ans->val;
            update(ans);
            return ansval;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxcachesize==0) {
            return;
        }

        if(keynode.find(key) != keynode.end()) {
            Node*node= keynode[key];
            node->val= value;
            update(node);
        }
        else{
            if(maxcachesize == currsize) {
                List* list= freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                freqlistmap[minfreq]->deletenode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq= 1;
            List* listfreq= new List();
            if(freqlistmap.find(minfreq)!=freqlistmap.end()){
                listfreq= freqlistmap[minfreq];
            }
            Node* node= new Node(key, value);
            listfreq->addnode(node);
            keynode[key]= node;
            freqlistmap[minfreq]= listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */