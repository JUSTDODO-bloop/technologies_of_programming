#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <string>

class Bird : public Animal {
private:
    std::string diet;
    std::string habitat;

public:
    Bird();
    Bird(const std::string& breed, const std::string& color, const std::string& diet, const std::string& habitat);
    Bird(const Bird& other);
    ~Bird();

    void display() const override;
    void setData() override;
    std::string getType() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

    std::string getDiet() const;
    std::string getHabitat() const;
    void setDiet(const std::string& diet);
    void setHabitat(const std::string& habitat);

    Bird& operator=(const Bird& other);
    friend std::ostream& operator<<(std::ostream& os, const Bird& bird);
    friend std::istream& operator>>(std::istream& is, Bird& bird);
};

#endif
