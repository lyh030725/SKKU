import java.util.Scanner;

public class iPhone extends Product{
	private int memory; // storing amount of memory on the iPhone that user selects.
	private String color; // storing color of the iPhone that user selects.
	
	//Constructor that calls Product(parent class)'s class constructor 
	//,handing over the default price of the iPhone and the default model name
	//and initialize amount of memory and color to base value.
	public iPhone() {
		super(800, "iPhone12");
		setMemory(64);
		setColor("base");
	}
	
	//getter function for memory.
	public int getMemory() {
		return memory;
	}
		
	//setter function for memory.
	public void setMemory(int memory) {
		this.memory = memory;
	}

	//getter function for color.
	public String getColor() {
		return color;
	}

	//setter function for color.
	public void setColor(String color) {
		this.color = color;
	}

	//the function asks the user which option to choose 
	//for the iPhone's model name, size, color, amount of memory, quantity
	//and assigns it to each variable.	
	public void getUserSelection() {
		Scanner userChoice = new Scanner(System.in);
		
		System.out.println("===========================================");
		System.out.println("Base cost of the iPhone: $800");
		
		System.out.print("Which model do you want (iPone12 or iPone13): ");
		super.setModel(userChoice.nextLine());
		
		System.out.print("Color (base, Gold, Silver): ");
		setColor(userChoice.nextLine());
		
		System.out.print("Memory (64, 128, 256, 512): ");
		setMemory(userChoice.nextInt());
		
		System.out.print("What do you want to buy: ");
		super.setQuantity(userChoice.nextInt());
	}
	
	//the function calculates the price of one product plus the extra cost
	//about model, color, and memory
	//and the total cost considering the quantity of products that user purchases.
	public void calculateCost() {
		float extraCost = 0;
		
		System.out.println("===== check =====");
		
		//If user selects model iPhone13,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		if(super.getModel().equals("iPhone13")) {
			System.out.println("Model (iPhone13) ----- +$200");
			extraCost += 200;
		}
		
		//If user selects color Gold,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		if(getColor().equals("Gold")) {
			System.out.println("Color (Gold) ----- +$20");
			extraCost += 20;
		}
		//If user selects color Silver,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		else if(getColor().equals("Silver")) {
			System.out.println("Color (Silver) ----- +$10");
			extraCost += 10;
		}
		//If user selects size of memory 128,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		if(getMemory() == 128) {
			System.out.println("Memory (128) ----- +$100");
			extraCost += 100;
		}
		//If user selects size of memory 256,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		else if(getMemory() == 256) {
			System.out.println("Memory (256) ----- +$200");
			extraCost += 200;
		}
		//If user selects size of memory 512,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		else if(getMemory() == 512) {
			System.out.println("Memory (512) ----- +$300");
			extraCost += 300;
		}
		
		System.out.println();
		
		//Storing one iPhone's cost,
		//the basic amount of a iPhone plus the extra cost for an additional option.
		float oneiPhoneTotalCost = extraCost + super.getBasePrice();
		System.out.println("Total cost for one iPhone: $" + oneiPhoneTotalCost);
		
		//Storing the final total cost 
		//considering the quantity of iPhones the user wants to purchase.
		float totalCost = oneiPhoneTotalCost * super.getQuantity();
		//Assign the total cost calculated to the member variable of the class 
		//using the setter function.
		super.setTotalCost(totalCost);
		
		System.out.println("Total cost (quantity x " + super.getQuantity() + "): $" +
		super.getTotalCost()
		);
	
	}
}
