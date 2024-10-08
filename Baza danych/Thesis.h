#ifndef THESIS_H
#define THESIS_H

#include <string>
#include <iostream>

class Thesis {
protected:
    std::string title;
    std::string supervisor;
    std::string student;
    std::string type;
    std::string status;
    std::string grade;
public:
    Thesis(const std::string& t, const std::string& sup, const std::string& typ);
    virtual ~Thesis() = default;

    virtual void display() const;
    const std::string& getStatus() const;
    const std::string& getTitle() const;
    const std::string& getSupervisor() const;
    const std::string& getStudent() const;
    const std::string& getType() const;
    void assignStudent(const std::string& stud);
    void removeStudent();
    void setGrade(const std::string& grd);
    const std::string& getGrade() const;
    virtual void displaySpecific() const = 0;
};

#endif 