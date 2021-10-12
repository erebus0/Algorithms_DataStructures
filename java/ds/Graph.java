package ds;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class Graph<T> {
    private List<List<Edge>> adjacencyList = new ArrayList<>();

    public Graph(List<T> nodes, List<Edge> edges) {
        for(int i = 0; i < nodes.size(); i++) {
            this.adjacencyList.add(new ArrayList<>());
        }
        edges.forEach(edge -> {
            this.adjacencyList.get(edge.getSourceNode()).add(new Edge(edge.getWeight(), edge.getDestNode()));
            this.adjacencyList.get(edge.getDestNode()).add(new Edge(edge.getWeight(), edge.getSourceNode()));
        });
    }

    public List<Integer> getShortestPath(int nodeNumber) {
        List<Integer> distances = new ArrayList<>();
        PriorityQueue<Edge> queue = new PriorityQueue<>();
        for(int i = 0; i < this.adjacencyList.size(); i++) {
            distances.add(Integer.MAX_VALUE);
        }

        distances.set(nodeNumber, 0);
        queue.add(new Edge(0, nodeNumber));

        while(!queue.isEmpty()) {
            Edge top = queue.poll();
            for(Edge destination: adjacencyList.get(top.getDestNode())) {
                if(distances.get(destination.getDestNode()) > destination.getWeight() + distances.get(top.getDestNode())) {
                    distances.set(destination.getDestNode(), destination.getWeight() + distances.get(top.getDestNode()));
                    queue.add(new Edge(distances.get(destination.getDestNode()), destination.getDestNode()));
                }
            }
        }
        return distances;
    }

    public static class Edge implements Comparable<Edge>{
        private int weight;
        private int sourceNode;
        private int destNode;

        public Edge(int weight, int destNode) {
            this.weight = weight;
            this.destNode = destNode;
        }

        public Edge(int weight, int sourceNode, int destNode) {
            this.weight = weight;
            this.sourceNode = sourceNode;
            this.destNode = destNode;
        }

        public int getSourceNode() {
            return sourceNode;
        }

        public void setSourceNode(int sourceNode) {
            this.sourceNode = sourceNode;
        }

        public int getWeight() {
            return weight;
        }

        public void setWeight(int weight) {
            this.weight = weight;
        }

        public int getDestNode() {
            return destNode;
        }

        public void setDestNode(int destNode) {
            this.destNode = destNode;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.getWeight(), o.getWeight());
        }
    }

    public static void main(String[] args) {
        List<Integer> values = new ArrayList<>();
        values.add(10);
        values.add(29);
        values.add(83);
        values.add(98);
        values.add(91);
        values.add(43);

        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge(3,0, 1));
        edges.add(new Edge(4, 0, 2));
        edges.add(new Edge(2, 0, 3));
        edges.add(new Edge(4, 1, 2));
        edges.add(new Edge(2, 1, 4));
        edges.add(new Edge(6, 2, 4));
        edges.add(new Edge(1, 3, 4));
        edges.add(new Edge(4, 3, 5));
        edges.add(new Edge(2, 4, 5));

        Graph<Integer> myGraph = new Graph<>(values, edges);
        System.out.println(myGraph.getShortestPath(0));
    }
}
