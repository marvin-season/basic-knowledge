package mawenshu.动态规划;


import java.io.BufferedReader;
import java.io.FileReader;
import java.util.concurrent.TimeUnit;

/**
 * @author 马文澍
 * @date 2021/3/26 10:24
 * 字符串匹配暴力算法
 */
public class NKMP {
    public static void main(String[] args) throws Exception {
        FileReader reader = new FileReader("content.txt");
        BufferedReader bufferedReader = new BufferedReader(reader);
        String content = bufferedReader.readLine();
        String pattern = "acdee";
        System.out.println(content);
        System.out.println(pattern+"\n"+"开始匹配...");
        System.out.println(System.currentTimeMillis());

        int searchRes = search(content, pattern);
        System.out.println(searchRes);
        System.out.println(System.currentTimeMillis());
    }

    //暴力匹配
    private static int search(String content, String pattern) {
        int n = content.length();//文本的长度
        int m = pattern.length();//模式串的长度

        for (int i = 0; i <= n - m; i++) {
            //  模式串非指针
            int j;
            for (j = 0; j < m; j++) {
                if (content.charAt(i + j) != pattern.charAt(j)) {
                    break;
                }
            }
            if (j == m) {
                return i;
            }
        }
        return -1;
    }
}
