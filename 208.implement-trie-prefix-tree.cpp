/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie { 
public:
    /** Initialize your data structure here. */
    Trie(): root(make_unique<TrieNode>()) {}
    // Trie(): root(new TrieNode()) {}
    // Trie() {
    //     root = new TrieNode();
    // }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root.get(); // get??
        // TrieNode* p = root; // get??
        for (const auto c : word){
            if (p->child[c - 'a'] == nullptr) p->child[c - 'a'] = new TrieNode();
            p = p->child[c - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find_prefix(word);
        if (p != nullptr && p->is_word) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find_prefix(prefix) != nullptr;
    }
private:
    struct TrieNode{
        bool is_word;
        vector<TrieNode*> child;

        TrieNode(): is_word(false), child(26, nullptr) {};
        ~TrieNode() {
            for (TrieNode* ch : child)
                if (ch) delete ch;
        }
    };

    unique_ptr<TrieNode> root; // smart pointer
    // TrieNode* root;

    TrieNode* find_prefix(string& prefix){
        TrieNode* p = root.get();
        // TrieNode* p = root;
        for (const auto c : prefix){
            p = p->child[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix); 
 */
// @lc code=end

