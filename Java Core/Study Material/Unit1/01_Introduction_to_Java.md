# 01 — Introduction to Java: History, Features & Program Structure

---

## 📖 Theory

### A Brief History of Java

Java was created by **James Gosling** and his team at **Sun Microsystems** in **1991**, originally under the project name "Oak." It was designed for consumer electronics but gained enormous traction when the World Wide Web took off. Java 1.0 was officially released in **1996**. Sun Microsystems was later acquired by **Oracle Corporation** in 2010, which continues to maintain Java today.

Key milestones:
- **1991** – Project Oak begins at Sun Microsystems
- **1995** – Java officially announced; applets revolutionize the web
- **1996** – JDK 1.0 released
- **2004** – Java 5 (Tiger) introduces generics, annotations, enums
- **2014** – Java 8 introduces lambdas and streams
- **2021** – Java 17 (LTS) released
- **2023** – Java 21 (LTS) released

---

### Features of Java

Java is famous for its rich set of features that make it a versatile, robust, and widely-used programming language.

| Feature | Description |
|---|---|
| **Simple** | Java is easy to learn. Its syntax is clean and based on C/C++, with complex features (like pointers) removed. |
| **Object-Oriented** | Everything in Java is treated as an object. It supports encapsulation, inheritance, and polymorphism. |
| **Platform Independent** | Java code is compiled to **bytecode**, which runs on any machine with a JVM — "Write Once, Run Anywhere." |
| **Secure** | Java has a robust security model: no explicit pointers, bytecode verification, and a Security Manager. |
| **Robust** | Strong type-checking, exception handling, and garbage collection make Java reliable. |
| **Multithreaded** | Java supports concurrent programming via built-in thread support. |
| **High Performance** | Just-In-Time (JIT) compilation brings Java close to native performance. |
| **Distributed** | Java is designed with network connectivity in mind (java.net, RMI). |
| **Dynamic** | Java can load classes at runtime. |

---

### Java Program Structure

Every Java program follows this fundamental structure:

```
package declaration      (optional)
import statements        (optional)
class declaration        (required)
    main method          (required for standalone programs)
        statements
```

**Anatomy of the simplest Java program:**

```java
// This is the HelloWorld class
public class HelloWorld {

    // The main method — entry point of every Java application
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

**Breaking it down:**

| Part | Meaning |
|---|---|
| `public` | Access modifier — visible to everyone |
| `class HelloWorld` | Declares a class named HelloWorld |
| `public static void main` | The method JVM looks for to start execution |
| `String[] args` | Array of command-line arguments |
| `System.out.println(...)` | Prints a line to the console |

> **Rule:** The filename must match the public class name. So `HelloWorld` must be saved as `HelloWorld.java`.

---

### Writing a Simple Java Class

A **class** is the blueprint for objects. It can contain:
- **Fields** (data / attributes)
- **Methods** (behaviour / functions)
- **Constructors** (used to create objects)

```java
public class Student {
    // Fields (attributes)
    String name;
    int age;

    // Method (behaviour)
    void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}
```

---

## 🧪 Practice Questions

1. What does "platform independence" mean in Java? How does the JVM achieve it?
2. List five features of Java and give a one-line example for each.
3. What is the purpose of the `main` method? Can a Java program have more than one `main` method?
4. Why must the filename match the public class name in Java?
5. Describe the difference between Java source code (`.java`), bytecode (`.class`), and machine code.

---

## 💻 Examples

### Example 1 – Hello World

```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

**Output:**
```
Hello, World!
```

---

### Example 2 – A Class with Fields and Methods

```java
public class Car {
    String brand;
    int year;

    void showDetails() {
        System.out.println("Brand: " + brand + ", Year: " + year);
    }

    public static void main(String[] args) {
        Car myCar = new Car();      // create an object
        myCar.brand = "Toyota";
        myCar.year = 2022;
        myCar.showDetails();        // call method
    }
}
```

**Output:**
```
Brand: Toyota, Year: 2022
```

---

### Example 3 – Multiple Classes in Action

```java
class Animal {
    String name;

    void speak() {
        System.out.println(name + " makes a sound.");
    }
}

public class TestAnimal {
    public static void main(String[] args) {
        Animal dog = new Animal();
        dog.name = "Dog";
        dog.speak();

        Animal cat = new Animal();
        cat.name = "Cat";
        cat.speak();
    }
}
```

**Output:**
```
Dog makes a sound.
Cat makes a sound.
```

---

## 📝 Summary

- Java was created by James Gosling in 1991 and became one of the world's most popular languages.
- Key features include: simple, object-oriented, platform-independent, secure, and robust.
- Every Java program requires at least one class with a `main` method.
- Bytecode makes Java platform-independent — the JVM translates it to machine code on any OS.
- The public class name must match the filename.

---

*Next → [02 – Command-Line Arguments & JDK, JRE, JVM](./02_CommandLine_JDK_JRE_JVM.md)*
