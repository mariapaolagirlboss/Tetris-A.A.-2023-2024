#include "../include/my_list.hpp"
#include <iostream>
#include <fstream>

using namespace std;

struct node {
    int val;
    node* next;
    node* prev;
};

using list = node*;

list head_insert(list l, int el) {
    list tmp = new node;
    tmp->val = el;
    tmp->next = l;
    tmp->prev = NULL;
    if (l != NULL) {
        l->prev = tmp;
    }
    return tmp;
}

list insert_ordered(list head, int el) {
    list newNode = new node;
    newNode->val = el;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL || el >= head->val) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    list current = head;
    while (current->next != NULL && el < current->next->val) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

void print_reverse_helper(list head, ofstream& outputFile) {
    if (head == NULL) return;
    if (head->next != NULL) {
        print_reverse_helper(head->next, outputFile);
    }
    outputFile << head->val << endl;  // Stampa anche il primo nodo
}

void print_reverse(list head, const char* filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Errore nell'apertura del file " << filename << endl;
        return;
    }
    print_reverse_helper(head, outputFile);
    outputFile.close();
}

void delete_list(list& head) {
    while (head != NULL) {
        list temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;  // Assicura che il puntatore venga azzerato
}
