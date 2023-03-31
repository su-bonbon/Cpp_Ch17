/// @file pa17a.cpp
/// @author Sujin Lee
/// @date 3/23/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Client Program using simple_list.h and simple_list.cpp
/// @note 25hr
/// 2022-03-23: Sujin created
#include <iostream>
#include "simple_list.h"
using namespace std;

int main() {

    int num;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;

    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    Node* head3 = nullptr;
    Node* tail3 = nullptr;

    list_init(head1, tail1);
    list_init(head2, tail2);
    list_init(head3, tail3);

    while (list_size(head1, tail1) < 15) {
        num = rand() % 101;
        if (head1 == nullptr) {  // when node is empty
            list_insert_first(head1, tail1, num);
        }
        else {
            if (list_front(head1, tail1) > num &&
                num > list_front(head1, tail1) - 5) {
                list_insert_first(head1, tail1, num);
            }
            else if (list_back(head1, tail1) < num &&
                     num < list_back(head1, tail1) + 5) {
                list_insert_last(head1, tail1, num);
            }
        }
    }

    while (list_size(head2, tail2) < 15) {
        num = rand() % 101;
        if (head2 == nullptr) {  // when node is empty
            list_insert_first(head2, tail2, num);
        }
        else {
            if (list_front(head2, tail2) > num &&
                num > list_front(head2, tail2) - 5) {
                list_insert_first(head2, tail2, num);
            }
            else if (list_back(head2, tail2) < num &&
                     num < list_back(head2, tail2) + 5) {
                list_insert_last(head2, tail2, num);
            }
        }
    }

    auto current1 = head1;
    auto current2 = head2;
    int comp1;
    int comp2;
    bool check = true;

    while (!(current1 == nullptr && current2 == nullptr)) {
        if (current1 != nullptr) {
            comp1 = list_front(current1, tail1);
        }
        if (current2 != nullptr) {
            comp2 = list_front(current2, tail2);
        }
        if (current1 != nullptr && current2 != nullptr) {
            if (comp1 < comp2 && check) {
                if (!list_search(head3, tail3, comp1)) {
                    list_insert_last(head3, tail3, comp1);
                }
                current1 = current1->link;
                comp1 = list_front(current1, tail1);
                check = false;
            }
            else if (comp1 > comp2 && check) {
                if (!list_search(head3, tail3, comp2)) {
                    list_insert_last(head3, tail3, comp2);
                }
                current2 = current2->link;
                comp2 = list_front(current2, tail2);
                check = false;
            }

            else if (comp1 == comp2 && check) {
                if (!list_search(head3, tail3, comp1)) {
                    list_insert_last(head3, tail3, comp1);
                }
                current1 = current1->link;
                current2 = current2->link;
                comp1 = list_front(current1, tail1);
                comp2 = list_front(current2, tail2);
                check = false;
            }
            check = true;
        }
        else if (current1 == nullptr) {
            if (!list_search(head3, tail3, comp2)) {
                list_insert_last(head3, tail3, comp2);
            }
            current2 = current2->link;
        }
        else if (current2 == nullptr) {
            if (!list_search(head3, tail3, comp1)) {
                list_insert_last(head3, tail3, comp1);
            }
            current1 = current1->link;
        }

    }
    cout << "***LIST1***" << endl;
    list_print(head1, tail1);
    cout << endl;
    cout << "***LIST2***" << endl;
    list_print(head2, tail2);
    cout << endl;
    cout << "***LIST3***" << endl;
    list_print(head3, tail3);
    cout << endl;

    list_destroy(head1, tail1);
    list_destroy(head2, tail2);
    list_destroy(head3, tail3);


    return 0;
}
