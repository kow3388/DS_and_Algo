#include <bits/stdc++.h>

using namespace std;

//color class
enum class Color
{
	Black,
	Red
};

//define node of red black tree
struct Node
{
	int val;
	Color color;
	Node *parent;
	Node *left;
	Node *right;

	Node(): val(0), color(Color::Red), parent(nullptr), left(nullptr), right(nullptr) {}
	Node(int v): val(v), color(Color::Red), parent(nullptr), left(nullptr), right(nullptr) {}
};

class red_black_tree
{
	public:
		Node *root;

		//initial there is no node
		red_black_tree()
		{
			root = nullptr;
		}

		//inorder to check is the red black tree is wrong or not
		void inorder()
		{
			cout << "Inorder: ";
			_inorder(this->root);
			cout << endl;
		}

		//level order to check is the red black tree is wrong or not
		void level_order()
		{
			cout << "Level order: " << endl;
			_levelorder(this->root);
		}

		//insert node
		void insert_node(int val)
		{
			Node *n = new Node(val);
			this->root = _insert_node(this->root, n);
			fix_insert(n);
		}

		void delete_node(int val)
		{
			_delete_node(this->root, val);
		}

	private:
		Node* minimum(Node *root)
		{
			if(!root || !root->left)
				return root;

			return minimum(root->left);
		}

		void _inorder(Node *root)
		{
			if(!root)
				return;

			_inorder(root->left);
			cout << root->val << " ";
			_inorder(root->right);
		}

		void _levelorder(Node *root)
		{
			if(!root)
			{
				cout << "There is no node!" << endl;
				return;
			}

			queue<Node*> q;
			q.push(root);

			while(!q.empty())
			{
				int s = q.size();
				for(int i = 0; i < s; i++)
				{
					Node *cur = q.front();
					q.pop();

					cout << cur->val;
					if(cur->color == Color::Red)
						cout << "(red) ";
					else
						cout << "(black) ";

					if(cur->left)
						q.push(cur->left);
					if(cur->right)
						q.push(cur->right);
				}
				cout << endl;
			}
		}

		void left_rotation(Node *root)
		{
			Node *r = root->right;
			Node *r_left = r->left;

			r->left = root;
			root->right = r_left;

			if(r_left)
				r_left->parent = root;

			if(!root->parent)
				this->root = r;
			else if(root == root->parent->left)
				root->parent->left = r;
			else
				root->parent->right = r;

			r->parent = root->parent;
			root->parent = r;
		}

		void right_rotation(Node *root)
		{
			Node *l = root->left;
			Node *l_right = l->right;

			l->right = root;
			root->left = l_right;

			if(l_right)
				l_right->parent = root;

			if(!root->parent)
				this->root = l;
			else if(root == root->parent->left)
				root->parent->left = l;
			else
				root->parent->right = l;

			l->parent = root->parent;
			root->parent = l;
		}

		//using BST to find the new node position
		Node* _insert_node(Node *root, Node *n)
		{
			if(!root)
			{
				root = n;
				return root;
			}

			if(root->val > n->val)
			{
				root->left = _insert_node(root->left, n);
				root->left->parent = root;
			}
			else
			{
				root->right = _insert_node(root->right, n);
				root->right->parent = root;
			}

			return root;
		}

		void _delete_node(Node *root, int val)
		{
			Node *del_node = nullptr;
			Node *inp_node, *fix_node;

			while(root)
			{
				if(root->val == val)
				{
					del_node = root;
					break;
				}
				else if(root->val > val)
					root = root->left;
				else
					root = root->right;
			}

			if(!del_node)
			{
				cout << "There isn't node val = " << val << endl;
				return;
			}

			inp_node = del_node;
			Color inp_ori_color = inp_node->color;

			if(!del_node->left)
			{
				inp_node = del_node->right;
				fix_node = inp_node;
				Transplant(del_node, inp_node);
			}
			else if(!del_node->right)
			{
				inp_node = del_node->left;
				fix_node = inp_node;
				Transplant(del_node, inp_node);
			}
			else
			{
				inp_node = minimum(del_node->right);

				fix_node = inp_node->right;
				if(inp_node->parent != del_node)
				{
					Transplant(inp_node, fix_node);

					if(fix_node)
						inp_ori_color = fix_node->color;
				}

				Transplant(del_node, inp_node);

				inp_node->left = del_node->left;
				inp_node->left->parent = inp_node;

				inp_node->right = del_node->right;
				inp_node->right->parent = inp_node;

				inp_node->color = del_node->color;
			}

			delete del_node;
			if(inp_ori_color == Color::Red)
				fix_delete(fix_node);
		}

		void color_change(Node *root)
		{
			root->color = Color::Red;
			root->left->color = Color::Black;
			root->right->color = Color::Black;
		}

		void Transplant(Node *del_node, Node *inp_node)
		{
			if(!del_node->parent)
			{
				this->root = inp_node;
				return;
			}
			else if(del_node == del_node->parent->left)
				del_node->parent->left = inp_node;
			else
				del_node->parent->right = inp_node;

			if(inp_node)
				inp_node->parent = del_node->parent;
		}

		void fix_insert(Node *root)
		{

			Node *uncle;
			//two consecutive red node, need fix
			while(root->parent && root->parent->color == Color::Red)
			{
				//the right child tree of root's grandparent is unbalance
				if(root->parent == root->parent->parent->right)
				{
					uncle = root->parent->parent->left;
					//need color change or not
					if(uncle && uncle->color == Color::Red)
						color_change(root->parent->parent);
					else
					{
						if(root == root->parent->left)
						{
							root = root->parent;
							right_rotation(root);
						}

						root->parent->color = Color::Black;
						root->parent->parent->color = Color::Red;
						left_rotation(root->parent->parent);
					}
				}
				else
				{
					uncle = root->parent->parent->right;
					if(uncle && uncle->color == Color::Red)
						color_change(root->parent->parent);
					else
					{
						if(root == root->parent->right)
						{
							root = root->parent;
							left_rotation(root);
						}
						
						root->parent->color = Color::Black;
						root->parent->parent->color = Color::Red;
						right_rotation(root->parent->parent);
					}
				}

			}

			this->root->color = Color::Black;
		}

		void fix_delete(Node *root)
		{
			if(!root)
				return;

			Node *sibling;
			while(root && root != this->root && root->color == Color::Black)
			{
				if(root == root->parent->left)
				{
					sibling = root->parent->right;
					if(sibling->color == Color::Red)
					{
						sibling->color = Color::Black;
						root->parent->color = Color::Red;
						left_rotation(root->parent);
						sibling = root->parent->right;
					}

					if(sibling->left->color == Color::Black && sibling->right->color == Color::Black)
					{
						sibling->color = Color::Red;
						root = root->parent;
					}
					else
					{
						if(sibling->right->color == Color::Black)
						{
							sibling->left->color = Color::Black;
							sibling->color = Color::Red;
							right_rotation(sibling);
							sibling = root->parent->right;
						}

						sibling->color = root->parent->color;
						root->parent->color = Color::Black;
						sibling->right->color = Color::Black;
						left_rotation(root->parent);
						root = this->root;
					}
				}
				else
				{
					sibling = root->parent->left;
					if(sibling->color == Color::Red)
					{
						sibling->color = Color::Black;
						root->parent->color = Color::Red;
						right_rotation(root->parent);
						sibling = root->parent->left;
					}

					if(sibling->left->color == Color::Black && sibling->right->color == Color::Black)
					{
						sibling->color = Color::Red;
						root = root->parent;
					}
					else
					{
						if(sibling->left->color == Color::Black)
						{
							sibling->right->color = Color::Black;
							sibling->color = Color::Red;
							left_rotation(sibling);
							sibling = root->parent->left;
						}

						sibling->color = root->parent->color;
						root->parent->color = Color::Black;
						sibling->left->color = Color::Black;
						right_rotation(root->parent);
						root = this->root;
					}
				}
			}
			root->color = Color::Black;
		}
};
