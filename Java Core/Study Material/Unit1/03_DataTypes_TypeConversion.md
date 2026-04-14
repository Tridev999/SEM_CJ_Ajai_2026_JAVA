# 03 — Data In the Cart: Primitive Data Types & Type Conversion

---

## 📖 Theory

### Primitive Data Types

Java has **8 primitive data types** — these are the most basic building blocks of data. They are not objects; they hold values directly in memory.

| Type | Size | Range | Default Value | Example |
|---|---|---|---|---|
| `byte` | 1 byte | -128 to 127 | 0 | `byte b = 100;` |
| `short` | 2 bytes | -32,768 to 32,767 | 0 | `short s = 2000;` |
| `int` | 4 bytes | -2,147,483,648 to 2,147,483,647 | 0 | `int n = 42;` |
| `long` | 8 bytes | -9.2×10¹⁸ to 9.2×10¹⁸ | 0L | `long l = 123456789L;` |
| `float` | 4 bytes | ~±3.4×10³⁸ (7 digits) | 0.0f | `float f = 3.14f;` |
| `double` | 8 bytes | ~±1.7×10³⁰⁸ (15 digits) | 0.0 | `double d = 3.14159;` |
| `char` | 2 bytes | '\u0000' to '\uffff' | '\u0000' | `char c = 'A';` |
| `boolean` | ~1 bit | true or false | false | `boolean flag = true;` |

> **Memory tip:** byte < short < int < long (integers) and float < double (decimals).

---

### Type Conversion (Type Casting)

Type conversion is the process of converting a value from one data type to another.

#### 1. Widening Conversion (Implicit / Automatic)

Converting a **smaller** type to a **larger** type. Java does this **automatically** — no data is lost.

```
byte → short → int → long → float → double
                char ↗
```

```java
int i = 100;
long l = i;     // automatic widening
double d = i;   // automatic widening
```

#### 2. Narrowing Conversion (Explicit / Manual)

Converting a **larger** type to a **smaller** type. You must **explicitly cast** it. Data may be **lost or truncated**.

```java
double d = 9.99;
int i = (int) d;   // explicit cast — i becomes 9 (decimal part lost)
```

**Syntax:** `targetType variableName = (targetType) value;`

---

#### Conversion Table

| From ↓ / To → | byte | short | int | long | float | double | char |
|---|---|---|---|---|---|---|---|
| byte | — | auto | auto | auto | auto | auto | cast |
| short | cast | — | auto | auto | auto | auto | cast |
| int | cast | cast | — | auto | auto | auto | cast |
| long | cast | cast | cast | — | auto | auto | cast |
| float | cast | cast | cast | cast | — | auto | cast |
| double | cast | cast | cast | cast | cast | — | cast |
| char | cast | auto | auto | auto | auto | auto | — |

---

### String-to-Primitive Conversion

Very common in real programs (e.g., reading user input):

| Method | Description |
|---|---|
| `Integer.parseInt("42")` | String → int |
| `Double.parseDouble("3.14")` | String → double |
| `Long.parseLong("9999999")` | String → long |
| `Boolean.parseBoolean("true")` | String → boolean |

### Primitive-to-String Conversion

```java
int n = 42;
String s = String.valueOf(n);   // "42"
String s2 = Integer.toString(n); // "42"
String s3 = "" + n;             // "42"  (string concatenation trick)
```

---

## 🧪 Practice Questions

1. List all 8 primitive types in Java with their sizes and ranges.
2. What is widening conversion? Give an example where it happens automatically.
3. What happens when you cast a `double` value of `9.99` to an `int`?
4. Why do `long` literals need the `L` suffix and `float` literals need the `f` suffix?
5. What is the difference between `float` and `double`? When would you prefer one over the other?
6. Convert the string `"100"` to an integer. What method do you use?
7. What will be the output of: `int i = (int) 'A';` ? Why?

---

## 💻 Examples

### Example 1 – All Primitive Types in Action

```java
public class PrimitiveTypes {
    public static void main(String[] args) {
        byte myByte = 100;
        short myShort = 5000;
        int myInt = 100000;
        long myLong = 15000000000L;   // Note the L suffix
        float myFloat = 5.75f;        // Note the f suffix
        double myDouble = 19.99;
        char myChar = 'A';
        boolean myBool = true;

        System.out.println("byte:    " + myByte);
        System.out.println("short:   " + myShort);
        System.out.println("int:     " + myInt);
        System.out.println("long:    " + myLong);
        System.out.println("float:   " + myFloat);
        System.out.println("double:  " + myDouble);
        System.out.println("char:    " + myChar);
        System.out.println("boolean: " + myBool);
    }
}
```

**Output:**
```
byte:    100
short:   5000
int:     100000
long:    15000000000
float:   5.75
double:  19.99
char:    A
boolean: true
```

---

### Example 2 – Widening Conversion

```java
public class WideningDemo {
    public static void main(String[] args) {
        int myInt = 9;
        double myDouble = myInt;  // automatic widening: int → double

        System.out.println("int value: " + myInt);
        System.out.println("double value: " + myDouble);  // 9.0
    }
}
```

**Output:**
```
int value: 9
double value: 9.0
```

---

### Example 3 – Narrowing Conversion (Explicit Cast)

```java
public class NarrowingDemo {
    public static void main(String[] args) {
        double price = 9.99;
        int truncated = (int) price;    // cast: truncates decimal

        float f = 3.14f;
        int fromFloat = (int) f;

        System.out.println("Original double: " + price);
        System.out.println("After casting to int: " + truncated);   // 9 (not 10!)
        System.out.println("Original float: " + f);
        System.out.println("After casting to int: " + fromFloat);   // 3
    }
}
```

**Output:**
```
Original double: 9.99
After casting to int: 9
Original float: 3.14
After casting to int: 3
```

---

### Example 4 – char and int Interconversion

```java
public class CharIntDemo {
    public static void main(String[] args) {
        char ch = 'A';
        int ascii = ch;               // char → int (automatic)
        System.out.println("'A' as int: " + ascii);      // 65

        int code = 90;
        char letter = (char) code;    // int → char (explicit cast)
        System.out.println("90 as char: " + letter);     // Z
    }
}
```

**Output:**
```
'A' as int: 65
90 as char: Z
```

---

### Example 5 – String Parsing

```java
public class StringParsing {
    public static void main(String[] args) {
        String numStr = "42";
        String decStr = "3.14";
        String boolStr = "true";

        int num = Integer.parseInt(numStr);
        double dec = Double.parseDouble(decStr);
        boolean flag = Boolean.parseBoolean(boolStr);

        System.out.println("Parsed int: " + num);
        System.out.println("Parsed double: " + dec);
        System.out.println("Parsed boolean: " + flag);

        // Primitive back to String
        String backToString = String.valueOf(num);
        System.out.println("Back to String: " + backToString);
    }
}
```

**Output:**
```
Parsed int: 42
Parsed double: 3.14
Parsed boolean: true
Back to String: 42
```

---

## 📝 Summary

- Java has 8 primitive types: `byte`, `short`, `int`, `long`, `float`, `double`, `char`, `boolean`.
- **Widening** conversion is automatic (smaller → larger, no data loss).
- **Narrowing** conversion requires explicit cast (larger → smaller, possible data loss/truncation).
- Always use the `L` suffix for `long` literals and `f` suffix for `float` literals.
- Use `Integer.parseInt()`, `Double.parseDouble()`, etc. to convert Strings to primitives.

---

*Previous → [02 – Command-Line Arguments & JDK, JRE, JVM](./02_CommandLine_JDK_JRE_JVM.md)*  
*Next → [04 – Keywords, Identifiers, Variables & Access Modifiers](./04_Keywords_Identifiers_Variables.md)*
