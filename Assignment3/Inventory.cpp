/**
 * File: Inventory.cpp
 * Author: James Clarke - bvr16rcu@uea.ac.uk
 * 
 * Source File, implements a list for the Inventory of the Chartlins electronics
 * company. Variables and Methods defined in Inventory.h.
 * 
 * Created on 25th March 2018 
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

#include "Inventory.h"
#include "StockItem.h"

invList::invList(const invList &list){
    std::cout << "Copy constructor called. \n";
    invNode *temp = new invNode;
    invNode *next = new invNode;
    
    temp = list.head;
    next = temp->next;
    
    while(next != NULL){
        this->createNode(temp->content);
        temp = next;
        next = next->next;
    }
}

invList& invList::operator = (const invList& list){
    invList temp(list);
    std::swap(temp.head, head);
    return *this;
}

invList::~invList(){
    std::cout << "List destructor called. \n";
    invNode *temp = this->head;
    while(temp != NULL){
        invNode *next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;
    delete head;
}

//invNode::invNode(const invNode& node){
//    StockItem *curr = new StockItem(node.content->compType, 
//            node.content->stockCode, node.content->stockNum, 
//            node.content->unitPrice, node.content->information);
//    
//    this->content = curr;
//}
//
//invNode& invNode::operator =(const invNode& node){
//    invNode temp(node);
//    std::swap(temp.content, content);
//    return *this;
//}
//
//invNode::~invNode(){
//    delete this;
//}

/**
 * Get method for returning the first item of a list.
 * @return invNode, first item (head) of the list.
 */
invNode* invList::getHead() {
    return this->head;
}

/**
 * Get method for returning the last item of a list.
 * @return invNode, last item (tail) of the list.
 */
invNode* invList::getTail() {
    return this->tail;
}

/**
 * Creates a new node in the current inventory list.
 * @param item - The StockItem to create an inventory node from.
 */
void invList::createNode(StockItem *item) {
    invNode* node = new invNode;

    node->content = item;
    node->next = NULL;

    if (head == NULL) {
        head = node;
        tail = node;
        node = NULL;
    } else {
        tail->next = node;
        tail = node;
    }
}

/**
 * Displays a linked list of inventory nodes, given a list to act upon.
 */
void invList::display() {
    invNode *temp = this->getHead();
    while (temp != NULL) {
        std::cout << *temp->content << "\n";
        temp = temp->next;
    }
    delete(temp);
}

/**
 * Method for arranging a list of inventory items by ascending price order. Will
 * continue to run a sort until all nodes are in ascending order.
 */
void invList::sortByPrice() {
    if (this->getHead() != this->getTail()) {
        bool sort;
        while (sort != true) {
            sort = true; //determines if a node needs sorting
            for (invNode *node = this->getHead(); node->next != NULL;
                    node = node->next) {
                if (node->content->unitPrice > node->next->content->unitPrice) {
                    StockItem *temp = node->content;
                    node->content = node->next->content;
                    node->next->content = temp;
                    sort = false;
                }
            }
        }
    }
}

/**
 * Variation on a price sort to be used in another method.
 */
void invList::sortByStock() {
    if (this->getHead() != this->getTail()) {
        bool sort;
        while (sort != true) {
            sort = true; //determines if a node needs sorting
            for (invNode *node = this->getHead(); node->next != NULL;
                    node = node->next) {
                if (node->content->stockNum > node->next->content->stockNum) {
                    StockItem *temp = node->content;
                    node->content = node->next->content;
                    node->next->content = temp;
                    sort = false;
                }
            }
        }
    }
}

/**
 * Sorts this inventory list by stock number (lowest to highest) and outputs the
 * last node.
 */
void invList::mostInStock() {
    this->sortByStock();
    StockItem *item = this->tail->content;
    std::cout << "The component with the most number of items in stock is:\n" <<
            *item << "\n";
}

/**
 * Outputs the number of NPN Transistors in stock to the console, given a list 
 * to work upon.
 */
void invList::getNPNTransistors() {
    invNode *current = this->head;

    int count = 0;
    while (current != NULL) {
        /**
         * Checks if the product type is a transistor and the information 
         * contains "NPN" (denotes an NPN transistor).
         */
        if (current->content->compType == "transistor" &&
                (current->content->information.find("NPN") != std::string::npos)) {
            count += current->content->stockNum;
            //            std::cout << current->content->toString() << "\n";
        }
        current = current->next;
    }
    std::cout << "NPN Transistors in Stock: " << count << "\n";
    delete(current);
}

/**
 * Function to output the total resistance of every resistor in stock, this is
 * the total resistance of each resistor as opposed to each type of resistor, so
 * is dependent on all the resistors in stock, as well as the number of each 
 * resistor in stock. 0 stock values are not considered.
 */
void invList::getTotalResistance() {
    invNode *current = this->getHead();
    long double count = 0.0;
    std::cout.precision(13); //prevents x*e^n output rounding off decimals.
    while (current != NULL) {
        if (current->content->compType == "resistor" &&
                current->content->stockNum > 0) {
            /*
             * For each component being a resistor, and having at least 1 in the
             * stock count, the resistance value is calculated based on the
             * letter denoting their magnitude of resistance. So each letter can
             * be replaced with a decimal point and multiplied respectively.
             */
            if (current->content->information.find("R") != std::string::npos) {
                std::replace(current->content->information.begin(),
                        current->content->information.end(), 'R', '.');
                count += stod(current->content->information) *
                        current->content->stockNum;
                /*
                 * Reverse replacement prevents inconsistent information being
                 * displayed for each Stock Item if accessed after this method
                 * is executed.
                 */
                std::replace(current->content->information.begin(),
                        current->content->information.end(), '.', 'R');

            } else if (current->content->information.find("K") != std::string::npos){
                std::replace(current->content->information.begin(),
                        current->content->information.end(), 'K', '.');
                count += stod(current->content->information) * 1000 *
                        current->content->stockNum;
                std::replace(current->content->information.begin(),
                        current->content->information.end(), '.', 'K');

            } else if (current->content->information.find("M") != std::string::npos){
                std::replace(current->content->information.begin(),
                        current->content->information.end(), 'M', '.');
                count += stod(current->content->information) * 1000000 *
                        current->content->stockNum;
                std::replace(current->content->information.begin(),
                        current->content->information.end(), '.', 'M');
            }
        }
        current = current->next;
    }
    std::cout << "Total resistance of resistors in stock: " << count << " ohms." <<
            "\n";
    delete(current);
}

/**
 * Outputs to the console every component in stock that has a unit price greater
 * than ten.
 */
void invList::aboveTen() {
    int count = 0;
    invNode *current = this->head;
    while (current != NULL) {
        if (current->content->unitPrice > 10) {
            count += 1;
        }
        current = current->next;
    }
    std::cout << "The number stock items with unit prices above 10p is: " << count <<
            "\n";
    delete(current);
}