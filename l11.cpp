// In this video we learned about the time and the space complexity

// Time complexity:
// There are eight types of complexities listed in decreasing order
// O(n!)
// O(2^n)
// O(n^3)
// O(n^2)
// O(nlogn)
// O(n)
// O(logn)
// O(1)

// the o(1) is the best time complexity and O(n!) is the worst or the slowest time complexity
// For solving the leet code problems . just remember that our machines are designed to perform 10^8 operations per second . so it is advised to use the code according to the constraints provided for n (input) at the bottom of the questions
// <10^8 -----------> O(n) or O(logn)
// <10^6 -----------> O(nlogn)
// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------



// Working with the space complexity:
// Space complexity is decided by the amount of memory our program takes while its execution
// for constant memory allocation : O(1)
// if memeory allocation depends on the variable n : O(n)
// for loops doesn't change the space complexity of the code because for each iteration the previous allocations are deleted and new allocations are made . So ultimately the amount of memeory used remains the same.