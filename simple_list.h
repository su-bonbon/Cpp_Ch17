/// @file simple_list.h
/// @author Sujin Lee
/// @date 3/23/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief header file(struct definition and the function prototypes)
/// @note 25hr
/// 2022-03-23: Sujin created

#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

#include <iostream>
#include <initializer_list>

// ---------------DEFINITION OF NODE--------------------------///
struct Node {
    int   info;
    Node* link;
};

// ---------------DEFINITION OF STANDALONE FUNCTIONS----------///
/// initializes a list to empty
void list_init(Node*& first, Node*& last);

/// checks whether a list is empty
/// @return bool
bool list_is_empty(const Node* first, const Node* last);

/// prints a list in order using {1,2,3} format
void list_print(const Node* first, const Node* last);

/// returns the number of elements (nodes) in a list
/// @return size_t
size_t list_size(const Node* first, const Node* last);

/// destroys a list
void list_destroy(Node*& first, Node*& last);

/// accesses the front element of a list
/// @return int
int list_front(const Node* first, const Node* last);

/// accesses the back element of a list
/// @return int
int list_back(const Node* first, const Node* last);

/// searches a list for an item, returning true if found
/// @return bool
bool list_search(const Node* first, const Node* last, int item);

/// inserts an element to the beginning of a list
void list_insert_first(Node*& first, Node*& last, int item);

/// inserts an element to the end of a list
void list_insert_last(Node*& first, Node*& last, int item);

/// removes the first element from a list
void list_delete_first(Node*& first, Node*& last);

/// removes the last element from a list
void list_delete_last(Node*& first, Node*& last);

/// creates of copy of the nodes from first1 to last1,
/// the copy beginning at first2 and ending at last2
void list_copy(const Node* first1, const Node* last1,
               Node*& first2, Node*& last2);

#endif /* SIMPLE_LIST_H */
