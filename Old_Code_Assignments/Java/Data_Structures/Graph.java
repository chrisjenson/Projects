import java.util.*;
import java.io.*;

public class Graph{ //Weighted digraph using adjacency list

		
		static class Edge{
		
			int source, destination;
		
			Edge(int src, int dest){ //Source is object, src is local
				
				source = src;
				destination = dest; 
			}	
		}
		
		List<List<Integer>> adj = new ArrayList<>();
		
		public Graph(List<Edge> edges) {
			for (int i = 0 ; i < edges.size() ; i++){
				adj.add(i, new ArrayList<>());
			}
			for (Edge current : edges){
				adj.get(current.source).add(current.destination);
				adj.get(current.destination).add(current.source);
			}
		}
		
		private static void printGraph(Graph graph){
			int source = 0;
			int n = graph.adj.size();
			
			while(source < n){
				for (int destination : graph.adj.get(source)){
					System.out.print("(" + source + "-->" + destination + ")\t");
					System.out.println();
					source++;
				}
			}
		}

	public static void main(String[] args){
		List<Edge> edges = Arrays.asList(new Edge(0,1), new Edge(1,2), new Edge(2,0), new Edge(2,1), new Edge(3,2), new Edge(4,5), new Edge(5,4));
		
		Graph graph = new Graph(edges);
		printGraph(graph);
		
		
	}
}