package mawenshu.递归回溯;

/**
 * @author 马文澍
 * @date 2021/5/2 8:20
 */
public class SimpleMaze2 {
    //  方向数组， 上下左右
    private final static int[][] direct = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    private final static int[] start = {1, 1};


    public static void main(String[] args) {
        int row = 11;
        int col = 10;

        int[][] maze = SimpleMaze.initMaze(row, col);
        maze[9][4] = 2; //出口

//        SimpleMaze.addWall(maze);
        SimpleMaze.showMaze(maze);
        find(maze);
        SimpleMaze.showMaze(maze);
    }

    private static void find(int[][] maze) {
        System.out.printf("从[%d,%d]开始出发\n", start[0], start[1]);
        findRoute(maze, start[0], start[1]);
    }

    private static boolean findRoute(int[][] maze, int x, int y) {
        if (x == 9 && y == 4) {
            //  找到啦
            return true;
        }

        if (maze[x][y] == 0) {
            //  当前暂时为通路
            maze[x][y] = 2;//标记为可走
            for (int i = 0; i < 4; i++) {
                if (findRoute(maze, x + direct[i][0], y + direct[i][1])) {
                    return true;
                }
            }
            //  四个方向都不可行
            maze[x][y] = 3; //标记为死胡同
        }
        return false;
    }
}
