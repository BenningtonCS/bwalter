import java.applet.*;
import java.net.*;

public class Test {
    public static void main(String[] args) {
        try {
            AudioClip clip = Applet.newAudioClip(new URL("file:meow.wav"));
            clip.play();
        } catch (MalformedURLException e) {
            System.out.println(e);
        }
    }
}
