from enum import Enum
from dataclasses import dataclass, field
from queue import Queue
from typing import Optional

#color class
class Color(Enum):
    Black = 0
    Red = 1

#define node of red black tree
@dataclass
class node:
    val: int = field(default=0)
    color: Color = field(default=Color.Red)
    parent: Optional['node'] = field(default=None)
    left: Optional['node'] = field(default=None)
    right: Optional['node'] = field(default=None)

class red_black_tree:
    #initial there is no node
    def __init__(self):
        self.root = None

    #inorder to check red black tree is wrong or not
    def inorder(self) -> None:
        print('Inorder:')
        self._inorder(self.root)
        print()

    def _inorder(self, root: node) -> None:
        if root == None:
            return

        self._inorder(root.left)
        print(root.val, end=' ')
        self._inorder(root.right)

    #level order to check red black tree is wrong or not
    def levelorder(self) -> None:
        print('Level order:')
        self._levelorder(self.root)

    def _levelorder(self, root: node) -> None:
        if root == None:
            print('There is no node !', end='')
            return

        q = Queue()
        q.put(root)

        while q.qsize() != 0:
            s = q.qsize()

            for i in range(s):
                cur = q.get()

                print('{}({})'.format(cur.val, cur.color.name), end=' ')

                if cur.left != None:
                    q.put(cur.left)

                if cur.right != None:
                    q.put(cur.right)

            print()

    def _left_rotation(self, root: node) -> None:
        r = root.right
        r_left = r.left

        r.left = root
        root.right = r_left

        if r_left != None:
            r_left.parent = root

        if root.parent == None:
            self.root = r
        elif root == root.parent.left:
            root.parent.left = r
        else:
            root.parent.right = r

        r.parent = root.parent
        root.parent = r

    def _right_rotation(self, root: node) -> None:
        l = root.left
        l_right = l.right

        l.right = root
        root.left = l_right

        if l_right != None:
            l_right.parent = root

        if root.parent == None:
            self.root = l
        elif root == root.parent.left:
            root.parent.left = l
        else:
            root.parent.right = r

        l.parent = root.parent
        root.parent = l

    #insert node
    def insert_node(self, v: int) -> None:
        n = node(val=v)
        self.root = self._insert_node(self.root, n)
        self._fix_insert(n)

    #using BST to find the new node position
    def _insert_node(self, root: node, n: node) -> node:
        if root == None:
            root = n
            return root

        if root.val > n.val:
            root.left = self._insert_node(root.left, n)
            root.left.parent = root
        else:
            root.right = self._insert_node(root.right, n)
            root.right.parent = root

        return root

    def _fix_insert(self, root: node) -> node:
        #two consecutive red node, need fix
        while root.parent != None and root.parent.color == Color.Red:
            #the right child tree of root's grandparent is unbalance
            if root.parent == root.parent.parent.right:
                uncle = root.parent.parent.left

                #need color change or not
                if uncle != None and uncle.color == Color.Red:
                    self._color_change(root.parent.parent)
                else:
                    if root == root.parent.left:
                        root = root.parent
                        self._right_rotation(root)

                    root.parent.color = Color.Black
                    root.parent.parent.color = Color.Red

                    self._left_rotation(root.parent.parent)
            #ther left child tree of root's grandparent is unbalance
            else:
                uncle = root.parent.parent.right

                #need color change or not
                if uncle != None and uncle.color == Color.Red:
                    self._color_change(root.parent.parent)
                else:
                    if root == root.parent.right:
                        root = root.parent
                        self._left_rotation(root)

                    root.parent.color = Color.Black
                    root.parent.parent = Color.Red

                    self._right_rotation(root.parent.parent)

        self.root.color = Color.Black

    def _color_change(self, root: node) -> None:
        root.color = Color.Red
        root.left.color = Color.Black
        root.right.color = Color.Black

    #delete node
    def delete_node(self, val: int) -> None:
        self._delete_node(self.root, val)

    def _delete_node(self, root: node, val: int) -> None:
        #delete node initial be None
        del_node = None

        #use BST to find the node need delete
        while root is not None:
            if root.val == val:
                del_node = root
                break

            elif root.val > val:
                root = root.left

            else:
                root = root.right

        if del_node is None:
            print('There is no node val = {}'.format(val))
            return

        inp_node = del_node
        inp_ori_color = inp_node.color

        #find inplace node
        if del_node.left is None:
            inp_node = del_node.right
            fix_node = inp_node
            self._Transplant(del_node, inp_node)

        elif del_node.right is None:
            inp_node = del_node.left
            fix_node = inp_node
            self._Transplant(del_node, inp_node)

        else:
            inp_node = self._minimum(del_node.right)
            fix_node = inp_node.right

            if inp_node.parent != del_node:
                self._Transplant(inp_node, fix_node)

                if fix_node is not None:
                    inp_ori_color = fix_node.color

            self._Transplant(del_node, inp_node)

            inp_node.left = del_node.left
            inp_node.left.parent = inp_node

            inp_node.right = del_node.right
            inp_node.right.parent = inp_node

            inp_node.color = del_node.color

        del del_node
        if inp_ori_color == Color.Red:
            self._fix_delete(fix_node)

    #inplace the inp_node to the del_node's position
    def _Transplant(self, del_node: node, inp_node: node) -> None:
        #delete node is root
        if del_node.parent is None:
            self.root = inp_node

        #delete node is left child
        elif del_node == del_node.parent.left:
            del_node.parent.left = inp_node

        #delete node is right child
        else:
            del_node.parent.right = inp_node

        #change inplace node's parent
        if inp_node is not None:
            inp_node.parent = del_node.parent

    #return the minimum val node of tree
    def _minimum(self, root: node) -> node:
        if root is None or root.left is None:
            return root

        return self._minimum(root.left)

    def _fix_delete(self, root: node) -> None:
        if root is None:
            return

        while root is not None and root != self.root and root.color == Color.Black:
            if root == root.parent.left:
                sibling = root.parent.right
                
                if sibling.color == Color.Red:
                    sibling.color = Color.Black
                    root.parent.color = Color.Red
                    self._left_rotation(root.parent)
                    sibling = root.parent.right

                if sibling.left.color == Color.Black and sibling.right.color == Color.Black:
                    sibling.color = Color.Red
                    root = root.parent

                else:
                    if sibling.right.color == Color.Black:
                        sibling.left.color = Color.Black
                        sibling.color = color.Red
                        self._right_rotation(sibling)
                        sibling = root.parent.right

                    sibling.color = root.parent.color
                    root.parent.color = Color.Black
                    sibling.right.color = Color.Black
                    self._left_rotation(root.parent)
                    root = self.root
            else:
                sibling = root.parent.left
                
                if sibling.color == Color.Red:
                    sibling.color = Color.Black
                    root.parent.color = Color.Red
                    self._right_rotation(root.parent)
                    sibling = root.parent.left

                if sibling.left.color == Color.Black and sibling.right.color == Color.Black:
                    sibling.color = Color.Red
                    root = root.parent

                else:
                    if sibling.left.color == Color.Black:
                        sibling.right.color = Color.Black
                        sibling.color = color.Red
                        self._left_rotation(sibling)
                        sibling = root.parent.left

                    sibling.color = root.parent.color
                    root.parent.color = Color.Black
                    sibling.left.color = Color.Black
                    self._right_rotation(root.parent)
                    root = self.root

            root.color = Color.Black
