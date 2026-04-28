
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;


struct Student {
    int id;                
    char lastName[21];      
    char firstName[21];    
    bool courses[5];       
};



static void initBinaryFile() {
    ofstream f1;
    f1.open("students.bin", ios::out |  ios::binary);
    if (f1.is_open()) {
        for (int j = 0;j < 100; j++) {
            Student s;
            s.id = 0;
            memset(s.lastName, 0, sizeof(s.lastName));
            memset(s.firstName, 0, sizeof(s.firstName));
            for (int i = 0; i < 5; i++) {
                s.courses[i] = false;
            }
            f1.write((char*)&s, sizeof(Student));
        }
    }
    f1.close();
   
} 
 static void addStudent(fstream& f) {
     Student s;
     cout << "enter detailes of student:";
     cout << "id: ";
     cin >> s.id;
     cin.ignore();
     cout << "firstName: ";
     cin.get(s.firstName, 21);
     cin.ignore();
     cout << "lastName: ";
     cin.get(s.lastName, 21); 
     cin.ignore();
     cout << "Enter 5 course statuses (Y/N): ";
     char cInput[6];
     cin >> cInput;
     for (int i = 0; i < 5; i++)
         s.courses[i] = (cInput[i] == 'Y' || cInput[i] == 'y');
     
     Student s1;
     f.clear();
     f.seekg(0, ios::beg);

     while (f.read((char*)&s1, sizeof(Student))) {
         if (s1.id == s.id && s1.id != 0) {
             cout << "Error: Student ID already exists!";
             break;
         }
         if (s1.id == 0) {
             f.seekp(-(long)sizeof(Student), ios::cur);
             f.write((char*)&s, sizeof(Student));
             cout << "Student added succesfully";
             break;
         }
     }
 }
 static void deleteStudent(fstream& f, int id) {
     f.clear();
     f.seekg(0, ios::beg);
     Student s;
     bool found = false;
     while (f.read((char*)&s, sizeof(Student))) {
         if (s.id == id) {
             f.seekp(-(long)sizeof(Student), ios::cur);
             f.write((char*)"\0\0\0\0", sizeof(int));
             cout << "Student deleted successfully!";
             found = true;
             break;
         }
     }
     if (!found) {
         cout << "This student does not exists!";
     }
 }
 static void updateStudent(fstream& f, int id) {
     f.clear();
     f.seekg(0);
     Student s;
     bool found = false;
     bool courses[5];
     while (f.read((char*)&s, sizeof(Student)))
     {
         if (s.id == id)
         {
             cout << "Enter 5 course statuses (Y/N): ";
             char cInput[6];
             cin >> cInput;
             for (int i = 0; i < 5; i++)
                 courses[i] = (cInput[i] == 'Y' || cInput[i] == 'y');
             f.seekp(-(long)(sizeof(bool) * 5), ios::cur);
             f.write((char*)&courses, sizeof(bool) * 5);
             found = true;
             cout << "Registration updated successfully!";
             break;
         }
        
     }
     if (!found) {
             cout << "Error: Student with ID " << id << " not found." << endl;
     }
 }
 static bool checkIfRegister(fstream& f, int id, int numCourse) {
     if (numCourse > 5 || numCourse < 1) {
         cout << "number of course not valid!";
         return false;
     }
     f.clear();
     f.seekg(0);
     Student s;
     bool found = false;
     while (f.read((char*)&s, sizeof(Student)))
     {
         if (s.id == id)
         {
             return s.courses[numCourse - 1];
             
         }
     }
     return false;
 }
 static void printStudent(fstream& f, int id) {
     f.clear();
     f.seekg(0);
     Student s;
     bool found = false;
     while (f.read((char*)&s, sizeof(Student)))
     {
         if (s.id == id)
         {
             found = true;
             char temp[5];
             for (int i = 0; i < 5; i++)
             {
                 temp[i] = (s.courses[i] == true) ? 'Y' : 'N';
             }

             cout << "detailes of student: \n name: " << s.firstName << " " <<
                 s.lastName << "\n coureses: \n 1. " << temp[0] << "\n 2. " <<
                 temp[1] << "\n 3. " << temp[2] << "\n 4. " << temp[3]
                 << "\n 5. " << temp[4] << endl;
             break;
         }

     }
     if (!found) {
         cout << "Student not exists!";
     }
 }
 static void printStudentsForCourse(fstream& f, int numCourse) {
     if (numCourse > 5 || numCourse < 1) {
         cout << "number of course not valid!";
         return ;
     }
     f.clear();      
     f.seekg(0);
     Student s;
     bool found = false;
     cout << "Students registered for course " << numCourse << ":" << endl;
     while (f.read((char*)&s, sizeof(Student)))
     {
         if (s.courses[numCourse-1] == true)
         {
             found = true;
             cout << s.firstName << " " << s.lastName << "\n";
         }
     }
     if (!found) {
         cout << "No students are registered for this course." << endl;
     }

 }
 int main()
 {
     initBinaryFile();

     fstream file("students.bin", ios::in | ios::out | ios::binary);
     if (!file) {
         cout << "ERROR: Could not open file!" << endl;
         return 1;
     }

     int choice = -1;
     int tempId, tempCourse;

     while (choice != 0) {
         cout << "\n--- Student Management System ---" << endl;
         cout << "1. Add Student" << endl;
         cout << "2. Delete Student" << endl;
         cout << "3. Update Registration (Courses)" << endl;
         cout << "4. Check if Registered to Course" << endl;
         cout << "5. Print Student Details" << endl;
         cout << "6. Print Students by Course" << endl;
         cout << "0. Exit" << endl;
         cout << "Enter choice: ";

         if (!(cin >> choice)) {
             cout << "ERROR" << endl;
             cin.clear();
             cin.ignore(1000, '\n');
             continue;
         }

         switch (choice) {
         case 1:
             addStudent(file);
             break;
         case 2:
             cout << "Enter ID to delete: ";
             cin >> tempId;
             deleteStudent(file, tempId);
             break;
         case 3:
             cout << "Enter ID to update: ";
             cin >> tempId;
             updateStudent(file, tempId);
             break;
         case 4:
             cout << "Enter ID: "; cin >> tempId;
             cout << "Enter Course (1-5): "; cin >> tempCourse;
             if (checkIfRegister(file, tempId, tempCourse)) cout << "True" << endl;
             else cout << "False" << endl;
             break;
         case 5:
             cout << "Enter ID to print: ";
             cin >> tempId;
             printStudent(file, tempId);
             break;
         case 6:
             cout << "Enter Course (1-5): ";
             cin >> tempCourse;
             printStudentsForCourse(file, tempCourse);
             break;
         case 0:
             cout << "Goodbye!" << endl;
             break;
         default:
             cout << "ERROR" << endl;
             break;
         }
     }

     file.close();
     return 0;
 }
 
