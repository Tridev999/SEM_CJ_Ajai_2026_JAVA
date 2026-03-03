# 06 — Operators in Java

---

## 📖 Theory

An **operator** is a symbol that performs an operation on one or more values (called operands). Java has a rich set of operators organized into several categories.

---

### 1. Arithmetic Operators

Used to perform basic math operations.

| Operator | Name | Example | Result |
|---|---|---|---|
| `+` | Addition | `5 + 3` | `8` |
| `-` | Subtraction | `5 - 3` | `2` |
| `*` | Multiplication | `5 * 3` | `15` |
| `/` | Division | `10 / 3` | `3` (integer div) |
| `%` | Modulus (Remainder) | `10 % 3` | `1` |
| `++` | Increment | `x++` / `++x` | adds 1 |
| `--` | Decrement | `x--` / `--x` | subtracts 1 |

> **Note on integer division:** `10 / 3 = 3` (not 3.33). Use `10.0 / 3` or cast to get decimal result.

**Pre vs Post Increment:**
```java
int a = 5;
int b = a++;   // b = 5, then a becomes 6 (post-increment: use then add)
int c = ++a;   // a becomes 7, then c = 7 (pre-increment: add then use)
```

---

### 2. Relational (Comparison) Operators

Compare two values; always return `boolean` (`true` or `false`).

| Operator | Meaning | Example | Result |
|---|---|---|---|
| `==` | Equal to | `5 == 5` | `true` |
| `!=` | Not equal to | `5 != 3` | `true` |
| `>` | Greater than | `5 > 3` | `true` |
| `<` | Less than | `5 < 3` | `false` |
| `>=` | Greater than or equal | `5 >= 5` | `true` |
| `<=` | Less than or equal | `5 <= 3` | `false` |

---

### 3. Logical Operators

Used to combine boolean expressions.

| Operator | Name | Example | Meaning |
|---|---|---|---|
| `&&` | Logical AND | `a && b` | true if **both** are true |
| `\|\|` | Logical OR | `a \|\| b` | true if **at least one** is true |
| `!` | Logical NOT | `!a` | reverses the boolean |

**Truth Table:**

| a | b | a && b | a \|\| b | !a |
|---|---|---|---|---|
| true | true | true | true | false |
| true | false | false | true | false |
| false | true | false | true | true |
| false | false | false | false | true |

**Short-circuit evaluation:**
- `&&` – if the left side is `false`, the right side is NOT evaluated
- `||` – if the left side is `true`, the right side is NOT evaluated

---

### 4. Assignment Operators

Assign values to variables.

| Operator | Example | Equivalent To |
|---|---|---|
| `=` | `x = 5` | x = 5 |
| `+=` | `x += 3` | x = x + 3 |
| `-=` | `x -= 3` | x = x - 3 |
| `*=` | `x *= 3` | x = x * 3 |
| `/=` | `x /= 3` | x = x / 3 |
| `%=` | `x %= 3` | x = x % 3 |

---

### 5. Bitwise Operators

Operate on individual bits of integer values.

| Operator | Name | Example | Result (binary) |
|---|---|---|---|
| `&` | Bitwise AND | `5 & 3` | `1` (0101 & 0011 = 0001) |
| `\|` | Bitwise OR | `5 \| 3` | `7` (0101 \| 0011 = 0111) |
| `^` | Bitwise XOR | `5 ^ 3` | `6` (0101 ^ 0011 = 0110) |
| `~` | Bitwise NOT | `~5` | `-6` |
| `<<` | Left shift | `5 << 1` | `10` (multiply by 2) |
| `>>` | Right shift | `10 >> 1` | `5` (divide by 2) |
| `>>>` | Unsigned right shift | `-1 >>> 28` | `15` |

---

### 6. Unary Operators

Operate on a single operand.

| Operator | Description | Example |
|---|---|---|
| `+` | Unary plus (positive value) | `+5` |
| `-` | Unary minus (negate value) | `-5` |
| `++` | Increment | `++x` or `x++` |
| `--` | Decrement | `--x` or `x--` |
| `!` | Logical NOT | `!true` → `false` |

---

### 7. Ternary Operator

A shorthand for `if-else`. Works with 3 operands.

**Syntax:**
```java
condition ? valueIfTrue : valueIfFalse
```

```java
int age = 20;
String status = (age >= 18) ? "Adult" : "Minor";
// equivalent to:
// if (age >= 18) status = "Adult";
// else status = "Minor";
```

---

### Operator Precedence (High → Low)

| Level | Operators |
|---|---|
| 1 (highest) | `()`, `[]`, `.` |
| 2 | `++`, `--` (postfix) |
| 3 | `++`, `--` (prefix), `+`, `-` (unary), `~`, `!` |
| 4 | `*`, `/`, `%` |
| 5 | `+`, `-` |
| 6 | `<<`, `>>`, `>>>` |
| 7 | `<`, `<=`, `>`, `>=` |
| 8 | `==`, `!=` |
| 9 | `&` |
| 10 | `^` |
| 11 | `\|` |
| 12 | `&&` |
| 13 | `\|\|` |
| 14 | `?:` (ternary) |
| 15 (lowest) | `=`, `+=`, `-=`, etc. |

> **Tip:** Use parentheses `()` to make your intent clear and override default precedence.

---

## 🧪 Practice Questions

1. What is the difference between `x++` and `++x`?
2. What is the output of `10 / 3` in Java? How do you get the floating-point result?
3. What does the `%` operator do? Give a real-world use case.
4. What is short-circuit evaluation in `&&` and `||`?
5. Simplify using the ternary operator: `if (score >= 50) result = "Pass"; else result = "Fail";`
6. What is the result of `5 & 3`? Show the bitwise calculation.
7. What is operator precedence? What is the result of `2 + 3 * 4`?
8. Rewrite `x = x + 5` using a compound assignment operator.

---

## 💻 Examples

### Example 1 – Arithmetic Operators

```java
public class ArithmeticDemo {
    public static void main(String[] args) {
        int a = 10, b = 3;

        System.out.println("a + b = " + (a + b));    // 13
        System.out.println("a - b = " + (a - b));    // 7
        System.out.println("a * b = " + (a * b));    // 30
        System.out.println("a / b = " + (a / b));    // 3  (integer division!)
        System.out.println("a % b = " + (a % b));    // 1

        // Float division
        double result = (double) a / b;
        System.out.println("a / b (float) = " + result);   // 3.3333...

        // Pre vs post increment
        int x = 5;
        System.out.println("x++: " + x++);   // prints 5, then x becomes 6
        System.out.println("After: " + x);   // 6
        System.out.println("++x: " + ++x);   // x becomes 7, prints 7
    }
}
```

**Output:**
```
a + b = 13
a - b = 7
a * b = 30
a / b = 3
a % b = 1
a / b (float) = 3.3333333333333335
x++: 5
After: 6
++x: 7
```

---

### Example 2 – Relational and Logical Operators

```java
public class LogicalDemo {
    public static void main(String[] args) {
        int age = 20;
        boolean hasID = true;

        // Relational
        System.out.println("age > 18: " + (age > 18));     // true
        System.out.println("age == 20: " + (age == 20));   // true
        System.out.println("age != 25: " + (age != 25));   // true

        // Logical
        boolean canEnter = (age >= 18) && hasID;
        System.out.println("Can Enter Club: " + canEnter); // true

        boolean freeEntry = (age < 10) || (age > 60);
        System.out.println("Free Entry: " + freeEntry);    // false

        System.out.println("!hasID: " + !hasID);           // false
    }
}
```

**Output:**
```
age > 18: true
age == 20: true
age != 25: true
Can Enter Club: true
Free Entry: false
!hasID: false
```

---

### Example 3 – Assignment Operators

```java
public class AssignmentDemo {
    public static void main(String[] args) {
        int x = 10;
        System.out.println("Initial: " + x);   // 10

        x += 5;
        System.out.println("After +=5: " + x); // 15

        x -= 3;
        System.out.println("After -=3: " + x); // 12

        x *= 2;
        System.out.println("After *=2: " + x); // 24

        x /= 4;
        System.out.println("After /=4: " + x); // 6

        x %= 4;
        System.out.println("After %=4: " + x); // 2
    }
}
```

**Output:**
```
Initial: 10
After +=5: 15
After -=3: 12
After *=2: 24
After /=4: 6
After %=4: 2
```

---

### Example 4 – Ternary Operator

```java
public class TernaryDemo {
    public static void main(String[] args) {
        // Example 1: Pass/Fail
        int marks = 72;
        String result = (marks >= 50) ? "PASS" : "FAIL";
        System.out.println("Result: " + result);

        // Example 2: Even/Odd
        int num = 7;
        String parity = (num % 2 == 0) ? "Even" : "Odd";
        System.out.println(num + " is " + parity);

        // Example 3: Max of two numbers
        int a = 45, b = 78;
        int max = (a > b) ? a : b;
        System.out.println("Max: " + max);

        // Nested ternary (Grade system)
        int score = 85;
        String grade = (score >= 90) ? "A" :
                       (score >= 80) ? "B" :
                       (score >= 70) ? "C" : "F";
        System.out.println("Grade: " + grade);
    }
}
```

**Output:**
```
Result: PASS
7 is Odd
Max: 78
Grade: B
```

---

### Example 5 – Bitwise Operators

```java
public class BitwiseDemo {
    public static void main(String[] args) {
        int a = 5;  // binary: 0101
        int b = 3;  // binary: 0011

        System.out.println("a & b  = " + (a & b));    // 0001 = 1
        System.out.println("a | b  = " + (a | b));    // 0111 = 7
        System.out.println("a ^ b  = " + (a ^ b));    // 0110 = 6
        System.out.println("~a     = " + (~a));        // -6
        System.out.println("a << 1 = " + (a << 1));   // 1010 = 10 (×2)
        System.out.println("a >> 1 = " + (a >> 1));   // 0010 = 2 (÷2)
    }
}
```

**Output:**
```
a & b  = 1
a | b  = 7
a ^ b  = 6
~a     = -6
a << 1 = 10
a >> 1 = 2
```

---

## 📝 Summary

- **Arithmetic operators** (`+`, `-`, `*`, `/`, `%`) perform math; note integer division truncates decimals.
- **Relational operators** (`==`, `!=`, `>`, `<`, `>=`, `<=`) compare values and return boolean.
- **Logical operators** (`&&`, `||`, `!`) combine boolean expressions with short-circuit evaluation.
- **Assignment operators** (`+=`, `-=`, etc.) are compound shortcuts.
- **Bitwise operators** work on individual bits; `<<` multiplies by 2 and `>>` divides by 2.
- The **ternary operator** (`? :`) is a compact `if-else` for simple conditions.
- Use parentheses to control and clarify operator precedence.

---

*Previous → [05 – Wrapper Classes](./05_WrapperClasses.md)*  
*Next → [07 – Conditional Statements](./07_ConditionalStatements.md)*
