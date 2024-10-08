#include "ThesisManager.h"
#include <iostream>

void showMenu() {
    std::cout << "1. Wyswietl wszystkie prace\n"
        << "2. Zarezerwuj prace\n"
        << "3. Usun rezerwacje\n"
        << "4. Wpisz oceny\n"
        << "5. Zrob raport\n"
        << "6. Exit\n";
}

int main() {
    ThesisManager manager;
    loadThesesFromFile(manager, "theses.txt");

    int choice;
    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            manager.displayTheses();
            break;
        case 2: {
            std::string title, student;
            std::cout << "Wprowadz tytul: ";
            std::getline(std::cin, title);
            std::cout << "Wprowadz imie: ";
            std::getline(std::cin, student);
            manager.reserveThesis(title, student);
            break;
        }
        case 3: {
            std::string title;
            std::cout << "Wprowadz tytul: ";
            std::getline(std::cin, title);
            manager.cancelReservation(title);
            break;
        }
        case 4: {
            std::string title, grade;
            std::cout << "Wprowadz tytul: ";
            std::getline(std::cin, title);
            std::cout << "Wprowadz ocene: ";
            std::getline(std::cin, grade);
            manager.inputGrades(title, grade);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Otworz plik z raportem: ";
            std::getline(std::cin, filename);
            manager.generateReport(filename);
            break;
        }
        case 6:
            saveThesesToFile(manager, "theses.txt");
            break;
        default:
            std::cout << "Zly wybor." << std::endl;
        }
    } while (choice != 6);

    return 0;
}