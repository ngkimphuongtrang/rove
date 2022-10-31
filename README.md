# rove 
Using basic external sort

- Divide file into runs fit in memory limit, use internal sort for each run 
- Use a min heap to save runs minimum element in each file run

# Command 
g++ myfsort.cpp -o myfsort && ./myfsort "input file name" "output file name" "memory limit in bytes"
# Sample Command
g++ myfsort.cpp -o myfsort && ./myfsort input.txt output.txt 8

# Issues
- Haven't handled non-ascii symbols
- Ambiguity in number of lines in file and size of file in the code
# References
- https://github.com/chiendo97/external-sort-cpp
- https://www.geeksforgeeks.org/external-sorting/
- https://thodrek.github.io/cs564-fall17/lectures/lecture-11/Lecture_11_ExtSort.pdf