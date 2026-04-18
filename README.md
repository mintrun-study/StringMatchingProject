# GROUP PROJECT: STRING MATCHING

## Introduction

This project is submitted for CSC10004 - Data Structures & Algorithms. It covers the String Matching problem - a core topic in computer science with applications in text search, DNA analysis, and plagiarism detection.

We implement and benchmark four algorithms (**Brute Force**, **Rabin-Karp**, **KMP**, **Boyer-Moore**) and one bonus algorithm (**Z-Algorithm**) on a 2D character grid, searching horizontally and vertically, with performance evaluated across varying grid sizes and keyword counts.

---

## Compile

```bash
g++ *.cpp -o crossword -std=c++17
```

> **Requirement:** GNU g++ compiler with C++17 standard. No non-standard libraries are used.

---

## Usage
 
```
Usage: crossword[.exe] -a [algorithm] -i [input_file] -o [output_file]
 
Options:
  -a [algorithm]    Select algorithm: bf, rk, kmp, bm, z
  -i [input_file]   Path to user-provided data file
  -o [output_file]  Path to the result output file
 
Example:
  crossword.exe -a kmp -i puzzle.txt -o solution.txt
```

---

## Input Format

```
R C
<R rows, each with C characters separated by spaces>
K
<K patterns, one per line>
```

**Example:**
```
4 4
t e s t
e a b c
s d e f
t g h i
2
test
bug
```

---

## Output Format

```
<pattern>: (rstart, cstart) -> (rend, cend); ...
<pattern>: not found
--------------------------------
Algorithm: KMP
Comparisons: 32
Execution Time: 0.12 ms
```

---

## Test Cases (`tests/`)
 
### Correctness
 
| Input | Output | Description |
|---|---|---|
| `test1_example.txt` | `test1_example_output.txt` | Basic example from problem statement |
| `test2_not_found.txt` | `test2_not_found_output.txt` | All patterns not found |
| `test3_horizontal.txt` | `test3_horizontal_output.txt` | Horizontal matches only |
| `test4_vertical.txt` | `test4_vertical_output.txt` | Vertical matches only |
| `test5_multiple.txt` | `test5_multiple_output.txt` | Multiple occurrences, both directions |
| `test6_edge.txt` | `test6_edge_output.txt` | Patterns at grid corners and edges |
| `test7_boundary_row.txt` | `test7_boundary_row_output.txt` | Pattern spanning full first/last row |
| `test8_boundary_col.txt` | `test8_boundary_col_output.txt` | Pattern spanning full first/last column |
| `test9_too_long.txt` | `test9_too_long_output.txt` | Pattern longer than grid dimensions |
| `test10_mixed.txt` | `test10_mixed_output.txt` | Both horizontal and vertical matches |
| `test11_worstcase_bm.txt` | `test11_worstcase_bm_output.txt` | Worst case for Boyer-Moore |
| `test12_stress.txt` | `test12_stress_output.txt` | Many overlapping matches |
| `test13_worstcase_kmp.txt` | `test13_worstcase_kmp_output.txt` | Worst case for KMP |
 
### Benchmarks: Performance
 
| Input | Output | Description |
|---|---|---|
| `bench1_10x10.txt` | `bench1_10x10_output.txt` | Scenario 1 — Grid 10×10, K=5 |
| `bench2_100x100.txt` | `bench2_100x100_output.txt` | Scenario 1 — Grid 100×100, K=5 |
| `bench3_500x500.txt` | `bench3_500x500_output.txt` | Scenario 1 — Grid 500×500, K=5 |
| `bench4_K10.txt` | `bench4_K10_output.txt` | Scenario 2 — Grid 100×100, K=10 |
| `bench5_K50.txt` | `bench5_K50_output.txt` | Scenario 2 — Grid 100×100, K=50 |
| `bench6_K100.txt` | `bench6_K100_output.txt` | Scenario 2 — Grid 100×100, K=100 |