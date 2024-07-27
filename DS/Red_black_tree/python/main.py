from Red_black_tree import red_black_tree as RB

if __name__ == '__main__': 
    rb = RB()

    rb.insert_node(10)
    rb.insert_node(20)
    rb.insert_node(30)
    rb.insert_node(40)
    rb.insert_node(50)
    rb.insert_node(25)

    rb.inorder()
    rb.levelorder()

    rb.delete_node(20)

    rb.inorder()
    rb.levelorder()
