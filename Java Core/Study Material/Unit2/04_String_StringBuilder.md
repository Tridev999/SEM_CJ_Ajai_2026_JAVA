# 04 — String Class: Constructors, Methods & StringBuilder

---

## 📖 Theory

### What Is a String?

In Java, `String` is a **class** (not a primitive) in the `java.lang` package. A `String` object represents an **immutable** sequence of characters.

**Immutable** means once a String is created, its content **cannot be changed**. Any "modification" actually creates a new String object.

```java
String s = "Hello";
s = s + " World";   // "Hello" is not changed; a NEW string is created
```

---

### Creating Strings

```java
// 1. String literal (stored in String Pool)
String s1 = "Hello";
String s2 = "Hello";   // s1 and s2 point to SAME object in pool

// 2. Using new keyword (always creates new object in heap)
String s3 = new String("Hello");

// 3. From char array
char[] chars = {'J', 'a', 'v', 'a'};
String s4 = new String(chars);   // "Java"

// 4. From StringBuilder
StringBuilder sb = new StringBuilder("World");
String s5 = sb.toString();
```

---

### String Comparison

```java
String a = "hello";
String b = "hello";
String c = new String("hello");

// == compares REFERENCES (memory addresses)
System.out.println(a == b);       // true (same pool object)
System.out.println(a == c);       // false (c is a new heap object!)

// .equals() compares CONTENT
System.out.println(a.equals(b));  // true
System.out.println(a.equals(c));  // true

// Case-insensitive comparison
System.out.println(a.equalsIgnoreCase("HELLO"));  // true
```

> **Always use `.equals()` to compare String content, NOT `==`.**

---

### Important String Methods

| Method | Description | Example |
|---|---|---|
| `length()` | Number of characters | `"Hello".length()` → 5 |
| `charAt(i)` | Character at index i | `"Hello".charAt(1)` → 'e' |
| `indexOf(str)` | First occurrence index | `"Hello".indexOf("l")` → 2 |
| `lastIndexOf(str)` | Last occurrence index | `"Hello".lastIndexOf("l")` → 3 |
| `substring(start)` | Substring from start | `"Hello".substring(2)` → "llo" |
| `substring(s, e)` | Substring from s to e-1 | `"Hello".substring(1, 4)` → "ell" |
| `toUpperCase()` | Convert to uppercase | `"hello".toUpperCase()` → "HELLO" |
| `toLowerCase()` | Convert to lowercase | `"HELLO".toLowerCase()` → "hello" |
| `trim()` | Remove leading/trailing spaces | `" Hi ".trim()` → "Hi" |
| `strip()` | Like trim but Unicode-aware | `" Hi ".strip()` → "Hi" |
| `replace(a, b)` | Replace all occurrences | `"aabbcc".replace("b","x")` → "aaxxcc" |
| `contains(str)` | Check if contains substring | `"Hello".contains("ell")` → true |
| `startsWith(str)` | Check prefix | `"Hello".startsWith("He")` → true |
| `endsWith(str)` | Check suffix | `"Hello".endsWith("lo")` → true |
| `isEmpty()` | Check if length is 0 | `"".isEmpty()` → true |
| `isBlank()` | Check if empty or whitespace | `"  ".isBlank()` → true |
| `split(regex)` | Split into array | `"a,b,c".split(",")` → ["a","b","c"] |
| `join(delim, ...)` | Join strings | `String.join("-","a","b")` → "a-b" |
| `format(...)` | Format string | `String.format("%d", 42)` → "42" |
| `valueOf(x)` | Convert to String | `String.valueOf(42)` → "42" |
| `toCharArray()` | Convert to char[] | `"Hi".toCharArray()` |
| `compareTo(str)` | Lexicographic compare | `"a".compareTo("b")` → negative |
| `matches(regex)` | Check regex match | `"123".matches("\\d+")` → true |

---

### String Immutability and String Pool

```
String Pool (in Heap)
┌─────────────────────────┐
│  "Hello"   ←── s1, s2  │
│  "World"   ←── s4      │
└─────────────────────────┘

Heap (regular objects)
┌─────────────────────────┐
│  new String("Hello") ←── s3  │
└─────────────────────────┘
```

Since Strings are immutable, they are thread-safe and can be safely shared (that's why string pooling works).

---

### StringBuilder

`StringBuilder` is a **mutable** sequence of characters. Use it when you need to modify strings frequently (e.g., in loops), because it avoids creating many String objects.

**Key difference from String:**
- `String` is immutable — every change creates a new object
- `StringBuilder` is mutable — changes happen in-place

```java
StringBuilder sb = new StringBuilder();
sb.append("Hello");
sb.append(", ");
sb.append("World");
System.out.println(sb.toString());   // "Hello, World"
```

#### StringBuilder Methods

| Method | Description |
|---|---|
| `append(x)` | Appends x at the end |
| `insert(i, x)` | Inserts x at index i |
| `delete(s, e)` | Deletes from index s to e-1 |
| `deleteCharAt(i)` | Deletes char at index i |
| `replace(s, e, str)` | Replaces from s to e-1 with str |
| `reverse()` | Reverses the string |
| `charAt(i)` | Returns char at index |
| `setCharAt(i, c)` | Sets char at index |
| `indexOf(str)` | First occurrence |
| `length()` | Current length |
| `toString()` | Convert to String |
| `capacity()` | Current buffer capacity |

---

### String vs StringBuilder vs StringBuffer

| Feature | String | StringBuilder | StringBuffer |
|---|---|---|---|
| Mutable? | ❌ No | ✅ Yes | ✅ Yes |
| Thread-safe? | ✅ Yes | ❌ No | ✅ Yes |
| Performance | Slow (many objects) | Fast | Moderate |
| Use case | Fixed text | Single-threaded mutations | Multi-threaded mutations |

> **Rule of thumb:** Use `String` for fixed text, `StringBuilder` for building strings in loops/single threads.

---

## 🧪 Practice Questions

1. What does "String is immutable" mean? Why is immutability useful?
2. What is the String Pool? Why does it exist?
3. Why should you use `.equals()` instead of `==` to compare strings?
4. What is the difference between `substring(2)` and `substring(2, 5)`?
5. Why is `StringBuilder` preferred over `String` for concatenation in loops?
6. What does `"Hello World".split(" ")` return?
7. How do you reverse a string using `StringBuilder`?
8. What does `String.format("Name: %s, Age: %d", "Alice", 25)` produce?

---

## 💻 Examples

### Example 1 – String Methods in Action

```java
public class StringMethods {
    public static void main(String[] args) {
        String s = "  Hello, Java World!  ";

        System.out.println("Original: '" + s + "'");
        System.out.println("Trimmed: '" + s.trim() + "'");
        System.out.println("Length: " + s.trim().length());
        System.out.println("Upper: " + s.trim().toUpperCase());
        System.out.println("Lower: " + s.trim().toLowerCase());
        System.out.println("Index of 'Java': " + s.indexOf("Java"));
        System.out.println("Contains 'World': " + s.contains("World"));
        System.out.println("Starts with '  He': " + s.startsWith("  He"));
        System.out.println("Replace: " + s.trim().replace("Java", "Python"));
        System.out.println("Substring(7, 11): " + s.trim().substring(7, 11));
    }
}
```

**Output:**
```
Original: '  Hello, Java World!  '
Trimmed: 'Hello, Java World!'
Length: 18
Upper: HELLO, JAVA WORLD!
Lower: hello, java world!
Index of 'Java': 9
Contains 'World': true
Starts with '  He': true
Replace: Hello, Python World!
Substring(7, 11): Java
```

---

### Example 2 – String Split and Join

```java
import java.util.Arrays;

public class SplitJoinDemo {
    public static void main(String[] args) {
        // Split
        String csv = "Alice,Bob,Charlie,Diana";
        String[] names = csv.split(",");
        System.out.println("Names: " + Arrays.toString(names));
        System.out.println("Count: " + names.length);

        // Split with limit
        String sentence = "one two three four five";
        String[] words = sentence.split(" ", 3);
        System.out.println("Split(3): " + Arrays.toString(words));

        // Join
        String joined = String.join(" | ", names);
        System.out.println("Joined: " + joined);

        // Join array
        String result = String.join(", ", "Apple", "Banana", "Cherry");
        System.out.println("Fruits: " + result);
    }
}
```

**Output:**
```
Names: [Alice, Bob, Charlie, Diana]
Count: 4
Split(3): [one, two, three four five]
Joined: Alice | Bob | Charlie | Diana
Fruits: Apple, Banana, Cherry
```

---

### Example 3 – StringBuilder Performance Demo

```java
public class StringBuilderDemo {
    public static void main(String[] args) {
        // Building with StringBuilder (efficient)
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 5; i++) {
            sb.append("Item ").append(i).append(", ");
        }
        sb.delete(sb.length() - 2, sb.length());   // remove trailing ", "
        System.out.println("Built: " + sb.toString());

        // StringBuilder methods
        StringBuilder s = new StringBuilder("Hello World");
        System.out.println("Original: " + s);

        s.insert(5, ",");
        System.out.println("After insert: " + s);

        s.replace(7, 12, "Java");
        System.out.println("After replace: " + s);

        s.delete(5, 6);
        System.out.println("After delete: " + s);

        s.reverse();
        System.out.println("Reversed: " + s);
    }
}
```

**Output:**
```
Built: Item 1, Item 2, Item 3, Item 4, Item 5
Original: Hello World
After insert: Hello, World
After replace: Hello, Java
After delete: Hello Java
Reversed: avaJ olleH
```

---

### Example 4 – Palindrome Checker

```java
public class PalindromeChecker {
    static boolean isPalindrome(String s) {
        String cleaned = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        String reversed = new StringBuilder(cleaned).reverse().toString();
        return cleaned.equals(reversed);
    }

    public static void main(String[] args) {
        String[] tests = {"racecar", "Hello", "A man a plan a canal Panama", "level", "Java"};

        for (String test : tests) {
            System.out.printf("'%s' → %s%n", test, isPalindrome(test) ? "Palindrome" : "Not a palindrome");
        }
    }
}
```

**Output:**
```
'racecar' → Palindrome
'Hello' → Not a palindrome
'A man a plan a canal Panama' → Palindrome
'level' → Palindrome
'Java' → Not a palindrome
```

---

### Example 5 – String Formatting

```java
public class StringFormatDemo {
    public static void main(String[] args) {
        String name = "Alice";
        int age = 22;
        double gpa = 3.87;

        // String.format
        String info = String.format("Name: %-10s | Age: %3d | GPA: %.2f", name, age, gpa);
        System.out.println(info);

        // Building a table
        System.out.println("\n--- Student Report ---");
        System.out.printf("%-15s %5s %6s%n", "Name", "Age", "GPA");
        System.out.println("-".repeat(28));

        String[][] students = {
            {"Alice", "22", "3.87"},
            {"Bob", "21", "3.54"},
            {"Charlie", "23", "3.92"}
        };

        for (String[] s : students) {
            System.out.printf("%-15s %5s %6s%n", s[0], s[1], s[2]);
        }
    }
}
```

**Output:**
```
Name: Alice      | Age:  22 | GPA: 3.87

--- Student Report ---
Name              Age    GPA
----------------------------
Alice              22   3.87
Bob                21   3.54
Charlie            23   3.92
```

---

## 📝 Summary

- **Strings are immutable** — every modification creates a new String object.
- The **String Pool** stores string literals; `new String()` always creates a heap object.
- **Always use `.equals()`** to compare string content; `==` compares references.
- Key methods: `length()`, `charAt()`, `substring()`, `indexOf()`, `replace()`, `split()`, `trim()`, `toUpperCase()`, `toLowerCase()`.
- **`StringBuilder`** is mutable and efficient for building strings in loops — use `append()`, `insert()`, `delete()`, `reverse()`.
- Use `String.format()` or `printf()` for professional string formatting.

---

*Previous → [03 – OOP Concepts](./03_OOP_Concepts.md)*  
*End of Unit 2*
