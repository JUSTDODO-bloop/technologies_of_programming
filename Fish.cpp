#include "Fish.h"
#include <iostream>
#include <fstream>

Fish::Fish() : Animal(), nutritionType("Unknown") {
    std::cout << "Fish default constructor called" << std::endl;
}

Fish::Fish(const std::string& breed, const std::string& color, const std::string& nutritionType)
    : Animal(breed, color), nutritionType(nutritionType) {
    std::cout << "Fish parameterized constructor called" << std::endl;
}

Fish::Fish(const Fish& other) : Animal(other), nutritionType(other.nutritionType) {
    std::cout << "Fish copy constructor called" << std::endl;
}

Fish::~Fish() {
    std::cout << "Fish destructor called" << std::endl;
}

void Fish::display() const {
    std::cout << "=== FISH ===" << std::endl;
    std::cout << "Breed: " << breed << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Nutrition Type: " << nutritionType << std::endl;
    std::cout << "============" << std::endl;
}

void Fish::setData() {
    std::cout << "Enter fish breed: ";
    std::cin.ignore();
    std::getline(std::cin, breed);
    
    std::cout << "Enter fish color: ";
    std::getline(std::cin, color);
    
    std::cout << "Enter nutrition type: ";
    std::getline(std::cin, nutritionType);
}

std::string Fish::getType() const {
    return "Fish";
}

void Fish::saveToFile(std::ofstream& file) const {
    file << "Fish" << std::endl;
    file << breed << std::endl;
    file << color << std::endl;
    file << nutritionType << std::endl;
}

void Fish::loadFromFile(std::ifstream& file) {
    std::getline(file, breed);
    std::getline(file, color);
    std::getline(file, nutritionType);
}

std::string Fish::getNutritionType() const {
    return nutritionType;
}

void Fish::setNutritionType(const std::string& nutritionType) {
    this->nutritionType = nutritionType;
}

Fish& Fish::operator=(const Fish& other) {
    if (this != &other) {
        Animal::operator=(other);
        nutritionType = other.nutritionType;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fish& fish) {
    fish.display();
    return os;
}

std::istream& operator>>(std::istream& is, Fish& fish) {
    fish.setData();
    return is;
}

