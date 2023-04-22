import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//iterating the user's purchase process for Apple products.
		while(true) {
			//receiving user's input about which Apple products user wants to buy.
			Scanner userInput = new Scanner(System.in);
			
			System.out.println("==== Welcome Apple Korea ====");
			System.out.println("What do you want to buy?");
			System.out.println("Choose 1 for Macbook");
			System.out.println("Choose 2 for iPhone");
			System.out.println("Choose 3 for AirPods");
			System.out.println("Choose 0 for Exit");
			System.out.print("Please enter your choice: ");
			
			int userChoice = userInput.nextInt(); // storing for user's choice about products(0~3)
			
			//If the user selects 1 (MacBook), 
			//the program presents additional options for the MacBook 
			//and calculates the total cost.
			if(userChoice == 1) {
				Macbook macBook = new Macbook();
				macBook.getUserSelection();
				macBook.calculateCost();
			}
			
			//If the user selects 2 (iPhone), 
			//the program presents additional options for the iPhone 
			//and calculates the total cost.
			else if(userChoice == 2) {
				iPhone iPhone = new iPhone();
				iPhone.getUserSelection();
				iPhone.calculateCost();
			}
			
			//If the user selects 3 (AirPods), 
			//the program presents additional options for the AirPods 
			//and calculates the total cost.
			else if(userChoice == 3) {
				AirPods airPods = new AirPods();
				airPods.getUserSelection();
				airPods.calculateCost();
			}
			
			//If the user selects 0 (Exit),
			//the program ends.
			else if(userChoice == 0) {
				break;
			}
			
			//Ask user if user want to buy more items
			System.out.print("Do you want to purchase something else (Yes: 1, No: 0): ");
			
			//If the user selects 0 (No), 
			//express the appreciation for the purchase 
			//and exit the program.
			if(userInput.nextInt() == 0) {
				System.out.println("Thank you for your purchase!");
				break;
			}
			
			//If the user selects 1 (Yes),
			//iterating user's purchase process.
		}
		

	}

}
