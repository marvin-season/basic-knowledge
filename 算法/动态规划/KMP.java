package mawenshu.动态规划;

import java.io.*;

/**
 * @author 马文澍
 * @date 2021/3/26 10:04
 */
public class KMP {
    private final String pattern;
    //  dfs[0]['a'] = 1;
    //  0状态 匹配到 'a' 进入1状态
    private int[][] dfs;

    public static void main(String[] args) throws Exception{
        FileReader reader = new FileReader("content.txt");
        BufferedReader bufferedReader = new BufferedReader(reader);
        String content = bufferedReader.readLine();
        String pattern = "acdee";

        System.out.println(content);
        System.out.println(pattern+"\n"+"开始匹配...");
        long x = System.currentTimeMillis();

        KMP kmp = new KMP(pattern);
        int i = kmp.searchIn(content);
        System.out.println(i);
        System.out.println(System.currentTimeMillis()-x);



    }

    public KMP(String pattern) {
        this.pattern = pattern;
        int m = pattern.length();
        // dfs[当前状态][字符] = 下一个状态
        dfs = new int[m][256];
        //base case
        dfs[0][pattern.charAt(0)] = 1;
        //  影子状态状态初始化
        int X = 0;

        //  初始化有限自动机
        for (int i = 1; i < m; i++) {
            for (int c = 0; c < 256; c++) {
                //  只有匹配到自己，转到下一个状态
                if (pattern.charAt(i) == c) {
                    dfs[i][c] = i + 1;
                }else{
                    //  否则, 去找自己的影子
                    //  dfs[0][...] 初始化都是0
                    dfs[i][c] = dfs[X][c];
                }
            }
            //  更新影子状态
            X = dfs[X][pattern.charAt(i)];
        }
    }

    public int searchIn(String content) {
        int n = content.length();
        int m = this.pattern.length();
        //  模式串的初始状态
        int j = 0;
        //  扫描文本，不回退指针
        for (int i = 0; i < n; i++) {
            j = dfs[j][content.charAt(i)]; //匹配成功，进入下一个状态
            //  终止态
            if (j == m) {
                //  返回字符串第一次匹配的字符索引
                return i - j + 1;
            }
        }
        return -1;
    }
}
