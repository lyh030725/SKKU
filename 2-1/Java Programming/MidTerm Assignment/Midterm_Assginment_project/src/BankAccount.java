
public class BankAccount {
	private String bankNumber; // for storing bank account number
	private int pinCode; // for storing bank account pin code
	private double balance; // for storing current balance in bank account
	private User bankUser; // for storing user of bank account
	
	//Constructor for receiving input of bank number, pin code, balance, and bank user
	//and assigning inputs to each member variable
	public BankAccount(String bankNumber, int pinCode, double balance, User bankUser) {
		setBankNumber(bankNumber);
		setPinCode(pinCode);
		setBalance(balance);
		setBankUser(bankUser);
	}
	
	public String getBankNumber() {
		return bankNumber;
	}
	public void setBankNumber(String bankNumber) {
		this.bankNumber = bankNumber;
	}
	public int getPinCode() {
		return pinCode;
	}
	public void setPinCode(int pinCode) {
		this.pinCode = pinCode;
	}
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public User getBankUser() {
		return bankUser;
	}
	public void setBankUser(User bankUser) {
		this.bankUser = bankUser;
	}
	
	
}
