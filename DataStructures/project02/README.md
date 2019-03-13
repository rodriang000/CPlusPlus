Thomas Plummer & Angel Rodriguez
tplumme2         arodri27
(implementation of different sorting methods)

Question 1
-----------
STL Sort has a time complexity of O(n\*log(n))
Qsort has a time complexity of O(n\*log(n))
Merge sort has a time complexity of O(n\*log(n))
QuickSort has a time complexity of O(n^2), but
an average case of O(n\*log(n))

Question 2
----------

| Mode    | Size  | Elapsed Time(s)| Memory (Mb)|
|---------|-------|---------------|---------|
| STL     | 10    | .001998       | 1.1289  |
| STL     | 100   | .001998       | 1.1796  |
| STL     | 1000  | .004998       | 1.2539  |
| STL     | 10000 | .036994       | 2.0078  |
| STL     | 100000| .464928       | 9.5429  |
| STL     | 1000000| 6.38402      | 85.074  |
| STL     | 10000000| 81.21265    | 840.3   |
| QSORT   | 10    | .001998       | 1.1679  |
| QSORT   | 100   | .001998       | 1.1757  |
| QSORT   | 1000  | .004998       | 1.3007  |
| QSORT   | 10000 | .036994       | 2.1054  |
| QSORT   | 100000| .44993        | 10.351  |
| QSORT   | 1000000| 5.7691       | 92.75   |
| QSORT   | 10000000| 65.284      | 916.722 |
| MERGE   | 10    | 0.001998      | 1.164   |
| MERGE   | 100   | 0.001998      | 1.1796  |
| MERGE   | 1000  | 0.004998      | 1.34375 |
| MERGE   | 10000 | 0.040992      | 2.99218 |
| MERGE   | 100000| .504922       | 19.468  | 
| MERGE   | 1000000| 1.6417       | 119.93  | \* Seg fault
| MERGE   | 10000000|12.100       | 795.14  | \* Seg fault
| QUICK   | 10    | .002998       | 1.165062|
| QUICK   | 100   | .001998       | 1.11718 |
| QUICK   | 1000  | .004998       | 1.242188|
| QUICK   | 10000 | .038993       | 1.929688|
| QUICK   | 100000| .500923       | 8.79687 |
| QUICK   | 1000000| 6.7829       | 77.4609 |
| QUICK   | 10000000| 95.54       | 764.105 |

1.) All sorting methods seemed to perform similarly, with tradeoffs between
time and memory. These differences could come from how each sorting method allocates
memory to deal with unsorted information
2.) This shows that if theoretical complexity is identical between two sorting methods,
it doesn't neccesarily mean that their performance in the real world will be the same. 
3.) It depends! If you need speed, then it seems that Qsort is the fastest method. But if
you are low on memory, then quicksort would be the best method to use. 
Ultimately, in our humble opinion, STL sort seems to fit a nice balance between time
and memory.  

Summary
-------
Angel Rodriguez: I halepd write node.cpp, list.cpp, stl.cpp and quick.cpp. I also made
the readme. 

Thomas Plummer: He made mergesort, qsort, and the scripts for testing the different
sort methods in the readme. 

