Queue Management System

This program is designed to simulate a queue management system. It allows the user to add customers to a queue, remove them from the queue, and display the customers in the queue and the customers who have already been served.
How to use the program
Compilation

This program is written in C++ and can be compiled using any standard C++ compiler.
Execution

Once compiled, execute the program by running the executable. Upon execution, the program will ask the user to enter the size of the queue.

After entering the size of the queue, the program will display a menu with the following options:

    Add Customer to Queue
    Serve Customer
    Display Customers in Queue
    Display Customers Served
    Exit

Add Customer to Queue

Selecting this option will prompt the user to enter the customer's details, including name, address, age, and bill. Once the user enters all the details, the program will add the customer to the queue.
Serve Customer

Selecting this option will remove the customer from the front of the queue and add them to the list of served customers.
Display Customers in Queue

Selecting this option will display all the customers currently in the queue.
Display Customers Served

Selecting this option will display all the customers who have already been served.
Exit

Selecting this option will exit the program.
Class Description
customer

This class represents a customer and contains the following attributes:

    name - a string representing the customer's name
    sno - an integer representing the customer's ID
    address - a string representing the customer's address
    age - an integer representing the customer's age
    bill - an integer representing the customer's bill

This class has the following methods:

    input() - prompts the user to enter the customer's details
    display_customer() - displays the customer's details

Queue

This class represents a queue of customers and contains the following attributes:

    arr - an array of customer objects representing the queue
    served - an array of customer objects representing the customers who have been served
    front - an integer representing the front of the queue
    rear - an integer representing the rear of the queue
    front2 - an integer representing the front of the list of served customers
    rear2 - an integer representing the rear of the list of served customers
    size - an integer representing the size of the queue
    ttl - an integer representing the total number of customers served

This class has the following methods:

    isfull() - checks if the queue is full
    isempty() - checks if the queue is empty
    isempty2() - checks if the list of served customers is empty
    enqueue(customer c) - adds a customer to the queue
    dequeue() - removes a customer from the queue and adds them to the list of served customers
    display() - displays all the customers currently in the queue
    display_served() - displays all the customers who have already been served

Dependencies

This program uses the following libraries:

    iostream
    string
    windows.h

License

This project is licensed under the MIT License. See the LICENSE file for details.

