import java.util.Scanner;

public class AirPods extends Product{
	
	//Constructor that calls Product(parent class)'s class constructor 
	//,handing over the default price of the AirPods and the default model name
	public AirPods() {
		super(120, "AirPods3");
	}
	
	//the function asks the user which option to choose 
	//for the AirPods' model name, quantity
	//and assigns it to each variable.	
	public void getUserSelection() {
		Scanner userChoice = new Scanner(System.in);
		
		System.out.println("===========================================");
		System.out.println("Base cost of the AirPods: $120");
		
		System.out.print("Which model do you want (AirPods3 or AirPodsPro or AirPodsMax): ");
		super.setModel(userChoice.nextLine());
		
		System.out.print("What do you want to buy: ");
		super.setQuantity(userChoice.nextInt());
	}
	
	//the function calculates the price of one product plus the extra cost
	//about model
	//and the total cost considering the quantity of products that user purchases.
	public void calculateCost() {
		float extraCost = 0;
		
		System.out.println("===== check =====");
		
		//If user selects model AirPodsPro,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		if(super.getModel().equals("AirPodsPro")) {
			System.out.println("Model (AirPodsPro) ----- +$100");
			extraCost += 100;
		}
		
		//If user selects model AirPodsMax,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		else if(super.getModel().equals("AirPodsMax")) {
			System.out.println("Model (AirPodsMax) ----- +$200");
			extraCost += 200;
		}
		
		
		System.out.println();
		
		//Storing one AirPods' cost,
		//the basic amount of a AirPods plus the extra cost for an additional option.
		float oneAirPodsTotalCost = extraCost + super.getBasePrice();
		System.out.println("Total cost for one AirPods: $" + oneAirPodsTotalCost);
		
		//Storing the final total cost 
		//considering the quantity of AirPods the user wants to purchase.
		float totalCost = oneAirPodsTotalCost * super.getQuantity();
		//Assign the total cost calculated to the member variable of the class 
		//using the setter function.
		super.setTotalCost(totalCost);
		System.out.println("Total cost (quantity x " + super.getQuantity() + "): $" +
		super.getTotalCost()
		);
	
	}
}
