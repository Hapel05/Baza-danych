#include "MasterThesis.h"

MasterThesis::MasterThesis(const std::string& t, const std::string& sup, bool research)
    : Thesis(t, sup, "Magister"), researchConducted(research) {}

void MasterThesis::displaySpecific() const {
    std::cout << "Przeprowadzone badania: " << (researchConducted ? "Tak" : "Nie") << std::endl;
}