import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.InetSocketAddress;
import java.net.Socket;

/**
 * @author 马文澍
 * @date 2021/4/19 10:09
 */
public class Client {
    public static void main(String[] args) throws IOException {
        //两个线程， 一个读取， 一个键入
        //  主线程键入

        Socket socket = new Socket();
        socket.connect(new InetSocketAddress("127.0.0.1", 60000), 10000);
        new Thread(new ClientRunnable(socket)).start();
        System.out.println(socket.getLocalPort() + "\t您已经进入群聊");
        PrintStream ps = new PrintStream(socket.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            ps.println(line);
        }
    }
}
