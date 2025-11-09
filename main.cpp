#include <iostream>
#include <string>
#include <stdexcept>
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

void displayMenu() {
    std::cout << "\n=== ANIMAL KEEPER MENU ===" << std::endl;
    std::cout << "1. Add Fish" << std::endl;
    std::cout << "2. Add Bird" << std::endl;
    std::cout << "3. Add Cat" << std::endl;
    std::cout << "4. Display All Animals" << std::endl;
    std::cout << "5. Display Fish" << std::endl;
    std::cout << "6. Display Birds" << std::endl;
    std::cout << "7. Display Cats" << std::endl;
    std::cout << "8. Modify Animal" << std::endl;
    std::cout << "9. Remove Animal" << std::endl;
    std::cout << "10. Save to File" << std::endl;
    std::cout << "11. Load from File" << std::endl;
    std::cout << "12. Show Statistics" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "Enter your choice: ";
}

void addFish(Keeper& keeper) {
    try {
        Fish* fish = new Fish();
        std::cin >> *fish;
        keeper.addAnimal(fish);
        std::cout << "Fish added successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error adding fish: " << e.what() << std::endl;
    }
}

void addBird(Keeper& keeper) {
    try {
        Bird* bird = new Bird();
        std::cin >> *bird;
        keeper.addAnimal(bird);
        std::cout << "Bird added successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error adding bird: " << e.what() << std::endl;
    }
}

void addCat(Keeper& keeper) {
    try {
        Cat* cat = new Cat();
        std::cin >> *cat;
        keeper.addAnimal(cat);
        std::cout << "Cat added successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error adding cat: " << e.what() << std::endl;
    }
}

void modifyAnimal(Keeper& keeper) {
    try {
        if (keeper.getSize() == 0) {
            std::cout << "No animals to modify." << std::endl;
            return;
        }
        
        std::cout << "Enter index of animal to modify (0-" << (keeper.getSize() - 1) << "): ";
        int index;
        std::cin >> index;
        
        keeper.modifyAnimal(index);
        std::cout << "Animal modified successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error modifying animal: " << e.what() << std::endl;
    }
}

void removeAnimal(Keeper& keeper) {
    try {
        if (keeper.getSize() == 0) {
            std::cout << "No animals to remove." << std::endl;
            return;
        }
        
        std::cout << "Enter index of animal to remove (0-" << (keeper.getSize() - 1) << "): ";
        int index;
        std::cin >> index;
        
        keeper.removeAnimal(index);
        std::cout << "Animal removed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error removing animal: " << e.what() << std::endl;
    }
}

void saveToFile(Keeper& keeper) {
    try {
        std::string filename;
        std::cout << "Enter filename to save: ";
        std::cin.ignore();
        std::getline(std::cin, filename);
        
        keeper.saveToFile(filename);
        std::cout << "Data saved successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error saving to file: " << e.what() << std::endl;
    }
}

void loadFromFile(Keeper& keeper) {
    try {
        std::string filename;
        std::cout << "Enter filename to load: ";
        std::cin.ignore();
        std::getline(std::cin, filename);
        
        keeper.loadFromFile(filename);
        std::cout << "Data loaded successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error loading from file: " << e.what() << std::endl;
    }
}

void showStatistics(Keeper& keeper) {
    std::cout << "\n=== STATISTICS ===" << std::endl;
    std::cout << "Total animals in keeper: " << keeper.getSize() << std::endl;
    std::cout << "Keeper capacity: " << keeper.getCapacity() << std::endl;
    std::cout << "Total animals created: " << Animal::getTotalAnimals() << std::endl;
    std::cout << "==================" << std::endl;
}

int main() {
    Keeper keeper;
    int choice;
    
    std::cout << "Welcome to Animal Keeper System!" << std::endl;
    
    while (true) {
        displayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addFish(keeper);
                break;
            case 2:
                addBird(keeper);
                break;
            case 3:
                addCat(keeper);
                break;
            case 4:
                keeper.displayAll();
                break;
            case 5:
                keeper.displayByType("Fish");
                break;
            case 6:
                keeper.displayByType("Bird");
                break;
            case 7:
                keeper.displayByType("Cat");
                break;
            case 8:
                modifyAnimal(keeper);
                break;
            case 9:
                removeAnimal(keeper);
                break;
            case 10:
                saveToFile(keeper);
                break;
            case 11:
                loadFromFile(keeper);
                break;
            case 12:
                showStatistics(keeper);
                break;
            case 0:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
    
    return 0;
}


