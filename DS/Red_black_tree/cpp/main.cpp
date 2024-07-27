#include "Red_black_tree.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	red_black_tree *rb = new red_black_tree();

	rb->insert_node(10);
	rb->insert_node(20);
	rb->insert_node(30);
	rb->insert_node(40);
	rb->insert_node(50);
	rb->insert_node(25);

	//rb->inorder();
	//rb->level_order();

	rb->delete_node(20);
	
	cout << "inorder: ";
	rb->inorder();
	cout << "level order: ";
	rb->level_order();

	return 0;
}
