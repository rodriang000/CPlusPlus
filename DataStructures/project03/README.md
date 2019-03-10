PROJECT 3
---------
Angel Rodriguez arodri27
Thomas Plummer tplumme2

Question 1
----------
Unsorted:

INSERT -
Best: O(1)
Average: O(1)
Worst: O(1)
When inserting into an unordered array it is simple insert to the end of the array, 
no other steps are needed.  

SEARCH -
Best: O(1)
Average: O(n)
Worst: O(n)
Since it is an unordered array we need to check every element to see if it matches
the key. It can be the first element checked, but is likely to be the nth element found,
giving it a O(n) for average and worst case. 

Sorted:

INSERT -
Best: O(1)
Average: O(n)
Worst: O(n)
Insertion becomes more complicated in a sorted array as for everytime you add an element,
it is reaquired to make n comparisons to see where it will fit, leading to a big O of n.

SEARCH:
Best: O(1)
Average: O(log(n))
Worst: O(log(n))
Since this is a sorted array, we can break down the search into comparisions with sections,
this leads to logarithimic time. The best case scenario is the first element checked is
the one being searched. 

Binary Search Tree:
INSERT -
Best: O(1)
Average: O(logn)
Worst: O(n)
Binary Search Tree has an average insert of logn as everything is broken down into branches
but because this tree doesn't have a balancing factor it could become linear giving it a
O(n) worst case. The best case is that the node is a root which takes constant time.

SEARCH-
Best: O(1)
Average: O(log(n))
Worst: O(n)
Searching for a node in a binary search tree takes on average O(log(n)) time since it is
likely that it will be balanced into halves, but since it doesn't self balance it could
end up linear and take O(n) time. The best case is that the root is the node being searched
for and it would take constant time.

Red-Black Trees:
INSERT
Best: O(1)
Average: O(log(n))
Worst: O(log(n))
Red-Black Trees are self balancing and so average and worst case have O(log(n)) as it
takes the time to balance only a section of the tree for each insertion only if it needs
to. The best case is O(1) when inserting the root.

SEARCH
Best: O(1)
Average: O(log(n))
Worst: O(log(n))
As stated above the O times are very similar, going through a red-black tree is like 
going through a balanced BST, giving you log(n) times on average and worst case. 

Treaps: 
INSERT
Best: O(1)
Average: O(log(n))
Worst: O(n)
Treaps only balance occasionally, they don't have set rules that the RB Trees have, so
they maintain an average of a balanced BST which is O(log(n)), but can become linear and
never balance, making it O(n), best case is inserting the root. 

SEARCH
Best: O(1)
Average: O(log(n))
Worst: O(n)
Similar to what was stated above, Treaps are most likley to take the form a a balanced
BST, but can become linear. So searching through a Treap on average is O(log(n)), but
can be linear giving it a worst case of O(n). Same scenario, the best case is O(1) for
the root. 

Question 2
----------

| Backend | NITEMS | PADLENGTH | Insert Time | Search Time |
|---------|--------|-----------|-------------|-------------|
| unsorted | 10 | 1 | 4.2885e-05 | 9.913e-06 |
| unsorted | 10 | 2 | 5.7929e-05 | 1.021e-05 |
| unsorted | 10 | 4 | 4.9794e-05 | 1.0878e-05 |
| unsorted | 10 | 8 | 4.9623e-05 | 1.0907e-05 |
| unsorted | 100 | 1 | 0.00041871 | 0.00040228 |
| unsorted | 100 | 2 | 0.00044432 | 0.00040829 |
| unsorted | 100 | 4 | 0.00045591 | 0.0003999 |
| unsorted | 100 | 8 | 0.00046436 | 0.00043209 |
| unsorted | 1000 | 1 | 0.034127 | 0.034587 |
| unsorted | 1000 | 2 | 0.034022 | 0.03487 |
| unsorted | 1000 | 4 | 0.035303 | 0.03469 |
| unsorted | 1000 | 8 | 0.036138 | 0.035456 |
| unsorted | 10000 | 1 | 3.3111 | 3.3206 |
| unsorted | 10000 | 2 | 3.3257 | 3.2605 |
| unsorted | 10000 | 4 | 3.4919 | 3.4334 |
| unsorted | 10000 | 8 | 3.5247 | 3.4756 |
| unsorted | 100000 | 1 |  INFINITY | INFINITY |
| unsorted | 100000 | 2 |  INFINITY | INFINITY |
| unsorted | 100000 | 4 |  INFINITY | INFINITY |
| unsorted | 100000 | 8 |  INFINITY | INFINITY |
| unsorted | 1000000 | 1 |  INFINITY | INFINITY |
| unsorted | 1000000 | 2 |  INFINITY | INFINITY |
| unsorted | 1000000 | 4 |  INFINITY | INFINITY |
| unsorted | 1000000 | 8 |  INFINITY | INFINITY |
| unsorted | 10000000 | 1 |  INFINITY | INFINITY |
| unsorted | 10000000 | 2 |  INFINITY | INFINITY |
| unsorted | 10000000 | 4 |  INFINITY | INFINITY |
| unsorted | 10000000 | 8 |  INFINITY | INFINITY |
| sorted | 10 | 1 | 5.1076e-05 | 1.4253e-05 |
| sorted | 10 | 2 | 5.5533e-05 | 1.6053e-05 |
| sorted | 10 | 4 | 5.2456e-05 | 1.4937e-05 |
| sorted | 10 | 8 | 5.3415e-05 | 1.5556e-05 |
| sorted | 100 | 1 | 0.00052368 | 0.00018741 |
| sorted | 100 | 2 | 0.00053545 | 0.00018832 |
| sorted | 100 | 4 | 0.00058887 | 0.00020568 |
| sorted | 100 | 8 | 0.00057223 | 0.0002098 |
| sorted | 1000 | 1 | 0.045749 | 0.0026615 |
| sorted | 1000 | 2 | 0.044804 | 0.0027515 |
| sorted | 1000 | 4 | 0.04606 | 0.0028303 |
| sorted | 1000 | 8 | 0.045624 | 0.0028412 |
| sorted | 10000 | 1 | 4.2032 | 0.034188 |
| sorted | 10000 | 2 | 4.1966 | 0.033871 |
| sorted | 10000 | 4 | 4.4826 | 0.034713 |
| sorted | 10000 | 8 | 4.5736 | 0.036443 |
| sorted | 100000 | 1 | 442.43 | 0.42168 |
| sorted | 100000 | 2 | 441.58 | 0.41994 |
| sorted | 100000 | 4 | 445.25 | 0.43322 |
| sorted | 100000 | 8 | 456.64 | 0.44048 |
| sorted | 1000000 | 1 |  INFINITY | INFINITY |
| sorted | 1000000 | 2 |  INFINITY | INFINITY |
| sorted | 1000000 | 4 |  INFINITY | INFINITY |
| sorted | 1000000 | 8 |  INFINITY | INFINITY |
| sorted | 10000000 | 1 |  INFINITY | INFINITY |
| sorted | 10000000 | 2 |  INFINITY | INFINITY |
| sorted | 10000000 | 4 |  INFINITY | INFINITY |
| sorted | 10000000 | 8 |  INFINITY | INFINITY |
| bst | 10 | 1 | 3.8196e-05 | 1.3163e-05 |
| bst | 10 | 2 | 4.5602e-05 | 1.2008e-05 |
| bst | 10 | 4 | 4.3322e-05 | 1.2411e-05 |
| bst | 10 | 8 | 4.3459e-05 | 1.2215e-05 |
| bst | 100 | 1 | 0.00012035 | 0.00013496 |
| bst | 100 | 2 | 0.00037685 | 0.00062828 |
| bst | 100 | 4 | 0.00037922 | 0.00061396 |
| bst | 100 | 8 | 0.00039646 | 0.00066834 |
| bst | 1000 | 1 | 0.0012845 | 0.0017275 |
| bst | 1000 | 2 | 0.0030704 | 0.0050678 |
| bst | 1000 | 4 | 0.032117 | 0.061322 |
| bst | 1000 | 8 | 0.032428 | 0.061126 |
| bst | 10000 | 1 | 0.016068 | 0.024668 |
| bst | 10000 | 2 | 0.033279 | 0.057938 |
| bst | 10000 | 4 | 3.3797 | 5.8005 |
| bst | 10000 | 8 | 3.5847 | 6.5114 |
| bst | 100000 | 1 | 0.1894 | 0.31177 |
| bst | 100000 | 2 | 0.35872 | 0.60515 |
| bst | 100000 | 4 | 27.901 | 46.227 |
| bst | 100000 | 8 |  INFINITY | INFINITY |
| bst | 1000000 | 1 |  INFINITY | INFINITY |
| bst | 1000000 | 2 |  INFINITY | INFINITY |
| bst | 1000000 | 4 |  INFINITY | INFINITY |
| bst | 1000000 | 8 |  INFINITY | INFINITY |
| bst | 10000000 | 1 |  INFINITY | INFINITY |
| bst | 10000000 | 2 |  INFINITY | INFINITY |
| bst | 10000000 | 4 |  INFINITY | INFINITY |
| bst | 10000000 | 8 |  INFINITY | INFINITY |
| rbtree | 10 | 1 | 4.7854e-05 | 1.2803e-05 |
| rbtree | 10 | 2 | 5.5877e-05 | 1.0165e-05 |
| rbtree | 10 | 4 | 5.7401e-05 | 9.767e-06 |
| rbtree | 10 | 8 | 5.044e-05 | 9.909e-06 |
| rbtree | 100 | 1 | 0.00017441 | 9.066e-05 |
| rbtree | 100 | 2 | 0.00017055 | 8.942e-05 |
| rbtree | 100 | 4 | 0.00018804 | 0.00010879 |
| rbtree | 100 | 8 | 0.00018831 | 0.0001048 |
| rbtree | 1000 | 1 | 0.001799 | 0.0010981 |
| rbtree | 1000 | 2 | 0.0017109 | 0.0010325 |
| rbtree | 1000 | 4 | 0.0018252 | 0.0011471 |
| rbtree | 1000 | 8 | 0.0018411 | 0.0012307 |
| rbtree | 10000 | 1 | 0.020651 | 0.012666 |
| rbtree | 10000 | 2 | 0.020071 | 0.012673 |
| rbtree | 10000 | 4 | 0.019494 | 0.012393 |
| rbtree | 10000 | 8 | 0.021485 | 0.014159 |
| rbtree | 100000 | 1 | 0.23353 | 0.15961 |
| rbtree | 100000 | 2 | 0.23321 | 0.16038 |
| rbtree | 100000 | 4 | 0.22048 | 0.15574 |
| rbtree | 100000 | 8 | 0.24916 | 0.16199 |
| rbtree | 1000000 | 1 | 2.6357 | 1.8113 |
| rbtree | 1000000 | 2 | 2.6118 | 1.7793 |
| rbtree | 1000000 | 4 | 2.6648 | 1.722 |
| rbtree | 1000000 | 8 | 2.9426 | 1.8296 |
| rbtree | 10000000 | 1 | 28.596 | 19.074 |
| rbtree | 10000000 | 2 | 28.232 | 18.657 |
| rbtree | 10000000 | 4 | 27.287 | 18.764 |
| rbtree | 10000000 | 8 | 34.598 | 19.585 |
| treap | 10 | 1 | 6.4161e-05 | 1.3264e-05 |
| treap | 10 | 2 | 6.657e-05 | 1.2395e-05 |
| treap | 10 | 4 | 6.8545e-05 | 1.2941e-05 |
| treap | 10 | 8 | 6.5565e-05 | 1.2649e-05 |
| treap | 100 | 1 | 0.00031919 | 0.00014536 |
| treap | 100 | 2 | 0.00058076 | 0.00063122 |
| treap | 100 | 4 | 0.00060143 | 0.00061578 |
| treap | 100 | 8 | 0.00059408 | 0.00061095 |
| treap | 1000 | 1 | 0.0032559 | 0.0018599 |
| treap | 1000 | 2 | 0.0051701 | 0.005105 |
| treap | 1000 | 4 | 0.03588 | 0.057024 |
| treap | 1000 | 8 | 0.03736 | 0.062132 |
| treap | 10000 | 1 | 0.034885 | 0.023065 |
| treap | 10000 | 2 | 0.054438 | 0.057348 |
| treap | 10000 | 4 | 1.8289 | 2.898 |
| treap | 10000 | 8 | 3.3404 | 5.1141 |
| treap | 100000 | 1 | 0.3941 | 0.31633 |
| treap | 100000 | 2 | 39 | 67.581 |
| treap | 100000 | 4 | 54.629 | 86.684 |
| treap | 100000 | 8 | 57.397 | 89.314 |
| treap | 1000000 | 1 |  INFINITY | INFINITY |
| treap | 1000000 | 2 |  INFINITY | INFINITY |
| treap | 1000000 | 4 |  INFINITY | INFINITY |
| treap | 1000000 | 8 |  INFINITY | INFINITY |
| treap | 10000000 | 1 |  INFINITY | INFINITY |
| treap | 10000000 | 2 |  INFINITY | INFINITY |
| treap | 10000000 | 4 |  INFINITY | INFINITY |
| treap | 10000000 | 8 |  INFINITY | INFINITY |


Question 3
----------
| Backend | Text   | File Size (bytes) | Elapsed Time |
|---------|--------|-----------|--------------|
| unsorted | Pride-and-Prejudice |  724725 |  0m25.888s |
| sorted | Pride-and-Prejudice |  724725 |  0m48.135s |
| bst | Pride-and-Prejudice |  724725 |  0m0.398s |
| rbtree | Pride-and-Prejudice |  724725 |  0m0.390s |
| treap | Pride-and-Prejudice |  724725 |  0m0.422s |
| unsorted | Jungle-Book.txt |  304376 |  0m11.198s |
| sorted | Jungle-Book.txt |  304376 |  0m13.394s |
| bst | Jungle-Book.txt |  304376 |  0m0.172s |
| rbtree | Jungle-Book.txt |  304376 |  0m0.176s |
| treap | Jungle-Book.txt |  304376 |  0m0.190s |
| unsorted | Les-Miserables.txt |  3324334 |  7m54.381s |
| sorted | Les-Miserables.txt |  3324334 |  18m33.108s |
| bst | Les-Miserables.txt |  3324334 |  0m1.948s |
| rbtree | Les-Miserables.txt |  3324334 |  0m2.057s |
| treap | Les-Miserables.txt |  3324334 |  0m2.035s |

Question 4
----------
Sorted and unsorted preformed the worst out of our data types. The reason they did so
is as the size increased the average case and worst case n affected them more and more.
BST performed better than them, but as the padding and N items increased it acted more
linerally leading to longer times. Treap performed better than the BST due to it's 
ability to self balance on occassion, but as the numbers increased the odds of balancing
became less and less which made it struggle. RB-Trees performed the best overall with
their consistant self-balancing ability. 

File Size appears to affect Sorted and Unsorted the most. BST, RBTree, and Treap seem 
less affected with the larger files. Sorted went from taking around 50 seconds to 18 min
with Les-Miserables. NITEMS, PADLENGTH, and File Size had minimal effect on rb trees.
On the other hand BST, unsorted, and sorted took increasingly more time as NTIMES 
increased and PADLENGTH increased, with Treaps making a noticable difference as 
PADLENGTH increased with NITEMS.
became increasingly affected as those items increased, particularly sorted and unsorted.

In our opinion RBTrees are the best map backend due to their consistent time complexity
with both insertion and searching. However wo do realize it is difficult to implement
but once implemented it appears to be the most consistant data structure as a backend.


Contributions
-----------
Angel: I did the README Q. 2, 3, and 4. Also I did Unsorted and BST and frequenceis
Thomas: He worked on Sorted, Treap, altered map.h, and helped with Q1. 
