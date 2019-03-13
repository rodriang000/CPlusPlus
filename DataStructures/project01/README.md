Angel Rodriguez && Thomas Plummer
arodri27           tplumme2
(scheme interpreter project)

Question1
---------
The complexity of our interpretor is O(log n) due to the fact that the interpreter only has to read binary arguments and do a simple arithmatic process on the children and report it to the parent. Therefore, it keeps doing simple equations for n size. The stack only every pops and pushes and doesn't do any sorting, so it's complexity is O(1) and because of that it doesn't affect the time complexity of the interpreter. 

Question2
---------
In uscheme, 2,753,037 bytes were allocated in total heap usage. In uschemeSmart, 4,063,757 bytes were allocated. Making it so that uschemeSmart takes up more memory than Uscheme.
UschemeSmart is 97kB while Uscheme is 88kB, therefore USchemeSmart takes more space as
an executable.  

Question3
---------
We prefered uschemeSmart! It was easier to implement as a programmer, and a deconstructor was not needed. 
Downside of smart pointers include larger memory, and file size, as well as it is difficult to import classes that use them into languages that don't have smart pointers. Regular pointers take less memeory but you have to be more mindfull of potential memory leaks. 

Question4
---------

In the structure it would be less of a binary tree and a tree of abritrary size, Each parent would not know how many children it has until the data is enetered in. So instead of having a left and right child, each node could have anywhere from 0 to n children. The parser would have to keep adding tokens until a ")" is reached and put them all into children of a same parent. The intepreter would have to be able to understand to keep reading numbers from children until there are no children left.


Angel: I did the readme, the structures, parsar, and initial implentation.
Thomas: He did the implementation of the smart pointers as well as the debug for uscheme and uschemeSMart.  
