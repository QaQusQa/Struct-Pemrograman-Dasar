#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*data Dummy = { Data student dummy, sebagai contoh saja
    {"Fyodor", "Dostoevsky"},
    {"Leo", "Tolstoy"},
    {"Anton", "Chekhov"},
    {"Alexander", "Pushkin"},
    {"Mikhail", "Bulgakov"},
    {"William", "Shakespeare"},
    {"Charles", "Dickens"},
    {"Jane", "Austen"},
    {"George", "Orwell"},
    {"Virginia", "Woolf"},
    {"Victor", "Hugo"},
    {"Alexandre", "Dumas"},
    {"Johann", "Goethe"},
    {"Franz", "Kafka"},
    {"Gabriel", "Marquez"},
    {"Haruki", "Murakami"},
    {"Ahmad", "Tohari"},
    {"Eka", "Kurniawan"},
    {"Leila", "Chudori"},
    {"Pramoedya", "Toer"}
    {"Chairil", "Anwar"},
    {"Osamu", "Dazai"},
    {"Soji", "Shimada"}
    };
*/

const int TOTAL_STUDENT = 20;

struct studentType // deklarasi struct untuk student
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

struct studentList
{
    studentType listOfStudent[TOTAL_STUDENT]; // array untuk menyimpan data
    int listLength;                           // untuk loop saat pengambilan data
};

void readStudentData(studentList &theList);                 // Baca inputan data dari user
void assignGrade(studentList &theList);                     // Beri kategori tergantung nilai
int findHighestScore(const studentList &theList);           // Cari nilai tertinggi
void whoIsHighest(const studentList &theList, int highest); // Siapa yang punya nilai tertinggi
void displayAllStudent(const studentList &theList);         // Tampilkan semua murid

int main()
{
    studentList theList;
    theList.listLength = 0;

    readStudentData(theList);
    assignGrade(theList);
    displayAllStudent(theList);

    int highest = findHighestScore(theList);
    cout << "The highest score: " << highest << endl;
    cout << "Student with the highest score: \n";
    whoIsHighest(theList, highest);
    cout << "-----------------------------------\n";
    return 0;
}

void readStudentData(studentList &theList)
{
    for (int i = 0; i < TOTAL_STUDENT; ++i)
    {
        cout << "\nEnter student data: " << (i + 1) << endl;
        cout << "Enter student first name: ";
        cin >> theList.listOfStudent[i].studentFName;

        cout << "Enter student last name: ";
        cin >> theList.listOfStudent[i].studentLName;

        cout << "Enter student test score(0-100): ";
        cin >> theList.listOfStudent[i].testScore;

        theList.listLength++;
    }
};

void assignGrade(studentList &theList)
{
    for (int i = 0; i < theList.listLength; ++i)
    {
        char studentGrade;
        int score = theList.listOfStudent[i].testScore;
        if (score >= 79)
        {
            studentGrade = 'A';
        }
        else if (score >= 69)
        {
            studentGrade = 'B';
        }
        else if (score >= 60)
        {
            studentGrade = 'C';
        }
        else if (score >= 50)
        {
            studentGrade = 'D';
        }
        else
        {
            studentGrade = 'E';
        }
        theList.listOfStudent[i].grade = studentGrade;
    }
}

void displayAllStudent(const studentList &theList)
{
    cout << "-----------------------------------";
    cout << "\nAll Student\n\n";
    for (int i = 0; i < theList.listLength; ++i)
    {
        const studentType &printStudent = theList.listOfStudent[i];
        cout << left << setw(20) << (printStudent.studentLName + ", " + printStudent.studentFName);
        cout << "Score: " << setw(5) << printStudent.testScore;
        cout << "Grade: " << setw(5) << printStudent.grade << endl;
        cout << "-----------------------------------------" << endl;
        cout << left;
    }
}

int findHighestScore(const studentList &theList)
{
    int highest = theList.listOfStudent[0].testScore;
    for (int i = 1; i < theList.listLength; ++i)
    {
        if (theList.listOfStudent[i].testScore > highest)
        {
            highest = theList.listOfStudent[i].testScore;
        }
    }
    return highest;
}
void whoIsHighest(const studentList &theList, int highest)
{
    for (int i = 0; i < theList.listLength; ++i)
    {
        if (theList.listOfStudent[i].testScore == highest)
        {
            cout << theList.listOfStudent[i].studentLName << ", " << theList.listOfStudent[i].studentFName << endl;
        }
    }
}