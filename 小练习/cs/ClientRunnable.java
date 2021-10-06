import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

/**
 * @author 马文澍
 * @date 2021/4/19 10:13
 */
//  实时打印接收到的信息
public class ClientRunnable implements Runnable {
    private Socket socket = null;
    private BufferedReader br = null;

    public ClientRunnable(Socket socket) throws IOException {
        this.socket = socket;
        br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    }

    @Override
    public void run() {
        try {
            String content;
            while ((content = br.readLine()) != null) {
                System.out.println(content);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
