/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package programassignment1;

import java.util.Calendar;
import java.util.GregorianCalendar;


public class ProgramAssignment1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        GregorianCalendar cal = new GregorianCalendar();
        GregorianCalendar myBirthday = new GregorianCalendar(1993, Calendar.JUNE, 14);
        
        System.out.print("The weekday of my birthday, Dale Rico, is ");
        System.out.println(myBirthday.get(Calendar.DAY_OF_MONTH) + " of June.");
        
        System.out.print("HW Part 1) ");
        System.out.print("Today's date is ");
        System.out.print(cal.get(Calendar.MONTH) + "/");
        System.out.println(cal.get(Calendar.DAY_OF_MONTH) + ".");
        System.out.println("---------------------------------------------------");
        
        //cal.add(Calendar.MONTH, 100);
        cal.add(Calendar.DAY_OF_MONTH, 100);
        System.out.print("HW Part 2) ");
        System.out.print("The date 100 days from now will be ");
        System.out.print(cal.get(Calendar.MONTH) + "/");
        System.out.println(cal.get(Calendar.DAY_OF_MONTH)+ ".");
        System.out.println("---------------------------------------------------");
        
        //myBirthday.add(Calendar.MONTH, 10000);
        myBirthday.add(Calendar.DAY_OF_WEEK, 10000);
        System.out.print("HW Part 3) ");
        System.out.print("10,000 days from my birthday will be ");
        System.out.print(myBirthday.get(Calendar.MONTH) + "/");
        System.out.println(myBirthday.get(Calendar.DAY_OF_MONTH));
        System.out.println("---------------------------------------------------");
        
    }
    
}
