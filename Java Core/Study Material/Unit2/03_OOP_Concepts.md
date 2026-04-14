# 03 — OOP Concepts: Classes, Objects, Constructors, Methods & Overloading

---

## 📖 Theory

### What Is Object-Oriented Programming?

**OOP** is a programming paradigm that organizes code around **objects** (real-world entities) rather than procedures. Java is built on 4 core OOP principles:

| Pillar | Description |
|---|---|
| **Encapsulation** | Bundling data and methods together; hiding internals |
| **Inheritance** | A class inheriting properties of another |
| **Polymorphism** | One interface, many implementations |
| **Abstraction** | Hiding complexity, exposing only essentials |

---

### Classes and Objects

A **class** is a blueprint/template. An **object** is an instance of a class.

```java
// Blueprint
class Dog {
    String name;   // attribute (field)
    String breed;

    void bark() {  // behaviour (method)
        System.out.println(name + " says: Woof!");
    }
}

// Create objects (instances) from the blueprint
Dog d1 = new Dog();
d1.name = "Rex";
d1.breed = "Labrador";
d1.bark();     // Rex says: Woof!

Dog d2 = new Dog();
d2.name = "Buddy";
d2.bark();     // Buddy says: Woof!
```

Each object has its own copy of instance variables but shares methods.

---

### Constructors

A **constructor** is a special method that is called automatically when an object is created with `new`. It is used to initialize the object.

**Rules:**
- Same name as the class
- No return type (not even `void`)
- Called once when object is created

#### Types of Constructors

**1. Default Constructor** (no arguments)
```java
class Car {
    String brand;
    int year;

    // Default constructor
    Car() {
        brand = "Unknown";
        year = 2020;
    }
}

Car c = new Car();   // calls default constructor
```

**2. Parameterized Constructor**
```java
class Car {
    String brand;
    int year;

    Car(String brand, int year) {
        this.brand = brand;   // 'this' distinguishes field from parameter
        this.year = year;
    }
}

Car c = new Car("Toyota", 2023);
```

**3. Copy Constructor**
```java
class Car {
    String brand;
    int year;

    Car(Car other) {
        this.brand = other.brand;
        this.year = other.year;
    }
}

Car original = new Car("Honda", 2021);
Car copy = new Car(original);
```

---

### The `this` Keyword

`this` refers to the **current object** inside an instance method or constructor.

**Uses of `this`:**

```java
class Student {
    String name;
    int age;

    // 1. Disambiguate fields vs parameters
    Student(String name, int age) {
        this.name = name;   // this.name = field, name = parameter
        this.age = age;
    }

    // 2. Call another constructor (constructor chaining)
    Student() {
        this("Unknown", 0);   // calls parameterized constructor
    }

    // 3. Pass current object to a method
    void show(Student s) {
        System.out.println(s.name + ", " + s.age);
    }

    void display() {
        show(this);   // pass current object
    }
}
```

---

### Methods

A **method** is a block of code that performs a specific task.

```java
// Syntax
returnType methodName(parameters) {
    // body
    return value;   // if returnType is not void
}
```

**Method with return value:**
```java
int add(int a, int b) {
    return a + b;
}
int result = add(5, 3);   // result = 8
```

**Void method:**
```java
void printMessage(String msg) {
    System.out.println(msg);
}
```

---

### Method Overloading

**Method overloading** means having **multiple methods with the same name** but different parameter lists (different number, type, or order of parameters).

The compiler decides which method to call based on the arguments — this is called **compile-time polymorphism**.

```java
class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
}
```

**Rules for overloading:**
- ✅ Different number of parameters
- ✅ Different types of parameters
- ✅ Different order of parameter types
- ❌ Return type alone is NOT enough to overload

---

### Constructor Overloading

Constructors can also be overloaded:

```java
class Rectangle {
    double width, height;

    Rectangle() {
        width = 1; height = 1;   // default square
    }

    Rectangle(double side) {
        width = side; height = side;   // square with custom size
    }

    Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    double area() {
        return width * height;
    }
}
```

---

### Initializer Blocks

**Instance Initializer Block** runs before the constructor, every time an object is created:

```java
class Demo {
    int value;

    // Instance initializer block
    {
        value = 10;
        System.out.println("Instance initializer block called.");
    }

    Demo() {
        System.out.println("Constructor called. Value = " + value);
    }
}
```

**Static Initializer Block** runs once when the class is first loaded:

```java
class Config {
    static String appName;
    static int version;

    static {
        appName = "MyApp";
        version = 1;
        System.out.println("Static block: App initialized.");
    }
}
```

---

## 🧪 Practice Questions

1. What is the difference between a class and an object?
2. What is a constructor? How is it different from a regular method?
3. What does the `this` keyword refer to? Give two different use cases.
4. What is method overloading? How does the compiler know which version to call?
5. Can you overload methods by changing only the return type? Explain.
6. What is the difference between an instance initializer block and a static initializer block?
7. Write a class `Circle` with constructors for no-args (radius = 1), one arg (radius), and a copy constructor.
8. What happens if you don't write any constructor in a class?

---

## 💻 Examples

### Example 1 – Class with Constructors and Methods

```java
public class BankAccount {
    private String owner;
    private double balance;
    private int accountId;
    private static int nextId = 1000;

    // Parameterized constructor
    BankAccount(String owner, double initialBalance) {
        this.owner = owner;
        this.balance = initialBalance;
        this.accountId = nextId++;
    }

    // Default constructor
    BankAccount(String owner) {
        this(owner, 0.0);   // calls parameterized constructor
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount + " | New balance: " + balance);
        }
    }

    boolean withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount + " | New balance: " + balance);
            return true;
        }
        System.out.println("Insufficient funds!");
        return false;
    }

    void displayInfo() {
        System.out.println("Account #" + accountId + " | Owner: " + owner + " | Balance: " + balance);
    }

    public static void main(String[] args) {
        BankAccount acc1 = new BankAccount("Alice", 1000.0);
        BankAccount acc2 = new BankAccount("Bob");

        acc1.displayInfo();
        acc1.deposit(500);
        acc1.withdraw(200);
        acc1.withdraw(2000);   // should fail

        acc2.displayInfo();
        acc2.deposit(750);
    }
}
```

**Output:**
```
Account #1000 | Owner: Alice | Balance: 1000.0
Deposited: 500.0 | New balance: 1500.0
Withdrawn: 200.0 | New balance: 1300.0
Insufficient funds!
Account #1001 | Owner: Bob | Balance: 0.0
Deposited: 750.0 | New balance: 750.0
```

---

### Example 2 – Method Overloading

```java
public class Printer {
    // Overloaded print methods
    void print(int value) {
        System.out.println("Integer: " + value);
    }

    void print(double value) {
        System.out.println("Double: " + value);
    }

    void print(String value) {
        System.out.println("String: " + value);
    }

    void print(int a, int b) {
        System.out.println("Two ints: " + a + " and " + b);
    }

    void print(String label, double value) {
        System.out.printf("%s: %.2f%n", label, value);
    }

    public static void main(String[] args) {
        Printer p = new Printer();
        p.print(42);
        p.print(3.14);
        p.print("Hello");
        p.print(10, 20);
        p.print("Price", 19.99);
    }
}
```

**Output:**
```
Integer: 42
Double: 3.14
String: Hello
Two ints: 10 and 20
Price: 19.99
```

---

### Example 3 – Constructor Overloading

```java
public class Rectangle {
    double width;
    double height;
    String color;

    // Default
    Rectangle() {
        this(1.0, 1.0, "White");
    }

    // Square
    Rectangle(double side) {
        this(side, side, "White");
    }

    // Full
    Rectangle(double width, double height, String color) {
        this.width = width;
        this.height = height;
        this.color = color;
    }

    // Copy
    Rectangle(Rectangle r) {
        this(r.width, r.height, r.color);
    }

    double area()      { return width * height; }
    double perimeter() { return 2 * (width + height); }

    @Override
    public String toString() {
        return color + " rectangle " + width + "x" + height
             + " | Area=" + area() + " | Perimeter=" + perimeter();
    }

    public static void main(String[] args) {
        System.out.println(new Rectangle());
        System.out.println(new Rectangle(5.0));
        System.out.println(new Rectangle(4.0, 6.0, "Blue"));
        Rectangle r = new Rectangle(3.0, 3.0, "Red");
        System.out.println(new Rectangle(r));   // copy
    }
}
```

**Output:**
```
White rectangle 1.0x1.0 | Area=1.0 | Perimeter=4.0
White rectangle 5.0x5.0 | Area=25.0 | Perimeter=20.0
Blue rectangle 4.0x6.0 | Area=24.0 | Perimeter=20.0
Red rectangle 3.0x3.0 | Area=9.0 | Perimeter=12.0
```

---

### Example 4 – this Keyword

```java
public class Employee {
    String name;
    String department;
    double salary;

    Employee(String name, String department, double salary) {
        this.name = name;               // disambiguate field vs param
        this.department = department;
        this.salary = salary;
    }

    Employee(String name, String department) {
        this(name, department, 30000.0);  // constructor chaining
    }

    void promote(double raise) {
        salary += raise;
        printDetails(this);             // pass current object
    }

    static void printDetails(Employee e) {
        System.out.println(e.name + " | " + e.department + " | Salary: " + e.salary);
    }

    public static void main(String[] args) {
        Employee e1 = new Employee("Priya", "Engineering", 60000);
        Employee e2 = new Employee("Arjun", "Marketing");  // default salary

        printDetails(e1);
        printDetails(e2);

        e1.promote(10000);
    }
}
```

**Output:**
```
Priya | Engineering | Salary: 60000.0
Arjun | Marketing | Salary: 30000.0
Priya | Engineering | Salary: 70000.0
```

---

## 📝 Summary

- A **class** is a blueprint; an **object** is an instance created from that blueprint with `new`.
- **Constructors** initialize objects; they have no return type and the same name as the class.
- **`this`** refers to the current object — useful for disambiguation and constructor chaining.
- **Method overloading** allows multiple methods with the same name but different parameter signatures.
- **Constructor overloading** provides multiple ways to create an object.
- **Initializer blocks** (`{}`) run before constructors; **static blocks** run once at class load.
- The 4 pillars of OOP: Encapsulation, Inheritance, Polymorphism, Abstraction.

---

*Previous → [02 – Arrays and Enums](./02_Arrays_Enums.md)*  
*Next → [04 – String Class](./04_String_StringBuilder.md)*
