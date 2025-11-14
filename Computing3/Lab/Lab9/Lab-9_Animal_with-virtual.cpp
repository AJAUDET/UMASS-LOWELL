#include <iostream>
#include <string>
#include <vector>

using std::ostream;
using std::cout;
using std::endl;
using std::string;


class Animal { // base class
public:
    Animal() : _name("NoName") {}
    Animal(string name) : _name(name) {}
    
    string getName() const { return _name; }
    
    virtual string speak() const { return "I'm an Animal!"; }
    virtual string stringify() const { return "Name:\t\t" + _name + "\n"; }
    
    friend ostream& operator<< (ostream& out, const Animal& a) { out << a.stringify() << endl; return out; }
    
private:
    string _name;
};


class Mammal : public Animal { // derived class
public:
    Mammal() : _furColor("NoColor") {}
    Mammal(string name, string furColor) : Animal(name), _furColor(furColor) {}
    
    virtual string speak() const { return "I'm a Mammal!"; } // overrides Animal::speak()
    virtual string stringify() const { return Animal::stringify() + "Fur Color:\t" + _furColor + "\n"; } // overrides Animal::stringify()
    
    friend ostream& operator<< (ostream& out, const Mammal& m) { out << m.stringify() << endl; return out; }
    
private:
    string _furColor;
};


class Dog : public Mammal {
public:
    Dog() : _earsType("NoEarsType") {}
    Dog(string name, string furColor, string earsType) : Mammal(name, furColor), _earsType(earsType) {}
    
    virtual string speak() const { return "Woof!"; } // overrides Mammal::speak()
    virtual string stringify() const { return Mammal::stringify() + "Type of ears:\t" + _earsType + "\n"; } // overrides Mammal::stringify()
    
    friend ostream& operator<< (ostream& out, const Dog& d) { out << d.stringify() << endl; return out; }
    
private:
    string _earsType; // floppy, straight
};


class Cat : public Mammal {
public:
    Cat() : _furType("NoFurType") {}
    Cat(string name, string furColor, string furType) : Mammal(name, furColor), _furType(furType) {}
    
    virtual string speak() const { return "Meow..."; } // overrides Mammal::speak()
    virtual string stringify() const { return Mammal::stringify() + "Type of fur:\t" + _furType + "\n"; } // overrides Mammal::stringify()
    
    friend ostream& operator<< (ostream& out, const Cat& c) { out << c.stringify() << endl; return out; }
    
private:
    string _furType; // long-hair, short-hair
};



int main(void) {
    Dog d("Rover", "brown", "floppy");
    cout << d.getName() << " says \"" << d.speak() << "\"\n\n";
    cout << d << endl;
    
    Cat c("Garfield", "calico", "long-hair");
    cout << c.getName() << " says \"" << c.speak() << "\"\n\n";
    cout << c << endl;
    
    Animal* a = &d;
    cout << a->getName() << " says \"" << a->speak() << "\"\n\n";
    cout << *a << endl;
    
    a = &c;
    cout << a->getName() << " says \"" << a->speak() << "\"\n\n";
    cout << *a << endl;
    
    return 0;
}

