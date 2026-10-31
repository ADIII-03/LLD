# Low-Level Design (LLD) & Object-Oriented Programming (OOP) Repository

Welcome to the **Low-Level Design (LLD)** learning and reference repository. This repository contains complete code implementations, architectural patterns, design diagrams, and deep-dive technical notes for core OOP principles and design patterns in C++.

---

## 🗂️ Repository Structure

```
LLD/
├── README.md               # Root repository index
└── oops/                   # Object-Oriented Programming Core Concepts
    ├── README.md           # Comprehensive notes, flow patterns & diagrams
    ├── encapsulation.cpp   # Data hiding, validation, and domain invariants
    ├── abstraction.cpp     # Abstract classes, pure virtual contracts, virtual destructors
    ├── inheritance.cpp     # 5 inheritance types (Single, Multilevel, Multiple, Hierarchical, Hybrid)
    ├── diamondproblem.cpp  # Diamond ambiguity in multiple inheritance & virtual base resolution
    └── polymorphism.cpp    # Static (overloading) & Dynamic (vtable/vptr, dynamic_cast) polymorphism
```

---

## 🚀 Quick Navigation to Modules

For exhaustive documentation with UML class diagrams, execution flow patterns, state machines, memory layouts, and step-by-step code breakdowns, visit:

👉 **[oops/README.md](file:///c:/Users/aradi/OneDrive/Documents/LLD/oops/README.md)**

### Key Topics Covered:

1. **Encapsulation & Data Hiding (`oops/encapsulation.cpp`)**
   - Private member variable isolation
   - Public accessors & mutators with boundary validations
   - State invariant rules (e.g., stopping car only when speed is 0)

2. **Abstraction & Contract-Based Design (`oops/abstraction.cpp`)**
   - Abstract Base Classes (ABC)
   - Pure virtual functions (`virtual void func() = 0`)
   - Crucial role of virtual destructors in preventing memory leaks

3. **Inheritance Architectures (`oops/inheritance.cpp`)**
   - Single, Multilevel, Multiple, Hierarchical, and Hybrid inheritance
   - Access specifier behavior across inheritance boundaries (`public`, `protected`, `private`)
   - Constructor/destructor invocation ordering

4. **The Diamond Problem & Virtual Inheritance (`oops/diamondproblem.cpp`)**
   - Ambiguity and duplicated base sub-objects in multipath inheritance
   - Resolution using `virtual public` inheritance
   - Under-the-hood memory layout (`vbptr` / `vbtable`) and constructor assignment rules

5. **Polymorphism Deep Dive (`oops/polymorphism.cpp`)**
   - **Static (Compile-Time)**: Function overloading (name mangling) & operator overloading (`operator+`)
   - **Dynamic (Run-Time)**: Virtual function tables (`vtable`), virtual pointers (`vptr`), dynamic dispatch
   - **RTTI & Safe Downcasting**: Using `dynamic_cast<T*>` on polymorphic pointers
   - Safe polymorphic destruction

---

## 🛠️ Quick Compilation

To compile and test all OOP examples:

```powershell
cd oops

# Compile and run individual examples:
g++ -std=c++17 -o encapsulation encapsulation.cpp && ./encapsulation
g++ -std=c++17 -o abstraction abstraction.cpp && ./abstraction
g++ -std=c++17 -o inheritance inheritance.cpp && ./inheritance
g++ -std=c++17 -o diamond diamondproblem.cpp && ./diamond
g++ -std=c++17 -o polymorphism polymorphism.cpp && ./polymorphism
```
