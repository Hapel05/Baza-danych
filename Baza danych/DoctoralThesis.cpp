#include "DoctoralThesis.h"

DoctoralThesis::DoctoralThesis(const std::string& t, const std::string& sup, bool internship)
    : Thesis(t, sup, "Doktor"), internshipCompleted(internship) {}

void DoctoralThesis::displaySpecific() const {
    std::cout << "Staz zaliczony: " << (internshipCompleted ? "Tak" : "Nie") << std::endl;
}