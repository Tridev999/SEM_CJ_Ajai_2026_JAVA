# 02 — Command-Line Arguments & Understanding JDK, JRE, JVM

---

## 📖 Theory

### What Are Command-Line Arguments?

When you run a Java program from the terminal, you can pass extra values directly after the program name. These are called **command-line arguments**. They allow users to give input to a program *without* having to modify the source code.

In Java, command-line arguments are received as a `String` array called `args` in the `main` method:

```java
public static void main(String[] args)
```

- `args[0]` → first argument
- `args[1]` → second argument
- `args.length` → total number of arguments passed

> **Note:** Command-line arguments are always received as **Strings**. If you need numeric values, you must convert them using `Integer.parseInt()`, `Double.parseDouble()`, etc.

---

### Running a Java Program with Arguments

```
# Compile
javac Greet.java

# Run with arguments
java Greet Alice 25
```

Here `"Alice"` is `args[0]` and `"25"` is `args[1]`.

---

### Understanding JDK, JRE, and JVM

These three form the backbone of the Java ecosystem. Understanding their relationship is fundamental.

```
┌────────────────────────────────────┐
│              JDK                   │
│  ┌──────────────────────────────┐  │
│  │            JRE               │  │
│  │  ┌────────────────────────┐  │  │
│  │  │         JVM            │  │  │
│  │  └────────────────────────┘  │  │
│  │  + Java Class Libraries      │  │
│  └──────────────────────────────┘  │
│  + Compiler (javac)                │
│  + Debugger, javadoc, jar, etc.    │
└────────────────────────────────────┘
```

---

#### JVM — Java Virtual Machine

The **JVM** is an abstract computing machine. It:
- Reads `.class` (bytecode) files
- Interprets or JIT-compiles them into native machine code
- Manages memory (heap, stack, garbage collection)
- Provides platform independence — each OS has its own JVM implementation

**The JVM is platform-specific** (different JVM for Windows, Linux, macOS), but bytecode is the same everywhere.

---

#### JRE — Java Runtime Environment

The **JRE** is what you need to *run* Java programs. It contains:
- The **JVM**
- **Java Class Libraries** (the standard API: `java.lang`, `java.util`, `java.io`, etc.)
- Supporting files

> If you only want to *run* Java applications (not develop them), install the JRE.

---

#### JDK — Java Development Kit

The **JDK** is what developers need to *write and compile* Java programs. It contains:
- The **JRE** (everything above)
- **javac** – the Java compiler (converts `.java` to `.class`)
- **javadoc** – documentation generator
- **jar** – archive tool (bundles `.class` files into `.jar`)
- **jdb** – Java debugger
- Other developer utilities

> If you are *developing* Java applications, install the JDK.

---

#### Summary Table

| | JVM | JRE | JDK |
|---|---|---|---|
| Run Java programs | ✅ | ✅ | ✅ |
| Java Class Libraries | ❌ | ✅ | ✅ |
| Compiler (javac) | ❌ | ❌ | ✅ |
| Debugger & tools | ❌ | ❌ | ✅ |

---

### How Java Code Gets Executed

```
Step 1: Write code         HelloWorld.java   (Source code)
         ↓
Step 2: Compile (javac)    HelloWorld.class  (Bytecode)
         ↓
Step 3: Run (java)         JVM loads .class file
         ↓
Step 4: JVM executes       JIT compiles to native machine code
         ↓
Step 5: Output             Result shown on screen
```

---

## 🧪 Practice Questions

1. What is the difference between JVM, JRE, and JDK? Which one do you need to only run Java programs?
2. How many command-line arguments can be passed to a Java program?
3. If a user passes `java Calculator 10 20`, what are `args[0]` and `args[1]`?
4. Why are command-line arguments always of type `String`? How would you use them as integers?
5. What does the `javac` command do? What file does it produce?
6. Explain what happens step-by-step when you execute `java HelloWorld` in the terminal.

---

## 💻 Examples

### Example 1 – Simple Command-Line Argument

```java
public class Greet {
    public static void main(String[] args) {
        if (args.length > 0) {
            System.out.println("Hello, " + args[0] + "!");
        } else {
            System.out.println("Hello, Stranger!");
        }
    }
}
```

**Run:**
```
java Greet Alice
```
**Output:**
```
Hello, Alice!
```

---

### Example 2 – Multiple Arguments

```java
public class StudentInfo {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: java StudentInfo <name> <age>");
            return;
        }
        String name = args[0];
        int age = Integer.parseInt(args[1]);  // convert String to int
        System.out.println("Student Name: " + name);
        System.out.println("Student Age: " + age);
    }
}
```

**Run:**
```
java StudentInfo Priya 20
```
**Output:**
```
Student Name: Priya
Student Age: 20
```

---

### Example 3 – Calculator Using Command-Line Arguments

```java
public class Calculator {
    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("Usage: java Calculator <num1> <operator> <num2>");
            return;
        }

        double a = Double.parseDouble(args[0]);
        String op = args[1];
        double b = Double.parseDouble(args[2]);

        double result = 0;

        switch (op) {
            case "+": result = a + b; break;
            case "-": result = a - b; break;
            case "*": result = a * b; break;
            case "/":
                if (b != 0) result = a / b;
                else { System.out.println("Cannot divide by zero!"); return; }
                break;
            default:
                System.out.println("Unknown operator: " + op);
                return;
        }

        System.out.println(a + " " + op + " " + b + " = " + result);
    }
}
```

**Run:**
```
java Calculator 15 + 5
```
**Output:**
```
15.0 + 5.0 = 20.0
```

---

### Example 4 – Printing All Arguments

```java
public class PrintArgs {
    public static void main(String[] args) {
        System.out.println("Total arguments: " + args.length);
        for (int i = 0; i < args.length; i++) {
            System.out.println("args[" + i + "] = " + args[i]);
        }
    }
}
```

**Run:**
```
java PrintArgs Java is fun
```
**Output:**
```
Total arguments: 3
args[0] = Java
args[1] = is
args[2] = fun
```

---

## 📝 Summary

- **Command-line arguments** let you pass input to Java programs at runtime via `String[] args`.
- Always convert string arguments to numeric types using `Integer.parseInt()` or `Double.parseDouble()`.
- The **JVM** executes bytecode and provides platform independence.
- The **JRE** = JVM + standard class libraries (needed to run Java).
- The **JDK** = JRE + development tools like `javac` (needed to develop Java).
- Java code flows: `.java` → compile with `javac` → `.class` (bytecode) → run with `java` → JVM executes.

---

*Previous → [01 – Introduction to Java](./01_Introduction_to_Java.md)*  
*Next → [03 – Primitive Data Types & Type Conversion](./03_DataTypes_TypeConversion.md)*
