#include "Animal.h"
#include <iostream>

int Animal::totalAnimals = 0;

Animal::Animal() : breed("Unknown"), color("Unknown") {
    totalAnimals++;
    std::cout << "Animal default constructor called. Total animals: " << totalAnimals << std::endl;
}

Animal::Animal(const std::string& breed, const std::string& color) 
    : breed(breed), color(color) {
    totalAnimals++;
    std::cout << "Animal parameterized constructor called. Total animals: " << totalAnimals << std::endl;
}

Animal::Animal(const Animal& other) : breed(other.breed), color(other.color) {
    totalAnimals++;
    std::cout << "Animal copy constructor called. Total animals: " << totalAnimals << std::endl;
}

Animal::~Animal() {
    totalAnimals--;
    std::cout << "Animal destructor called. Total animals: " << totalAnimals << std::endl;
}

std::string Animal::getBreed() const {
    return breed;
}

std::string Animal::getColor() const {
    return color;
}

void Animal::setBreed(const std::string& breed) {
    this->breed = breed;
}

void Animal::setColor(const std::string& color) {
    this->color = color;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        breed = other.breed;
        color = other.color;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Animal& animal) {
    animal.display();
    return os;
}

std::istream& operator>>(std::istream& is, Animal& animal) {
    animal.setData();
    return is;
}

int Animal::getTotalAnimals() {
    return totalAnimals;
}

