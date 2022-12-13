# CS225-FA-2022-Final-Project
The graph.h and graph.cpp are the most important files where we initialized the graph of the road system and implemented all the algorithms. 

The main.cpp reads the data from the cedge.txt and cnode.txt files from the data file. It executes the program that we intend to run on finding the shortest path between two nodes from the data read.

The test.cpp is a test file to run test cases to see if the code works.

The data file contains all the road network data, which includes nodes and edges, from the University of Utah. It also contains other test cases, where we manually put in different number values for nodes and edges.

The documents file contains all of the documentations during the project, which includes the written report, team contract, and proposal.

The build file contains Cmake files.


To build and run the code, you can open a terminal at build file, then type in make main.cpp to execute the whole program. 

You can also run tests by doing make test.cpp. 

The output should give the shortest path by BFS (unweighted), shortest path by A*(weighted), and the shortest distance calculated by Floyd-Warshall. 

The input of the program is the data from txt files of nodes and edges, and the typed in coordinates that the user wants to find the shortest path between.

The main function will automatically read the txt files, and the input files can be changed by changing the names of the file in the main function. 

Also, the coordinates can be changed by changing them in the main function.
