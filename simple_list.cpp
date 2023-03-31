/// @file simple_list.h
/// @author Sujin Lee
/// @date 3/23/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief source file(function definitions)
/// @note 25hr
/// 2022-03-23: Sujin created

#include "simple_list.h"
using namespace std;

/// ---------------DEFINITION OF STANDALONE FUNCTIONS----------///
/// initializes a list to empty
void list_init(Node*& first, Node*& last) {
    if (first != nullptr){
        list_destroy(first, last);
    }
    else {
        first = nullptr;
        last = nullptr;
    }
}

/// checks whether a list is empty
/// @return bool
bool list_is_empty(const Node* first, const Node* last) {
    bool flag;
    return flag = (first == nullptr)? true : false;
}

/// prints a list in order using {1,2,3} format
void list_print(const Node* first, const Node* last) {
    auto current = first;
    char separator[2] = "";

    cout << '{';
    while (current != nullptr) {
        cout << separator << current->info;
        current = current->link;
        *separator = ',';
    }
    cout << '}';
}

/// returns the number of elements (nodes) in a list
/// @return size_t
size_t list_size(const Node* first, const Node* last) {
    auto current = first;
    size_t counter = 0;

    while (current != nullptr) {
        counter++;
        current = current->link;
    }
    return counter;
}

/// destroys a list
void list_destroy(Node*& first, Node*& last) {
    while (first != nullptr) {
        auto temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
}

/// accesses the front element of a list
/// @return int
int list_front(const Node* first, const Node* last) {
    int val = -1;
    if (first != nullptr) {
        val = first->info;
    }
    return val;
}

/// accesses the back element of a list
/// @return int
int list_back(const Node* first, const Node* last) {
    int val = -1;
    if (last != nullptr) {
        val = last->info;
    }
    return val;
}

/// searches a list for an item, returning true if found
/// @return bool
bool list_search(const Node* first, const Node* last, int item) {
    bool flag = false;
    auto current = first;
    while (current != nullptr && !flag) {
        if (current->info == item) {
            flag = true;
        }
        current = current->link;
    }
    return flag;
}

/// inserts an element to the beginning of a list
void list_insert_first(Node*& first, Node*& last, int item) {
    // initialize new_node
    auto new_node = new Node;
    new_node->info = item;
    new_node->link = nullptr;

    new_node->link = first;
    first = new_node;

    if (last == nullptr) {
        last = new_node;
    }
}

/// inserts an element to the end of a list
void list_insert_last(Node*& first, Node*& last, int item) {
    // initialize new_node
    auto new_node = new Node;
    new_node->info = item;
    new_node->link = nullptr;

    if (last == nullptr) {
        new_node->link = first;
        first = last = new_node;
    }
    else {
        last->link = new_node;
        last = new_node;
    }
}

/// removes the first element from a list
void list_delete_first(Node*& first, Node*& last) {
    if (first != nullptr) {
        auto temp = first;
        first = first->link;
        delete temp;

        // if we deleted the last node, then...
        if (first == nullptr) {
            last = nullptr;
        }
    }
}

/// removes the last element from a list
void list_delete_last(Node*& first, Node*& last) {
    if (last != nullptr) {
        auto current = first;

        while (current != nullptr && current->link != last) {
            current = current->link;
        }

        auto temp = last;
        last = current;
        last->link = nullptr;
        delete temp;
    }
}

/// creates of copy of the nodes from first1 to last1,
/// the copy beginning at first2 and ending at last2
void list_copy(const Node* first1, const Node* last1,
               Node*& first2, Node*& last2){
    const Node* current = first1;
    list_destroy(first2, last2);
    while (current != nullptr) {
        // there is just one element so first == last
        list_insert_last(first2, last2, current->info);
        current = current->link;
    }
}
