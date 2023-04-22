import java.util.Scanner;


public class Task2 {
	
	//the function receives the number of days that Frank saves the money
	//and calculates the total saving after the number of days.
	public static int calculateSaving(int theNumberofDays) {
		
		int count = 0; // for counting how many iterates in for loop.
		int savingMoney = 1; // for storing how much money Frank saves a day.
		int savingSum = 0; // for storing total saving Frank saves.
		
		/* Iterating for adding Frank's daily saving to total saving
		and increase daily saving every seven days */
		for(int i = 0; i < theNumberofDays; ++i) {
			
			count++;
			
			savingSum += savingMoney;
			
			// Increase Frank's daily saving by one every seven days.
			if(count % 7 == 0) {
				savingMoney++;
			}
		}
		
		return savingSum;
	}
	
	/* the function receives the number of days that Frank saves money.
	and prints total Frank's saving */
	public static void printSaving(int theNumberofDays) {
		System.out.println("Total Frank's saving (after " + theNumberofDays + " days): " + calculateSaving(theNumberofDays));
	}
	
	

	public static void main(String[] args) {
		
		System.out.print("Enter the number of days: ");

		Scanner input = new Scanner(System.in);
		
		int theNumberOfDay = input.nextInt(); // for storing the number of days that Frank saves the money.
		
		printSaving(theNumberOfDay);
		

	}

}
