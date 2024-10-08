#include "ThesisManager.h"
#include "EngineeringThesis.h"
#include "MasterThesis.h"
#include "DoctoralThesis.h"
#include <fstream>
#include <iostream>
#include <sstream>



ThesisManager::~ThesisManager() {
    for (Thesis* thesis : theses) {
        delete thesis;
    }
    theses.clear();
}


void ThesisManager::addThesis(Thesis* thesis) {
    theses.push_back(thesis);
}

void ThesisManager::displayTheses() const {
    for (const auto thesis : theses) {
        thesis->display();
        thesis->displaySpecific();
        std::cout << std::endl;
    }
}

void ThesisManager::reserveThesis(const std::string& title, const std::string& student) {
    for (const auto thesis : theses) {
        if (thesis->getTitle() == title && thesis->getStatus() == "Dostepny") {
            thesis->assignStudent(student);
            std::cout << "Temat zarezerwowany pomyslnie." << std::endl;
            return;
        }
    }
    std::cout << "Bledny temat lub zarezerwowany." << std::endl;
}

void ThesisManager::cancelReservation(const std::string& title) {
    for (const auto thesis : theses) {
        if (thesis->getTitle() == title && thesis->getStatus() == "Zarezerwowany") {
            thesis->removeStudent();
            std::cout << "Usuniecie rezerwacji pomyslnie przetworzone." << std::endl;
            return;
        }
    }
    std::cout << "Bledny temat lub niezarezerwowany." << std::endl;
}

void ThesisManager::inputGrades(const std::string& title, const std::string& grade) {
    for (const auto thesis : theses) {
        if (thesis->getTitle() == title && thesis->getStatus() == "Zarezerwowany") {
            thesis->setGrade(grade);
            std::cout << "Oceny zapisane." << std::endl;
            return;
        }
    }
    std::cout << "Bledny temat lub niezarezerwowany." << std::endl;
}

void ThesisManager::generateReport(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Blad w otwieraniu pliku: " << filename << std::endl;
        return;
    }

    for (const auto thesis : theses) {
        file << thesis->getType() << ";" << thesis->getTitle() << ";" << thesis->getSupervisor() << ";" << thesis->
            getStatus() << ";" << thesis->getGrade() << "\n";
    }
}

const std::vector<Thesis*>& ThesisManager::getTheses() const {
    return theses;
}

void loadThesesFromFile(ThesisManager& manager, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Blad w otwieraniu pliku: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type, title, supervisor, rest;
        std::getline(iss, type, ';');
        std::getline(iss, title, ';');
        std::getline(iss, supervisor, ';');
        std::getline(iss, rest);

        if (type == "Engineering") {
            std::string specialization = rest;
            manager.addThesis(new EngineeringThesis(title, supervisor, specialization));
        }
        else if (type == "Master") {
            bool researchConducted = (rest == "1");
            manager.addThesis(new MasterThesis(title, supervisor, researchConducted));
        }
        else if (type == "Doctoral") {
            bool internshipCompleted = (rest == "1");
            manager.addThesis(new DoctoralThesis(title, supervisor, internshipCompleted));
        }
    }
}

void saveThesesToFile(const ThesisManager& manager, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Blad w otwieraniu pliku: " << filename << std::endl;
        return;
    }

    for (const auto& thesis : manager.getTheses()) {
        file << thesis->getType() << ";" << thesis->getTitle() << ";" << thesis->getSupervisor() << "\n";
    }
}