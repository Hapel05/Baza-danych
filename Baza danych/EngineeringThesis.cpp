#include "EngineeringThesis.h"

EngineeringThesis::EngineeringThesis(const std::string& t, const std::string& sup, const std::string& spec)
    : Thesis(t, sup, "Inzynier"), specialization(spec) {}

void EngineeringThesis::displaySpecific() const {
    std::cout << "Specjalizacja: " << specialization << std::endl;
}