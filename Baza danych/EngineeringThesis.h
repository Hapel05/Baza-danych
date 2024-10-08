#ifndef ENGINEERING_THESIS_H
#define ENGINEERING_THESIS_H

#include "Thesis.h"

class EngineeringThesis : public Thesis {
private:
    std::string specialization;
public:
    EngineeringThesis(const std::string& t, const std::string& sup, const std::string& spec);
    void displaySpecific() const override;
};

#endif #pragma once
