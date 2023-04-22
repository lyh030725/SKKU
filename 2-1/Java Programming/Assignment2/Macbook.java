import java.util.Scanner;

public class Macbook extends Product{
	
	private int memory; // storing amount of memory on the MacBook that user selects.
	private int size; // storing size(inch) of the MacBook that user selects.
	private String color; // storing color of the MacBook that user selects.
	
	//Constructor that calls Product(parent class)'s class constructor 
	//,handing over the default price of the MacBook and the default model name
	//and initialize amount of memory and size and color to base value.
	public Macbook() {
		super(1000, "Air");
		setMemory(128);
		setSize(13);
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
	
	//getter function for size.
	public int getSize() {
		return size;
	}

	//setter function for size.
	public void setSize(int size) {
		this.size = size;
	}

	//the function asks the user which option to choose 
	//for the MacBook's model name, size, color, amount of memory, and quantity 
	//and assigns it to each variable.
	public void getUserSelection() {
		Scanner userChoice = new Scanner(System.in);
		
		System.out.println("===========================================");
		System.out.println("Base cost of the Macbook: $1000");
		
		System.out.print("Which model do you want (Air or Pro): ");
		super.setModel(userChoice.nextLine());
		
		System.out.print("Size (13, 14, 16): ");
		setSize(userChoice.nextInt());
		
		System.out.print("Color (base, Gold, Silver): ");
		//The nextLine function is called 
		//to eliminate the newline character ('\n').
		userChoice.nextLine();
		setColor(userChoice.nextLine());
		
		System.out.print("Memory (128, 256, 512): ");
		setMemory(userChoice.nextInt());
		
		System.out.print("What do you want to buy: ");
		super.setQuantity(userChoice.nextInt());
	}
	
	//the function calculates the price of one product plus the extra cost
	//about model, size, color, and memory
	//and the total cost considering the quantity of products that user purchases.
	public void calculateCost() {
		float extraCost = 0; //storing for extra cost about additional options for MacBook
		
		System.out.println("===== check =====");
		
		//If user selects model Pro,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		if(super.getModel().equals("Pro")) {
			System.out.println("Model (Pro) ----- +$200");
			extraCost += 200;
		}
		
		//If user selects size 14,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		if(getSize() == 14) {
			System.out.println("Size (14) ----- +$100");
			extraCost += 100;
		}
		
		//If user selects size 16,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		else if(getSize() == 16) {
			System.out.println("Size (16) ----- +$200");
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
		
		//If user selects size of memory 256,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		if(getMemory() == 256) {
			System.out.println("Memory (256) ----- +$100");
			extraCost += 100;
		}
		//If user selects size of memory 512,
		//the program prints extra cost and add additional cost to the variable (extra cost)
		else if(getMemory() == 512) {
			System.out.println("Memory (512) ----- +$300");
			extraCost += 300;
		}
		
		System.out.println();
		
		//Storing one Macbook's cost,
		//the basic amount of a MacBook plus the extra cost for an additional option.
		float oneMacbookTotalCost = extraCost + super.getBasePrice();
		System.out.println("Total cost for one Macbook: $" + oneMacbookTotalCost);
		
		//Storing the final total cost 
		//considering the quantity of MacBooks the user wants to purchase.
		float totalCost = oneMacbookTotalCost * super.getQuantity();
		//Assign the total cost calculated to the member variable of the class 
		//using the setter function.
		super.setTotalCost(totalCost);
		
		System.out.println("Total cost (quantity x " + super.getQuantity() + "): $" +
		super.getTotalCost()
		);
	
	}
} 
