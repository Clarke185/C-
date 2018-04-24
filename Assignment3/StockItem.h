/* 
 * File:   StockItem.h
 * Author: James
 *
 * Header File, defines a Stock Item. Each Stock Item should be created as their
 * own specific type depending on their component type. I.e. a component with
 * "resistor" as the component type will be should be instantiated. If no
 * applicable component type exists then a standard Stock Item should be created
 * 
 * Created on 25 March 2018, 15:43
 */

#ifndef STOCKITEM_H
#define STOCKITEM_H

#include <cstdlib>
#include <string>
#include <iostream>

class StockItem {
    
public:
    //Variable definitions.
    std::string compType, stockCode, information;
    int stockNum, unitPrice;

    //Constructor declaration.
    StockItem(std::string compType, std::string stockCode, int stockNum, int unitPrice,
            std::string information);
    
    //Get method declarations.
    virtual std::string getComp();
    virtual std::string getCode();
    virtual int getQuantity();
    virtual int getPrice();
    virtual std::string getInfo();
    
    friend std::ostream &operator<<(std::ostream &os, const StockItem &item);
    
};
std::ostream& operator<<(std::ostream& os, const StockItem &item);

class Resistor : public StockItem {
public:
    Resistor(std::string stockCode, int stockNum, int unitPrice, std::string information);
    
    std::string getComp() override;
    std::string getCode() override;
    int getQuantity() override;
    int getPrice() override;
    std::string getInfo() override;
    friend std::ostream& operator<<(std::ostream& os, const Resistor &item);
    
};
std::ostream& operator<<(std::ostream& os, const Resistor &item);

class Capacitor : public StockItem {
public:
    Capacitor(std::string stockCode, int stockNum, int unitPrice,
            std::string information);
    std::string getComp() override;
    std::string getCode() override;
    int getQuantity() override;
    int getPrice() override;
    std::string getInfo() override;
    friend std::ostream& operator<<(std::ostream& os, const Capacitor &item);
};
std::ostream& operator<<(std::ostream& os, const Capacitor &item);

class Diode : public StockItem {
public:
    Diode(std::string stockCode, int stockNum, int unitPrice);
    std::string getComp() override;
    std::string getCode() override;
    int getQuantity() override;
    int getPrice() override;
    std::string getInfo() override;
    friend std::ostream& operator<<(std::ostream& os, const Diode &item);
};
std::ostream& operator<<(std::ostream& os, const Diode &item);

class Transistor : public StockItem {
public:
    Transistor(std::string stockCode, int stockNum, int unitPrice,
            std::string information);
    std::string getComp() override;
    std::string getCode() override;
    int getQuantity() override;
    int getPrice() override;
    std::string getInfo() override;
    friend std::ostream& operator<<(std::ostream& os, const Transistor &item);
};
std::ostream& operator<<(std::ostream& os, const Transistor &item);

class IC : public StockItem {
public:
    IC(std::string stockCode, int stockNum, int unitPrice, std::string information);
    std::string getComp() override;
    std::string getCode() override;
    int getQuantity() override;
    int getPrice() override;
    std::string getInfo() override;
    friend std::ostream& operator<<(std::ostream& os, const IC &item);
};
std::ostream& operator<<(std::ostream& os, const IC &item);


#endif /* STOCKITEM_H */

