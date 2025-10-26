#include "Keeper.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

Keeper::Keeper() : capacity(10), size(0) {
    animals = new Animal*[capacity];
    for (int i = 0; i < capacity; i++) {
        animals[i] = nullptr;
    }
    std::cout << "Keeper default constructor called" << std::endl;
}

Keeper::Keeper(int initialCapacity) : capacity(initialCapacity), size(0) {
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity must be positive");
    }
    animals = new Animal*[capacity];
    for (int i = 0; i < capacity; i++) {
        animals[i] = nullptr;
    }
    std::cout << "Keeper parameterized constructor called" << std::endl;
}

Keeper::Keeper(const Keeper& other) : capacity(other.capacity), size(other.size) {
    animals = new Animal*[capacity];
    for (int i = 0; i < capacity; i++) {
        animals[i] = nullptr;
    }
    
    for (int i = 0; i < size; i++) {
        if (other.animals[i] != nullptr) {
            std::string type = other.animals[i]->getType();
            if (type == "Fish") {
                animals[i] = new Fish(*(Fish*)other.animals[i]);
            } else if (type == "Bird") {
                animals[i] = new Bird(*(Bird*)other.animals[i]);
            } else if (type == "Cat") {
                animals[i] = new Cat(*(Cat*)other.animals[i]);
            }
        }
    }
    std::cout << "Keeper copy constructor called" << std::endl;
}

Keeper::~Keeper() {
    clear();
    delete[] animals;
    std::cout << "Keeper destructor called" << std::endl;
}

void Keeper::resize() {
    int newCapacity = capacity * 2;
    Animal** newAnimals = new Animal*[newCapacity];
    
    for (int i = 0; i < newCapacity; i++) {
        newAnimals[i] = nullptr;
    }
    
    for (int i = 0; i < size; i++) {
        newAnimals[i] = animals[i];
    }
    
    delete[] animals;
    animals = newAnimals;
    capacity = newCapacity;
}

void Keeper::clear() {
    for (int i = 0; i < size; i++) {
        if (animals[i] != nullptr) {
            delete animals[i];
            animals[i] = nullptr;
        }
    }
    size = 0;
}

void Keeper::addAnimal(Animal* animal) {
    if (animal == nullptr) {
        throw std::invalid_argument("Cannot add null animal");
    }
    
    if (size >= capacity) {
        resize();
    }
    
    animals[size] = animal;
    size++;
    std::cout << "Animal added successfully. Total animals: " << size << std::endl;
}

void Keeper::removeAnimal(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (animals[index] != nullptr) {
        delete animals[index];
    }
    
    for (int i = index; i < size - 1; i++) {
        animals[i] = animals[i + 1];
    }
    
    animals[size - 1] = nullptr;
    size--;
    std::cout << "Animal removed successfully. Total animals: " << size << std::endl;
}

void Keeper::displayAll() const {
    if (size == 0) {
        std::cout << "No animals in the collection." << std::endl;
        return;
    }
    
    std::cout << "=== ALL ANIMALS ===" << std::endl;
    for (int i = 0; i < size; i++) {
        if (animals[i] != nullptr) {
            std::cout << "Index " << i << ": ";
            animals[i]->display();
            std::cout << std::endl;
        }
    }
    std::cout << "==================" << std::endl;
}

void Keeper::displayByType(const std::string& type) const {
    bool found = false;
    std::cout << "=== " << type << "S ===" << std::endl;
    
    for (int i = 0; i < size; i++) {
        if (animals[i] != nullptr && animals[i]->getType() == type) {
            std::cout << "Index " << i << ": ";
            animals[i]->display();
            std::cout << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No " << type << "s found." << std::endl;
    }
    std::cout << "==================" << std::endl;
}

void Keeper::modifyAnimal(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (animals[index] == nullptr) {
        throw std::runtime_error("Animal at index is null");
    }
    
    std::cout << "Current animal data:" << std::endl;
    animals[index]->display();
    std::cout << "Enter new data:" << std::endl;
    animals[index]->setData();
    std::cout << "Animal data updated successfully." << std::endl;
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }
    
    file << size << std::endl;
    for (int i = 0; i < size; i++) {
        if (animals[i] != nullptr) {
            animals[i]->saveToFile(file);
        }
    }
    
    file.close();
    std::cout << "Data saved to file: " << filename << std::endl;
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for reading: " + filename);
    }
    
    clear();
    
    int fileSize;
    file >> fileSize;
    file.ignore();
    
    for (int i = 0; i < fileSize; i++) {
        std::string type;
        std::getline(file, type);
        
        Animal* animal = nullptr;
        if (type == "Fish") {
            animal = new Fish();
        } else if (type == "Bird") {
            animal = new Bird();
        } else if (type == "Cat") {
            animal = new Cat();
        } else {
            throw std::runtime_error("Unknown animal type in file: " + type);
        }
        
        animal->loadFromFile(file);
        addAnimal(animal);
    }
    
    file.close();
    std::cout << "Data loaded from file: " << filename << std::endl;
}

int Keeper::getSize() const {
    return size;
}

int Keeper::getCapacity() const {
    return capacity;
}

Animal* Keeper::getAnimal(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return animals[index];
}

Keeper& Keeper::operator=(const Keeper& other) {
    if (this != &other) {
        clear();
        delete[] animals;
        
        capacity = other.capacity;
        size = other.size;
        animals = new Animal*[capacity];
        
        for (int i = 0; i < capacity; i++) {
            animals[i] = nullptr;
        }
        
        for (int i = 0; i < size; i++) {
            if (other.animals[i] != nullptr) {
                std::string type = other.animals[i]->getType();
                if (type == "Fish") {
                    animals[i] = new Fish(*(Fish*)other.animals[i]);
                } else if (type == "Bird") {
                    animals[i] = new Bird(*(Bird*)other.animals[i]);
                } else if (type == "Cat") {
                    animals[i] = new Cat(*(Cat*)other.animals[i]);
                }
            }
        }
    }
    return *this;
}

Animal* Keeper::operator[](int index) const {
    return getAnimal(index);
}

std::ostream& operator<<(std::ostream& os, const Keeper& keeper) {
    keeper.displayAll();
    return os;
}

