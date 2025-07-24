//https://neetcode.io/problems/design-word-search-data-structure?list=blind75

class TrieNode{
    public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        for(int i=0;i<26;++i){
            children[i]=nullptr;
        }
        endOfWord=false;
    }
};

class Trie{
    TrieNode* root;
    public:
     Trie(){
        root= new TrieNode();
     }
    void insert(string word){
        TrieNode* curr= root;
        for(auto it:word){
            auto ch= it-'a';
            if(!curr->children[ch]){
                TrieNode* node= new TrieNode();
                curr->children[ch]=node;
                
            }
            curr=curr->children[ch];
            
        }
        curr->endOfWord=true;
    }
    bool search(string word){
        return search(word,0,root);
    }
private:
    bool search(string word,int id, TrieNode* curr){
        if(id>=word.size()) return curr->endOfWord;
        if(word[id]!='.'){
            if(!curr->children[word[id]-'a']) return false;
            return search(word,id+1,curr->children[word[id]-'a']);
        }
        else{
            for(int i=0;i<26;++i){
                if(curr->children[i] && search(word,id+1,curr->children[i])){
                    return true;
                }
            }
            return false;
        }
    }
};

class WordDictionary {
TrieNode* root;
Trie t;
public:
    WordDictionary() {
        root=new TrieNode();
        t=Trie();

    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.search(word);
    }
};
