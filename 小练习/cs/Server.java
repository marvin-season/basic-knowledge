import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @author 马文澍
 * @date 2021/4/19 9:41
 */
public class Server {

    private static final List<Socket> sockets = Collections.synchronizedList(new ArrayList<>());

    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket();
        serverSocket.bind(new InetSocketAddress(60000));

        while (true) {
            System.out.println("服务器监听中...");
            //  server 如果没有监听到来自客户机的 socket, 线程会在这儿阻塞
            Socket socket = serverSocket.accept();
            System.out.println(socket.getPort() + "\t进入聊天");
            sockets.add(socket);
            new Thread(new ServerRunnable(socket)).start();
        }
    }

    public static class ServerRunnable implements Runnable {
        private String aim = null;

        private Socket socket = null;
        private BufferedReader br = null;
        private PrintStream ps = null;

        public ServerRunnable(Socket socket) throws IOException {
            this.socket = socket;
            br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        }

        @Override
        public void run() {
            //  处理一个线程的任务
            String content = null;
            try {
                while ((content = readFromClient()) != null) {
                    if (aim == null) {
                        for (Socket s : sockets) {
                            if (s.equals(socket)) {
                                continue;
                            }
                            ps = new PrintStream(s.getOutputStream());
                            ps.println("全体信息:\t" + content);
                        }
                    } else {
                        for (Socket s : sockets) {
                            if (s.getPort() == Integer.parseInt(aim)) {
                                ps = new PrintStream(s.getOutputStream());
                                ps.println(socket.getPort() + ":\t" + content);
                                break;
                            }
                        }
                    }
                }
            } catch (Exception e) {

            }
        }

        private String readFromClient() {
            try {
                String line = br.readLine();
                String[] message = line.split(":");
                if (message.length == 1) {
                    return line;
                } else {
                    aim = message[0];
                    return message[1];
                }
            } catch (IOException e) {
                sockets.remove(socket);
                System.out.println(socket.getPort() + "\t退出群聊");
            }
            return null;
        }
    }
}
