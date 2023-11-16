#include <iostream>

class human
{
public:
    char name[50];
    char surname[50];
    int age;

    void init()
    {
        strcpy_s(name, "Xanbaba");
        strcpy_s(surname, "Fatullayev");
        age = 42;
    }

    void info()
    {
        std::cout << name << '\n';
        std::cout << surname << '\n';
        std::cout << age << '\n';
    }

    void reveal_secret()
    {
        std::cout << secret1_;
    }

private:
    char secret1_[50] = "some secret";

protected:
    char secret2_[50] = "another secret";
};




int main(int argc, char* argv[])
{
    // OOP - Object Oriented Paradigm

    // OOP Principles
    // 1. Inheritance
    // 2. Encapsulation
    // 3. Polymorphism
    // 4. Abstraction

    /*{
        human human_obj;
        human_obj.init();
        human_obj.info();
        human_obj.reveal_secret();
    

        // access modificator
        // 1. public
        // 2. private
        // 3. protected
    }*/

    Student student1 = {"Xanbaba", "Fatullayev", 15, {12, 12, 12, 12, 12}};
    Student student2 = {"Sabir", "Quliyev", 17, {10, 12, 11, 8, 12}};
    student1.info();
    student2.info();
    return 0;
}
