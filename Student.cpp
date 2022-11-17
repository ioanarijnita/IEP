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

class Student: private Uncopyable
{                        
    public: 
    
        Student(){} //default constructor
    
        Student(const int age, const int grade, const string& firstName, const string& lastName):     // custom paramaterized constructor
             age(age),
             grade(grade),
             firstName(firstName),
             lastName(lastName)
       {}
 
        void showStudent(){
             cout<<"The student with name: "<<firstName<<" "<<lastName<<" and age: "<<age<<" has the following grade: "<<grade<<"\n";
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
    private: 
    
        int age, grade;      
        string firstName, lastName;
};

  
int main()
{
     Student student1(23, 10, "Ioana", "Rijnita"); 
     student1.showStudent();

     Student student2(student1);  // copy constructor 
     student2.showStudent();

    //the copy constructor creates a separate memory block for the new object. But the assignment operator
    // does not make new memory space

     Student student3(24, 9, "Ioana2", "Rijnita2"); 
     Student student4; 
     student4=student3;  // copy assignment operator
     
  //   student4.showStudent();

    return 0;
}