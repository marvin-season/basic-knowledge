package mawenshu.递归回溯;

import java.util.Hashtable;

/**
 * @author 马文澍
 * @date 2021/5/2 8:46
 */
public class Demo {
    public static void main(String[] args) {
        System.out.println("start");
        Go:
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                System.out.print(i + " ");
                if (i == 1 && j == 2) {
                    break Go;
                }
            }
        }
        System.out.println("end");
        Demo demo = new Demo();
        System.out.println(Integer.toHexString(demo.hashCode()));
        System.out.println(demo);
        System.out.println(Demo.class.getName());
        System.out.println(demo.getClass().getName());
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
