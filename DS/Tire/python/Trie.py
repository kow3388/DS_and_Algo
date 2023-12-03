class TrieNode:
    def __init__(self):
        self.is_word = False
        self.child = [None]*26

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

        return

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
