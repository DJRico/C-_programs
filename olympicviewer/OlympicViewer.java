/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package olympicviewer;
import javax.swing.JFrame;

public class OlympicViewer {


    public static void main(String[] args) {
        // TODO code application logic here
        

      JFrame frame = new JFrame();

      final int FRAME_WIDTH = 300;
      final int FRAME_HEIGHT = 230;

      frame.setSize(300, 230);
      frame.setTitle("OlympicRingViewer");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      OlympicComponent component = new OlympicComponent();
      frame.add(component);

      frame.setVisible(true);

        
    }
    
}
