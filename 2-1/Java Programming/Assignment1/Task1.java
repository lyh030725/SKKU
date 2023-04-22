import java.util.Scanner;


public class Task1 {
	
	//the class for BankAccount's variables and functions
	public static class BankAccount{
		
		private String userName;  //for storing the bank user's name
		private float initialBalance; // for storing initialBalance of user
		private float increasePercentage; // for indicating by how much percent the balance will be increased each year
		private int theNumberOfYears; // for storing how much years user put the money
		
		//the function assigns the inputs(name, initialBalance, percentage, the number of years)
		//to bank account information
		public void createAccount() {
			System.out.println("Please, enter following information:");
			
			Scanner input = new Scanner(System.in);
			
			System.out.print("Your name: ");
			userName = input.nextLine();
			
			System.out.print("Initial Balance: ");
			initialBalance = input.nextFloat();
			
			System.out.print("Percentage: ");
			increasePercentage = input.nextFloat();
			
			System.out.print("Number of years: ");
			theNumberOfYears = input.nextInt();
		}
		
		
		/* the function calculates final balance after the number of years
		that bank user put the money. */
		public float calculateMoney() {
			float copyInitialBalance = initialBalance; // make a copy variable for making initial balance not changing
			
			//Iterating for getting balance increase for each year.
			for(int i = 0; i < theNumberOfYears; ++i) {
				copyInitialBalance += copyInitialBalance * (increasePercentage/100);
			}
			
			return copyInitialBalance;
		}
		
		
		// the function prints bank account's information(user name, percentage, final balance)
		public void PrintAccountInformation() {
			System.out.println("==========================================");
			System.out.println("User name: " + userName);
			System.out.println("Percentage : " + increasePercentage);
			System.out.println("Your balance (after " + theNumberOfYears + " years): " + calculateMoney());
		}
		
	}
	

	public static void main(String[] args) {
		
		BankAccount user = new BankAccount();  // for making new empty bank account
		
		user.createAccount(); // assigning user information to bank account
		
		user.PrintAccountInformation(); // printing bank account information

		
	}

}
