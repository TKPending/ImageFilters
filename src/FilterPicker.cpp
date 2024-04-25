#include <iostream>

enum Filters {
    invalidFilter = 0,
    Grayscale = 1,
};

int chosenFilterCheck(char chosenFilter) {
    switch (chosenFilter) {
        case '1': return Grayscale;
        default:
            return invalidFilter;
    }
}

int pickImageFilter() {
    for (int i = 0; i < 3; i++) {
        char chosenFilter;
        
        std::cout << "Choose a filter:\nGrayscale [1]\n" << std::endl;
        std::cout << "Your answer: ";
        std::cin >> chosenFilter;
        
        int filter = chosenFilterCheck(chosenFilter);
        if (filter == Grayscale) {
            return filter;
        }
        
        std::cout << "\nInvalid answer. Must be a number\n";
    }
    
    return invalidFilter;
}
