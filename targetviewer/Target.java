/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package targetviewer;

import java.awt.Color;
import java.awt.geom.Ellipse2D;
import java.awt.Graphics2D;

/**
 *
 * @author dalerico
 */
public class Target {
    
    private int xCoor;
    private int yCoor;
    
    public Target (int x, int y)
    {
        xCoor = x;
        yCoor = y;
    }
    
    public void draw(Graphics2D g2)
    {
     
        Ellipse2D.Double black1 = new Ellipse2D.Double (xCoor + 80, yCoor + 50, 100, 100 );
        Ellipse2D.Double white1 = new Ellipse2D.Double (xCoor + 90, yCoor + 60, 80, 80);
        Ellipse2D.Double black2 = new Ellipse2D.Double (xCoor + 100, yCoor + 70, 60, 60);
        Ellipse2D.Double white2 = new Ellipse2D.Double (xCoor + 110, yCoor + 80, 40, 40);
        Ellipse2D.Double black3 = new Ellipse2D.Double (xCoor + 120, yCoor + 90, 20, 20);
        
        g2.setColor(Color.BLACK);
        g2.fill(black1);
        g2.setColor(Color.WHITE);
        g2.fill(white1);
        g2.setColor(Color.BLACK);
        g2.fill(black2);
        g2.setColor(Color.WHITE);
        g2.fill(white2);
        g2.setColor(Color.BLACK);
        g2.fill(black3);
        
        
    }
}
