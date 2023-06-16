#include "Hash.h"

using namespace std;

LinearProbing::LinearProbing() {
    for(int i = 0; i < 26; ++i)
        memset(SymbolTable[i], '\0', sizeof(char) * 100);
}

void LinearProbing::Insert(char *str) {
    int key = str[0] - 'a';
    if(SymbolTable[key][0] == '\0') {
        strcpy(SymbolTable[key], str);
        return;
    }
    int i = key + 1;
    while(i != key) {
        if (SymbolTable[i][0] == '\0') {
            strcpy(SymbolTable[i], str);
            return;
        }
        i = (i + 1) % 26;
    }
}


bool LinearProbing::Search(char *str) {
    int key = str[0] - 'a';
    if(!strcmp(SymbolTable[key], str)) {
        return true;
    }
    int i = key + 1;
    while(i != key){
        if (!strcmp(SymbolTable[i], str))
            return true;
        i = (i + 1) % 26;
    }
    return false;
}

void LinearProbing::Print() {
    for(int i = 0; i < 26; ++i)
        cout << i << "(" << (char)(i + 'a') << ")" << ":\t" << SymbolTable[i] << endl;
}




ChainList::ChainList() {
    for(int i = 0; i < 26; ++i) 
        SymbolTable[i] = nullptr;
}

void ChainList::Insert(char *str){
    int key = str[0] - 'a';
    if(SymbolTable[key] == nullptr) {
        SymbolTable[key] = new Link;
        strcpy(SymbolTable[key]->item, str);
        SymbolTable[key]->next = nullptr;
        return;
    }
    Link *new_node = new Link;
    strcpy(new_node->item, str); new_node->next = nullptr;
    Link *current = SymbolTable[key];
    while(current->next != nullptr) current = current = current->next;
    current->next = new_node;
}

bool ChainList::Search(char *str) {
    int key = str[0] - 'a';
    if(SymbolTable[key] == nullptr) return false;
    if(!strcmp(SymbolTable[key]->item, str)) {
        return true;
    }
    Link *current = SymbolTable[key];
    while(current != nullptr) {
        if(!strcmp(current->item, str)) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void ChainList::Print() {
    for(int i = 0; i < 26; ++i) {
        cout << i << "(" << (char)(i + 'a') << "):\t";
        if(SymbolTable[i] != nullptr) {
            Link *current = SymbolTable[i];
            while(current != nullptr) {
                if(current->next == nullptr)
                    cout << current->item;
                else 
                    cout << current->item << " -> ";
                current = current->next; 
            }
        }
        cout << endl;
    }
}

