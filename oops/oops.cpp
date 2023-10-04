class and object

class : A class is a user-defined data type that we can use in our program, and it works as an object constructor, or a "blueprint" for creating objects.

object : An object is an instance of a class

#include <bits/stdc++.h>
using namespace std;
class Student
{
    // there are 3 types of access modifiers they are private , public and protected
    // data members are private by default
    // we should specify it as public to access directly
public:
    string name;
    int roll;
    int classno;
    void intro()
    {
        cout << name << " " << roll << " " << classno;
    }
};
int main()
{
    Student s1;
    s1.name = "sanu";
    s1.classno = 12;
    s1.roll = 28;
    s1.intro();

    //    cout<<s1.name;
    //    cout<<s1.roll;
    //    cout<<s1.classno;
    return 0;
}

constructor

constructor :  constructor is a special “MEMBER FUNCTION”  that has the same name as the class it belongs to and is used to initialise values for object's data members

#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int classno;
    void intro()
    {
        cout << name << " " << roll << " " << classno << endl;
    }

    // Below Student() is a default constructor , it is called when we create a object in main class
    Student() {}

    Student(string name)
    {
        this->name = name;
    }

    Student(string name, int roll, int classno)
    {
        this->name = name;
        this->roll = roll;
        this->classno = classno;
    }
};
int main()
{
    // 1st parameterized constructor is called
    Student s1("sanu");
    s1.intro();
    // 2nd parameterized constructor is called
    Student s2("jana", 26, 10);
    s2.intro();
    //    this is copy constructor Student s3(s2); simply means copy all the values of s2 in s3
    // IMPORTANT - default copy constructor creates a shallow copy of the object
    Student s3(s2);
    s3.intro();

    Student s4;
    //    this is copy assignment operator copies all the values of s2 into s4 like s4.name = s2.name , s4.roll = s2.roll ...
    s4 = s2;
    s3.intro();
    return 0;
}

destructor : -A destructor is a member function that is invoked automatically when the object goes out of scope or is explicitly destroyed by a call to delete.

#include <bits/stdc++.h>
                                                                                                                   using namespace std;
class Student
{
public:
    Student()
    {
        cout << "constructor called ";
    }
    ~Student()
    {
        cout << "destructor called ";
    }
};
int main()
{
    // destructor called automatically for static allocation
    Student s1;
    // destructor called manualy for dynamic allocation
    Student *s2 = new Student();
    // we need to delete explicitly
    delete s2;
    return 0;
}

encapsulation

    Encapsulation : Encapsulation is a process of combining member functions and data members in a single unit called a class.The purpose is to prevent access to the data directly.Its also known as data hiding;

#include <bits/stdc++.h>
using namespace std;
class Student
{
    // we are encapsulating data member to prevent direct access outside of class , we will rather use getter and setter to get and set values of data members
private:
    string name;
    int roll;
    int classno;

public:
    // setter and getters
    void setname(string name)
    {
        this->name = name;
    }
    string getname()
    {
        return name;
    }
    void setroll(int roll)
    {
        this->roll = roll;
    }
    int getroll()
    {
        return roll;
    }
    void setclsno(int classno)
    {
        this->classno = classno;
    }
    int getclsno()
    {
        return classno;
    }
    void intro()
    {
        cout << name << " " << roll << " " << classno << endl;
    }
    Student(string name, int roll, int classno)
    {
        this->name = name;
        this->roll = roll;
        this->classno = classno;
    }
};
int main()
{
    Student s1 = Student("sanu", 28, 12);
    s1.intro();            // output : -
    s1.setname("Santanu"); // sanu 28 12
    s1.setroll(100);       // new values are : Santanu 100 123
    s1.setclsno(123);
    cout << "new values are : " << s1.getname() << " " << s1.getroll() << " " << s1.getclsno();
    return 0;
}

Abstraction

    Abstraction : Abstraction is the process of only showing the necessary details to the user and hiding the other details in the background.

#include <bits/stdc++.h>
                  using namespace std;
// abstract class
class Abstudent
{
public:
    // Pure Virtual Function
    virtual void result() = 0;
};
// inheriting the abstract class
class Student : Abstudent
{
private:
    string name;
    int roll;
    int classno;

public:
    void intro()
    {
        cout << name << " " << roll << " " << classno << endl;
    }
    Student(string name, int roll, int classno)
    {
        this->name = name;
        this->roll = roll;
        this->classno = classno;
    }
    void result()
    {
        // implementation of the pure virtual function
        if (roll >= 25)
        {
            cout << "Passed" << endl;
        }
        else
        {
            cout << "Falied" << endl;
        }
    }
};
int main()
{
    Student s1 = Student("sanu", 8, 12);
    s1.intro();
    s1.result(); // calling
    Student s2 = Student("jana", 88, 12);
    s2.intro();
    s2.result(); // calling

    // output :-
    // sanu 8 12
    // Falied
    // jana 88 12
    // Passed

    return 0;
}

Inheritance

    Inheritance : The capability of a class to derive properties and characteristics from another class is called Inheritance.

#include <bits/stdc++.h>
                  using namespace std;

class Human
{
public:
    int a;
};
class Male : public Human
{
public:
    int b;
};
int main()
{
    Male m;
    // inherited data member "a" from Human to Male
    m.a = 1;
    m.b = 2;
    cout << m.a << " " << m.b;
    return 0;
}

types of Inheritence

    1. Single Inheritence

        Human |
    Male

#include <bits/stdc++.h>
    using namespace std;
class Human
{
public:
    int a;
};
class Male : public Human
{
public:
    int b;
};
int main()
{
    Male m;
    m.a = 1;
    m.b = 2;
    cout << m.a << " " << m.b;
    return 0;
}

2. Multilevel inheritance

        A |
    B |
    C

#include <bits/stdc++.h>
    using namespace std;
class Human
{
public:
    int a;
};
class Male : public Human
{
public:
    int b;
};
class Indian : public Male
{
};
int main()
{
    Indian m;
    m.a = 1;
    m.b = 2;
    cout << m.a << " " << m.b;
    return 0;
}

3. Multiple Inheritance

        A B
   \ /
    C

#include <bits/stdc++.h>
    using namespace std;
class Human
{
public:
    int a;
};
class Male
{
public:
    int b;
};
class Indian : public Human, public Male
{
};
int main()
{
    Indian m;
    m.a = 1;
    m.b = 2;
    cout << m.a << " " << m.b;
    return 0;
}

4. Hierarchical Inheritance

        A /
    B C

#include <bits/stdc++.h>
    using namespace std;
class Human
{
public:
    int a;
    void say()
    {
        cout << "HI" << endl;
    }
};
class Female : public Human
{
};
class Male : public Human
{
};
int main()
{
    Female f;
    Male m;
    f.say();
    m.say();
    return 0;
}

5. Hybrid Inheritance
    combination of any two different type Inheritance such
    as(single + multiple)

        Inheritance Ambiguity
    if inherited classes are having same named data members,
    it can create Inheritance Ambiguity to the derived or child class, in this case we use scope resolution operator(::) to specify the data member of that class.

#include <bits/stdc++.h>
                                                                       using namespace std;
    class A{
        public:
int a;
void say()
{
    cout << "HI form a" << endl;
}
}
;
class B
{
public:
    int a;
    void say()
    {
        cout << "HI from b" << endl;
    }
};
class C : public A, public B
{
};
int main()
{
    C c1;
    // Data member of A
    c1.A::say();
    // Data member of B
    c1.B::say();
    return 0;
}

Polymorphism

        It is an important concept of object -
    oriented programming.It simply means more than one form.

    its two types compile -
    time polymorphism and runtime polymorphism

        Compile -
    time polymorphism is two types - 1. function overloading,
    2. operator overloading

#include <bits/stdc++.h>
    using namespace std;
class A
{
public:
    // function overloading
    void sum(int a, int b)
    {
        cout << "sum is : " << a + b << endl;
    }
    void sum(int a, int b, int c)
    {
        cout << "sum is : " << a + b + c << endl;
    }

    // operator overloading
    // syntax return_type operator operator_sign(){}
    void operator()()
    {
        cout << "bracket operator is overloaded";
    }
};
int main()
{
    A a1;
    // function overloading
    a1.sum(1, 2);
    a1.sum(1, 2, 3);

    // operator overloading
    a1();
    return 0;
}

Runtime polymorphism is function overriding

#include <bits/stdc++.h>
    using namespace std;
class A
{
public:
    void say()
    {
        cout << "Say from A" << endl;
    }
};
class B : public A
{
public:
    // function overridden
    void say()
    {
        cout << "Say from B" << endl;
    }
};
int main()
{
    B b1;
    // Called function of B 
    b1.say();
    return 0;
}


Abstraction
Abstraction : means displaying only essential information and hiding the details.

#include <bits/stdc++.h>
using namespace std;
// abstract class
class Abstudent
{
public:
    // Pure Virtual Function
    virtual void result() = 0;
};
// inheriting the abstract class
class Student : public Abstudent
{
public:
    void result()
    {
        // implementation of the pure virtual function
         cout << "You passed" << endl;
    }
};
int main()
{
    Student s2 ;
    s2.result(); 
    return 0;
}