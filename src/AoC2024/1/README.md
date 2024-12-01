# AoC 2024 - 1
## Task:
- Empty list of locations to check, fill it
- Start at the office
    - No Chief Historian there
    - But lists and notes of significant locations
- List of significant locatinos by `locationID`
- Two groups search the office
    - Each creating their own list
- What is the total distance between both lists?

## Given
- Comparing the two lists side by side (input)
    - Lists aren't similar
- Example:
```
3   4
4   3
2   5
1   3 
3   9
3   3
```
- Pair up the numbers and measure how far apart they are
    - Pair up the smallest number in the left with the smallest in the right
    - Then second-smallest left with second smalles right ...
- Within each pair figure out how far apart the numbers are:
    - Add up all of those distances
    - E.g. pair of 3 and 7, distance is 4, pair of 9 and 3, distance is 6
- In the example:
    - Smallest in left is 1, smallest in right is 3, distance is 2
    - Second-smallest is 2 and 3, distance 1
    - Third smallest in both is 3, distance 0
    - ...
- Total distance is defined as adding up all distances