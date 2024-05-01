#include "AVL_tree.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	AVL_tree *avl = new AVL_tree();

	avl->insert_node(10);
	avl->insert_node(20);
	avl->insert_node(30);
	avl->insert_node(40);
	avl->insert_node(50);
	avl->insert_node(25);

	cout << "Inorder: ";
	avl->inorder();
	cout << "Preorder: ";
	avl->preorder();

	avl->delete_node(20);
	
	cout << "Inorder: ";
	avl->inorder();
	cout << "Preorder: ";
	avl->preorder();

	return 0;
}
