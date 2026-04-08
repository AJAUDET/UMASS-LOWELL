# PS5: DNA Alignment

## Contact
Name: AJ Audet
Section: 204

Partner: Hoang Bach Nguyen
Partner Section: 201

Time to Complete: 10 hours

## Description
Explain what the project does

Takes two input strings from a file or command line input, and then either uses the original allignmentDP() or the Hirschberg algorithm allignment() to perform the cost calculations. Then the output to the terminal is the alligned strings with the cost for the individual operations, the total cost of all the operations, and the time to complete the program.

### Features
Explain how you did the actual alignment including the data structures used.

Implements a classic edit distance algorithm to compare two DNA strands via the alignmentDP() function. Uses a 2D DP table "opt_" to compute the minimum alignment cost. We use match -> 0 cost, substitution -> 1 cost, and gap -> 2 cost. Final result is stored at opt_[0][0].

The function alignmentDP() reconstructs the optimal alignment using the DP table. Outputs the characteres from strand 1, strand 2 with "-" for gaps, and the cost.

Implements Hirschberg’s algorithm via the alignment() function. Reduces space complexity from O(m·n) → O(n). Recursively splits the problem to build the alignment by using computeForward() and computeBackwards().

The hirschberg() function splits one string in half, then it finds the optimal split point in the other string, and recursively solves subproblems, and it will fallback on alignmentDP() for smaller datasets.

### Testing
Describe what the unit tests you wrote check for and why you picked them.

TestMin3: Checks that min3() correctly returns the smallest value among three integers.
TestPenalty: Checks that penalty() returns 0 for matching characters and 1 for mismatched characters.
TestOptDistanceExample: Checks that optDistance() produces the correct edit distance.
TestOptDistanceIdentical: Checks the edit distance is 0 when both strings are identical.
TestOptDistanceOneEmpty: Checks that the algorithm correctly handles cases where one of the strings is empty.
TestOptDistanceAllMismatch: Checks that the algorithm correctly handles strings where every character mismatches.
TestOptDistanceSmall: Checks very small inputs to ensure the algorithm works correctly for single character and empty cases.
TestAlignmentLength: Checks that the alignment output is not empty and contains expected characters.
TestAlignmentLength2: Checks that the alignment output contains enough lines when the strings have different lengths.
TestAlignmentIdentical: Checks the alignment function works correctly when both input strings are identical.
TestAlignmentDirection: Checks the program produces a valid alignment and non-negative distance even when the strings are very different.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

The first iteration of the code for EDistance.cpp and Edistance.hpp can only handle files hat are smaller than ecoli28284.txt, it is unable to run that file and any files above it. Otherwise the program has full functionaliy and has no memory leaks appearing, we used valgrind to verify this. When we implemented the extra credit we are able to get around this limitation.

## Analysis

### Example
Do one additional test case by hand. It should be constructed in such a way that you know the correct  output before running your program on it, and it should be a "corner case" that helps check if your program handles all special situations correctly. 

Please list:
 - a copy of the test case input
 - the expected test case output
 - whether your program ran correctly on it or not
 - optionally, any other remarks

Test case:
s1 = "ACGT"
s2 = "TTT"

Epected output:
A T 1
C T 1
G - 2
T T 0
Edit distance = 4

The program got it correctly

### Specs
Your Computer
Memory: 4GB DDR4
Processors: QEMU Virtual version 2.5+ (4) @ 2.100GHz

Partner's Computer
Memory: 16gb, DDR4
Processors: AMD Ryzen 7 5700U @ 3.20 GHz x16

### Runs
Fill in the table with the results of running your code on both your and your partner's computers.

Being able to test across multiple devices and then compare that data to see how hardware interacts with this projet and how larger datasets can fail completely due to memory allocation errors. We used the Hirschberg algorithm for running our program.

Using the command: valgrind --tool=massif ./EDistance < sequence/ecoli{number}.txt
Vizualizing data using command: ms_print massif.out.{pid}

| data file     | distance | memory (MiB) | time (seconds) | partner time |
|---------------|----------|--------------|----------------|--------------|
|ecoli2500.txt  |118       |0.1516        |0.015969        |0.015937      |
|ecoli5000.txt  |160       |0.2270        |0.063498        |0.062062      |
|ecoli7000.txt  |194       |0.309         |0.123           |0.12535       |
|ecoli10000.txt |223       |0.3779        |0.251983        |0.236689      |
|ecoli20000.txt |3135      |0.6797        |1.0163          |0.991143      |
|ecoli28284.txt |8394      |0.993         |2.0252          |1.69952       |
|ecoli50000.txt |19485     |1.733         |6.45182         |6.18433       |
|ecoli100000.txt|24166     |3.453         |26.2155         |26.005        |

Here is an example from another computer for some of the files.

| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |

### Time
Assume the two strings are the same length (M = N).  By applying the doubling method to the data points that you obtained, estimate the running time of youu program in seconds as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input your program can handle if it is limited to one day of computation.

Provide a brief justification/explanation of how you applied the doubling method, and if you data seems not to work, describe what went wrong and use the sample data instead.
 - a = 2.6 * 10^(-9)
 - b = 2
 - largest N = 5.8 * 10^6

When the input size doubled (2500->5000, 5000->10000, 10000->20000), the runtime increased by roughly a factor of 4. Since 2^b = 4 we have b = 2. Using the largest data point (N = 100000, time approx 26s), we have a = 2.6 * 10^(-9), therefore largest N = 5.8 * 10^6

### Memory
Assume the two strings are the same length (M = N).  Look at your code and determine how much memory it requires as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle if limited to 8GiB of RAM.
 - a = 8
 - b = 1
 - largest N = 2^30
 
Hirschberg’s algorithm reduces memory usage by storing only two rows of the dynamic programming table at a time. In the implementation, computeForward() and computeBackward() each allocate two vectors of size N + 1. Since each integer requires 4 bytes, the memory usage is approximately 2(N+1) * 4 = 8N bytes. With an 8 GiB memory (8 * 2^30 bytes = 8N) limit gives a maximum N size of 2^30

### Valgrind
Run valgrind and list any errors you see.  Identify whether the memory usage reported by valgrind almost matches the calculations in the previous section.

| data file     | Calculated (MiB) | Measured (MiB) | Difference (%) |
|---------------|------------------|----------------|----------------|
|ecoli2500.txt  |0.827             |0.1516          |138.034         |
|ecoli5000.txt  |1.656             |0.2270          |151.779         |
|ecoli7000.txt  |2.517             |0.309           |156.263         |
|ecoli10000.txt |3.396             |0.3779          |159.946         |
|ecoli20000.txt |7.038             |0.6797          |164.772         |
|ecoli28284.txt |10.826            |0.993           |166.393         |
|ecoli50000.txt |20.151            |1.733           |168.324         |
|ecoli100000.txt|42.367            |3.453           |169.856         |

## Pair Programming
If you worked with a partner, do you have any remarks on the pair programming method? E.g., how many times did you switch, what are the tradeoffs of driving vs. navigating, etc.?

Working with a partner made this project significantly easier. We were able to come up with different implementations, compare them, and then create a better method based off of the ideas from those original implementations.

## Extra Credit
Anything special you did.  This is required to earn bonus points.

We implemented the Hirschberg method to cut down on memory and time to compute, we are now able to compute the data for sufficiently larger files than ecoli28284.txt. 

Hirschberg’s algorithm reduces the memory required for sequence alignment by not storing the entire dynamic programming table. Needleman–Wunsch style algorithm builds and stores an N x N matrix, which requires O(N^2) space. Hirschberg instead observes that each row of the (dynamic programming) DP table only depends on the previous row, so it computes the alignment using only two rows at a time. The algorithm uses a divide-and-conquer strategy as it splits one string in half, computes forward and backward dynamic programming costs to determine where the optimal alignment crosses the midpoint, and then recursively solves the two smaller subproblems which reduces the space complexity to O(N) while maintaining the same O(N^2) running time as the standard dynamic programming solution. However, in reality with large dataset it runs faster because it operates on much smaller arrays that fit better in CPU cache and require far fewer memory accesses.

| data file     | distance | memory (MiB) | time (seconds) | partner time |
|---------------|----------|--------------|----------------|--------------|
|ecoli28284.txt |8394      |0.993         |2.0252          |1.69952       |

Our customMin() function works by checking if a is less than or equal to b and c, if it is return a, if not it runs a check against b to see if it is less than or equal to a and c, if it is return b, otherwise it will return c.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

- Hirschberg’s Algorithm: A Space‑Efficient Approach to the Longest Common Subsequence by Eugen Sławomir Oparin https://every-algorithm.github.io/2025/07/04/hirschbergs_algorithm.html
- Valgrind Documentation: https://valgrind.org/docs/
- Massif Documentation: https://valgrind.org/docs/manual/ms-manual.html
