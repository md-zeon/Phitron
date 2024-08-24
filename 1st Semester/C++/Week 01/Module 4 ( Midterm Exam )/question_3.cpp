/*
* Question 03:
* a. What is the size that an object allocates to the memory?
= The size that an object allocates in memory is determined by the sum of the sizes of its data members, along with any alignment or padding added by the compiler. This size can be calculated using the `sizeof` operator.

  *Example:**
  
  class Example {
  public:
      int a;       // 4 bytes
      double b;    // 8 bytes
      char c;      // 1 byte
  };

  int main() {
      std::cout << "Size of Example object: " << sizeof(Example) << " bytes" << std::endl;
      return 0;
  }
  
  The output will depend on compiler and system architecture, but typically, it will include padding bytes to ensure alignment, so the total size could be larger than just the sum of the individual data members.

*/

/*
* b. Can you return a static object from a function? If yes, show with an example.
= Yes, you can return a static object from a function. A static object has a lifetime that extends across the entire duration of the program, which allows it to be safely returned from a function.

  *Example:**
  
  class Example {
  public:
      int value;
      Example(int v) : value(v) {}
  };

  Example& getStaticObject() {
      static Example obj(42); // static object
      return obj;
  }

  int main() {
      Example& ref = getStaticObject();
      std::cout << "Value: " << ref.value << std::endl; // Outputs: Value: 42
      return 0;
  }

  - The static object `obj` inside the function retains its value and exists for the entire program's lifetime, so it can be safely returned by reference.

*/

/*
* c. Why do we need `->` (arrow sign)?
- The `->` (arrow operator) is used to access members of a class or struct through a pointer. It is a shorthand for dereferencing the pointer and then accessing the member.

*Example:**
    *If you have a pointer to an object, you can access its members using the arrow operator:

    Person* personPtr = new Person("Alice", 5.7f, 25);
    std::cout << personPtr->name << std::endl; // Using the arrow operator to access the 'name' member


  * Without the arrow operator, you would need to dereference the pointer first and then access the member:

    std::cout << (*personPtr).name << std::endl;


  *The arrow operator simplifies the syntax and makes the code more readable.
*/


/*
* d. Create two objects of the `Person` class from question 2-c and initialize them with proper values. Now compare whose age is greater, and print his/her name.


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
    //* Creating two objects of the Person class
    Person person1("Alice", 5.7f, 25);
    Person person2("Bob", 6.0f, 30);

    //* Comparing ages and printing the name of the older person
    if (person1.age > person2.age) {
        std::cout << person1.name << " is older." << std::endl;
    } else if (person2.age > person1.age) {
        std::cout << person2.name << " is older." << std::endl;
    } else {
        std::cout << "Both are of the same age." << std::endl;
    }

    return 0;
}

 *Explanation:**
  - Two objects of the `Person` class, `person1` and `person2`, are created and initialized with different values.
  - The ages of the two objects are compared, and the program prints the name of the person with the greater age.

*/