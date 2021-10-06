package mawenshu.graph;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;

/**
 * @author 马文澍
 * @date 2021/4/2 11:50
 */
public class ConstructGraph {

    public static ArrayList<Node> getNeighborTable() {
        int n = 5;
        ArrayList<Node> list = new ArrayList<>(n);

        HashMap<Integer, String> map = new HashMap<>();
        map.put(1, "2,3,5");
        map.put(2, "1,4");
        map.put(3, "1,5,4");
        map.put(4, "2,3");
        map.put(5, "1,3");

        for (int i = 1; i <= n; i++) {
            Node node = new Node(i);
            String[] neighborNodes = map.get(i).split(",");
            node.neighborNodes = new Node[neighborNodes.length];
            for (int j = 0; j < neighborNodes.length; j++) {
                node.neighborNodes[j] = new Node(Integer.parseInt(neighborNodes[j]));
            }
            list.add(node);
        }
        return list;
    }
}
