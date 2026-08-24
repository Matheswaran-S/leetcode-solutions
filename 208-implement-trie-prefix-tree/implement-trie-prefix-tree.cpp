struct Node{
    Node* arr[26];
    bool last = false;
};
class Trie {
private:
    Node* trie;
public:
    Trie() {
        trie = new Node();
    }
    
    void insert(string word) {
        Node* root = trie;
        for(auto &c : word){
            if(!(root->arr[c-'a'])){
                root->arr[c-'a'] = new Node();
            }
            root = root->arr[c-'a'];
        }
        root->last = true;
    }
    
    bool search(string word) {
        Node* root = trie;
        for(auto &c : word){
            if(!(root->arr[c-'a'])){
                return false;
            }
            root = root->arr[c-'a'];
        }
        return root->last;
    }
    
    bool startsWith(string prefix) {
        Node* root = trie;
        for(auto &c : prefix){
            if(!(root->arr[c-'a'])){
                return false;
            }
            root = root->arr[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */