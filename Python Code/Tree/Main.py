from BSTDS import BST
import random

myTree = BST()#Dont forget the paranthesis
random.seed(None)

i = 0
while i < 100:
    myTree.insert(random.randint(1, 10000))
    i += 1


print('Maximum Number: ', myTree.getMax())
print('Minimum Number: ', myTree.getMin())
print('Traverse in Order')
myTree.TraverseInOrder()