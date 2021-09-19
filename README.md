# I. How to run push_swap

#### **a. With an environment variable :**
- 1. without any checker

  `ARG="5 1 3 4 2" && make push_swap && ./push_swap $ARG`

- 2. without any checker and using the command `wc` to count the instructions

  `ARG="5 1 3 4 2" && make push_swap && ./push_swap $ARG | wc -l`

- 3. with the checker given by the school

  `ARG="5 1 3 4 2" && make push_swap && ./push_swap $ARG | ./checker_linux $ARG`

- 4. with my own checker

  `ARG="5 1 3 4 2" && make push_swap && make checker && ./push_swap $ARG | ./checker $ARG`

- 5. only with my own checker

  `./checker "5 1 3 4 2"`. Then, enter the list of instructions followed by enter. To stop the lecture of the instruction, ctrl-D in order to have an EOF

#### **b. Without an environment variable :**

- 1. without the checker

  `make push_swap  && ./push_swap "5 1 3 4 2"`

- 2. without the checker and using the command `wc` to count the instructions

  `make push_swap  && ./push_swap "5 1 3 4 2" | wc -l`

- 3. with the checker given by the school

  `make push_swap  && ./push_swap "5 1 3 4 2" | ./checker_linux "5 1 3 4 2"`

- 4. with my own checker

  `make push_swap  && ./push_swap "5 1 3 4 2" | ./checker "5 1 3 4 2"`

# II. How to test push_swap

Online random number generator : https://numbergenerator.org/randomnumbergenerator/1-500

## a. Push_swap program
- Test with arguments that aren’t integers. The program must display "Error"
- Test with duplicates. The program must display "Error"
- Test with empty string. The program must not display anything
- Test with a mix of negative and positive numbers and then, only positive numbers and then, only negative numbers.
- Test with arguments bigger than an integer (`INT_MIN`, `INT_MAX`). The program must display "Error"
- Test leaks with the command line (only mac) : `make push_swap && leaks -atExit -- ./push_swap "5 1 3 4 2"`
- When running the program by passing the argument directly to the executable (i.e without an environment variable), check if it accepts string but also a list of integers.

  Example :
    `./push_swap "5 1 3 4 2"` and also `./push_swap 5 1 3 4 2`
- Run the following command `./push_swap 42`. The program should display nothing (0 instruction).
- Run the following command `./push_swap 0 1 2 3`. The program should display nothing (0 instruction).
- Run the following command `./push_swap 0 1 2 3 4 5 6 7 8 9`. The program should display nothing (0 instruction).

## b. Checker program

- Test checker with non numeric parameters. The program must display "Error"
- Run checker with a duplicate numeric parameter. The program must display "Error".
- Run checker with only numeric parameters including one greater than MAXINT. The program must display "Error".
- Run checker without any parameters. The program must not display anything and give the prompt back.
- Run checker with valid parameters, and write an action that doesn't exist during the instruction phase. The program must display "Error".
- Run checker with valid parameters, and write an action with one or several spaces before and/or after the action during the instruction phase. The program must display "Error".
- Run checker with the following command `./checker 0 9 1 8 2 7 3 6 4 5` then write the following valid action list
"[sa, pb, rrr]". Checker should display "KO".
- Run checker with the following command `./checker 0 1 2` then press CTRL+D without writing any instruction. The
program should display "OK".
- Run checker with the following command `./checker 0 9 1 8 2` then write the following valid action list
"[pb, ra, pb, ra, sa, ra, pa, pa]". The program should
display "OK".

## c. Online tester

  https://github.com/lmalki-h/push_swap_tester

  https://github.com/tsannie/push_swap_tester

# III. How to grade push_swap

Pour 3 values = entre 2 / 3 opérations

Pour 5 values = max 12

Pour 100 values = barème de 1 à 5

  - moins de 700: 5
  - moins de 900: 4
  - moins de 1100: 3
  - moins de 1300: 2
  - moins de 1500: 1

Pour 500 values = barème de 1 à 5

  - moins de 5500: 5
  - moins de 7000: 4
  - moins de 8500: 3
  - moins de 10000: 2
  - moins de 11500: 1

# IV. How I did push_swap
#### **a. For 3 random numbers :**
- Only five possible cases
- Compare top number to middle number, middle number to bottom number, and bottom   number to top number
#### **b. For 5 random numbers :**
- Find the biggest value (and its position) and push it to stack b
- Find the smallest value (and its position) and push it to stack b
- Sort the three remaining numbers
- Push back the numbers from stack b to stack a

#### **c. For 100 random numbers and above :**
- Use a pre-sorting algorithm to push numbers from stack a to stack b:
    - Find the smallest and biggest value. And then divide this range into 5 chunks. Ex : 0 is the smallest and 10000 is the biggest value. I'll have five chunks of 2000 numbers (0->2000, 2000->4000, 4000->6000, 6000->8000, 8000->10000)
    - Then do a pre-sort by chunk. For each number that is present in the chunk, I calculated its distance from the edge of the stack (either it is closer to the top or it is closer to the bottom). Then, I move the number that is closest to the top edge of the stack a (in order to use as few instructions as possible) and push it onto the stack b.
- Use an adapted version of insertion sort :
    - I push the numbers from stack b to stack a using insertion sort
    - This means, that I sort one number at a time. I take the number x from stack b and then I iterate in stack a to find the number that is just above our number x. And I'll push it using the minimum operation by still using the method of: "Should this number be in the top half or the bottom half of the stack a ?"

#### **d. For 500 random numbers and above :**
- if the biggest number value is below 999: use an adapted version radix sort :
  - Instead of sorting with base ten numerals, I'll sort with base two numerals. (Because I don't have 10 stacks, I only have 2 stacks).
  - No need to convert in binary. Using % 2 to get the last digit in binary
  - Using bitwise operator >> to shift all the bits to the right
  - Break out of the while loop when the ith-digit of the biggest number is 0
- if the biggest number value is above 999: use insertion sort

# V. Documentation that helped me
- https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
- https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- Reminder on pointer and why to use double pointer for a linked list : https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/









