/**************************************************
 *                                                *
 *             Algoritmos de Pesquisa             *
 *               Pesquisa Sequencial              *
 *                                                *
 **************************************************
 *                                                *
 *  Autor: Juliano Moreira Aleixo                 *
 *  Disciplina: C03                               *
 *  Professor: Jonas Lopes de Vilas Boas          *
 *  Data: 09/03/2024                              *
 *                                                *
 **************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string course;
    int registrationNumber = 0;
};

int searchStudentByName(Student *list, int qtd, string name) {
    for(int i = 0; i < qtd; i++) {
        if (list[i].name == name) {
            return i;
        }
    }
    return -1;
}

int main() {
    int qtd;
    string nameToSearch;
    int indexOfFoundStudent;

    cout << "Enter the quantity of students: " << endl;
    cin >> qtd;

    Student studentsList[qtd];

    for (int i = 0; i < qtd; i++) {
        cout << "Student #" << i + 1 << endl;
        cout << "Name:" << endl;
        cin.ignore();
        getline(cin, studentsList[i].name);
        cout << "Course:" << endl;
        getline(cin, studentsList[i].course);
        cout << "Registration number: " << endl;
        cin >> studentsList[i].registrationNumber;
    }
    cout << endl;
    cout << "Enter the name of student to search: " << endl;
    cin.ignore();
    getline(cin, nameToSearch);
    cout << endl;

    indexOfFoundStudent = searchStudentByName(studentsList, qtd, nameToSearch);

    if(indexOfFoundStudent != -1) {
        cout << "Students data: " << endl;
        cout << studentsList[indexOfFoundStudent].name << endl;
        cout << studentsList[indexOfFoundStudent].course << endl;
        cout << studentsList[indexOfFoundStudent].registrationNumber << endl;
    } else {
        cout << "Student not found." << endl;
    }


    return 0;
}