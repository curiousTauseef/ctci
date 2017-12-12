# (C++) Cracking the Coding Interview - 6th Edition
Interview Preparation

All questions were completed in under ~00:45:00 - 01:00:00 time limit

*Recommend learning more on www.geeksforgeeks.org/ for tries, heaps, etc. which are not covered enough in CTCI*

Helpful test case definitions that you can apply to testing your algorithms:
<a href="https://docs.google.com/document/d/1rfrGD9AFYc1IjOceACETc6R0U7pMxYLO96rT_o-cYvk/edit">Testing Your Code</a>

# How I Approached these Problems

1. Read the problem carefully and think about what it's asking for
2. Get a piece of notebook paper
3. Draw a diagram and write down pseudo-code
4. Go through multiple examples and test your pseudo-code with those examples
5. Translate your pseudo-code to actual code
6. Always test code for edge, boundary, corner, and base cases
7. If stuck on a solution for more than one hour, do not read the code, but read the hints/approaches
8. From reading those hints/approaches, try to translate them to pseudo-code then to actual code


# Table of Contents
[Chapter 1 | Array and Strings](#chapter-1-array-and-strings)

[Chapter 2 | Linked Lists](#chapter-2-linked-lists)

[Chapter 3 | Stacks and Queues](#chapter-3-stacks-and-queues)

[Chapter 4 | Trees and Graphs](#chapter-4-trees-and-graphs)

[Chapter 5 | Bit Manipulation](#chapter-5-bit-manipulation)

[Chapter 7 | Object Oriented Design](#chapter-7-object-oriented-design)

[Chapter 8 | Recursion and Dynamic Programming](#chapter-8-recursion-and-dynamic-programming)

[Chapter 9 | System Design and Scalability](#chapter-9-system-design-and-scalability)

[Chapter 10 | Sorting and Searching](#chapter-10-sorting-and-searching)

## Chapter 1 Array and Strings
<a href="https://github.com/DittoPDX/CTCI/tree/master/CH1">Chapter 1 | Questions & Answers</a>

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-1.cpp">1.1: Is Unique</a>

<blockquote>
Optimized question requires doing some look-ups on the bitset documentation.
</blockquote>

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-2.cpp">1.2: Check Permutation</a>

<blockquote>
Optimized question requires understanding word frequency and using a simple array structure.
</blockquote>

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-3.cpp">1.3: URLify</a>

<blockquote>
Optimized question asked by Microsoft. Modifying a string from the end is useful here.
</blockquote>

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-4.cpp">1.4: Permutation of Palindrome</a>

<blockquote>
Optimized solution requires understanding the relationship between palindromes and permutations.
</blockquote>

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-5.cpp">1.5: One Away</a>

<blockquote>
Optimized question is tricky. Only one if-statement is needed for the equal length special case.
</blockquote>


- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-6.cpp">1.6: String Compression</a>

<blockquote>
Optimized question asked by Amazon in a Software Engineer Interview. If done without "string",
it would require multiple tedious implementations of concatenation from digits to char. Highly
recommend this question; requires some understanding of "string" library and conversions.
</blockquote>

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-7.cpp">1.7: Rotate Matrix</a>

<blockquote>
Optimized question requires some knowledge of matrix algebra. The rest of the algorithm can be derived with a reverse strategy. C++ can pass 2-D arrays by doing "T (&array)[][]".
</blockquote>


- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-8.cpp">1.8: Zero Matrix</a>

<blockquote>
Optimized question that's a bit tricky. Biggest trick is to use row #0 and col #0 as "auxiliary" arrays to get to O(1) space complexity. Amazon supposedly asked this sort of similar question.
</blockquote>

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH1/1-9.cpp">1.9: String Rotation</a>

<blockquote>
Optimized question requires some basic knowledge of C++ "string" library. Biggest idea is that you can double the first array, and then call the substring() function once.
</blockquote>

## Chapter 2 Linked Lists

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH2/2-1.cpp">2.1: Remove Dups</a>

<blockquote>
Optimized question requires using mergesort or using unordered set to store the duplicates.
</blockquote>

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH2/2-2.cpp">2-2: Return Kth to Last</a>

<blockquote>
Optimized question requires some basic knowledge of back-tracking during recursion.
</blockquote>

## Chapter 3 Stacks and Queues

- <a href="https://github.com/DittoPDX/CTCI/blob/master/CH2/2-3.cpp">2-3: Delete Middle Node</a>

<blockquote>
Optimized question requires some basic knowledge of back-tracking during recursion.
</blockquote>

## Chapter 4 Trees and Graphs

## Chapter 5 Bit Manipulation

## Chapter 7 Object Oriented Design

## Chapter 8 Recursion and Dynamic Programming

## Chapter 9 System Design and Scalability

## Chapter 10 Sorting and Searching
