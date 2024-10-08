#ifndef DOCTORAL_THESIS_H
#define DOCTORAL_THESIS_H

#include "Thesis.h"

class DoctoralThesis : public Thesis {
private:
    bool internshipCompleted;
public:
    DoctoralThesis(const std::string& t, const std::string& sup, bool internship);
    void displaySpecific() const override;
};

#endif 