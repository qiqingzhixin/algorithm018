//
// Created by Administrator on 2020/12/07.
//

class Trie {
private:
    Trie *root[26] = {nullptr};
    bool end = false;
public:

    /** Initialize your data structure here. */

    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *next = this;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (next->root[index] == nullptr) {
                next->root[index] = new Trie();
            }
            next = next->root[index];
        }
        next->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *next = this;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (next->root[index] == nullptr) {
                return false;
            }
            next = next->root[index];
        }
        return next->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *next = this;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (next->root[index] == nullptr) {
                return false;
            }
            next = next->root[index];
        }
        return true;
    }
};