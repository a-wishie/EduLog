// #include<iostream>
// #include<fstream>
// #include<iomanip>
// #include<vector>
// #include<string>

// using namespace std;

// // Subject structure to store subject name and marks
// struct Subject {
//     string name;
//     int marks;
// };

// // the class that stores student data
// class Student {
//     int rollno;
//     char name[50];
//     vector<vector<Subject>> semesters; // Each vector represents a semester

// public:
//     void getData();
//     void showData() const;
//     void calculate(int semesterIndex);
//     int retRollNo() const;
//     double getAverage(int semesterIndex) const;
//     char getGrade(double average) const;
//     void addSemesterSubjects(int semesterIndex);
// };

// // Function to calculate average marks and grade for a specific semester
// void Student::calculate(int semesterIndex) {
//     if (semesterIndex >= semesters.size()) {
//         cout << "Invalid semester index." << endl;
//         return;
//     }
//     double total = 0;
//     for (const Subject& subject : semesters[semesterIndex]) {
//         total += subject.marks;
//     }
//     double average = total / semesters[semesterIndex].size();
//     char grade = getGrade(average);

//     cout << "\nAverage Marks: " << average;
//     cout << "\nGrade: " << grade << endl;
// }

// void Student::getData() {
//     cout << "Enter student's roll number: ";
//     cin >> rollno;

//     cout << "Enter student's name: ";
//     cin.ignore();
//     cin.getline(name, 50);

//     int numSemesters;
//     cout << "Enter number of semesters: ";
//     cin >> numSemesters;
//     semesters.resize(numSemesters);

//     for (int i = 0; i < numSemesters; ++i) {
//         addSemesterSubjects(i);
//     }
// }

// void Student::showData() const {
//     cout << "\nRoll number of student: " << rollno;
//     cout << "\nName of student: " << name;

//     for (int i = 0; i < semesters.size(); ++i) {
//         cout << "\n\nSemester " << i + 1 << ":";
//         for (const Subject& subject : semesters[i]) {
//             cout << "\n" << subject.name << ": " << subject.marks;
//         }
//         double average = getAverage(i);
//         char grade = getGrade(average);
//         cout << "\nAverage Marks: " << average;
//         cout << "\nGrade: " << grade;
//     }
// }

// double Student::getAverage(int semesterIndex) const {
//     if (semesterIndex >= semesters.size()) {
//         return 0.0;
//     }
//     double total = 0;
//     for (const Subject& subject : semesters[semesterIndex]) {
//         total += subject.marks;
//     }
//     return total / semesters[semesterIndex].size();
// }

// char Student::getGrade(double average) const {
//     if (average >= 90)
//         return 'A';
//     else if (average >= 75)
//         return 'B';
//     else if (average >= 50)
//         return 'C';
//     else
//         return 'F';
// }

// int Student::retRollNo() const {
//     return rollno;
// }

// void Student::addSemesterSubjects(int semesterIndex) {
//     int numSubjects;
//     cout << "\nEnter number of subjects for semester " << semesterIndex + 1 << ": ";
//     cin >> numSubjects;
//     semesters[semesterIndex].resize(numSubjects);

//     for (int i = 0; i < numSubjects; ++i) {
//         cout << "Enter name of subject " << i + 1 << ": ";
//         cin.ignore();
//         getline(cin, semesters[semesterIndex][i].name);
//         cout << "Enter marks for " << semesters[semesterIndex][i].name << ": ";
//         cin >> semesters[semesterIndex][i].marks;
//     }
// }

// // Function declarations
// void createStudent();
// void displaySpecific(int);//display particular record
// void displayAll(); // display all records
// void deleteStudent(int);//delete particular record
// void changeStudent(int);//edit particular record

// // Main Function
// int main() {
//     char ch;
//     cout << setprecision(2);

//     do {
//         int num;
//         system("cls");
//         cout << "Welcome to Student Registration Management System" << endl;
//         cout << "\nMENU" << endl;
//         cout << "1. Create a new student record" << endl;
//         cout << "2. Search student record" << endl;
//         cout << "3. Display all students records" << endl;
//         cout << "4. Delete student record" << endl;
//         cout << "5. Modify student record" << endl;
//         cout << "6. Exit" << endl;
//         cout << "\nEnter your choice: ";
//         cin >> ch;

//         system("cls");

//         switch (ch) {
//             case '1': createStudent(); break;
//             case '2': cout << "\n\n\tEnter The roll number: "; 
//                       cin >> num;
//                       displaySpecific(num); break;
//             case '3': displayAll(); break;
//             case '4': cout << "\n\n\tEnter The roll number: ";
//                       cin >> num;
//                       deleteStudent(num); break;
//             case '5': cout << "\n\n\tEnter The roll number: "; 
//                       cin >> num;
//                       changeStudent(num); break;
//             case '6': cout << "Exiting, Thank you!"; exit(0);
//         }

//     } while (ch != '6');
//     return 0;
// }

// // Write Student Details to File
// void createStudent() {
//     Student stud;
//     ofstream oFile;
//     oFile.open("student.dat", ios::binary | ios::app);
//     stud.getData();
//     oFile.write(reinterpret_cast<char*>(&stud), sizeof(Student));
//     oFile.close();
//     cout << "\nStudent's record has been created ";
//     cin.ignore();
//     cin.get();
// }

// // Read File Records
// void display_all() {
//     student stud;
//     ifstream inFile;
//     inFile.open("student.dat", ios::binary);
//     if (!inFile) {
//         cout << "File could not be opened !! Press any Key to exit";
//         cin.ignore();
//         cin.get();
//         return;
//     }

//     cout << "\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
//     bool hasRecords = false;
//     while (inFile.read(reinterpret_cast<char*>(&stud), sizeof(student))) {
//         if (strlen(stud.name) > 0) {  // Check if the name is not empty
//             stud.showdata();
//             cout << "\n\n====================================\n";
//             hasRecords = true;
//         }
//     }

//     if (!hasRecords) {
//         cout << "\nNo records found.";
//     }

//     inFile.close();
//     cin.ignore();
//     cin.get();
// }

// // Read Specific Record Based on Roll Number
// void displaySpecific(int n) {
//     Student stud;
//     ifstream iFile;
//     iFile.open("student.dat", ios::binary);
//     if (!iFile) {
//         cout << "File could not be opened... Press any Key to exit";
//         cin.ignore();
//         cin.get();
//         return;
//     }

//     bool flag = false;
//     while (iFile.read(reinterpret_cast<char*>(&stud), sizeof(Student))) {
//         if (stud.retRollNo() == n) {
//             stud.showData();
//             flag = true;
//         }
//     }

//     iFile.close();
//     if (!flag)
//         cout << "\n\nRecord does not exist";
//     cin.ignore();
//     cin.get();
// }

// // Modify Record for Specified Roll Number
// void changeStudent(int n) {
//     bool found = false;
//     Student stud;
//     fstream fl;
//     fl.open("student.dat", ios::binary | ios::in | ios::out);
//     if (!fl) {
//         cout << "File could not be opened. Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return;
//     }

//     while (!fl.eof() && !found) {
//         fl.read(reinterpret_cast<char*>(&stud), sizeof(Student));
//         if (stud.retRollNo() == n) {
//             stud.showData();
//             cout << "\nEnter new student details:" << endl;
//             stud.getData();
//             int pos = (-1) * static_cast<int>(sizeof(stud));
//             fl.seekp(pos, ios::cur);
//             fl.write(reinterpret_cast<char*>(&stud), sizeof(Student));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }

//     fl.close();
//     if (!found)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }

// // Delete Record with Particular Roll Number
// void deleteStudent(int n) {
//     Student stud;
//     ifstream iFile;
//     iFile.open("student.dat", ios::binary);
//     if (!iFile) {
//         cout << "File could not be opened... Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     ofstream oFile;
//     oFile.open("Temp.dat", ios::out);
//     iFile.seekg(0, ios::beg);
//     while (iFile.read(reinterpret_cast<char*>(&stud), sizeof(Student))) {
//         if (stud.retRollNo() != n) {
//             oFile.write(reinterpret_cast<char*>(&stud), sizeof(Student));
//         }
//     }
//     oFile.close();
//     iFile.close();
//     remove("student.dat");
//     rename("Temp.dat", "student.dat");
//     cout << "\n\n\tRecord Deleted ..";
//     cin.ignore();
//     cin.get();
// }

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Subject structure to store subject name and marks
struct Subject {
    string name;
    int marks;
};

// the class that stores student data
class Student {
    int rollno;
    char name[50];
    vector<vector<Subject>> semesters; // Each vector represents a semester

public:
    void getData();
    void showData() const;
    void calculate(int semesterIndex);
    int retRollNo() const;
    double getAverage(int semesterIndex) const;
    char getGrade(double average) const;
    void addSemesterSubjects(int semesterIndex);

    // Serialization and Deserialization
    void serialize(ofstream& ofs) const;
    void deserialize(ifstream& ifs);
};

// Function to calculate average marks and grade for a specific semester
void Student::calculate(int semesterIndex) {
    if (semesterIndex >= semesters.size()) {
        cout << "Invalid semester index." << endl;
        return;
    }
    double total = 0;
    for (const Subject& subject : semesters[semesterIndex]) {
        total += subject.marks;
    }
    double average = total / semesters[semesterIndex].size();
    char grade = getGrade(average);

    cout << "\nAverage Marks: " << average;
    cout << "\nGrade: " << grade << endl;
}

void Student::getData() {
    cout << "Enter student's roll number: ";
    cin >> rollno;
    cin.ignore();  // Clear newline from the buffer

    cout << "Enter student's name: ";
    cin.getline(name, 50);

    int numSemesters;
    cout << "Enter number of semesters: ";
    cin >> numSemesters;
    semesters.resize(numSemesters);

    for (int i = 0; i < numSemesters; ++i) {
        addSemesterSubjects(i);
    }
}

void Student::showData() const {
    cout << "\nRoll number of student: " << rollno;
    cout << "\nName of student: " << name;

    for (int i = 0; i < semesters.size(); ++i) {
        cout << "\n\nSemester " << i + 1 << ":";
        for (const Subject& subject : semesters[i]) {
            cout << "\n" << subject.name << ": " << subject.marks;
        }
        double average = getAverage(i);
        char grade = getGrade(average);
        cout << "\nAverage Marks: " << average;
        cout << "\nGrade: " << grade;
    }
}

double Student::getAverage(int semesterIndex) const {
    if (semesterIndex >= semesters.size()) {
        return 0.0;
    }
    double total = 0;
    for (const Subject& subject : semesters[semesterIndex]) {
        total += subject.marks;
    }
    return total / semesters[semesterIndex].size();
}

char Student::getGrade(double average) const {
    if (average >= 90)
        return 'A';
    else if (average >= 75)
        return 'B';
    else if (average >= 50)
        return 'C';
    else
        return 'F';
}

int Student::retRollNo() const {
    return rollno;
}

void Student::addSemesterSubjects(int semesterIndex) {
    int numSubjects;
    cout << "\nEnter number of subjects for semester " << semesterIndex + 1 << ": ";
    cin >> numSubjects;
    cin.ignore();  // Clear newline from the buffer
    semesters[semesterIndex].resize(numSubjects);

    for (int i = 0; i < numSubjects; ++i) {
        cout << "Enter name of subject " << i + 1 << ": ";
        getline(cin, semesters[semesterIndex][i].name);
        cout << "Enter marks for " << semesters[semesterIndex][i].name << ": ";
        cin >> semesters[semesterIndex][i].marks;
        cin.ignore();  // Clear newline from the buffer
    }
}

void Student::serialize(ofstream& ofs) const {
    ofs.write(reinterpret_cast<const char*>(&rollno), sizeof(rollno));
    ofs.write(name, sizeof(name));
    size_t numSemesters = semesters.size();
    ofs.write(reinterpret_cast<const char*>(&numSemesters), sizeof(numSemesters));
    for (const auto& semester : semesters) {
        size_t numSubjects = semester.size();
        ofs.write(reinterpret_cast<const char*>(&numSubjects), sizeof(numSubjects));
        for (const auto& subject : semester) {
            size_t nameSize = subject.name.size();
            ofs.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
            ofs.write(subject.name.c_str(), nameSize);
            ofs.write(reinterpret_cast<const char*>(&subject.marks), sizeof(subject.marks));
        }
    }
}

void Student::deserialize(ifstream& ifs) {
    ifs.read(reinterpret_cast<char*>(&rollno), sizeof(rollno));
    ifs.read(name, sizeof(name));
    size_t numSemesters;
    ifs.read(reinterpret_cast<char*>(&numSemesters), sizeof(numSemesters));
    semesters.resize(numSemesters);
    for (auto& semester : semesters) {
        size_t numSubjects;
        ifs.read(reinterpret_cast<char*>(&numSubjects), sizeof(numSubjects));
        semester.resize(numSubjects);
        for (auto& subject : semester) {
            size_t nameSize;
            ifs.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
            subject.name.resize(nameSize);
            ifs.read(&subject.name[0], nameSize);
            ifs.read(reinterpret_cast<char*>(&subject.marks), sizeof(subject.marks));
        }
    }
}

// Function declarations
void createStudent();
void displaySpecific(int);  // display particular record
void displayAll();  // display all records
void deleteStudent(int);  // delete particular record
void changeStudent(int);  // edit particular record

// Main Function
int main() {
    char ch;
    cout << setprecision(2);

    do {
        int num;
        system("cls");
        cout << "Welcome to Student Registration Management System" << endl;
        cout << "\nMENU" << endl;
        cout << "1. Create a new student record" << endl;
        cout << "2. Search student record" << endl;
        cout << "3. Display all students records" << endl;
        cout << "4. Delete student record" << endl;
        cout << "5. Modify student record" << endl;
        cout << "6. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;

        system("cls");

        switch (ch) {
            case '1': createStudent(); break;
            case '2': cout << "\n\n\tEnter The roll number: ";
                      cin >> num;
                      displaySpecific(num); break;
            case '3': displayAll(); break;
            case '4': cout << "\n\n\tEnter The roll number: ";
                      cin >> num;
                      deleteStudent(num); break;
            case '5': cout << "\n\n\tEnter The roll number: ";
                      cin >> num;
                      changeStudent(num); break;
            case '6': cout << "Exiting, Thank you!"; exit(0);
        }

    } while (ch != '6');
    return 0;
}

// Write Student Details to File
void createStudent() {
    Student stud;
    ofstream oFile("student.dat", ios::binary | ios::app);
    if (!oFile) {
        cout << "File could not be opened. Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    stud.getData();
    stud.serialize(oFile);
    oFile.close();
    cout << "\nStudent's record has been created ";
    cin.ignore();
    cin.get();
}

// Read All Records
void displayAll() {
    ifstream inFile("student.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
    Student stud;
    while (inFile.peek() != EOF) {
        stud.deserialize(inFile);
        stud.showData();
        cout << "\n\n====================================\n";
    }

    inFile.close();
    cin.ignore();
    cin.get();
}

// Read Specific Record Based on Roll Number
void displaySpecific(int n) {
    ifstream inFile("student.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened... Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }

    Student stud;
    bool found = false;
    while (inFile.peek() != EOF) {
        stud.deserialize(inFile);
        if (stud.retRollNo() == n) {
            stud.showData();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n\nRecord does not exist";
    }

    inFile.close();
    cin.ignore();
    cin.get();
}