# coding=utf-8
class huffmanNode:
    def __init__(self, data=None, lis=None):
        self.data = data
        self.left = None
        self.right = None
        self.lis = lis

    def lis_to_nodes(self):
        if not isinstance(self.lis[0], huffmanNode):
            self.lis = [huffmanNode(data) for data in self.lis]
        return self.lis

    def join(self, node1, node2):
        new_node = huffmanNode(node1.data + node2.data)
        new_node.left = node1
        new_node.right = node2
        return new_node

    def create(self):
        if self.lis is None or len(self.lis) == 0:
            raise RuntimeError("error: list is empty or null")
        if not isinstance(self.lis[0], huffmanNode):
            self.lis_to_nodes()
        self.lis = sorted(self.lis, key=lambda node: node.data)

        while len(self.lis) > 1:
            node1, node2 = self.lis[:2]
            self.lis = self.lis[2:]
            self.lis.append(self.join(node1, node2))

    def travel(self, root=None):
        if root == None:
            root = self.lis[0]
        self.__travel(root)

    def __travel(self, tree):
        if tree:
            self.__travel(tree.left)
            print(tree.data)
            self.__travel(tree.right)


if __name__ == '__main__':
    node = huffmanNode(lis=[5, 29, 7, 8, 14, 23, 3, 11])
    # for item in sorted(node.lis_to_nodes(),key=lambda node: node.data):print(item.data)
    node.create()
    node.travel()
