// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
#include <cmath>

// Ваші файли загловки 
//
class Entity {
protected:
    std::string name_;
public:
    Entity(const std::string& name) : name_(name) {}
    virtual ~Entity() {}
    virtual void print() const {
        std::cout << "Name: " << name_ << std::endl;
    }
};

class Human : public Entity {
private:
    int age_;
public:
    Human(const std::string& name, int age) : Entity(name), age_(age) {}
    virtual ~Human() {}
    virtual void print() const override {
        Entity::print();
        std::cout << "Age: " << age_ << std::endl;
    }
};

class Father : public Human {
private:
    std::string job_;
public:
    Father(const std::string& name, int age, const std::string& job)
        : Human(name, age), job_(job) {}
    virtual ~Father() {}
    virtual void print() const override {
        Human::print();
        std::cout << "Job: " << job_ << std::endl;
    }
};

class Mother : public Human {
private:
    std::string hobby_;
public:
    Mother(const std::string& name, int age, const std::string& hobby)
        : Human(name, age), hobby_(hobby) {}
    virtual ~Mother() {}
    virtual void print() const override {
        Human::print();
        std::cout << "Hobby: " << hobby_ << std::endl;
    }
};

class Daughter : public Father, public Mother {
public:
    Daughter(const std::string& name, int age, const std::string& job,
        const std::string& hobby)
        : Father(name, age, job), Mother(name, age, hobby), Entity(name) {}
    virtual ~Daughter() {}
    virtual void print() const override {
        Father::print();
        Mother::print();
    }
};

int main() {
    Entity* entity = new Entity("John Doe");
    Human* human = new Human("Jane Doe", 30);
    Father* father = new Father("Jim Doe", 50, "Engineer");
    Mother* mother = new Mother("Mary Doe", 45, "Reading");
    Daughter* daughter = new Daughter("Jenny Doe", 10, "Student", "Drawing");
    entity->print();
    human->print();
    father->print();
    mother->print();
    daughter->print();
    delete entity;
    delete human;
    delete father;
    delete mother;
    delete daughter;
    return 0;
}

