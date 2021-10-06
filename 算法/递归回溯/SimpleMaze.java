package mawenshu.递归回溯;

/**
 * @author 马文澍
 * @date 2021/1/21 11:01
 */
public class SimpleMaze {
    public static void main(String[] args) {
        int row = 11;
        int col = 10;
        int[][] maze = initMaze(row, col);
        addWall(maze);
        showMaze(maze);
        findRoute(maze, 1, 1);
        showMaze(maze);
    }

    private static boolean findRoute(int[][] maze, int currentRow, int currentCol) {
        if (maze[9][1] == 2) {
            //  找到了出口
            return true;
        }
        //继续找
        else {
            //  当前结点没有走过   0
            if (maze[currentRow][currentCol] == 0) {
                //  走当前结点,设置为走过了 2
                maze[currentRow][currentCol] = 2;
                //选择下一个要走的结点
                //  向下走，看行的通吗，如果行得通，则返回true,
                if (findRoute(maze, currentRow + 1, currentCol)) {
                    return true;
                }
                //  向右
                else if (findRoute(maze, currentRow, currentCol + 1)) {
                    return true;
                }

                //  向上
                else if (findRoute(maze, currentRow - 1, currentCol)) {
                    return true;
                }

                //  向左
                else if (findRoute(maze, currentRow, currentCol - 1)) {
                    return true;
                } else {
                    //  设置为当前结点走过了，但是行不通  3
                    maze[currentRow][currentCol] = 3;
                    return false;
                }

            } else {
                //  当前结点是墙   1
                //  当前结点走过了，但是行不通  3
                return false;
            }

        }
    }

    public static void addWall(int[][] maze) {
        maze[1][4] = 1;
        maze[2][1] = 1;
        maze[2][2] = 1;
        maze[2][4] = 1;
        maze[2][6] = 1;
        maze[3][6] = 1;
        maze[4][2] = 1;
        maze[4][3] = 1;
        maze[4][4] = 1;
        maze[4][5] = 1;
        maze[4][6] = 1;
        maze[4][7] = 1;
        maze[4][8] = 1;
        maze[6][1] = 1;
        maze[6][2] = 1;
        maze[6][3] = 1;
        maze[6][4] = 1;
        maze[5][7] = 1;
        maze[6][7] = 1;
        maze[8][7] = 1;
        maze[9][7] = 1;
        maze[9][5] = 1;
        maze[8][3] = 1;
        maze[8][4] = 1;
        maze[8][5] = 1;
    }

    public static int[][] initMaze(int row, int col) {
        int[][] maze = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    maze[i][j] = 1;
                } else {
                    maze[i][j] = 0;
                }
            }
        }
        return maze;
    }

    public static void showMaze(int[][] maze) {
        for (int i = 0; i < maze[0].length; i++) {
            System.out.print(i + " ");
        }
        System.out.println();
        int rowNo = 0;
        for (int[] row : maze) {
            for (int data : row) {
                if (data == 1) {
                    System.out.print("# ");
                } else if (data == 3) {
                    System.out.print("× ");
                } else if (data == 0) {
                    System.out.print("  ");
                } else {
                    System.out.print("√ ");
                }
            }
            System.out.println(rowNo);
            rowNo += 1;
        }
        System.out.println("\n====================================================\n");
    }
}
