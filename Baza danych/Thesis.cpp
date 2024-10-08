#include "Thesis.h"

Thesis::Thesis(const std::string& t, const std::string& sup, const std::string& typ)
    : title(t), supervisor(sup), type(typ), status("Dostepny") {}

void Thesis::display() const {
    std::cout << type << ": " << title << ", Prowadzacy: " << supervisor << ", Status: " << status << ", Ocena: " << grade << std::endl;
}

const std::string& Thesis::getStatus() const { return status; }
const std::string& Thesis::getTitle() const { return title; }
const std::string& Thesis::getSupervisor() const { return supervisor; }
const std::string& Thesis::getStudent() const { return student; }

const std::string& Thesis::getType() const { return type; }

void Thesis::assignStudent(const std::string& stud) {
    student = stud;
    status = "Zarezerwowany";
}

void Thesis::removeStudent() {
    student = "";
    status = "Dostepny";
}

void Thesis::setGrade(const std::string& grd) {
    grade = grd;
}

const std::string& Thesis::getGrade() const {
    return grade;
}