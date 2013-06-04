import java.util.HashMap;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    private static class State {
        public int node;
        public int ttl;
        
        public State(int node, int ttl) {
            this.node = node;
            this.ttl = ttl;
        }
    }
    
    public static int solve (HashMap<Integer, ArrayList<Integer>> graph, int startNode, int ttl) {
        HashSet<Integer> visited = new HashSet<Integer>();
        Queue<State> queue = new LinkedList<State>();
        queue.add(new State(startNode, ttl));
        visited.add(startNode);
        
        while (queue.size() > 0) {
            State nextState = queue.poll();
        
            if (nextState.ttl > 0) {
                for (Integer link: graph.get(nextState.node)) {
                    if (!visited.contains(link)) {
                        queue.add(new State(link, nextState.ttl-1));
                        visited.add(link);
                    }
                }
            }
        }
        
        int answ = 0;
        
        for (Integer node: graph.keySet()) {
            if (! visited.contains(node)) {
                ++answ;
            }
        }
        return answ;
    }
    
    public static void addLink(HashMap<Integer, ArrayList<Integer>> graph, int n1, int n2) {
        if (graph.containsKey(n1)) {
            graph.get(n1).add(n2);
        } else {
            ArrayList<Integer> a = new ArrayList<Integer>();;
            a.add(n2);
            graph.put(n1, a);
        }
        
        if (graph.containsKey(n2)) {
            graph.get(n2).add(n1);
        } else {
            ArrayList<Integer> a = new ArrayList<Integer>();;
            a.add(n1);
            graph.put(n2, a);
        }
    
    }
    

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int case_ = 1, nc, inputIx = 0, node1, node2, source, ttl;
        String line;

        nc = in.nextInt();
        
        while (nc != 0) {
            HashMap<Integer, ArrayList<Integer>> graph = new HashMap<Integer, ArrayList<Integer>>();
            
            for (int i = 0; i < nc; i++) {
                node1 = in.nextInt();
                node2 = in.nextInt();
                addLink(graph, node1, node2);
            }
            
            source = in.nextInt();
            ttl = in.nextInt();
            
            while (source != 0 || ttl != 0) {
                System.out.println("Case " + case_++ + ": " + solve(graph, source, ttl) + " nodes not reachable from node " + source + " with TTL = " + ttl + ".");
                source = in.nextInt();
                ttl = in.nextInt();
            }
            
            nc = in.nextInt();
        }
    }
}