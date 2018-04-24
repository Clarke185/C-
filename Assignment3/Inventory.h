/* 
 * File:   Inventory.h
 * Author: James
 * 
 * Header File, defines a node and list for a set of inventory items. A linked
 * list is used for this definition.
 *
 * Created on 25 March 2018, 15:43
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <cstdlib>
#include <string>
#include <iostream>
#include "StockItem.h"

struct invNode {
public:
    StockItem *content;
    invNode *next;
    
    invNode(){
        content = NULL;
        next = NULL;
    }
    
//    //invNode Copy constructor
//    invNode(const invNode &node);
//    //invNode copy assignment operator
//    invNode& operator = (const invNode &node);
//    //invNode destructor.
//    ~invNode();

};
class invList {
private:
    invNode *head, *tail;

public:

    //Default constructor
    invList() {
        head = NULL;
        tail = NULL;
    }
    
    //List Copy constructor
    invList(const invList &list);
    //List Copy Assignment Operator
    invList& operator = (const invList &list);
    //List Destructor
    ~invList();

    invNode* getHead();
    invNode* getTail();
    void createNode(StockItem *item);
    void display();    
    void sortByPrice();
    void sortByStock();
    void mostInStock();
    void getNPNTransistors();
    void getTotalResistance();
    void aboveTen();
};

#endif /* INVENTORY_H */

