class Node:
    def __init__(self, val: int = 0):
        self.val = val
        self.h = 0
        self.BF = 0
        self.left = None
        self.right = None

class AVL_tree:
    def __init__(self):
        self.root = None

    def inorder(self) -> None:
        print('Inorder:', end=' ')
        self._inorder(self.root)
        print('')

    def preorder(self) -> None:
        print('Preorder:', end=' ')
        self._preorder(self.root)
        print('')

    def insert_node(self, val: int) -> None:
        n = Node(val)
        self.root = self._insert_node(self.root, n)

    def delete_node(self, val: int) -> None:
        self.root = self._delete_node(self.root, val)

    def _inorder(self, root: Node) -> None:
        if root is None:
            return

        self._inorder(root.left)
        print('{}'.format(root.val), end=' ')
        self._inorder(root.right)

    def _preorder(self, root: Node) -> None:
        if root is None:
            return

        print('{}'.format(root.val), end=' ')
        self._preorder(root.left)
        self._preorder(root.right)

    def _insert_node(self, root: Node, n: Node) -> Node:
        if root is None:
            root = n
            return root

        if n.val > root.val:
            root.right = self._insert_node(root.right, n)
        else:
            root.left = self._insert_node(root.left, n)

        self._update_h_bf(root)

        if root.BF > 1:
            #LL type
            if root.left.BF >= 0:
                return self._right_rotation(root)
            #LR type
            else:
                root.left = self._left_rotation(root.left)
                return self._right_rotation(root)

        elif root.BF < -1:
            #RR type
            if root.right.BF <= 0:
                return self._left_rotation(root)
            #RL type
            else:
                root.right = self._right_rotation(root.right)
                return self._left_rotation(root)

        return root

    def _delete_node(self, root: Node, val: int) -> Node:
        if root is None:
            return None

        if val > root.val:
            root.right = self._delete_node(root.right, val)
        elif val < root.val:
            root.left = self._delete_node(root.left, val)
        else:
            if not root.left and not root.right:
                del root
                return None

            elif not root.left:
                tmp = root.right
                del root
                return tmp

            elif not root.right:
                tmp = root.left
                del root
                return tmp

            else:
                max_l = self._findMax(root.left)
                root.val, max_l.val = max_l.val, root.val
                root.left = self._delete_node(root.left, val)

        self._update_h_bf(root)

        if root.BF > 1:
            #LL type
            if root.left.BF >= 0:
                return self._right_rotation(root)
            #LR type
            else:
                root.left = self._left_rotation(root.left)
                return self._right_rotation(root)

        elif root.BF < -1:
            #RR type
            if root.right.BF <= 0:
                return self._left_rotation(root)
            #RL type
            else:
                root.right = self._right_rotation(root.right)
                return self._left_rotation(root)

        return root

    def _findMax(self, root: Node) -> Node:
        if root is None:
            return None

        return self._findMax(root.right) if root.right is not None else root

    def _update_h_bf(self, root: Node) -> None:
        if root is None:
            return

        l = root.left.h if root.left is not None else -1
        r = root.right.h if root.right is not None else -1

        root.h = max(l, r) + 1
        root.BF = l - r

    def _left_rotation(self, root: Node) -> Node:
        r = root.right
        r_lchild = r.left

        r.left = root
        root.right = r_lchild

        self._update_h_bf(root)
        self._update_h_bf(r)

        return r

    def _right_rotation(self, root: Node) -> Node:
        l = root.left
        l_rchild = l.right

        l.right = root
        root.left = l_rchild

        self._update_h_bf(root)
        self._update_h_bf(l)

        return l
