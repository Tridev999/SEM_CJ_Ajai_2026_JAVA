# 02 — Arrays and Enums

---

## 📖 Theory — Arrays

### What Is an Array?

An **array** is a fixed-size, ordered collection of elements of the **same data type**. All elements are stored in **contiguous memory locations** and are accessed by a numeric **index** starting at `0`.

```
Index:  [0]   [1]   [2]   [3]   [4]
Value:   10    20    30    40    50
```

---

### Declaring and Creating Arrays

```java
// 1. Declaration only
int[] numbers;

// 2. Declaration + creation (empty)
int[] numbers = new int[5];     // 5 elements, all initialized to 0

// 3. Declaration + creation + initialization
int[] numbers = {10, 20, 30, 40, 50};

// 4. Alternate syntax (avoid — less readable)
int numbers[] = new int[5];
```

**Default values when array is created with `new`:**

| Type | Default |
|---|---|
| `int`, `byte`, `short`, `long` | `0` |
| `float`, `double` | `0.0` |
| `char` | `'\u0000'` |
| `boolean` | `false` |
| Object | `null` |

---

### Accessing and Modifying Elements

```java
int[] arr = {10, 20, 30, 40, 50};

// Access
System.out.println(arr[0]);   // 10 (first element)
System.out.println(arr[4]);   // 50 (last element)
System.out.println(arr.length); // 5 (size of array)

// Modify
arr[2] = 99;
System.out.println(arr[2]);   // 99

// ArrayIndexOutOfBoundsException if you go out of range:
// System.out.println(arr[5]);  // ERROR!
```

---

### Multi-Dimensional Arrays

A 2D array is an array of arrays — like a table with rows and columns.

```java
// 2D Array: 3 rows, 4 columns
int[][] matrix = new int[3][4];

// 2D Array with initialization
int[][] grid = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Access: grid[row][column]
System.out.println(grid[1][2]);   // 6 (row 1, column 2)

// Dimensions
System.out.println(grid.length);        // 3 rows
System.out.println(grid[0].length);     // 3 columns
```

---

### Array Access and Iteration

```java
// Using traditional for loop (with index)
for (int i = 0; i < arr.length; i++) {
    System.out.println("arr[" + i + "] = " + arr[i]);
}

// Using for-each (simpler, no index)
for (int element : arr) {
    System.out.println(element);
}

// Iterating 2D array
for (int i = 0; i < grid.length; i++) {
    for (int j = 0; j < grid[i].length; j++) {
        System.out.print(grid[i][j] + " ");
    }
    System.out.println();
}
```

---

### Useful `Arrays` Class Methods

The `java.util.Arrays` class provides utility methods:

```java
import java.util.Arrays;

int[] arr = {5, 2, 8, 1, 9, 3};

Arrays.sort(arr);                          // sorts in ascending order
System.out.println(Arrays.toString(arr));  // [1, 2, 3, 5, 8, 9]

int idx = Arrays.binarySearch(arr, 8);    // find index of 8 (after sorting!)
System.out.println("Index of 8: " + idx); // 4

int[] copy = Arrays.copyOf(arr, arr.length);   // full copy
int[] partial = Arrays.copyOfRange(arr, 1, 4); // partial copy [index 1 to 3]

Arrays.fill(arr, 0);                       // fill all with 0
System.out.println(Arrays.equals(arr, copy)); // compare two arrays
```

---

### Varargs (Variable Arguments)

Varargs allows a method to accept a variable number of arguments of the same type. Internally, they're treated as arrays.

```java
// Syntax: dataType... paramName
public static int sum(int... numbers) {
    int total = 0;
    for (int n : numbers) {
        total += n;
    }
    return total;
}

// Call with any number of arguments
System.out.println(sum(1, 2, 3));          // 6
System.out.println(sum(10, 20, 30, 40));   // 100
System.out.println(sum());                 // 0
```

**Rules for varargs:**
- Must be the **last parameter** in the method signature
- Only **one varargs** parameter allowed per method

---

## 📖 Theory — Enumerations (Enums)

### What Is an Enum?

An **enum** (short for *enumeration*) is a special class in Java that represents a **fixed set of named constants**. Use enums when a variable should only hold one of a limited set of predefined values.

```java
enum Day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
}
```

---

### Using Enums

```java
Day today = Day.WEDNESDAY;

if (today == Day.SATURDAY || today == Day.SUNDAY) {
    System.out.println("It's a weekend!");
} else {
    System.out.println("It's a weekday.");
}
```

---

### Enums in switch

```java
Day day = Day.MONDAY;

switch (day) {
    case MONDAY:
        System.out.println("Start of the work week.");
        break;
    case FRIDAY:
        System.out.println("TGIF!");
        break;
    case SATURDAY:
    case SUNDAY:
        System.out.println("Weekend!");
        break;
    default:
        System.out.println("Midweek.");
}
```

---

### Enum Methods

```java
Day d = Day.FRIDAY;

d.name()           // "FRIDAY" — enum constant name as String
d.ordinal()        // 4 — zero-based position
Day.values()       // array of all enum values
Day.valueOf("MONDAY")  // get enum from String
```

---

### Enums with Fields and Methods

Enums can have constructors, fields, and methods:

```java
enum Planet {
    MERCURY(3.303e+23, 2.4397e6),
    VENUS  (4.869e+24, 6.0518e6),
    EARTH  (5.976e+24, 6.37814e6);

    private final double mass;    // in kilograms
    private final double radius;  // in meters

    Planet(double mass, double radius) {
        this.mass = mass;
        this.radius = radius;
    }

    double surfaceGravity() {
        final double G = 6.67300E-11;
        return G * mass / (radius * radius);
    }
}
```

---

## 🧪 Practice Questions

1. What is an array? How does it differ from a single variable?
2. What is the default value of an `int` array element?
3. What exception is thrown if you access `arr[10]` when the array has only 5 elements?
4. What is the difference between `arr.length` and `arr.length()`?
5. How do you sort an array in Java without writing your own sorting algorithm?
6. What is a varargs method? Write one that finds the maximum of any number of integers.
7. Why are enums better than using `int` constants for fixed values like days or seasons?
8. What does `Day.values()` return?

---

## 💻 Examples

### Example 1 – 1D Array Operations

```java
import java.util.Arrays;

public class ArrayDemo {
    public static void main(String[] args) {
        // Create and initialize
        int[] scores = {85, 92, 78, 95, 88};

        // Access
        System.out.println("First score: " + scores[0]);
        System.out.println("Last score: " + scores[scores.length - 1]);

        // Find max and min
        int max = scores[0], min = scores[0];
        int total = 0;
        for (int s : scores) {
            if (s > max) max = s;
            if (s < min) min = s;
            total += s;
        }

        System.out.println("Max: " + max);
        System.out.println("Min: " + min);
        System.out.println("Average: " + (double) total / scores.length);

        // Sort
        Arrays.sort(scores);
        System.out.println("Sorted: " + Arrays.toString(scores));
    }
}
```

**Output:**
```
First score: 85
Last score: 88
Max: 95
Min: 78
Average: 87.6
Sorted: [78, 85, 88, 92, 95]
```

---

### Example 2 – 2D Array (Matrix Addition)

```java
public class MatrixAddition {
    public static void main(String[] args) {
        int[][] a = {{1, 2, 3}, {4, 5, 6}};
        int[][] b = {{7, 8, 9}, {1, 2, 3}};
        int rows = 2, cols = 3;
        int[][] sum = new int[rows][cols];

        // Add matrices
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }

        // Display result
        System.out.println("Matrix A + B:");
        for (int[] row : sum) {
            for (int val : row) {
                System.out.printf("%4d", val);
            }
            System.out.println();
        }
    }
}
```

**Output:**
```
Matrix A + B:
   8  10  12
   5   7   9
```

---

### Example 3 – Varargs

```java
public class VarargsDemo {
    static int sum(int... nums) {
        int total = 0;
        for (int n : nums) total += n;
        return total;
    }

    static double average(double... nums) {
        double total = 0;
        for (double n : nums) total += n;
        return nums.length == 0 ? 0 : total / nums.length;
    }

    public static void main(String[] args) {
        System.out.println("Sum(1,2,3): " + sum(1, 2, 3));
        System.out.println("Sum(5,10,15,20): " + sum(5, 10, 15, 20));
        System.out.println("Sum(): " + sum());
        System.out.println("Avg(10,20,30): " + average(10, 20, 30));
    }
}
```

**Output:**
```
Sum(1,2,3): 6
Sum(5,10,15,20): 50
Sum(): 0
Avg(10,20,30): 20.0
```

---

### Example 4 – Enum Basics

```java
public class EnumDemo {
    enum Season { SPRING, SUMMER, AUTUMN, WINTER }

    public static void main(String[] args) {
        Season current = Season.SUMMER;

        System.out.println("Current season: " + current);
        System.out.println("Name: " + current.name());
        System.out.println("Ordinal: " + current.ordinal());

        System.out.println("\nAll seasons:");
        for (Season s : Season.values()) {
            System.out.println("  " + s.ordinal() + ": " + s);
        }

        // switch with enum
        String activity;
        switch (current) {
            case SPRING: activity = "Plant flowers"; break;
            case SUMMER: activity = "Go swimming"; break;
            case AUTUMN: activity = "Collect leaves"; break;
            case WINTER: activity = "Build snowman"; break;
            default: activity = "Unknown";
        }
        System.out.println("\nActivity: " + activity);
    }
}
```

**Output:**
```
Current season: SUMMER
Name: SUMMER
Ordinal: 1

All seasons:
  0: SPRING
  1: SUMMER
  2: AUTUMN
  3: WINTER

Activity: Go swimming
```

---

### Example 5 – Enum with Fields and Methods

```java
public class EnumWithMethods {
    enum TrafficLight {
        RED("Stop", 60),
        YELLOW("Slow down", 5),
        GREEN("Go", 45);

        private final String action;
        private final int durationSeconds;

        TrafficLight(String action, int durationSeconds) {
            this.action = action;
            this.durationSeconds = durationSeconds;
        }

        public String getAction() { return action; }
        public int getDuration() { return durationSeconds; }
    }

    public static void main(String[] args) {
        for (TrafficLight light : TrafficLight.values()) {
            System.out.printf("%-8s → %-15s (lasts %ds)%n",
                light, light.getAction(), light.getDuration());
        }
    }
}
```

**Output:**
```
RED      → Stop            (lasts 60s)
YELLOW   → Slow down       (lasts 5s)
GREEN    → Go              (lasts 45s)
```

---

## 📝 Summary

- **Arrays** store multiple values of the same type in contiguous memory, indexed from 0.
- Access with `arr[index]`; get size with `arr.length` (no parentheses).
- Use `Arrays.sort()`, `Arrays.toString()`, `Arrays.copyOf()` from `java.util.Arrays`.
- **Multi-dimensional arrays** are arrays of arrays; `grid[row][col]` for 2D access.
- **Varargs** (`type...`) let a method accept any number of arguments; treated as an array internally.
- **Enums** represent a fixed set of named constants; safer and more readable than magic numbers/strings.
- Enums can have fields, constructors, and methods for richer behaviour.

---

*Previous → [01 – Loops](./01_Loops.md)*  
*Next → [03 – OOP Concepts](./03_OOP_Concepts.md)*
