# OCaml Version

## Purpose of the OCaml Version

This version demonstrates functional programming in OCaml by using immutable lists, list transformations, and higher-order functions to compute the same statistics problem.

## Why It Is Functional

- The dataset is defined as an immutable list.
- The program uses `List.fold_left` to reduce the list into a sum.
- The program uses `List.sort` to create a sorted list instead of mutating the original data.
- The calculations are expressed as transformations of values rather than imperative loops and mutable state.
