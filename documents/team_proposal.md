## Leading Question 
Given a dataset of roads in North America, we will implement an algorithm to find the shortest path between 2 or more points on the map. We will accomplish this by reading a set of nodes and edges to represent a road network. The edges will have weights corresponding to their distance between the nodes that they connnect. 
## Dataset Acquisition
## Data Format
We will use an open-source dataset from the CS department of the University of Utah. This dataset provides a set of around 175000 nodes with coordinates and 179000 edges with L2 distance. We plan to use all of the data in the dataset. The format of the nodes dataset is: ID, X-coordinate, Y-coordinate. The format of the edges dataset is: ID, Start Node ID, End Node ID, Distance.
## Data Correction
If the input data is missing entries, then we will ignore the line in our dataset. Similarly, for edges that connect to undefined nodes, we will ignore those edges.
## Data Storage
We will store the set of edges into a general weighted tree with distance weight. The set of nodes with coordinates will be stored into a large list. We will create our own classes to store the data in each edge and node. The storage cost will be roughly O(n) for each node and edge.

## Algorithm 
We will create an algorithm to find the closest starting node from a given input of coordinates. To do this, we will use BFS to traverse the pre-sorted tree of nodes with their given coordinates. We will calculate the distance between the given point and the node to determine the path of the traversal. The expected output is a single node that is the closest to the given coordinates. We will use this information as the starting and ending point of our path algorithm. The worst-case efficiency of this algorithm is O(n), where n is the number of edges and the number of nodes. The memory efficiency of this algorithm is O(n).

We will create an algorithm to find the shortest path between 2 nodes. To do this, we will use the A* search algorithm. The distance will be used as the weight of an edge. The expected output is a list of edges representing roads to take for the shortest path. We will visualize this output by drawing the edges and nodes on a map of North America. The worst-case time efficiency of this algorithm is O(b^d), where b is the branching factor and d is the depth of the shortest path. The memory efficiency of this algorithm is also O(b^d).
## Timeline
Week 1 (Nov 7-13): Implement reading and storage of the datasets.
Week 2 (Nov 14-20): Start implementing the algorithm to find the closest starting point given a set of coordinates.
Week 3 (Nov 21-27): Continue implmenting the algorithm.
Week 4 (Nov 28-Dec 4): Implement algorithm to find the shortest path between 2 points.
Week 5 (Dec 4-Dec 8): Make the presentation and other documents.
