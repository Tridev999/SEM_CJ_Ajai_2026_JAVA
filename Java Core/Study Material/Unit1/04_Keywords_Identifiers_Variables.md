# 04 — Keywords, Identifiers, Variables & Access Modifiers

---

## 📖 Theory

### Keywords

**Keywords** (also called reserved words) are predefined words in Java that have a specific meaning and purpose. You **cannot** use them as names for variables, classes, or methods.

Java has **53 reserved keywords** (as of Java 17):

```
abstract    assert      boolean     break       byte
case        catch       char        class       const*
continue    default     do          double      else
enum        extends     final       finally     float
for         goto*       if          implements  import
instanceof  int         interface   long        native
new         null**      package     private     protected
public      return      short       static      strictfp
super       switch      synchronized this        throw
throws      transient   try         var***      void
volatile    while
```

> `*` reserved but not used  
> `**` technically a literal, not a keyword  
> `***` introduced in Java 10

---

### Identifiers

**Identifiers** are names you give to classes, methods, variables, and other elements in your program.

#### Rules for Valid Identifiers:
1. Must begin with a **letter** (a-z, A-Z), an **underscore** (`_`), or a **dollar sign** (`$`)
2. Can be followed by letters, digits (0-9), underscores, or dollar signs
3. **Cannot** be a Java keyword
4. **Case-sensitive** (`age` and `Age` are different identifiers)
5. No length limit (practically)

#### Valid vs Invalid Identifiers:

| Identifier | Valid? | Reason |
|---|---|---|
| `myVariable` | ✅ | Standard camelCase |
| `_count` | ✅ | Starts with underscore |
| `$price` | ✅ | Starts with $ |
| `student1` | ✅ | Letter + digit |
| `1student` | ❌ | Starts with digit |
| `my-var` | ❌ | Contains hyphen |
| `class` | ❌ | Reserved keyword |
| `my variable` | ❌ | Contains space |

#### Java Naming Conventions:

| Element | Convention | Example |
|---|---|---|
| Variable | camelCase | `studentAge`, `totalPrice` |
| Method | camelCase | `calculateArea()`, `getName()` |
| Class | PascalCase | `StudentRecord`, `BankAccount` |
| Constant | UPPER_SNAKE_CASE | `MAX_SIZE`, `PI` |
| Package | all lowercase | `com.company.project` |

---

### Variables

A **variable** is a named storage location in memory that holds a value. In Java, every variable must be **declared with a type** before use.

**Syntax:**
```java
dataType variableName;            // declaration
dataType variableName = value;    // declaration + initialization
```

#### Types of Variables

**1. Local Variables**
- Declared inside a method or block
- Must be initialized before use
- Only accessible within that method/block

```java
void greet() {
    String message = "Hello!";   // local variable
    System.out.println(message);
}
```

**2. Instance Variables (Non-static Fields)**
- Declared inside a class, but outside methods
- Each object gets its own copy
- Initialized to default values automatically

```java
class Person {
    String name;    // instance variable
    int age;        // instance variable
}
```

**3. Class Variables (Static Fields)**
- Declared with `static` keyword
- Shared by all objects of the class
- Only one copy exists in memory

```java
class Counter {
    static int count = 0;   // class variable
}
```

---

### Access Modifiers

Access modifiers control the **visibility** of classes, methods, and variables.

| Modifier | Same Class | Same Package | Subclass | Other Packages |
|---|---|---|---|---|
| `private` | ✅ | ❌ | ❌ | ❌ |
| *(default)* | ✅ | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ✅ | ❌ |
| `public` | ✅ | ✅ | ✅ | ✅ |

#### `private`
Most restrictive. Member is only accessible within the **same class**. Used to implement encapsulation.

```java
class BankAccount {
    private double balance;   // only accessible inside BankAccount
}
```

#### *(default / package-private)*
No keyword used. Accessible within the **same package**.

```java
class Helper {
    int value;   // package-private
}
```

#### `protected`
Accessible within the **same package** and in **subclasses** (even in other packages).

```java
class Animal {
    protected String name;
}
```

#### `public`
Least restrictive. Accessible from **anywhere**.

```java
public class Student {
    public String getName() { ... }
}
```

---

### The `static` Keyword

`static` means the member belongs to the **class**, not to any specific object.

```java
class MathHelper {
    static final double PI = 3.14159;   // static constant

    static double circleArea(double r) {  // static method
        return PI * r * r;
    }
}

// Use without creating an object:
double area = MathHelper.circleArea(5.0);
```

---

## 🧪 Practice Questions

1. List 10 Java keywords and explain the purpose of each.
2. Which of these are valid identifiers? `_value`, `2ndPlace`, `myVar`, `class`, `$total`, `student name`
3. What is the difference between a local variable and an instance variable?
4. What access modifier would you use for a bank account balance? Why?
5. What is the difference between `protected` and `public`?
6. Can a `static` method access an instance variable? Why or why not?
7. What are Java's naming conventions for classes, methods, and constants?

---

## 💻 Examples

### Example 1 – Variable Types

```java
public class VariableDemo {
    // Instance variable
    String color = "Red";

    // Class (static) variable
    static int objectCount = 0;

    public static void main(String[] args) {
        // Local variable
        int localNum = 10;
        System.out.println("Local variable: " + localNum);

        VariableDemo obj = new VariableDemo();
        System.out.println("Instance variable: " + obj.color);
        System.out.println("Static variable: " + objectCount);
    }
}
```

**Output:**
```
Local variable: 10
Instance variable: Red
Static variable: 0
```

---

### Example 2 – Access Modifiers

```java
public class Person {
    private String name;       // only this class
    protected int age;         // this class, package, subclasses
    public String city;        // everywhere

    public Person(String name, int age, String city) {
        this.name = name;
        this.age = age;
        this.city = city;
    }

    public String getName() {   // public getter for private field
        return name;
    }

    public static void main(String[] args) {
        Person p = new Person("Alice", 22, "Mumbai");
        System.out.println("Name: " + p.getName());  // via public method
        System.out.println("Age: " + p.age);         // protected, same class OK
        System.out.println("City: " + p.city);       // public
        // System.out.println(p.name);  // ERROR: name is private!
    }
}
```

**Output:**
```
Name: Alice
Age: 22
City: Mumbai
```

---

### Example 3 – Static vs Instance

```java
public class Counter {
    static int totalCreated = 0;   // shared across all objects
    int id;                         // unique per object

    Counter() {
        totalCreated++;
        id = totalCreated;
    }

    public static void main(String[] args) {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();

        System.out.println("c1 id: " + c1.id);
        System.out.println("c2 id: " + c2.id);
        System.out.println("c3 id: " + c3.id);
        System.out.println("Total created: " + Counter.totalCreated);
    }
}
```

**Output:**
```
c1 id: 1
c2 id: 2
c3 id: 3
Total created: 3
```

---

### Example 4 – Naming Conventions in Practice

```java
public class BankAccount {
    // Constants: UPPER_SNAKE_CASE
    public static final double INTEREST_RATE = 0.05;
    public static final int MAX_WITHDRAWALS = 10;

    // Instance variables: camelCase
    private String accountHolder;
    private double balance;

    // Constructor: PascalCase (same as class name)
    public BankAccount(String accountHolder, double balance) {
        this.accountHolder = accountHolder;
        this.balance = balance;
    }

    // Methods: camelCase
    public void depositAmount(double amount) {
        balance += amount;
    }

    public double getBalance() {
        return balance;
    }

    public static void main(String[] args) {
        BankAccount account = new BankAccount("Rahul", 5000.0);
        account.depositAmount(1500.0);
        System.out.println("Balance: " + account.getBalance());
        System.out.println("Interest Rate: " + BankAccount.INTEREST_RATE);
    }
}
```

**Output:**
```
Balance: 6500.0
Interest Rate: 0.05
```

---

## 📝 Summary

- **Keywords** are reserved words in Java; they cannot be used as identifiers.
- **Identifiers** must start with a letter, `_`, or `$`; they are case-sensitive and cannot be keywords.
- Java has 3 types of variables: **local** (inside methods), **instance** (per object), and **static/class** (shared).
- **Access modifiers** (`private`, default, `protected`, `public`) control visibility.
- Use `private` for sensitive data + public getters/setters for controlled access (encapsulation).
- The `static` keyword makes members belong to the class, not to objects.

---

*Previous → [03 – Primitive Data Types & Type Conversion](./03_DataTypes_TypeConversion.md)*  
*Next → [05 – Wrapper Classes](./05_WrapperClasses.md)*
