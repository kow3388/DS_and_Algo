#include <bits/stdc++.h>

using namespace std;

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

class Trie
{
	public:
		TrieNode *root;

		Trie()
		{
			root = new TrieNode();
		}

		void insert(string word)
		{
			TrieNode *tmp = root;

			for(char w : word)
			{
				int k = w - 'a';
				if(!tmp->children[k])
					tmp->children[k] = new TrieNode();
				tmp = tmp->children[k];
			}

			tmp->is_word = true;
		}

		bool search(string word)
		{
			TrieNode *tmp = root;

			for(char w : word)
			{
				int k = w - 'a';
				if(!tmp->children[k])
					return false;
				tmp = tmp->children[k];
			}

			return tmp->is_word;
		}

		bool startsWith(string prefix)
		{
			TrieNode *tmp = root;

			for(char w : prefix)
			{
				int k = w - 'a';
				if(!tmp->children[k])
					return false;
				tmp = tmp->children[k];
			}

			return true;
		}
};
