public class Product {
	
	protected int basePrice; //storing the base price of each Apple's product.
	protected double totalCost; //storing the total cost of each Apple's product 
								//( (base price + extra fee) * product's quantity)
	protected String model; //storing the model's name of each Apple's product.
	protected int quantity; //storing the product's quantity of each Apple's product that user purchases
	
	//Constructor that receives base prices and model names, 
	//assigns them to prices and models of Apple products, respectively, 
	//and initialize the total amount and quantity of products to zero
	public Product(int basePrice, String model) {
		setBasePrice(basePrice);
		setTotalCost(0);
		setModel(model);
		setQuantity(0);
	}
	
	//Function only for overriding 
	//that receives additional options from the user.
	public void getUserSelection() {
		
		
	}
	
	//Function only for overriding 
	//calculates the price of one product plus the extra cost 
	//and the total cost considering the quantity of products.
	public void calculateCost() {
		
	}
	
	//getter function for basePrice.
	public int getBasePrice() {
		return basePrice;
	}
	
	//setter function for basePrice.
	public void setBasePrice(int basePrice) {
		this.basePrice = basePrice;
	}

	//getter function for totalCost.
	public double getTotalCost() {
		return totalCost;
	}

	//setter function for totalCost.
	public void setTotalCost(double totalCost) {
		this.totalCost = totalCost;
	}
	
	//getter function for model.
	public String getModel() {
		return model;
	}

	//setter function for model.
	public void setModel(String model) {
		this.model = model;
	}
	
	//getter function for quantity.
	public int getQuantity() {
		return quantity;
	}

	//setter function for quantity.
	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
}
