### Exercise 4.5

Write a program that uses threads to perform a parallel matrix multiply. To multiply two matrices, C = A * B, the result entry C (i,j) is computed by taking the dot product of the ith row of A and the jth column of B: 

![formula](https://github.com/afendin/ParallelMatrixMultiply/raw/main/formula.gif)

We can divide the work by creating one thread to compute each value (or each row) in C, and then executing those threads on different processors in parallel