# push_swap
Because Swap_push isn’t as natural

Write a program which calculates and displays  
on the standard output the smallest number of Push_swap instruction language that  
sorts the integer arguments received.  
you have 2 stacks a and b, the stack a contains a random amount of negative and/or positive numbers  
which cannot be duplicated.  
The goal is to sort in ascending order numbers into stack a.  
  
#### To do this you have the following operations:
* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.
  
You can see the full assignment here [subject](https://github.com/cbridget42/push_swap_42/blob/main/subject/en.subject.pdf)  
Coding style: [norminette](https://github.com/cbridget42/push_swap_42/blob/main/subject/en.norm.pdf)
  
### Requirements:
* ruby is needed for tests.
  
### Usage:
* first you need to download the repository and compile the code! To do this, run:
	```bash
	git clone git@github.com:cbridget42/push_swap_42.git
	cd push_swap_42
	make
	make bonus //compile bonus
	```
* then you will have executables named push_swap and checker.
	+ to run with 100 random nambers enter this command:
  ```bash
  ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG
	```
	+ to run with 100 random nambers and checker enter this command:
  ```bash
  ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	```
* also you can:
	```bash
	make clean //remove objects files
	make fclean //remove objects files and executable files
	```
* script to generate random numbers:
  ```bash
  `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
	```
  
### Usage example:
![image](https://github.com/cbridget42/push_swap_42/blob/main/images/push_swap.svg)
  
### Tests:
![image](https://github.com/cbridget42/push_swap_42/blob/main/images/Screenshot%20from%202022-11-14%2021-16-55.png)
![image](https://github.com/cbridget42/push_swap_42/blob/main/images/Screenshot%20from%202022-11-14%2021-17-42.png)
  
### final score:
![image](https://github.com/cbridget42/push_swap_42/blob/main/images/Screenshot%20from%202022-11-14%2021-20-09.png)
  
