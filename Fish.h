#ifndef FISH_H
#define FISH_H

#include "Animal.h"
#include <string>

class Fish : public Animal {
private:
    std::string nutritionType;

public:
    Fish();
    Fish(const std::string& breed, const std::string& color, const std::string& nutritionType);
    Fish(const Fish& other);
    ~Fish();

    void display() const override;
    void setData() override;
    std::string getType() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

    std::string getNutritionType() const;
    void setNutritionType(const std::string& nutritionType);

    Fish& operator=(const Fish& other);
    friend std::ostream& operator<<(std::ostream& os, const Fish& fish);
    friend std::istream& operator>>(std::istream& is, Fish& fish);
};

#endif

