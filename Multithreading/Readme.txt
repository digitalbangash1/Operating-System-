a)What is the idea of the application?

The idea implemented in our project is about a single lane problem and a solution to the problem. There is a road construction underway and there is single lane that connects the two cities. The problem has its root in the singe lane which can take only one car at a time. The singe lane is open in two direction i.e. east and west. The single lane allows only one car to cross by at a time from any direction to avoid deadlock and closing for the other cars using semaphores to avoid accident.

b) Why is concurrency needed?
Concurrency in computing is needed to avoid resources starvation which can result in problems like deadlocks. However, in our project, the concurrency is needed to avoid accident of the cars that share the same resource i.e. singe lane.

c) What could be the potential issues specifical?
The potential issues could be as following:
1.	The distribution of threads could be hard to control thus resulting in creating of many cars object in both direction ending up in a queue of cars waiting to pass the singe lane.so that neither side can move.
2.	Testing and debugging is difficult.

d) Address race conditions

Race conditions happens when several threads get access to the same data or use shared variable and every thread try to change it, and it depends on threads scheduling algorithm.
In our program the shared data would be the bridge, because both directions need to share it and thus if cars from both directions would enter the bridge at the same time, the result would be an accident.

e) Solution for race conditions

Mutual exclusion is the way to avoid the race condition. The way that the mutual exclusion works is like when a thread using a shared data so the other threads can’t use it until the first thread allows to use it.
In our solution we decided to use semaphore to control access to a common resource which is the bridge, when a car enters the bridge from either direction it is the only car that has access to the bridge at the given time.

f) Address deadlocks and starvation

Deadlock is a situation where a set of processes are blocked because each process is holding a resource and waiting for another resource acquired by some other process. Starvation is the problem that occurs when high priority processes keep executing and low priority processes get blocked for indefinite time.

g) Solution for deadlocks and starvation
There could be some possible solution to the problem, i.e. using semaphores and synchronization, design an algorithm that prevents deadlock. However, in our solution, we have taken only semaphore into account.




Output looks like this:
Car from east:  28 is waiting
Car from west:  27 is waiting
Car from east:  28 has the green light 
Car from east:  28 is passing the lane
Car from east:  28 has passed the lane
Car from west:  27 has the green light 
Car from west:  27 is passing the lane
Car from west:  27 has passed the lane
Car from west:  29 is waiting
Car from west:  29 has the green light 
Car from west:  29 is passing the lane
Car from west:  29 has passed the lane
Car from east:  30 is waiting
Car from east:  30 has the green light 
Car from east:  30 is passing the lane
Car from east:  30 has passed the lane
