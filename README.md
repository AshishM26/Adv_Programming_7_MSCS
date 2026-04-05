# Adv_Programming_7_MSCS

## Assignment Purpose Multi-Paradigm Statistics

This project solves the same statistics problem in three different programming paradigms:

- C demonstrates procedural programming.
- OCaml demonstrates functional programming.
- Python demonstrates object-oriented programming.

The shared task is to calculate the mean, median, and mode for the same fixed dataset:

`[12, 6, 3, 6, 9, 15, 6, 3, 12]`

Using the same dataset and nearly identical output in all three languages makes it easier to compare how each paradigm organizes logic, data, and program flow.

## How the Three Paradigms Differ

### C: Procedural Programming
The C version is written as a sequence of procedures that operate directly on arrays. It uses explicit loops, manual size tracking, and direct data handling. This makes the step-by-step nature of procedural programming easy to observe.

### OCaml: Functional Programming
The OCaml version keeps data immutable and uses list processing with higher-order functions such as `List.fold_left` and `List.sort`. Instead of changing data in place, the program creates transformed values from existing ones.

### Python: Object-Oriented Programming
The Python version places both data and behavior inside a `StatisticsCalculator` class. The dataset is stored as object state, and the calculations are implemented as methods. This shows encapsulation and method-based design.

## Repository Structure

```text
multi-paradigm-statistics/
├── REPORT_NOTES.md
├── SCREENSHOT_GUIDE.md
├── c/
│   ├── README.md
│   └── statistics.c
├── ocaml/
│   ├── README.md
│   └── statistics.ml
└── python/
    ├── README.md
    └── statistics_calculator.py
```