#include "Bird.h"
#include <iostream>
#include <fstream>

Bird::Bird() : Animal(), diet("Unknown"), habitat("Unknown") {
    std::cout << "Bird default constructor called" << std::endl;
}

Bird::Bird(const std::string& breed, const std::string& color, const std::string& diet, const std::string& habitat)
    : Animal(breed, color), diet(diet), habitat(habitat) {
    std::cout << "Bird parameterized constructor called" << std::endl;
}

Bird::Bird(const Bird& other) : Animal(other), diet(other.diet), habitat(other.habitat) {
    std::cout << "Bird copy constructor called" << std::endl;
}

Bird::~Bird() {
    std::cout << "Bird destructor called" << std::endl;
}

void Bird::display() const {
    std::cout << "=== BIRD ===" << std::endl;
    std::cout << "Breed: " << breed << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Diet: " << diet << std::endl;
    std::cout << "Habitat: " << habitat << std::endl;
    std::cout << "============" << std::endl;
}

void Bird::setData() {
    std::cout << "Enter bird breed: ";
    std::cin.ignore();
    std::getline(std::cin, breed);
    
    std::cout << "Enter bird color: ";
    std::getline(std::cin, color);
    
    std::cout << "Enter diet: ";
    std::getline(std::cin, diet);
    
    std::cout << "Enter habitat: ";
    std::getline(std::cin, habitat);
}

std::string Bird::getType() const {
    return "Bird";
}

void Bird::saveToFile(std::ofstream& file) const {
    file << "Bird" << std::endl;
    file << breed << std::endl;
    file << color << std::endl;
    file << diet << std::endl;
    file << habitat << std::endl;
}

void Bird::loadFromFile(std::ifstream& file) {
    std::getline(file, breed);
    std::getline(file, color);
    std::getline(file, diet);
    std::getline(file, habitat);
}

std::string Bird::getDiet() const {
    return diet;
}

std::string Bird::getHabitat() const {
    return habitat;
}

void Bird::setDiet(const std::string& diet) {
    this->diet = diet;
}

void Bird::setHabitat(const std::string& habitat) {
    this->habitat = habitat;
}

Bird& Bird::operator=(const Bird& other) {
    if (this != &other) {
        Animal::operator=(other);
        diet = other.diet;
        habitat = other.habitat;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bird& bird) {
    bird.display();
    return os;
}

std::istream& operator>>(std::istream& is, Bird& bird) {
    bird.setData();
    return is;
}

