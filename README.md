### PROBLEM DESCRIPTION

A cybercriminal is orchestrating an attack on the central bank's data server. In response, a group 
of skilled engineers has been mobilized to prevent the breach. The central bank's network 
comprises numerous interconnected computers, forming a complex web of communication 
pathways. You can model this communication network as a graph, where each computer serves 
as a vertex and the connections between them are represented as edges. Note that, all the 
connections are bidirectional.

Given a graph (that defines computer network) as the input, your task is to develop a program (in 
C++) to output the minimum number of connections that must be severed (removed) to ensure 
no connectivity between the hacker’s computer and the central bank server.

### INPUT:
You should read a name of a text file from the keyboard (standard input). This file contains 
the graph (network). The first line of the text file contains two integers n and m.
n is the number of computers
m is the number of connections
Next m lines describe the connections. Each line contains two integers u and v, indicating that 
there is a network connection between computer u and computer v. There is at most one 
network connection between two computers. The hacker is using the computer 1 and the 
central bank’s data server is represented by n.

### OUTPUT:
Output a single integer X where X is the minimum number of connections that must be 
removed to break all pathways between the hacker’s computer and the central bank’s server.

### EXAMPLE:
Input: test_input-7.txt --> name of input text file
Contents of the text file:

4 4 --> n=4 computers, m=4 connections
1 2 --> computer 1 is connected to computer 2
1 3
2 4
3 4

Output:
2 --> X=2, the number of connections to be removed

### Explanation:
We need to remove at least 2 connections, between computers 1-3 and computers 2-4, 
to break all pathways between the hacker’s computer, 1, and the central bank’s server, 
4. Hence, the answer is 2.
