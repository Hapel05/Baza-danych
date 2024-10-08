#ifndef THESIS_MANAGER_H
#define THESIS_MANAGER_H

#include "Thesis.h"
#include <vector>
#include <memory>
#include <string>

class ThesisManager {
private:
    std::vector<Thesis*> theses;

public:
    void addThesis(Thesis* thesis);

    void displayTheses() const;

    void reserveThesis(const std::string& title, const std::string& student);

    void cancelReservation(const std::string& title);

    void inputGrades(const std::string& title, const std::string& grade);

    void generateReport(const std::string& filename) const;

    const std::vector<Thesis*>& getTheses() const;

    ~ThesisManager();
};

void loadThesesFromFile(ThesisManager& manager, const std::string& filename);

void saveThesesToFile(const ThesisManager& manager, const std::string& filename);

#endif 