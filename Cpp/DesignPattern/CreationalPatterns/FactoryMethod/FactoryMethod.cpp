#include <iostream>
using namespace std;
using std::cin;
typedef enum{
    CAT,DOG,COW,
}AnimalType;
class Animal{
    public:
        virtual void Speak(void)=0;
        static Animal* CreateAnimal(AnimalType animalType);
        explicit Animal(){
            std::cout<<"Animal Constructor\n";
        }
        virtual ~Animal(){
            std::cout<<"Animal Destructor\n";
        }
};
class Dog: public Animal{
    public:
        void Speak(void)override final{
            std::cout<<"Dog Bark\n";
        }
        explicit Dog(){
            std::cout<<"Dog Constructor\n";
        }
        virtual ~Dog(){
            std::cout<<"Dog Destructor\n";
        }
};
class Cat: public Animal{
    public:
        void Speak(void)override final{
            std::cout<<"Cat Meow\n";
        }
        explicit Cat(){
            std::cout<<"Cat Constructor\n";
        }
        virtual ~Cat(){
            std::cout<<"Cat Destructor\n";
        }
};
class Cow: public Animal{
    public:
        void Speak(void)override final{
            std::cout<<"Cow Moos\n";
        }
        explicit Cow(){
            std::cout<<"Cow Constructor\n";
        }
        virtual ~Cow(){
            std::cout<<"Cow Destructor\n";
        }
};

Animal* Animal::CreateAnimal(AnimalType animalType){
    switch(animalType){
        case CAT:
            return new Cat();
        case DOG:
            return new Dog();
        case COW:
            return new Cow();
        default:
            std::cout<<"Invalid Input\n";
            return nullptr;
    }
}
int main(){
    Animal*dog = Animal::CreateAnimal(DOG);
    dog->Speak();
    Animal* cat = Animal::CreateAnimal(CAT);
    cat->Speak();
    Animal* cow = Animal::CreateAnimal(COW);
    cow->Speak();

    delete dog;
    delete cat;
    delete cow;
    return 0;
}