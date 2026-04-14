# 01 — Loops: for, while, do-while, and for-each

---

## 📖 Theory

**Loops** allow you to repeat a block of code multiple times without writing it repeatedly. Java has four types of loops.

---

### 1. The `for` Loop

Best used when you **know in advance** how many times to iterate.

**Syntax:**
```java
for (initialization; condition; update) {
    // body
}
```

**Execution flow:**
1. `initialization` — runs once at the start
2. `condition` — checked before each iteration; loop stops when false
3. body — executes if condition is true
4. `update` — runs after each iteration, then go to step 2

```java
for (int i = 1; i <= 5; i++) {
    System.out.println("Count: " + i);
}
```

---

### 2. The `while` Loop

Best when you **don't know** how many iterations are needed in advance — the loop runs as long as the condition is true.

**Syntax:**
```java
while (condition) {
    // body
}
```

> **Entry-controlled:** The condition is checked **before** entering the loop. If the condition is initially false, the body never executes.

```java
int n = 1;
while (n <= 5) {
    System.out.println("n = " + n);
    n++;
}
```

---

### 3. The `do-while` Loop

Similar to `while`, but the body is executed **at least once** because the condition is checked **after** the body.

**Syntax:**
```java
do {
    // body
} while (condition);
```

> **Exit-controlled:** The body runs first, then the condition is checked.

```java
int n = 1;
do {
    System.out.println("n = " + n);
    n++;
} while (n <= 5);
```

**Key difference from `while`:**
```java
// while: body may never execute
int x = 10;
while (x < 5) {
    System.out.println("while: " + x);  // never prints
}

// do-while: body executes at least once
int y = 10;
do {
    System.out.println("do-while: " + y);   // prints once!
} while (y < 5);
```

---

### 4. The `for-each` Loop (Enhanced for)

Specifically designed to iterate over **arrays** and **collections** (like `ArrayList`). Cleaner and less error-prone than traditional `for`.

**Syntax:**
```java
for (dataType element : arrayOrCollection) {
    // use element
}
```

```java
int[] numbers = {10, 20, 30, 40, 50};
for (int num : numbers) {
    System.out.println(num);
}
```

> **Limitation:** You cannot modify the array or access the index directly with for-each.

---

### Loop Control Statements

| Statement | Effect |
|---|---|
| `break` | Immediately exits the loop |
| `continue` | Skips the current iteration, goes to next |
| `return` | Exits the entire method |

```java
// break example
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;     // stops at 5
    System.out.print(i + " ");
}
// Output: 1 2 3 4

// continue example
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) continue;   // skip even numbers
    System.out.print(i + " ");
}
// Output: 1 3 5 7 9
```

---

### Comparing the Four Loops

| Loop | When to Use | Condition Checked | Min Iterations |
|---|---|---|---|
| `for` | Known count | Before | 0 |
| `while` | Unknown count | Before | 0 |
| `do-while` | At least once | After | 1 |
| `for-each` | Arrays/Collections | N/A | 0 |

---

## 🧪 Practice Questions

1. What is the difference between `while` and `do-while`?
2. Write a `for` loop to print multiples of 3 from 3 to 30.
3. What will happen if you forget to update the loop variable in a `while` loop?
4. When would you prefer a `for-each` loop over a regular `for` loop?
5. Write a loop that prints all even numbers from 1 to 20 using `continue`.
6. What is an infinite loop? Write one intentionally and explain when it might be useful.
7. Trace through: what does this print? `for(int i=0; i<5; i++) { if(i==3) break; System.out.print(i + " "); }`

---

## 💻 Examples

### Example 1 – All Four Loop Types (Same Task)

```java
public class LoopComparison {
    public static void main(String[] args) {
        System.out.print("for:       ");
        for (int i = 1; i <= 5; i++) System.out.print(i + " ");

        System.out.print("\nwhile:     ");
        int i = 1;
        while (i <= 5) { System.out.print(i + " "); i++; }

        System.out.print("\ndo-while:  ");
        int j = 1;
        do { System.out.print(j + " "); j++; } while (j <= 5);

        System.out.print("\nfor-each:  ");
        int[] arr = {1, 2, 3, 4, 5};
        for (int n : arr) System.out.print(n + " ");

        System.out.println();
    }
}
```

**Output:**
```
for:       1 2 3 4 5 
while:     1 2 3 4 5 
do-while:  1 2 3 4 5 
for-each:  1 2 3 4 5 
```

---

### Example 2 – Nested Loops (Multiplication Table)

```java
public class MultiplicationTable {
    public static void main(String[] args) {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                System.out.printf("%4d", i * j);
            }
            System.out.println();
        }
    }
}
```

**Output:**
```
   1   2   3   4   5
   2   4   6   8  10
   3   6   9  12  15
   4   8  12  16  20
   5  10  15  20  25
```

---

### Example 3 – while Loop (Guess Simulation)

```java
public class NumberGuess {
    public static void main(String[] args) {
        int secret = 7;
        int guess = 1;

        while (guess != secret) {
            System.out.println("Guessing: " + guess + " ... wrong!");
            guess++;
        }
        System.out.println("Guessing: " + guess + " ... CORRECT!");
    }
}
```

**Output:**
```
Guessing: 1 ... wrong!
Guessing: 2 ... wrong!
...
Guessing: 6 ... wrong!
Guessing: 7 ... CORRECT!
```

---

### Example 4 – do-while (Menu System)

```java
public class MenuDemo {
    public static void main(String[] args) {
        int choice;
        // Simulating a menu — in real use you'd read from Scanner
        int[] simulatedChoices = {1, 2, 4};
        int index = 0;

        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Add");
            System.out.println("2. Subtract");
            System.out.println("3. Multiply");
            System.out.println("4. Exit");

            choice = simulatedChoices[index++];
            System.out.println("Choice entered: " + choice);

            switch (choice) {
                case 1: System.out.println("Performing addition..."); break;
                case 2: System.out.println("Performing subtraction..."); break;
                case 3: System.out.println("Performing multiplication..."); break;
                case 4: System.out.println("Goodbye!"); break;
                default: System.out.println("Invalid choice!");
            }
        } while (choice != 4);
    }
}
```

**Output:**
```
--- MENU ---
Choice entered: 1
Performing addition...

--- MENU ---
Choice entered: 2
Performing subtraction...

--- MENU ---
Choice entered: 4
Goodbye!
```

---

### Example 5 – for-each with ArrayList

```java
import java.util.ArrayList;

public class ForEachDemo {
    public static void main(String[] args) {
        ArrayList<String> fruits = new ArrayList<>();
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");
        fruits.add("Mango");

        System.out.println("Fruits list:");
        for (String fruit : fruits) {
            System.out.println("  - " + fruit);
        }

        // Sum example
        int[] marks = {85, 92, 78, 90, 88};
        int total = 0;
        for (int mark : marks) {
            total += mark;
        }
        System.out.println("\nTotal marks: " + total);
        System.out.println("Average: " + (double) total / marks.length);
    }
}
```

**Output:**
```
Fruits list:
  - Apple
  - Banana
  - Cherry
  - Mango

Total marks: 433
Average: 86.6
```

---

### Example 6 – Star Pattern (Nested Loops)

```java
public class StarPattern {
    public static void main(String[] args) {
        int rows = 5;

        // Right triangle
        System.out.println("Right Triangle:");
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }

        // Inverted triangle
        System.out.println("\nInverted Triangle:");
        for (int i = rows; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
```

**Output:**
```
Right Triangle:
* 
* * 
* * * 
* * * * 
* * * * * 

Inverted Triangle:
* * * * * 
* * * * 
* * * 
* * 
* 
```

---

## 📝 Summary

- **`for` loop** — best when iteration count is known; compact syntax with init, condition, update.
- **`while` loop** — best when condition-driven; condition checked before each iteration (may run 0 times).
- **`do-while` loop** — guaranteed to run at least once; condition checked after body.
- **`for-each` loop** — cleanest way to iterate arrays and collections; no index needed.
- `break` exits a loop immediately; `continue` skips the current iteration.
- Nested loops enable patterns, tables, and multi-dimensional data processing.

---

*Previous → [Unit 1 – Conditional Statements](../Unit1/07_ConditionalStatements.md)*  
*Next → [02 – Arrays and Enums](./02_Arrays_Enums.md)*
