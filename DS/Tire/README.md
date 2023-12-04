# Trie
- 字典樹，又叫做單詞搜尋樹，也有人稱為prefix tree
- 利用字串的特性來節省空間(EX: ten和tea都有te)
- 除了root外每個node都代表一個char
- 每個node會紀錄從root到此node是否為一個完整的string
- Trie的高度為最常字串的長度

## Implement
### C++
Tree Node
```cpp=
class TrieNode
{
    public:
        bool is_word;
        vector<TrieNode*> children;
        TrieNode()
        {
            is_word = false;
            children.resize(26, nullptr);

        }
};
```

Tire
```cpp=
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *tmp = root;

        for(char w : word)
        {
            int k = w -'a';
            if(tmp->children[k] == nullptr)
                tmp->children[k] = new TrieNode();
            tmp = tmp->children[k];
        }

        tmp->is_word = true;
    }
    
    bool search(string word) {
        TrieNode *tmp = root;
        for(char w : word)
        {
            int k = w - 'a';
            if(tmp->children[k] == nullptr)
                return false;
            tmp = tmp->children[k];
        }

        return tmp->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for(char w : prefix)
        {
            int k = w - 'a';
            if(tmp->children[k] == nullptr)
                return false;
            tmp = tmp->children[k];
        }

        return true;
    }
};
```

## Python
Tree Node
```python=
class TrieNode:
    def __init__(self):
        self.is_word = False
        self.child = [None]*26
```

Tire
```python=
class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        tmp = self.root
        for w in word:
            k = ord(w) - ord('a')
            if tmp.child[k] is None:
                tmp.child[k] = TrieNode()
            tmp = tmp.child[k]
        
        tmp.is_word = True

    def search(self, word: str) -> bool:
        tmp = self.root
        for w in word:
            k = ord(w) - ord('a')
            if tmp.child[k] is None:
                return False
            tmp = tmp.child[k]
        
        return tmp.is_word

    def startsWith(self, prefix: str) -> bool:
        tmp = self.root
        for w in prefix:
            k = ord(w) - ord('a')
            if tmp.child[k] is None:
                return False
            tmp = tmp.child[k]
        
        return True
```

###### tags : `Tree`
