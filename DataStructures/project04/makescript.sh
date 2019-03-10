#!/bin/bash

echo "| Backend | NITEMS | PADLENGTH | Insert Time | Search Time |"
echo "|---------|--------|-----------|-------------|-------------|"
for backend in unsorted sorted bst rbtree treap unordered
do
	  slow=false
	    for i in 10 100 1000 10000 100000 1000000 10000000
		      do
			          for pad in 1 2 4 8
					      do
						            if [ "$slow" = false ]
								          then
										          echo -n "| $backend | $i | $pad | "
											          str=`timeout 10m ./map_bench -b $backend -n $i -p $pad`
												          rc=$?
													          if [ $rc -eq 124 ] # We timed out.
															          then
																	            slow=true
																		              echo " INFINITY | INFINITY |"
																			              else
																					                echo $str | tr -d '\n' | awk '{print $2 " | " $5 " | "}'
																							        fi
																								      else # No use in testing something that will be slower.
																									              echo -n "| $backend | $i | $pad | "
																										              echo " INFINITY | INFINITY |"
																											            fi
																												        done
																													  done
																												  done
