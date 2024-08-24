// *Question 02:
/*
* a. How does class and object work? How to declare an object?
 *Class:** A class is a user-defined data type that represents a blueprint for creating objects. It encapsulates data (attributes) and methods (functions) that operate on that data.

 *Object:** An object is an instance of a class. It represents a specific entity of the class with defined values for its attributes.

  *Example of Declaring an Object:**
  
  class Car {
  public:
      string model;
      int year;

      void displayInfo() {
          std::cout << "Model: " << model << ", Year: " << year << std::endl;
      }
  };

  //* Declaring an object of the Car class
  Car myCar;
  myCar.model = "Toyota";
  myCar.year = 2022;
  myCar.displayInfo(); // Outputs: Model: Toyota, Year: 2022

*/
/*
* b. What is a constructor and why do we need this? How to create a constructor? Show with an example.
*Constructor:** A constructor is a special member function of a class that is automatically called when an object is created. It is used to initialize the object's attributes and allocate any necessary resources.

  *Why do we need a constructor?**
    - To ensure that an object is initialized properly when it is created.
    - To set default values for data members or perform any setup tasks that are required for the object to function correctly.

  *Example of a Constructor:**

  class Car {
  public:
      string model;
      int year;

      //* Constructor to initialize the object
      Car(string m, int y) {
          model = m;
          year = y;
      }

      void displayInfo() {
          std::cout << "Model: " << model << ", Year: " << year << std::endl;
      }
  };

  //* Creating an object using the constructor
  Car myCar("Toyota", 2022);
  myCar.displayInfo(); // Outputs: Model: Toyota, Year: 2022

*/
/*
* c. Create a class named `Person` where the class will have properties `name` (string), `height` (float), and `age` (int). Make a constructor and create a dynamic object of that class, and finally, pass proper values using the constructor.

#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    float height;
    int age;

    //* Constructor to initialize the properties
    Person(std::string n, float h, int a) {
        name = n;
        height = h;
        age = a;
    }

    void displayInfo() {
        std::cout << "Name: " << name << ", Height: " << height << ", Age: " << age << std::endl;
    }
};

int main() {
    //* Creating a dynamic object of the Person class
    Person* personPtr = new Person("Alice", 5.7f, 25);

    //* Displaying the person's information
    personPtr->displayInfo();

    //* Freeing the dynamically allocated memory
    delete personPtr;

    return 0;
}

 *Explanation:**
  - The `Person` class has three properties: `name`, `height`, and `age`.
  - A constructor is defined to initialize these properties.
  - A dynamic object of the class is created using the `new` keyword.
  - The object's properties are initialized by passing values to the constructor.
  - The dynamically allocated memory is later freed using `delete`.

*/