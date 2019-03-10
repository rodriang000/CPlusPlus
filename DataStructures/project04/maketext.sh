#!/bin/bash

echo "| Backend | Text   | File Size (bytes) | Elapsed Time |"
echo "|---------|--------|-----------|--------------|"

for text in Pride_and_Prejudice Beowulf.txt Jungle_Book.txt Les_Miserables.txt #replace these with your texts from gutenberg project
do
	  for backend in unsorted sorted bst rbtree treap
		    do
			        file_size=$(stat -c%s "$text")
				    utime="$( TIMEFORMAT='%lU';time ( ./frequencies -b $backend < $text) 2>&1 1>/dev/null )"
				        echo -n "| $backend | $text | "
					    echo -n " $file_size | "
					        echo " $utime |"
						  done
					  done
