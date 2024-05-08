#include <string>

using namespace std;

class TrieNode {
public:
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(bool b = false) {
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = b;
  }
};

class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *p = root;
    for (int i = 0; i < word.size(); i++) {
      if (p->children[word[i] - 'a'] == NULL) {
        p->children[word[i] - 'a'] = new TrieNode;
      }
      p = p->children[word[i] - 'a'];
    }
    p->isTerminal = true;
  }

  bool search(string word) {
    TrieNode *p = root;
    for (int i = 0; i < word.size(); i++) {
      if (p->children[word[i] - 'a'] == NULL) {
        return false;
      }
      p = p->children[word[i] - 'a'];
    }
    return p->isTerminal;
  }

  bool startsWith(string prefix) {
    TrieNode *p = root;
    for (int i = 0; i < prefix.size(); i++) {
      if (p->children[prefix[i] - 'a'] == NULL) {
        return false;
      }
      p = p->children[prefix[i] - 'a'];
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
