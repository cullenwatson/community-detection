**Community Detection in Networks**

**Project Overview**<br>
The goal of this project was to implement the Girvan-Newman algorithm to detect communities in a network. Overall, given a GraphML file, my project processes the file and applies the Girvan-Newman algorithm. Consequently, it then outputs the processed GraphML file after applying the algorithm. 
<br>

This new GraphML file if read by a GraphML reader, such as NetworkX, would then reveal to you the communities in the graph. Note: I have provided the python script I used to plot the GraphML files. 

**Algorithm Overview**<br>
In a broad overview, the Girvan-Newman algoritm calculates the edge betweeness for all edges in the graph and then removes the edge with the highest betweenness. To calculate the edge betweenness, I used the Dijkstra's algorithm, as part of the Boost library, to compute the shortest path from one chosen vertex to all other vertices in the graph.
<br>
I stored all the paths into a Edge Centrality Map. The key in this map is a unique edge, and the value is the resulting frequency  in which they appeared in Dijkstra's algorithm. After doing this for one vertex, I then applied Dijkstra's algorithm for all the vertices in the graph. This gave me the resulting Edge Centrality Map. Finally, I traversed the map to find the edge with the highest centrality. I then removed the corresponding edge from the graph.
<br>
This process was repeated until enough edges had been removed removed to detect the communities. In my case, I chose to stop the algorithm after all edges had a centrality of 2. This left me with about 500 edges remaining with an initial of about 1250 edges in the datases. This gave me a good view of the communities without removing too many edges.<br>

**Data Sets Test**<br>
I tested the algorithm on a computer-generated dataset [2] and the Football Conference 2000 Dataset [2]. In the project repo, you can see both of these datasets in the data folder, named people.graphml and football.graphml respectively.

**COMPUTER-GENERATED DATA**
-original (with and without color)
![image](https://user-images.githubusercontent.com/78247585/162675880-7f046b8d-3fe2-4d7c-9e71-c3174826aff0.png)
![image](https://user-images.githubusercontent.com/78247585/162675896-2c46ff51-d16a-4055-af73-25a0992da4bb.png)
<br>-results: here you can now see the 4 friend groups, without the need for colored nodes
![image](https://user-images.githubusercontent.com/78247585/162674915-39fe611d-8240-45c2-9827-e1374e1fd79a.png)

**FOOTBALL DATASET**
-original (with and without color)
![image](https://user-images.githubusercontent.com/78247585/162676215-3e5332f3-be47-4284-b56e-7544ac5a8361.png)
![image](https://user-images.githubusercontent.com/78247585/162676180-e5909d73-0cc2-46e1-aff8-923869df3bc1.png)
<br>-results: here you can now see the 11 conferences, without the need for colored nodes
![image](https://user-images.githubusercontent.com/78247585/162676193-0a71250a-6171-4804-82b8-3ea38bcfb6a9.png)

**How to Run the Project**<br>
After cloning the repo and installing boost libraries, create the CMake project with the provided CMakeLists.txt. 
<br>
The program takes one program argument, which is the path of the input .graphml file. <br>The prograpm will then output the
corresponding processed .graphml file in the results folder as results.graphml
