/* 
 * File:   StockProgram.cpp
 * Author: James Clarke - bvr16rcu@uea.ac.uk
 * 
 * Main file, used to process inventory data. Will use Inventory.cpp and 
 * StockItem.cpp to allow this. Comments contained are left in as evidence of
 * testing.
 *
 * Created on 23 March 2018, 16:11
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "string.h"
#include "StockItem.h"
#include "Inventory.h"

int main(int argc, char** argv) {
    
    std::ifstream inFile("Inventory.txt");
    std::ofstream outFile("Output.txt");
    invList aList;
    if (!inFile) {
        std::cout << "Unable to open file.";
        exit(1); //error return, no inventory to read, program cannot run.
    } else {
        std::cout << "file found \n";
        std::string line;
        std::string token;
        std::string toAdd[5];
        
        while (getline(inFile, line)) {
            std::istringstream ss(line);
            int count = 0;
            while (getline(ss, token, ',')) {
                toAdd[count] = token;
                count += 1;
            }
            
            //Determines what type of Stock Item to make.
            if (toAdd[0].compare("resistor") == 0) {
                StockItem *item = new Resistor(toAdd[1], stoi(toAdd[2]),
                        stoi(toAdd[3]), toAdd[4]);
                aList.createNode(item);
                outFile << *item << "\n";
            } else if (toAdd[0].compare("capacitor") == 0) {
                StockItem *item = new Capacitor(toAdd[1], stoi(toAdd[2]),
                        stoi(toAdd[3]), toAdd[4]);
                aList.createNode(item);
                outFile << *item << "\n";
            } else if (toAdd[0].compare("diode") == 0) {
                StockItem *item = new Diode(toAdd[1], stoi(toAdd[2]),
                        stoi(toAdd[3]));
                aList.createNode(item);
                outFile << *item << "\n";
            } else if (toAdd[0].compare("transistor") == 0) {
                StockItem *item = new Transistor(toAdd[1], stoi(toAdd[2]),
                        stoi(toAdd[3]), toAdd[4]);
                aList.createNode(item);
                outFile << *item << "\n";
            } else if (toAdd[0].compare("IC") == 0) {
                StockItem *item = new IC(toAdd[1], stoi(toAdd[2]), stoi(toAdd[3]),
                        toAdd[4]);
                aList.createNode(item);
                outFile << *item << "\n";
            //Will only trigger if the item is not an electronic component.
            } else {
                StockItem *item = new StockItem(toAdd[0], toAdd[1], stoi(toAdd[2]),
                        stoi(toAdd[3]), toAdd[4]);
                aList.createNode(item);
                outFile << *item << "\n";
            }
        }
    }
    
    inFile.close();
    outFile.close();

    /*
     * Question 1: Print a list of the inventory, sorted in order of increasing 
     * price.
     */
    aList.sortByPrice();
//    aList.display();
//    aList.sortByStock(); //Optional sort.
    std::cout << "\n";
    
    /*
     * Question 2: What is the component with the largest number of components 
     * in stock?
     */
    aList.mostInStock();
    std::cout << "\n";
    
    /*
     * Question 3: How many NPN Transistors does Chartlins have in stock?
     */
    aList.getNPNTransistors();
    std::cout << "\n";
    
    /*
     * Question 4: What is the total resistance of all of the resistors in 
     * stock?
     */
    aList.getTotalResistance();
    std::cout << "\n";
    
    /*
     * Question 5: How many stock items have unit prices above 10p?
     */
    aList.aboveTen();
    std::cout << "\n";
    
//    StockItem *test = new StockItem("a", "b", 1, 2, "c");
//    invNode *node = new invNode;
//    delete node;
//    node->content = test;
//    cout << *node->content;
    
//    delete test;
//    delete node;
    
    //Testing of copy constructor for the inventory list.
    invList secondList = aList;
    secondList.display();
    
    /*
     * Called explicitly for testing purposes, destructor is called when list 
     * goes out of scope (when EXIT return is called). For most situations the 
     * destructor shouldn't be called explicitly.
     */
//    aList.~invList();
    return EXIT_SUCCESS;
}



