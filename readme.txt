File Content:
	linkedlist.h -> implementation of link list
	shuffler.h -> library for shuffl an array of elements.
	serial.c -> serial implementation of the link list operations
	mutex.c -> link lint operations implementation with mutex.
	lock.c -> link list implementation with read write locks.

In both mutex.c and lock.c, we used 'pthread' libarary in C for write multy threding 
applications. 

how to compile:
	gcc -pthread -o serial serial.h
	gcc -pthread -o mutex mutex.h
	gcc -pthread -o lock lock.h

run the code:
	arguments:

	t_count - total thread count.
	n - number of elements in starting point.
	m - number of operations to be perfom
	mem_pre - member function call probability
	inst_pre - insert function call probability
	del_pre - delete function call probability
	
	serial -> (n, m, mem_pre, inst_pre, del_pre)
	mutex -> (t_count, n, m, mem_pre, inst_pre, del_pre)
	lock -> (t_count, n, m, mem_pre, inst_pre, del_pre)

