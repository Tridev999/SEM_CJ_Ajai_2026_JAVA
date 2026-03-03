# 05 — Wrapper Classes

---

## 📖 Theory

### What Are Wrapper Classes?

In Java, **primitive types** (`int`, `double`, `char`, etc.) are not objects. However, Java's Collections Framework (like `ArrayList`, `HashMap`) and many APIs work **only with objects**. This is where **Wrapper Classes** come in.

A **Wrapper Class** wraps (encapsulates) a primitive value inside an object, giving it object-like behavior and utility methods.

| Primitive | Wrapper Class |
|---|---|
| `byte` | `Byte` |
| `short` | `Short` |
| `int` | `Integer` |
| `long` | `Long` |
| `float` | `Float` |
| `double` | `Double` |
| `char` | `Character` |
| `boolean` | `Boolean` |

All wrapper classes are in the `java.lang` package (imported automatically).

---

### Autoboxing and Unboxing

Before Java 5, you had to manually convert between primitives and wrapper objects. Java 5 introduced **autoboxing** and **unboxing** to do this automatically.

#### Autoboxing (Primitive → Object)
The automatic conversion of a primitive to its wrapper class.

```java
int num = 42;
Integer obj = num;   // autoboxing: int → Integer (automatic)
```

#### Unboxing (Object → Primitive)
The automatic conversion of a wrapper object to its primitive.

```java
Integer obj = Integer.valueOf(42);
int num = obj;   // unboxing: Integer → int (automatic)
```

---

### Key Methods of Wrapper Classes

#### Integer
```java
Integer.parseInt("42")         // String → int
Integer.valueOf(42)            // int → Integer object
Integer.toString(42)           // int → String
Integer.MAX_VALUE              // 2147483647
Integer.MIN_VALUE              // -2147483648
Integer.toBinaryString(10)     // "1010"
Integer.toHexString(255)       // "ff"
Integer.toOctalString(8)       // "10"
Integer.compare(a, b)          // compare two ints
```

#### Double
```java
Double.parseDouble("3.14")     // String → double
Double.valueOf(3.14)           // double → Double
Double.isNaN(value)            // check if NaN
Double.isInfinite(value)       // check if infinite
Double.MAX_VALUE               // largest double
Double.MIN_VALUE               // smallest positive double
```

#### Character
```java
Character.isLetter('A')        // true
Character.isDigit('5')         // true
Character.isWhitespace(' ')    // true
Character.isUpperCase('A')     // true
Character.isLowerCase('a')     // true
Character.toUpperCase('a')     // 'A'
Character.toLowerCase('A')     // 'a'
```

#### Boolean
```java
Boolean.parseBoolean("true")   // true
Boolean.parseBoolean("false")  // false
Boolean.parseBoolean("yes")    // false (only "true" returns true)
```

---

### Wrapper Classes and Collections

Primitive types cannot be stored in collections; you must use wrapper classes:

```java
// This works:
ArrayList<Integer> list = new ArrayList<>();
list.add(10);   // autoboxing: 10 → Integer(10)
int val = list.get(0);  // unboxing: Integer(10) → 10

// This does NOT work:
// ArrayList<int> list2 = new ArrayList<>();  // COMPILE ERROR
```

---

### Important Note: == vs .equals() for Wrapper Objects

When comparing wrapper objects, use `.equals()` instead of `==` (which compares references).

```java
Integer a = 500;
Integer b = 500;
System.out.println(a == b);       // false (different objects)
System.out.println(a.equals(b));  // true (same value)

// Exception: Java caches Integer values from -128 to 127
Integer x = 100;
Integer y = 100;
System.out.println(x == y);   // true (cached)
```

---

## 🧪 Practice Questions

1. Why do we need Wrapper classes in Java?
2. What is autoboxing? Give an example where it happens automatically.
3. What does `Integer.parseInt("123")` return? What does `Integer.valueOf(123)` return? What is the difference?
4. What will `Boolean.parseBoolean("YES")` return? Why?
5. Why can't you use `ArrayList<int>` but you can use `ArrayList<Integer>`?
6. What is the danger of using `==` to compare two `Integer` objects?
7. Convert the integer `255` to its binary, hexadecimal, and octal string representations.

---

## 💻 Examples

### Example 1 – Basic Wrapper Usage

```java
public class WrapperBasics {
    public static void main(String[] args) {
        // Creating wrapper objects
        Integer intObj = Integer.valueOf(42);
        Double dblObj = Double.valueOf(3.14);
        Character charObj = Character.valueOf('J');
        Boolean boolObj = Boolean.valueOf(true);

        System.out.println("Integer: " + intObj);
        System.out.println("Double: " + dblObj);
        System.out.println("Character: " + charObj);
        System.out.println("Boolean: " + boolObj);

        // Useful constants
        System.out.println("Max int: " + Integer.MAX_VALUE);
        System.out.println("Min int: " + Integer.MIN_VALUE);
        System.out.println("Max double: " + Double.MAX_VALUE);
    }
}
```

**Output:**
```
Integer: 42
Double: 3.14
Character: J
Boolean: true
Max int: 2147483647
Min int: -2147483648
Max double: 1.7976931348623157E308
```

---

### Example 2 – Autoboxing and Unboxing

```java
public class AutoboxingDemo {
    public static void main(String[] args) {
        // Autoboxing
        int primitive = 99;
        Integer wrapped = primitive;      // automatic: int → Integer
        System.out.println("Autoboxed: " + wrapped);

        // Unboxing
        Integer obj = Integer.valueOf(50);
        int unboxed = obj;               // automatic: Integer → int
        System.out.println("Unboxed: " + unboxed);

        // Works in arithmetic too
        Integer a = 10;
        Integer b = 20;
        int sum = a + b;   // both unboxed, then added
        System.out.println("Sum: " + sum);
    }
}
```

**Output:**
```
Autoboxed: 99
Unboxed: 50
Sum: 30
```

---

### Example 3 – String Parsing with Wrapper Classes

```java
public class ParseDemo {
    public static void main(String[] args) {
        String ageStr = "25";
        String salaryStr = "75000.50";
        String activeStr = "true";

        int age = Integer.parseInt(ageStr);
        double salary = Double.parseDouble(salaryStr);
        boolean active = Boolean.parseBoolean(activeStr);

        System.out.println("Age: " + age + " (type: int)");
        System.out.println("Salary: " + salary + " (type: double)");
        System.out.println("Active: " + active + " (type: boolean)");

        // Increase age by 5
        age += 5;
        System.out.println("Age in 5 years: " + age);
    }
}
```

**Output:**
```
Age: 25 (type: int)
Salary: 75000.5 (type: double)
Active: true (type: boolean)
Age in 5 years: 30
```

---

### Example 4 – Character Utility Methods

```java
public class CharacterDemo {
    public static void main(String[] args) {
        char[] testChars = {'A', 'z', '5', ' ', '@'};

        for (char c : testChars) {
            System.out.println("'" + c + "' ->"
                + " Letter: " + Character.isLetter(c)
                + " | Digit: " + Character.isDigit(c)
                + " | Upper: " + Character.isUpperCase(c)
                + " | Lower: " + Character.isLowerCase(c));
        }

        System.out.println("\nToUpperCase('z'): " + Character.toUpperCase('z'));
        System.out.println("toLowerCase('A'): " + Character.toLowerCase('A'));
    }
}
```

**Output:**
```
'A' -> Letter: true | Digit: false | Upper: true | Lower: false
'z' -> Letter: true | Digit: false | Upper: false | Lower: true
'5' -> Letter: false | Digit: true | Upper: false | Lower: false
' ' -> Letter: false | Digit: false | Upper: false | Lower: false
'@' -> Letter: false | Digit: false | Upper: false | Lower: false

ToUpperCase('z'): Z
toLowerCase('A'): a
```

---

### Example 5 – Wrapper Classes with ArrayList

```java
import java.util.ArrayList;

public class WrapperCollection {
    public static void main(String[] args) {
        ArrayList<Integer> scores = new ArrayList<>();

        // Autoboxing: int literals → Integer objects
        scores.add(85);
        scores.add(92);
        scores.add(78);
        scores.add(95);

        int total = 0;
        for (int score : scores) {   // unboxing happens here
            total += score;
        }

        double average = (double) total / scores.size();
        System.out.println("Scores: " + scores);
        System.out.println("Total: " + total);
        System.out.println("Average: " + average);
    }
}
```

**Output:**
```
Scores: [85, 92, 78, 95]
Total: 350
Average: 87.5
```

---

### Example 6 – Number System Conversion

```java
public class NumberSystems {
    public static void main(String[] args) {
        int num = 255;

        System.out.println("Decimal: " + num);
        System.out.println("Binary: " + Integer.toBinaryString(num));
        System.out.println("Octal: " + Integer.toOctalString(num));
        System.out.println("Hex: " + Integer.toHexString(num));

        // Parse different bases
        int fromBinary = Integer.parseInt("11111111", 2);   // 255
        int fromHex = Integer.parseInt("ff", 16);            // 255
        System.out.println("From binary '11111111': " + fromBinary);
        System.out.println("From hex 'ff': " + fromHex);
    }
}
```

**Output:**
```
Decimal: 255
Binary: 11111111
Octal: 377
Hex: ff
From binary '11111111': 255
From hex 'ff': 255
```

---

## 📝 Summary

- **Wrapper classes** wrap primitive types as objects, enabling them to be used with collections and APIs.
- Each primitive has a corresponding wrapper: `int` → `Integer`, `double` → `Double`, `char` → `Character`, etc.
- **Autoboxing** converts primitive → wrapper automatically; **unboxing** does the reverse.
- Wrapper classes provide useful utility methods like `parseInt()`, `valueOf()`, `toBinaryString()`, `isDigit()`, etc.
- Always use `.equals()` to compare wrapper objects, not `==`.

---

*Previous → [04 – Keywords, Identifiers, Variables & Access Modifiers](./04_Keywords_Identifiers_Variables.md)*  
*Next → [06 – Operators in Java](./06_Operators.md)*
