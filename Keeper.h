#ifndef KEEPER_H
#define KEEPER_H

#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

class Keeper {
private:
    Animal** animals;
    int capacity;
    int size;

    void resize();
    void clear();

public:
    Keeper();
    Keeper(int initialCapacity);
    Keeper(const Keeper& other);
    ~Keeper();

    void addAnimal(Animal* animal);
    void removeAnimal(int index);
    void displayAll() const;
    void displayByType(const std::string& type) const;
    void modifyAnimal(int index);
    
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    
    int getSize() const;
    int getCapacity() const;
    Animal* getAnimal(int index) const;
    
    Keeper& operator=(const Keeper& other);
    Animal* operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& os, const Keeper& keeper);
};

#endif

