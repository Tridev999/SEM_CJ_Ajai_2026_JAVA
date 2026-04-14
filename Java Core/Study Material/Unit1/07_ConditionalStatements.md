# 07 — Conditional Statements: if/else & switch-case

---

## 📖 Theory

**Conditional statements** allow a program to make decisions and execute different blocks of code based on whether a condition is true or false. They control the **flow** of program execution.

---

### The `if` Statement

Executes a block of code only when the condition is `true`.

**Syntax:**
```java
if (condition) {
    // code to run if condition is true
}
```

```java
int age = 20;
if (age >= 18) {
    System.out.println("You are an adult.");
}
```

---

### The `if-else` Statement

Provides an alternative block to run when the condition is `false`.

**Syntax:**
```java
if (condition) {
    // runs if condition is true
} else {
    // runs if condition is false
}
```

```java
int marks = 45;
if (marks >= 50) {
    System.out.println("Pass");
} else {
    System.out.println("Fail");
}
```

---

### The `if-else if-else` (Ladder)

Tests multiple conditions in sequence.

**Syntax:**
```java
if (condition1) {
    // block 1
} else if (condition2) {
    // block 2
} else if (condition3) {
    // block 3
} else {
    // default block
}
```

```java
int score = 82;
if (score >= 90) {
    System.out.println("Grade: A");
} else if (score >= 80) {
    System.out.println("Grade: B");
} else if (score >= 70) {
    System.out.println("Grade: C");
} else {
    System.out.println("Grade: F");
}
```

---

### Nested `if`

An `if` statement inside another `if` statement.

```java
int age = 25;
boolean hasLicense = true;

if (age >= 18) {
    if (hasLicense) {
        System.out.println("You can drive.");
    } else {
        System.out.println("You need a license.");
    }
} else {
    System.out.println("You are too young to drive.");
}
```

---

### The `switch` Statement

An efficient alternative to `if-else if` when you need to compare one variable against multiple **constant** values. It is particularly clean when you have many fixed choices.

**Syntax:**
```java
switch (expression) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    // ...
    default:
        // code if no case matches
}
```

> **`break`** is crucial! Without it, execution "falls through" to the next case.

**What can be used in switch:**
- `int`, `byte`, `short`, `char`
- `String` (since Java 7)
- `enum` types

**What CANNOT be used:**
- `long`, `float`, `double`, `boolean`

---

### Fall-through Behavior

When `break` is omitted, execution continues to the next case:

```java
int day = 2;
switch (day) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        System.out.println("Weekday");
        break;
    case 6:
    case 7:
        System.out.println("Weekend");
        break;
    default:
        System.out.println("Invalid");
}
```

Here cases 1–5 all fall through to the same `println`.

---

### Switch Expression (Java 14+)

Modern Java introduced a cleaner switch syntax:

```java
// Traditional switch statement
String result;
switch (day) {
    case 1: result = "Monday"; break;
    case 2: result = "Tuesday"; break;
    default: result = "Other";
}

// Switch expression (concise, no fall-through issues)
String result = switch (day) {
    case 1 -> "Monday";
    case 2 -> "Tuesday";
    default -> "Other";
};
```

---

### `if-else` vs `switch` — When to Use Which

| Situation | Prefer |
|---|---|
| Range comparisons (`> 90`, `< 50`) | `if-else` |
| Boolean conditions | `if-else` |
| Exact match against multiple fixed values | `switch` |
| Menu selection (1, 2, 3...) | `switch` |

---

## 🧪 Practice Questions

1. What is the difference between `if` and `switch`? When would you prefer `switch`?
2. What happens if you forget the `break` statement in a switch case?
3. Write an `if-else if` ladder to assign grades: A (≥90), B (≥80), C (≥70), D (≥60), F (otherwise).
4. Can `switch` work with a `double` or `float`? Why or why not?
5. What does the `default` case in a switch do?
6. Rewrite this using a ternary operator: `if (x > 0) sign = "positive"; else sign = "non-positive";`
7. Write a program that takes a number 1-7 and prints the corresponding day of the week.

---

## 💻 Examples

### Example 1 – Simple if-else

```java
public class VotingCheck {
    public static void main(String[] args) {
        int age = 17;

        if (age >= 18) {
            System.out.println("You are eligible to vote.");
        } else {
            System.out.println("You are not eligible to vote yet.");
            System.out.println("You need " + (18 - age) + " more year(s).");
        }
    }
}
```

**Output:**
```
You are not eligible to vote yet.
You need 1 more year(s).
```

---

### Example 2 – if-else if Ladder (Grade System)

```java
public class GradeCalculator {
    public static void main(String[] args) {
        int marks = 73;

        String grade;
        if (marks >= 90) {
            grade = "A (Outstanding)";
        } else if (marks >= 80) {
            grade = "B (Excellent)";
        } else if (marks >= 70) {
            grade = "C (Good)";
        } else if (marks >= 60) {
            grade = "D (Average)";
        } else if (marks >= 50) {
            grade = "E (Pass)";
        } else {
            grade = "F (Fail)";
        }

        System.out.println("Marks: " + marks);
        System.out.println("Grade: " + grade);
    }
}
```

**Output:**
```
Marks: 73
Grade: C (Good)
```

---

### Example 3 – switch with Numbers (Day of Week)

```java
public class DayOfWeek {
    public static void main(String[] args) {
        int day = 4;
        String dayName;

        switch (day) {
            case 1: dayName = "Monday"; break;
            case 2: dayName = "Tuesday"; break;
            case 3: dayName = "Wednesday"; break;
            case 4: dayName = "Thursday"; break;
            case 5: dayName = "Friday"; break;
            case 6: dayName = "Saturday"; break;
            case 7: dayName = "Sunday"; break;
            default: dayName = "Invalid day";
        }

        System.out.println("Day " + day + " is: " + dayName);
    }
}
```

**Output:**
```
Day 4 is: Thursday
```

---

### Example 4 – switch with String

```java
public class SeasonChecker {
    public static void main(String[] args) {
        String month = "July";
        String season;

        switch (month) {
            case "December":
            case "January":
            case "February":
                season = "Winter";
                break;
            case "March":
            case "April":
            case "May":
                season = "Spring";
                break;
            case "June":
            case "July":
            case "August":
                season = "Summer";
                break;
            case "September":
            case "October":
            case "November":
                season = "Autumn";
                break;
            default:
                season = "Unknown";
        }

        System.out.println(month + " is in " + season);
    }
}
```

**Output:**
```
July is in Summer
```

---

### Example 5 – Calculator Using switch

```java
import java.util.Scanner;

public class SimpleCalculator {
    public static void main(String[] args) {
        double a = 15.0, b = 4.0;
        char operator = '+';

        double result;
        boolean valid = true;

        switch (operator) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b != 0) {
                    result = a / b;
                } else {
                    System.out.println("Error: Division by zero!");
                    return;
                }
                break;
            default:
                System.out.println("Unknown operator!");
                return;
        }

        // This is needed because Java may think result is uninitialized
        // In real code, use a local var or assign default above
        // For clarity here:
        System.out.printf("%.1f %c %.1f = %.2f%n", a, operator, b, a + b);
    }
}
```

**Output:**
```
15.0 + 4.0 = 19.00
```

---

### Example 6 – Nested if (Login System)

```java
public class LoginSystem {
    public static void main(String[] args) {
        String username = "admin";
        String password = "pass123";
        boolean isActive = true;

        if (username.equals("admin")) {
            if (password.equals("pass123")) {
                if (isActive) {
                    System.out.println("Login successful! Welcome, " + username);
                } else {
                    System.out.println("Account is inactive. Contact support.");
                }
            } else {
                System.out.println("Incorrect password.");
            }
        } else {
            System.out.println("Username not found.");
        }
    }
}
```

**Output:**
```
Login successful! Welcome, admin
```

---

## 📝 Summary

- **`if`** executes a block when the condition is true.
- **`if-else`** provides an alternative path when the condition is false.
- **`if-else if`** ladder tests multiple conditions in order — first true condition wins.
- **`switch`** efficiently matches a single variable against multiple constant values.
- Always use `break` in switch cases unless intentional fall-through is needed.
- `switch` works with `int`, `char`, `String`, and `enum` but NOT with `double`, `float`, or `long`.
- Use `if-else` for range/boolean checks; use `switch` for exact value matching.

---

*Previous → [06 – Operators in Java](./06_Operators.md)*  
*Next → [Unit 2 – Loops](../Unit2/01_Loops.md)*
