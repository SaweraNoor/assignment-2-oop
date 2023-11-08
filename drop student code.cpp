#include<iostream>
using namespace std;

class course
{
    private:
        string courseName;
        string* students;
        int numberOfStudents;
        int capacity;

    public:
        course(const string& courseName, int capacity);
        ~course();
        string getcourseName() const;
        void addStudent(const string&name);
        void dropStudent(const string& name);
        string* getStudents() const;
        int getNumberOfStudents() const;
};

course::course(const string& courseName, int capacity)
{
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity];
}

course::~course() { delete [] students; }

string course::getcourseName() const { return courseName; }

void course::addStudent(const string&name)
{
    students[numberOfStudents] = name;
    numberOfStudents++;
}

void course::dropStudent(const string& name)
{
    for(int i=0; i<numberOfStudents; i++)
    {
                if(students[i] == name){
            for(int j=i; j<numberOfStudents-1; j++){
                students[j] = students[j+1];
            }
            numberOfStudents--;
            return;
        }
    }
}

string* course::getStudents() const {
    return students;
}

int course::getNumberOfStudents() const {
    return numberOfStudents;
}

int main(){
    course c1("data structure", 10);
    course c2("database system", 15);
    c1.addStudent("ali");
    c1.addStudent("ahmad");
    c1.addStudent("imran");
    c2.addStudent("rizwan");
    c2.addStudent("akeel");
     c1.dropStudent("ali");
    cout << "number of students in course 1: " << c1.getNumberOfStudents() << endl;
    string* students1 = c1.getStudents();
    for(int i=0; i<c1.getNumberOfStudents(); i++){
        cout << students1[i] << ", ";
    }
    cout << "/nnumber of students in course 2: " << c2.getNumberOfStudents() << endl;
    string* students2 = c2.getStudents();
    for(int i=0; i<c2.getNumberOfStudents(); i++){
        cout << students2[i] << ", ";
    }
   
    return 0;
}

