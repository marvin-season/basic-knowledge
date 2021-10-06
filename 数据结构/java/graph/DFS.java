package mawenshu.graph;

import java.util.ArrayList;

/**
 * @author 马文澍
 * @date 2021/4/2 11:49
 */
public class DFS {
    public static void main(String[] args) {
        ArrayList<Node> list = ConstructGraph.getNeighborTable();
        Node[] neighborNodes = list.get(0).neighborNodes;

        traverseGraph(list.get(0));
    }

    private static void traverseGraph(Node curNode) {
        if (curNode == null){
            return;
        }
        for (Node neighborNode : curNode.neighborNodes) {

            System.out.println("curNode.val = " + curNode.val);
            traverseGraph(neighborNode);
        }
    }
}
