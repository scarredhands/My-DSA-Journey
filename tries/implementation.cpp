//https://leetcode.com/problems/implement-trie-prefix-tree/

//implementing tries - prefix tree.
//used in spellchecker and autocomplete.


class Node{
    public:
    Node* child[26];
    bool isWord;
    Node(){
        isWord=false;
        for(auto &a:child){
            a=nullptr;
        }
    }
};


class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* p=root;
        for(int i=0;i<word.size();++i){
            int j=word[i]-'a';
            if(!p->child[j]){
                p->child[j]=new Node();
            }
            p=p->child[j];
        }
        p->isWord=true;
    }
    
    bool search(string word, bool prefix=false) {
        Node* p=root;
        for(auto & a:word){
            int i=a-'a';
            if(!p->child[i]){
                return false;
            }
            p=p->child[i];
        }
        if(prefix==false){
            return p->isWord;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
       return search(prefix,true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */