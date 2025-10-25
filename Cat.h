#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include <string>

class Cat : public Animal {
private:
    std::string ownerName;
    std::string nickname;

public:
    Cat();
    Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname);
    Cat(const Cat& other);
    ~Cat();

    void display() const override;
    void setData() override;
    std::string getType() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

    std::string getOwnerName() const;
    std::string getNickname() const;
    void setOwnerName(const std::string& ownerName);
    void setNickname(const std::string& nickname);

    Cat& operator=(const Cat& other);
    friend std::ostream& operator<<(std::ostream& os, const Cat& cat);
    friend std::istream& operator>>(std::istream& is, Cat& cat);
};

#endif

