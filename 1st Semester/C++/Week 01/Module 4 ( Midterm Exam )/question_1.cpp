//! Question 01:

//* a. Explain Stack and Heap Memory.
/* 
*Stack Memory:
  = Stack memory is a region in memory that stores local variables and function call information. It follows a Last In, First Out (LIFO) structure where memory is automatically managed (allocated and deallocated) when the function call ends.
  * Characteristics:
    - Fast access.
    - Limited in size, usually smaller than heap memory.
    - Memory is deallocated automatically when the function scope is exited.
    - Mainly used for static memory allocation (variables whose size is known at compile-time).

*Heap Memory:
  = Heap memory is a region used for dynamic memory allocation where variables are allocated and deallocated manually by the programmer using specific functions like `new`/`delete` in C++ or `malloc`/`free` in C.
  * Characteristics:
    - Slower access compared to stack memory.
    - Larger in size, allowing for more flexible memory allocation.
    - Memory remains allocated until explicitly freed by the programmer.
    - Used for dynamic memory allocation (variables whose size is determined at runtime).
*/
/*
*b. Why do we need dynamic memory allocation? Explain with examples.
 * Dynamic memory allocation** is necessary when the size of the data structures (e.g., arrays, linked lists) cannot be determined at compile-time. It allows the program to request memory during runtime based on the actual needs of the application.

  *Example 1:**
  If you need an array where the size is unknown until runtime (e.g., reading user input or file data), dynamic memory allocation is needed:
  
  int size;
  std::cout << "Enter the size of the array: ";
  std::cin >> size;
  int* arr = new int[size]; // dynamically allocated array

  *Example 2:**
  Dynamic memory allocation is useful for creating complex data structures like linked lists, trees, and graphs where the amount of memory required can change as new elements are added or removed.

  struct Node {
      int data;
      Node* next;
  };
  Node* head = new Node(); // dynamic memory allocation for a linked list node

  &Without dynamic memory allocation, you would be restricted to using fixed-size arrays, which may waste memory if the array is larger than needed or cause problems if it’s too small.

*/

/*
* c. How to create a dynamic array? What are the benefits of it?
* Creating a dynamic array in C++ is done using pointers and the `new` keyword:

  int size;
  std::cout << "Enter the size of the array: ";
  std::cin >> size;
  int* dynamicArray = new int[size]; // Creating a dynamic array


*Benefits of Dynamic Arrays:**
   *Flexible Size:** Unlike static arrays, dynamic arrays allow the size to be determined at runtime, making them more flexible.
   *Efficient Memory Usage:** You can allocate exactly the amount of memory you need, reducing the possibility of wasting memory.
   *Resizable:** You can resize dynamic arrays by reallocating memory if needed (e.g., with `std::vector` in C++).
*/