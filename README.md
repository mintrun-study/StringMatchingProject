# Test Cases & Benchmarks

## Input Format
```
n m
<grid n rows x m cols>
k
<k patterns>
```

## Usage
You **MUST** follow the prototype:
```bash
./main -a <algo> -i <input> -o <output>
# algo: bf | kmp | rk | bm | z
# input: name input file (ex: input.txt)
# output: name output file (ex: output.txt)
```

---

## testcase/ — correctness

| File | Description |
|------|-------------|
| `test1_example.txt` | Basic example |
| `test2_not_found.txt` | Pattern not found |
| `test3_horizontal.txt` | Horizontal match only |
| `test4_vertical.txt` | Vertical match only |
| `test5_multiple.txt` | Multiple patterns |
| `test6_edge.txt` | Pattern at grid corners/edges |
| `test7_boundary_row.txt` | Pattern at first/last row |
| `test8_boundary_col.txt` | Pattern at first/last column |
| `test9_too_long.txt` | Pattern longer than grid |
| `test10_mixed.txt` | Both horizontal and vertical |
| `test11_worstcase_bm.txt` | Worst case for Boyer-Moore |
| `test12_stress.txt` | Many overlapping matches |
| `test13_worstcase_kmp.txt` | Worst case for KMP |

## tests/ — performance

| File | Description |
|------|-------------|
| `bench1_10x10.txt` | 10×10 grid |
| `bench2_100x100.txt` | 100×100 grid |
| `bench3_500x500.txt` | 500×500 grid |
| `bench4_K10.txt` | 10 patterns |
| `bench5_K50.txt` | 50 patterns |
| `bench6_K100.txt` | 100 patterns |