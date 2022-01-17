## Memory management

Gruppe 16
01/11/2021

### Strategies implemented
- Best fit
- First fit
- Worst fit
- Next fit

### Guide

In order to run at tests run these commands:

- `make`

- "./mem -test -f0 all first" for first-fit
- "./mem -test -f0 all best" for best-fit


In order to run different algorithms strategies:

- "./mem -try best"
- "./mem -try next "
- "./mem -try worst"
- "./mem -try first"


### Question / Answers


##### 1) Why is it so important that adjacent free blocks not be left as such?  What would happen if they were permitted?
 
It is important because the free blocks will become too small to meet the request to allocate memory even if there is a sufficient amount of free memory available. 

##### 2) Which function(s) need to be concerned about adjacent free blocks?

The "myfree()" function, because when the memory manager free ups a block, it should combine adjacent free blocks. 

##### 3) Name one advantage of each strategy.
- First-fit
 	 - It is the fastest algorithm because it searches as little as possible. 
 	 
- Next-fit 
	  - Memory blocks is more evenly distributed in the memory pool, because it does not start looking for a free block every time from the beginning, but from where it left off. 
- Best-fit:
	- It guarantees that the fragment left behind is as small as possible, so minimizes the wastage space
	
- Worst-fit
  	-It reduces the rate of production of small gaps. 

##### 4) Run the stress test on all strategies, and look at the results (tests.out). What is the significance of "Average largest free block"?  Which strategy generally has the best performance in this metric?  Why do you think this is?

The first strategy has the best performance in metric because the the size of average largest free block is significantly bigger than most of the other strategies but not so much from the best strategy. Although the first performs also better in time performance.
##### 5) In the stress test results (see Question 4), what is the significance of "Average number of small blocks"?  Which strategy generally has the best performance in this metric?  Why do you think this is?

The best fit test performs better in results due to tightest fit is always chosen. The fit is usually sufficiently tight that the remainder of the block is unusuably small.

##### 6) Eventually, the many mallocs and frees produces many small blocks scattered across the memory pool.  There may be enough space to allocate a new block, but not in one place.  It is possible to compact the memory, so all the free blocks are moved to one large free block.  How would you implement this in the system you have built?

There could occur two different cases of free small blocks. The first case is when many small free block is placed contiguous. This case is solved in our implementation of memory management and it works as follows. Every time a block needs to be made free, the `myfree()`  function checks, if the block before or after is free. If it is a case, so joins these blocks to one bigger block.  

#####7) If you did implement memory compaction, what changes would you need to make
in how such a system is invoked (i.e. from a user's perspective)?
 ______
|  OS  |0K
|______|400K
|  P1  |
|______|
| 800k |
|______|
| 900k |
|______| 
|      |
|  P2  |
|      |
|      |
|      |
|______|
| 1600k|
|______|
|______|
|______|
| 2000k|
|______|


In compaction,the idea is o move all the processes towards one end of memory and all the free blocks of memory towards the other end. For example in the image above, when the compaction algorithm is used, we move the process P2 upwards, and the free block of 100K between P1 and P2 downwards thus forming a big block of 500 K. The changes made to invoke such a system are:
- The adresses of the memories should be updated
- Compaction is only possible when dynamic relocation is used i.e when the adress binding is done at runtime.

####8) How would you use the system you have built to implement realloc?  (Brief
explanation; no code)

The whole idea with the "realloc"" is to resize the memory block. There are few steps involved in the realloc funtion.
- First it will the check the size of the request is available
- Secondly it will use my mymalloc to allocate a new block and copies the data from the old to the new block
- Third, the free() is used to free or to remove the previously allocated block. 

####9) Which function(s) need to know which strategy is being used?  Briefly explain why this/these and not others.

- The "mymalloc" functions because it allocates memory differently depending on the strategy used.

##### 10) Give one advantage of implementing memory management using a linked list over a bit array, where every bit tells whether its corresponding byte is allocated.

From a memory allocation point of view, linked lists are more efficient than arrays. Unlike arrays, the size for a linked list is not pre-defined, allowing the linked list to increase or decrease in size as the program runs. This is possible because to insert or delete from a linked list, the pointers need to be updated accordingly.

 	








