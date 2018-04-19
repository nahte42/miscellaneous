import random
import LinkedListDS

random.seed(None)

list = LinkedListDS.LinkedList()

list.insert(random.randint(1, 10))
list.insert(random.randint(1, 10))
list.insert(random.randint(1, 10))
list.insert(random.randint(1, 10))
list.insert(random.randint(1, 10))
list.insert(random.randint(1, 10))
list.insert(random.randint(1, 10))
list.insert(12)

list.traverse()

list.remove(12)

list.traverse()



