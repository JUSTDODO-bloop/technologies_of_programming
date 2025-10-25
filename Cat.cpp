#include "Cat.h"
#include <iostream>
#include <fstream>

Cat::Cat() : Animal(), ownerName("Unknown"), nickname("Unknown") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname)
    : Animal(breed, color), ownerName(ownerName), nickname(nickname) {
    std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), ownerName(other.ownerName), nickname(other.nickname) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::display() const {
    std::cout << "=== CAT ===" << std::endl;
    std::cout << "Breed: " << breed << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Owner Name: " << ownerName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "===========" << std::endl;
}

void Cat::setData() {
    std::cout << "Enter cat breed: ";
    std::cin.ignore();
    std::getline(std::cin, breed);
    
    std::cout << "Enter cat color: ";
    std::getline(std::cin, color);
    
    std::cout << "Enter owner name: ";
    std::getline(std::cin, ownerName);
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
}

std::string Cat::getType() const {
    return "Cat";
}

void Cat::saveToFile(std::ofstream& file) const {
    file << "Cat" << std::endl;
    file << breed << std::endl;
    file << color << std::endl;
    file << ownerName << std::endl;
    file << nickname << std::endl;
}

void Cat::loadFromFile(std::ifstream& file) {
    std::getline(file, breed);
    std::getline(file, color);
    std::getline(file, ownerName);
    std::getline(file, nickname);
}

std::string Cat::getOwnerName() const {
    return ownerName;
}

std::string Cat::getNickname() const {
    return nickname;
}

void Cat::setOwnerName(const std::string& ownerName) {
    this->ownerName = ownerName;
}

void Cat::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        ownerName = other.ownerName;
        nickname = other.nickname;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Cat& cat) {
    cat.display();
    return os;
}

std::istream& operator>>(std::istream& is, Cat& cat) {
    cat.setData();
    return is;
}

