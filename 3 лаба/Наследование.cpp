#include <iostream>
#include <string>

class Company {
private:
    std::string company;
public:
    Company() {
        company = " неизвестная компания";
    }

    Company(std::string name) {
        company = name;
    }

    std::string getCompanyName() {
        return company;
    }

    void setCompanyName(std::string name) {
        company = name;
    }
};


class Employee {
private:
    std::string name;

public:
    int age;

    Employee() {
        name = "неизвестно";
        age = 0;
    }

    Employee(std::string N, int A) {
        name = N;
        age = A;
    }

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(std::string N) {
        name = N;
    }

    void setAge(int A) {
        age = A;
    }

    void displayInfo() {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Возраст: " << age <<  std::endl;
    }
};

class Vehicle {
protected:
    std::string brand;
public:
    Vehicle() {
        brand = "неизвестный ";
    }

    Vehicle(std::string B) {
        brand = B;
    }

    std::string getBrand() {
        return brand;
    }

    void setBrand(std::string B) {
        brand = B;
    }
};


class Truck : public Vehicle {
private:
    int maxload;
public:
    Truck() : Vehicle() {
        maxload = 0;
    }

    Truck(std::string B, int load) : Vehicle(B) {
        maxload = load;
    }

    Truck(std::string B) : Vehicle(B) {
        maxload = 0;
    }

    void setMaxLoad(int load) {
        maxload = load;
    }

    int getMaxLoad() {
        return maxload;
    }

    void displayInfo() {
        std::cout << "Бренд: " << getBrand() << std::endl;
        std::cout << "Максимальный тоннаж: " << maxload << std::endl;
    }
};

class Model : public Vehicle {
private:
    int maxspeed;

public:
    Model() : Vehicle() {
        maxspeed = 0;
    }
    
    Model(std::string b, int speed) : Vehicle(b) {
        maxspeed = speed;
    }
    
    Model(int speed) : Vehicle() {
        maxspeed = speed;
    }
    
    void setMaxSpeed(int speed) {
        maxspeed = speed;
    }
    
    int getMaxSpeed() {
        return maxspeed;
    }
    
    void displayInfo() {
        std::cout << "Модель: " << getBrand() << std::endl;
        std::cout << "Максимальная скорость: " << maxspeed  << std::endl;
    }
};

int main() {   
    setlocale(LC_CTYPE, "rus");
    
    Truck truck1("kia", 8);
    truck1.displayInfo();

    Model model1("optima", 250);
    model1.displayInfo();

    Employee employee1("Ворокова Надежда ", 20);
    employee1.displayInfo();

    return 0;
}