#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int val;
	int height;
	int BF;
	Node *left;
	Node *right;

	Node(): val(0), height(0), BF(0), left(nullptr), right(nullptr) {}
	Node(int v): val(v), height(0), BF(0), left(nullptr), right(nullptr) {}
};

class AVL_tree
{
	private:
		Node* findMax(Node *root)
		{
			if(!root)
				return nullptr;

			return root->right ? findMax(root->right) : root;
		}

		void update_h_bf(Node *root)
		{
			if(!root)
				return;

			int l = root->left ? root->left->height : -1;
			int r = root->right ? root->right->height : -1;

			root->height = max(l, r) + 1;
			root->BF = l - r;
		}

		void _inorder(Node *root)
		{
			if(!root)
				return;

			_inorder(root->left);
			cout << root->val << " ";
			_inorder(root->right);
		}

		void _preorder(Node *root)
		{
			if(!root)
				return;
			cout << root->val << " ";
			_preorder(root->left);
			_preorder(root->right);
		}

		Node* left_rotation(Node *root)
		{
			Node *r = root->right;
			Node *r_lchild = r->left;

			r->left = root;
			root->right = r_lchild;

			update_h_bf(root);
			update_h_bf(r);

			return r;
		}

		Node* right_rotation(Node *root)
		{
			Node *l = root->left;
			Node *l_rchild = l->right;

			l->right = root;
			root->left = l_rchild;

			update_h_bf(root);
			update_h_bf(l);

			return l;
		}

		Node* _insert_node(Node *root, Node *n)
		{
			if(!root)
			{
				root = n;
				return root;
			}

			if(n->val > root->val)
				root->right = _insert_node(root->right, n);
			else
				root->left = _insert_node(root->left, n);

			update_h_bf(root);

			if(root->BF > 1)
			{
				// LL type
				if(root->left->val >= 0)
					return right_rotation(root);
				//LR type
				else
				{
					root->left = left_rotation(root->left);
					return right_rotation(root);
				}
			}
			else if(root->BF < -1)
			{
				//RR type
				if(root->right->BF <= 0)
					return left_rotation(root);
				//RL type
				else
				{
					root->right = right_rotation(root->right);
					return left_rotation(root);
				}
			}

			return root;
		}

		Node* _delete_node(Node *root, int val)
		{
			if(!root)
				return nullptr;

			if(val > root->val)
				root->right = _delete_node(root->right, val);
			else if(val < root->val)
				root->left = _delete_node(root->left, val);
			else
			{
				if(!root->left && !root->right)
				{
					delete root;
					return nullptr;
				}
				else if(!root->left)
				{
					Node *tmp = root->right;
					delete root;
					return tmp;
				}
				else if(!root->right)
				{
					Node *tmp = root->left;
					delete root;
					return tmp;
				}
				else
				{
					Node *max_l = findMax(root->left);
					swap(root->val, max_l->val);
					root->left = _delete_node(root->left, val);
				}
			}

			update_h_bf(root);

			if(root->BF > 1)
			{
				// LL type
				if(root->left->BF >= 0)
					return right_rotation(root);
				//LR type
				else
				{
					root->left = left_rotation(root->left);
					return right_rotation(root);
				}
			}
			else if(root->BF < -1)
			{
				//RR type
				if(root->right->BF <= 0)
					return left_rotation(root);
				//RL type
				else
				{
					root->right = right_rotation(root->right);
					return left_rotation(root);
				}
			}

			return root;
		}

	public:
		Node *root;
		
		AVL_tree()
		{
			root = nullptr;
		}

		void inorder()
		{
			_inorder(this->root);
			cout << endl;
		}

		void preorder()
		{
			_preorder(this->root);
			cout << endl;
		}

		void insert_node(int val)
		{
			Node *n = new Node(val);
			this->root = _insert_node(this->root, n);
		}

		void delete_node(int val)
		{
			_delete_node(this->root, val);
		}
};
