Our leading question was to find the shortest path between two or more points in the map. In this project, we explore three different algorithms(BFS (Breadth-First Search), Floyd-Warshall, and A*) for solving this problem and applying them to the road network of California.

BFS is a simple, brute-force algorithm that guarantees to find the shortest path between two points in a graph, if one exists. However, it has a time complexity of O(n^2), which means that it may not be suitable for large graphs.

Floyd-Warshall is a more sophisticated algorithm that is able to find the shortest paths between all pairs of points in a graph. It has a time complexity of O(n^3), which is better than BFS in terms of scalability, but still may not be suitable for very large graphs.

A* is a popular heuristic search algorithm that is able to find the shortest path between two points more efficiently than BFS or Floyd-Warshall. It uses a combination of heuristics and graph search to prune the search space and find the optimal path.

In this project, we implement and compare the performance of these three algorithms on a variety of test cases.

To implement the BFS, Floyd-Warshall, and A* algorithms, we first represent the input graph as an adjacency matrix. This allows us to easily access the distances between any two points in the graph.

Next, we implement the BFS algorithm by starting at the source point and exploring all of its neighbors in a breadth-first manner. This means that we first explore all of the neighbors of the source point, then all of the neighbors of those neighbors, and so on. We continue this process until we reach the destination point, at which point we have found the shortest path between the source and destination.

To implement Floyd-Warshall, we first initialize a distance matrix to represent the distances between all pairs of points in the graph. We then iterate over the matrix and use a dynamic programming approach to update the distances based on the distances between the points that are currently being considered. This allows us to find the shortest path between all pairs of points in the graph.

Finally, we implement the A* algorithm using a priority queue to store the unexplored points. At each step, we choose the point with the lowest estimated cost (based on the distance from the source and the heuristic estimate of the distance to the destination) and expand it. This allows us to prune the search space and find the shortest path more efficiently than with BFS or Floyd-Warshall.

We tested the performance of the BFS, Floyd-Warshall, and A* algorithms on a small test data set and the graph model from the California road network data. Overall, we found that BFS performed well on small data sizes but was not scalable to larger ones. Floyd-Warshall performed better than BFS on large graphs but was still not efficient enough for very large graphs. A* performed the best on all of the test cases, consistently finding the shortest path in the least amount of time. 

We implemented and compared the performance of BFS, Floyd-Warshall, and A* algorithms for finding the shortest path between two points in a graph. We found that A* performed the best on all of the test cases, due to its ability to prune the search space using heuristics. This makes it a good choice for finding the shortest path in real-world scenarios where the input graph may be large and complex.

In sum, BFS was used to find the shortest path between two nodes unweighted, which shows the shortest path with least turns. The A* shows the shortest path in a weighted graph, which shows the path with least distance. The Floyd-Warshall algorithm calculates the shortest distance between the two nodes. These approaches answer our leading question of how to find the shortest path between two points in a map by representing them in a graph in an adjacency matrix.

We wanted to take latitude and longitude coordinates from the user to calculate the closest coordinates in the node data to then find the shortest distance between the nodes. However, it was difficult to implement functions to receive direct coordinate inputs from users to calculate which nodes to use in the data provided in the California road network data. As a result, we had to get input in the main function and manually change the coordinate values in the code. If we had more time, we could have implemented the user interface. 
