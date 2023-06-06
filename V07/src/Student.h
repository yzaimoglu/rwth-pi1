//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
   
    bool operator == (const Student& student) const;
	bool operator < (const Student& student) const;
	bool operator > (const Student& student) const;

    void ausgabe(std::ostream& ausgabe) const;

    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    // void ausgabe() const;
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

std::ostream& operator << (std::ostream& ausgabe, const Student& student);

#endif
