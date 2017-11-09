package nim;
import java.util.Scanner;
/**
 *
 * @author dalerico
 */
public class Nim {

    public int getComputerMove(int left)
    {
        return (int)(Math.random()* left/2)+1;
    }
    
    public void play()
    {
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements to start.");
        int left = sc.nextInt();
        while(left > 0)
        {
            int computer = getComputerMove(left);
            System.out.println("Computer takes " + computer);
            left -= computer;
            System.out.println("Now there are " + left + " left.");
            if (left <= 0)
            {
                System.out.println("YOU WIN!");
                return;
            }
            System.out.println("What's your move?");
            if(left == 1)
            {
                System.out.println("Looks like whoever takes this last loses!");
            }
            else
                System.out.println("You can only take up to " + left/2);
            int person = sc.nextInt();
           // while (person!=1 && person!=2)
            //{
            //    System.out.println(person + " not allowed, choose 1 or 2");
            //    person = sc.nextInt();
            //}
            left -= person;
            System.out.println("Now there are " + left + " left.");
            if (left<= 0)
            {
                System.out.println("YOU LOSE!");
                return;
            }
        }
    }
    public static void main(String[] args) {
        Nim nim = new Nim();
        nim.play();
    }
    
}
