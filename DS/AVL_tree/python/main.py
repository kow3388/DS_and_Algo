from AVL_tree import AVL_tree as AVL

if __name__ == '__main__':
    avl = AVL()

    avl.insert_node(10)
    avl.insert_node(20)
    avl.insert_node(30)
    avl.insert_node(40)
    avl.insert_node(50)
    avl.insert_node(25)

    avl.inorder()
    avl.preorder()

    avl.delete_node(20)

    avl.inorder()
    avl.preorder()
