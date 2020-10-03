/*
https://leetcode.com/problems/course-schedule/
*/


import java.util.*;
class Solution {

    class Graph {
        // No. of vertices
        int V;

        // An Array of List which contains
        // references to the Adjacency List of
        // each vertex
        ArrayList<ArrayList<Integer>> adj;

        // Constructor
        public Graph(int V) {
            this.V = V;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }
        }

        // Function to add an edge to graph
        public void addEdge(int u, int v) {
            adj.get(u).add(v);
        }

        // prints a Topological Sort of the
        // complete graph
        public boolean isTopSortPossible() {
            // Create a array to store
            // inDegrees of all
            // vertices. Initialize all
            // inDegrees as 0.
            int[] inDegree = new int[V];
            Vector<Integer> topOrder = new Vector<>();

            Queue<Integer> queue = new LinkedList<>();
            // Traverse adjacency lists
            // to fill inDegrees of
            // vertices. This step takes
            // O(V+E) time
            for (int i = 0; i < V; i++) {
                ArrayList<Integer> temp = adj.get(i);
                for (int node : temp) {
                    inDegree[node]++;
                }
            }

            // Create a queue and enqueue
            // all vertices with inDegree 0

            for (int i = 0; i < V; i++) {
                if (inDegree[i] == 0)
                    queue.add(i);
            }

            // Create a vector to store result
            // (A topological ordering of the vertices)

            while (!queue.isEmpty()) {
                // Extract front of queue
                // (or perform deque)
                // and add it to topological order
                int u = queue.poll();
                topOrder.add(u);

                // Iterate through all its
                // neighbouring nodes
                // of polled node u and
                // decrease their in-degree
                // by 1
                for (int node : adj.get(u)) {
                    // If in-degree becomes zero,
                    // add it to queue
                    if (--inDegree[node] == 0)
                        queue.add(node);
                }
            }

            // Check if all the nodes can be visited, i.e. no cycle exist
            return topOrder.size() == V;
        }
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Graph graph = new Graph(numCourses);
        for (int[] prerequisite : prerequisites) {
            graph.addEdge(prerequisite[0], prerequisite[1]);
        }
        return graph.isTopSortPossible();
    }
}


/*
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
*/
