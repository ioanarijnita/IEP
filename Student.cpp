#include <iostream>
using namespace std;

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
        
       
        void showStudent(){
            // cout<<"The student with name: "<<firstName<<" "<<lastName<<" and age: "<<age<<" has the following grade: "<<grade<<"\n";
             cout<<"The student with name: "<<firstName<<" "<<lastName<<" and age: "<<age<<" has the following grade: "<<*grade<<"\n";
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

    return 0;
}