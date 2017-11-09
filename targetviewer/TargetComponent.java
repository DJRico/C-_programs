/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package targetviewer;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JComponent;
/**
 *
 * @author dalerico
 */
public class TargetComponent extends JComponent{
    
    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D)g;
        
        Target target = new Target (0,0);
        
        target.draw(g2);
    }
    
}
