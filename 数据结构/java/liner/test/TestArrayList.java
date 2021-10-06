package mawenshu.liner.test;


import mawenshu.liner.List;
import mawenshu.liner.sequence.ArrayList;

import java.util.Set;

/**
 * @author 马文澍
 * @date 2021/1/12 15:27
 */
public class TestArrayList {
    public static void main(String[] args) {
        List list = new ArrayList();
        list.add(123);
        list.add(234);
        list.add(345);
        list.add(456);
        list.add(456);
        list.add(456);
        list.add(777);
        list.add(789);
        System.out.println(list);

        list.add(2, 999);
        System.out.println(list);

        System.out.println("removeByIndex 0");
        list.removeByIndex(0);
        System.out.println(list);

        System.out.println("remove  456");
        Object removed = list.remove(456);
        System.out.println(list);
        System.out.println("removed = " + removed);

        System.out.println("replaceByIndex 4 777");
        Integer obj = 777;
        list.replaceByIndex(4, obj);
        System.out.println(list);
        System.out.println("replace 777 888");
        Integer obj2 = 888;
        list.replace(obj, obj2);
        System.out.println(list);

        System.out.println("list.get(4) = " + list.get(4));
        System.out.println("list.get(5) = " + list.get(5));
    }
}
