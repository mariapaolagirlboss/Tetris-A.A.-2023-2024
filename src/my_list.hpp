#ifndef MY_LIST_HPP
#define MY_LIST_HPP

#include <iostream>
#include <fstream>

using namespace std;

// Definizione della struttura nodo
struct node {
    int val;
    node* next;
    node* prev;
};

// Alias per la lista
using list = node*;

// Funzioni per la gestione della lista
list head_insert(list l, int el);
list insert_ordered(list head, int el);
void print_reverse(list head, const char* filename);
void delete_list(list& head);  // Passaggio per riferimento

#endif // MY_LIST_HPP
