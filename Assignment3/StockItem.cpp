/*
 * File: StockItem.cpp
 * Author: James Clarke - bvr16rcu@uea.ac.uk
 * 
 * Source File, represents Stock Items within the program, allows functions to
 * be performed on instances of said Stock Items. Variables and methods defined
 * in StockItem.h
 * 
 * Created on 25th March 2018
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include "StockItem.h"

//Constructor Implementations.
StockItem::StockItem(std::string cType = "", std::string stkCode = "", int stkNum = 0,
        int uPrice = 0, std::string info = "") {
    compType = cType;
    stockCode = stkCode;
    stockNum = stkNum;
    unitPrice = uPrice;
    information = info;
}

/**
 * Constructors for each component type will have predefined component types as
 * a Resistor for example would never have a component type of "diode".
 */
Resistor::Resistor(std::string stkCode = "", int stkNum = 0, int uPrice = 0,
        std::string info = "") {
    compType = "resistor";
    stockCode = stkCode;
    stockNum = stkNum;
    unitPrice = uPrice;
    information = info;
}

Capacitor::Capacitor(std::string stkCode = "", int stkNum = 0, int uPrice = 0,
        std::string info = "") {
    compType = "capacitor";
    stockCode = stkCode;
    stockNum = stkNum;
    unitPrice = uPrice;
    information = info;
}

/*
 * Information variable in this component is predefined to "No info" as Diodes 
 * do not have any additional information.
 */
Diode::Diode(std::string stkCode = "", int stkNum = 0, int uPrice = 0) {
    compType = "diode";
    stockCode = stkCode;
    stockNum = stkNum;
    unitPrice = uPrice;
    information = "No info";
}

Transistor::Transistor(std::string stkCode = "", int stkNum = 0, int uPrice = 0,
        std::string info = "") {
    compType = "transistor";
    stockCode = stkCode;
    stockNum = stkNum;
    unitPrice = uPrice;
    information = info;
}

IC::IC(std::string stkCode = "", int stkNum = 0, int uPrice = 0, std::string info = "") {
    compType = "IC";
    stockCode = stkCode;
    stockNum = stkNum;
    unitPrice = uPrice;
    information = info;
}

//Get Method implementations.

std::string StockItem::getComp(){
    return this->compType;
}

std::string StockItem::getCode() {
    return this->stockCode;
}

int StockItem::getQuantity() {
    return this->stockNum;
}

int StockItem::getPrice() {
    return this->unitPrice;
}

std::string StockItem::getInfo() {
    return this->information;
}

std::string Resistor::getComp(){
    return "resistor";
}

std::string Capacitor::getComp(){
    return "capacitor";
}

std::string Diode::getComp(){
    return "diode";
}

std::string Transistor::getComp(){
    return "transistor";
}

std::string IC::getComp(){
    return "IC";
}

std::string Resistor::getCode(){
    return this->stockCode;
}

std::string Capacitor::getCode(){
    return this->stockCode;
}

std::string Diode::getCode(){
    return this->stockCode;
}

std::string Transistor::getCode(){
    return this->stockCode;
}

std::string IC::getCode(){
    return this->stockCode;
}

int Resistor::getQuantity(){
    return this->stockNum;
}

int Capacitor::getQuantity(){
    return this->stockNum;
}

int Diode::getQuantity(){
    return this->stockNum;
}

int Transistor::getQuantity(){
    return this->stockNum;
}

int IC::getQuantity(){
    return this->stockNum;
}

int Resistor::getPrice(){
    return this->unitPrice;
}

int Capacitor::getPrice(){
    return this->unitPrice;
}

int Diode::getPrice(){
    return this->unitPrice;
}

int Transistor::getPrice(){
    return this->unitPrice;
}

int IC::getPrice(){
    return this->unitPrice;
}

std::string Resistor::getInfo(){
    return this->information;
}

std::string Capacitor::getInfo(){
    return this->information;
}

std::string Diode::getInfo(){
    return this->information;
}

std::string Transistor::getInfo(){
    return this->information;
}

std::string IC::getInfo(){
    return this->information;
}

std::ostream &operator<<(std::ostream &os, const StockItem &item){
    os << "Component Type: " << item.compType << "\n"
            << "Stock Code: " << item.stockCode << "\n"
            << "Number in Stock: " << item.stockNum << "\n"
            << "Price per unit: " << item.unitPrice << "\n"
            << "Information: " << item.information << "\n";
    return os;
}

std::ostream &operator <<(std::ostream &os, const Resistor &item){
    os << "Component Type: " << item.compType << "\n"
            << "Stock Code: " << item.stockCode << "\n"
            << "Number in Stock: " << item.stockNum << "\n"
            << "Price per unit: " << item.unitPrice << "\n"
            << "Information: " << item.information << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Capacitor &item){
    os << "Component Type: " << item.compType << "\n"
            << "Stock Code: " << item.stockCode << "\n"
            << "Number in Stock: " << item.stockNum << "\n"
            << "Price per unit: " << item.unitPrice << "\n"
            << "Information: " << item.information << "\n";
    return os;
}
std::ostream &operator<<(std::ostream &os, const Diode &item){
    os << "Component Type: " << item.compType << "\n"
            << "Stock Code: " << item.stockCode << "\n"
            << "Number in Stock: " << item.stockNum << "\n"
            << "Price per unit: " << item.unitPrice << "\n"
            << "Information: " << item.information << "\n";
    return os;
}
std::ostream &operator<<(std::ostream &os, const Transistor &item){
    os << "Component Type: " << item.compType << "\n"
            << "Stock Code: " << item.stockCode << "\n"
            << "Number in Stock: " << item.stockNum << "\n"
            << "Price per unit: " << item.unitPrice << "\n"
            << "Information: " << item.information << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const IC &item){
    os << "Component Type: " << item.compType << "\n"
            << "Stock Code: " << item.stockCode << "\n"
            << "Number in Stock: " << item.stockNum << "\n"
            << "Price per unit: " << item.unitPrice << "\n"
            << "Information: " << item.information << "\n";
    return os;
}