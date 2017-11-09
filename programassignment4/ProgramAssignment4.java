package programassignment4;
import java.util.Scanner;
public class ProgramAssignment4 {

    public static void main(String[] args) {
      
        Scanner scan = new Scanner (System.in);
        System.out.print ("Enter Number: ");
        int number = scan.nextInt();
        
        String romanNumeral = "";
        
        if(number > 3999){
            System.out.println("Error!! Unable to convert!");
        }
        else{
        //1000
        while (number >= 1000){
            romanNumeral += "M";
            number -= 1000;
        }
        //900
        while (number >= 900){
            romanNumeral += "CM";
            number -= 900;
        }
        //500
        while (number >= 500){
            romanNumeral += "D";
            number -= 500;
        }
        //400
        while (number >= 400){
            romanNumeral += "CD";
            number -= 400;
        }
        //100
        while (number >= 100){
            romanNumeral += "C";
            number -= 100;
        }
        //90
        while (number >= 90){
            romanNumeral += "XC";
            number -= 90;
        }
        //50
        while (number >= 50){
            romanNumeral += "L";
            number -= 50;
        }
        //40
        while (number >= 40){
            romanNumeral += "XL";
            number -= 40;
        }
        //10
        while (number >= 10){
            romanNumeral += "X";
            number -= 10;
        }
        //9
        while (number >= 9){
            romanNumeral += "IX";
            number -= 9;
        }
        //5
        while (number >= 5){
            romanNumeral += "V";
            number -= 5;
        }
        //4
        while (number >= 4){
            romanNumeral += "IV";
            number -= 4;
        }
        //1
        while (number >= 1){
            romanNumeral += "I";
            number -= 1;
        }
        
        System.out.println("Roman Numeral: " + romanNumeral);
        }

        
        
    }
    
}
