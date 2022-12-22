#include <iostream>
#include <memory>
using namespace std;
#define Lock_Code "";

//Base Class
class Uncopyable{
    protected:
        Uncopyable(){}
        ~Uncopyable(){}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};

class Student

//: private Uncopyable

{     
    private:
        bool isLocked = false;                   
    public: 
    
        Student(): 
            age(0),
            grade(0),
            firstName("Ioana0"),
            lastName("Rijnita0"),
            university("UPT")
       {} 
    
     Student(const int age, const int grade, const string& firstName, const string& lastName, const string& university);

        Student(const Student &student):     // custom paramaterized constructor
             age(age),
             grade(new int (*student.grade)),
             firstName(firstName),
             lastName(lastName),
             university(university)
       {}
        
       
        string showStudent(){
            if (isLocked)
            {
                return "Lock_Code";
            } else {
                // cout<<"The student with name: "<<firstName<<" "<<lastName<<" and age: "<<age<<" has the following grade: "<<grade<<"\n";
                cout<<"The student with name: "<<firstName<<" "<<lastName<<" and age: "<<age<<" has the following grade: "<<*grade<<"\n";
            }
         }

        ~Student(){ //destructor
            cout<<"The student does not exist anymore in the memory.\n";
        }

        //  Student& operator=(const Student& student){   // Custom Copy Asignment Operator, Item 6 
        //    this->age=student.age;
        //    this->grade=student.grade;
        //    this->firstName=student.firstName;
        //    this->lastName=student.lastName;
        //    return *this;
        //  }

       //Item 10 and Item 11 
        Student& operator=(const Student& rhs){

            //before deletion, make sure to have a copy of the original value

            int *copyOfTheOriginalGrade = grade;
            grade = new int (*rhs.grade);
            delete copyOfTheOriginalGrade;

            if(this == &rhs){
                cout<<"The students have the same reference. Return the current student reference.\n";
                return *this;
            }

            //otherwise

            this->age = rhs.age;
            this->grade = rhs.grade;
            this->firstName = rhs.firstName;
            this->lastName = rhs.lastName;
            this->university = rhs.university;

            return *this;
        }

    getisStudentLocked(){
        return this->isLocked;
    }

    setStudentLocked(bool locked){
        this->isLocked = locked;
    }
    private: 
    
        int age;
        //int grade;      
        int *grade;
        string firstName, lastName, university;
};

 Student::Student(const int age, const int grade, const string& firstName, const string& lastName, const string& university): 
     age(age),
     grade(new int (grade)),
     firstName(firstName),
     lastName(lastName),
     university(university) 
     {}

void lockStudent(Student &value)
        {
           value.setStudentLocked(true);
        }

void unLockStudent(Student &value)
        {
            value.setStudentLocked(false);
        }

//Item 12

class CTIStudent: public Student {

    public: 

    CTIStudent():  Student(), faculty("CTI")
    {}

    CTIStudent(const int age, const int grade, const string& firstName, const string& lastName, const string& university, const string& faculty): 
    
     Student(age, grade, firstName, lastName, university),
     faculty(faculty)
     {}

    
    // Copy constructor 
    
    CTIStudent(const CTIStudent& student) : 
     
     Student(student),
     faculty(student.faculty) 
     {}

    // Assignment operator

    CTIStudent& operator=(const CTIStudent& rhs)
        {
            if(this == &rhs)
            {
                cout<<"The students have the same reference. Return the current student reference.\n";
                return *this;
            }

            Student::operator=(rhs);
            faculty = rhs.faculty;
            return *this;
        }

        string getFaculty()
        {
            return this->faculty;
        }

    private:
        string faculty;
};

class LockedStudent:  private Uncopyable
{

public:
    explicit LockedStudent(Student &value) : lockedStudent(value)
    {
        lockStudent(lockedStudent);
    }

    ~LockedStudent()
    {
        unLockStudent(lockedStudent);
    }
private:
    Student &lockedStudent;
};

Student *createStudentInstance(int age, int grade, string firstName, string lastName, string university)
{
    return (new Student(age, grade, firstName, lastName, university));
}

//Item 13
void createAndShowStudent()
{
    Student *s = createStudentInstance(21, 3, "Ana", "Maria", "UPT");
    return;
    delete s;
   
    unique_ptr<Student> newStudent(createStudentInstance(22, 4, "Ana", "Lorena", "UVT"));
    newStudent->showStudent();

    unique_ptr<Student> newStudent2 = move(newStudent);

    shared_ptr<Student> s2(createStudentInstance(22, 4, "Vlad", "Andrei", "UMFT"));
    shared_ptr<Student> s3(s2);
   
    s2->showStudent();
    s3->showStudent();
    s2.use_count();

    shared_ptr<Student> s4 = move(s2);
    s4->showStudent();
}
  
int main()
{
     Student student1(23, 10, "Ioana", "Rijnita", "UPT"); 
     student1.showStudent();

     //Student student2(student1);  // copy constructor 
     //student2.showStudent();

    //the copy constructor creates a separate memory block for the new object. But the assignment operator
    // does not make new memory space

    //Student student3(24, 9, "Ioana2", "Rijnita2", "UPT2"); 
    //Student student4; 
    //student4=student3;  // copy assignment operator
     
    //student4.showStudent();

      CTIStudent student5(20, 9, "Maria", "Popescu", "UPT", "CTI RO");
      student5.showStudent();

      CTIStudent student6(19, 8, "Andrei", "Ionescu", "UPT", "CTI EN");
      student6.showStudent();
      cout<<"The student is enrolled at the following faculty: "<<student6.getFaculty()<<endl;

      createAndShowStudent();

    //Item 14
    Student Student7(19, 8, "Andrei", "Ionescu", "UPT");
    LockedStudent *lockedStudent = new LockedStudent(Student7);

    Student7.showStudent();

    delete lockedStudent;
    Student7.showStudent();

    return 0;
}