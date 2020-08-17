# Smart-Waste-Management-System
Waste management always finds difficulty in knowing when to collect waste. If the vehicle
comes to collect too early it would lead to unnecessary trips. And when comes to
collect too late will result in an overflow of waste. Even though the level is moderate
the odor produced by the waste can cause air pollution. These problems stated can
be resolved using IoT technology used by this project. The workers need not want to
approach the bin to know whether a waste is ready to be removed. Also, it is used to
monitor whether the bin is not full and if not checks the smell of waste and then the
bin can be removed.  

The code is basically divided into two major parts. First one is the selection of bins
which are filled as per the parameters sent in and the second part is deciding
shortest path for the filled bins so as to reduce the garbage truck fuel consumption.  

1. Selection of bins  
5 different parameters are sent in to check whether the bin needs to be emptied or not
• Level of waste:
if (level of waste > 60% of dustbin height)
then level of waste is quite high, return true
else
return false  
• Temperature of waste:
if (temperature > 20 C)
then temperature is high, may become home for breeding insects, return true
else
return false  
• Odour level:
if (content of gas > 15 ppm)
then odour is high, return true
else
return false  
• Type of waste:
if (liquid level > 40% of dustbin height)
then liquid level is quite high, return true
else
return false  
• Weekly collection:
if (last pickup of waste >= 7 days)
then return true
else
return false  
This also helps to maintain the waste detection system because if the system
is broken and is not sending signals, then the weekly collection will prevent
garbage rotting and also system can be fixed.  
Now different combinations are fixed for collection of bins:  
1 level of waste is greater than desired level  
2 temperature and odour both are high  
3 level of liquid and odour both are high  
4 weekly collection  


2. Selecting the shortest path for Waste bin collection  
This is done using the Dijkstra Algorithm. It consists of the following steps:  
1.Initialization of all nodes with distance "infinite"; initialization of the starting node with 0.    
2.Marking of the distance of the starting node as permanent, all other distances as temporarily.  
3.Setting of starting node as active.  
4.Calculation of the temporary distances of all neighbour nodes of the active node by summing up its distance with the weights of the edges.  
5.If such a calculated distance of a node is smaller as the current one, update the distance and set the current node as antecessor. This step is also called
update and is Dijkstra's central idea.  
6.Setting of the node with the minimal temporary distance as active. Mark its distance as permanent.  
7.Repeating of steps 4 to 7 until there aren't any nodes left with a permanent distance, which neighbours still have temporary distances.  

Thus, in this way an optimised path can be created to only pickup those dustbins which are either filled or are fouling a lot.  
Note: These input values from the sensors can be changed as per the user's requirement. Here only sample values are taken after going through some research papers.
