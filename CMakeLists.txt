cmake_minimum_required(VERSION 3.23)
project(aisd2023 C)

set(CMAKE_C_STANDARD 99)

add_executable(aisd2023 main.c task/tsk1.c task/tsk1.h stack/array/stack.c stack/array/stack.h stack/list/stack.c stack/list/stack.h queue/vector/queue.c queue/vector/queue.h queue/list/queue.c queue/list/queue.h queue/circular_list/queue.c queue/circular_list/queue.h deque/array/deque.c deque/array/deque.h deque/circular_list/deque.c deque/circular_list/deque.h deque/list/deque.c deque/list/deque.h table/array/table.c table/array/table.h table/hash/hash.c table/hash/hash.h table/list/table.c table/list/table.h table/ordered/table.c table/ordered/table.h table/hash_chaining/hash_table.c table/hash_chaining/hash_table.h table/hash_probing/hash_table.c table/hash_probing/hash_table.h tree/BST/binaryTree.c tree/BST/binaryTree.h tree/BST_par/binaryTree.c tree/BST_par/binaryTree.h)
