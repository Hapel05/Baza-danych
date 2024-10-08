#ifndef MASTER_THESIS_H
#define MASTER_THESIS_H

#include "Thesis.h"

class MasterThesis : public Thesis {
private:
    bool researchConducted;
public:
    MasterThesis(const std::string& t, const std::string& sup, bool research);
    void displaySpecific() const override;
};

#endif 
