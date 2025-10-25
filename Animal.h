#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
protected:
    std::string breed;
    std::string color;
    static int totalAnimals;

public:
    Animal();
    Animal(const std::string& breed, const std::string& color);
    Animal(const Animal& other);
    virtual ~Animal();

    virtual void display() const = 0;
    virtual void setData() = 0;
    virtual std::string getType() const = 0;
    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(std::ifstream& file) = 0;

    std::string getBreed() const;
    std::string getColor() const;
    void setBreed(const std::string& breed);
    void setColor(const std::string& color);

    virtual Animal& operator=(const Animal& other);
    friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
    friend std::istream& operator>>(std::istream& is, Animal& animal);

    static int getTotalAnimals();
};

#endif

