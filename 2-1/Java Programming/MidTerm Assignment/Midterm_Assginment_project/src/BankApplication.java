import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.ArrayList;
import java.awt.GridLayout;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import javax.swing.JTextPane;

//a Class for the application that combines all the banking functions
public class BankApplication extends JFrame implements ActionListener{

	private JPanel atmContentPane; //Basic panel containing all components
	private JLabel wooriIconLabel; //a label for showing WOORI Bank's icon
	private JLabel atmNameLabel; //a label for showing ATM's name, "SKKU ATM"
	private JTextPane atmTextPane; //a text panel for showing all ATM's texts.
	private JPanel optionPanel; // a panel for placing option buttons in grid layout
	private JButton optionOneButton; //a button for option 1 functioning "Balance Checking"
	private JButton optionTwoButton; //a button for option 2 functioning "Withdrawing money"
	private JButton optionThreeButton; //a button for option 3 functioning "Deposit"
	private JButton optionFourButton; //a button for option 4 functioning "Transfer"
	private JButton optionFiveButton; //a button for option 5 functioning "Change Bank Account Information"
	private JPanel languagePanel; //a panel for placing language buttons in grid layout
	private JButton languageEnglishButton; // a button for setting language "ENGLISH"
	private JButton languageKoreanButton; // a button for setting language "KOREAN"
	private JPanel keyPadPanel; // a panel for placing key buttons in grid layout
	private JButton keyZero; // a button for key 0
	private JButton keyOne; // a button for key 1
	private JButton keyTwo; // a button for key 2
	private JButton keyThree; // a button for key 3
	private JButton keyFive; // a button for key 4
	private JButton keySix; // a button for key 5
	private JButton keyFour; // a button for key 6
	private JButton keyEight; // a button for key 7
	private JButton keySeven; // a button for key 8
	private JButton keyNine; // a button for key 9
	private JPanel functionPadPanel; // a panel for placing function buttons in grid layout
	private JButton cancelButton; // a button for canceling processing any time
	private JButton clearButton; // a button for clearing digit texts
	private JButton enterButton; // a button for enter function
	
	//the list of multiple bank accounts in one place
	static private ArrayList<BankAccount> bankAccounts = new ArrayList<>();
	
	private int state = 0; // for storing status of the process the application is performing
	private int keyPadOn = 0; // for Deciding whether to use the keypad function or not
	private int isUnique = 1; // for distinguishing between duplicates in the process of changing account information
	private BankAccount currentBankAccount; // for saving the user who is currently using the banking application
	private BankAccount currentTransferAccount; // for saving the target account to transfer in the process of Transfer	
	static private StringBuffer atmText = new StringBuffer(); // String Buffer for the ability to append texts to atmTextPane
	
	
	public static void main(String[] args) {
		
		BankApplication frame = new BankApplication(); // generating BankApplication object for making basic frame
		frame.setVisible(true); // set the frame visible
		frame.setResizable(false); // set the frame not resizable
		
		User user1 = new User("Firuz"); // generating first user , "Firuz"
		User user2 = new User("John"); // generating second user, "John"
		User user3 = new User("Eldor"); // generating third user, "Eldor"
		
		bankAccounts.add(new BankAccount("200100237898",1234,500000.0, user1));
		bankAccounts.add(new BankAccount("110000022033",4321,700000.0, user2));
		bankAccounts.add(new BankAccount("111111111111",2222,900000.0, user3));
		
	}
	

	
	public BankApplication() {
		//Placement of all buttons and panels for ATM applications(line 76-106)
		setTitle("ATM");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 540, 490);
		atmContentPane = new JPanel();
		atmContentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(atmContentPane);
		atmContentPane.setLayout(null);
		
		wooriIconLabel = new JLabel("New label");
		wooriIconLabel.setIcon(new ImageIcon("images/woori.png"));
		wooriIconLabel.setBounds(6, 6, 200, 50);
		atmContentPane.add(wooriIconLabel);
		
		atmNameLabel = new JLabel("SKKU ATM");
		atmNameLabel.setBounds(231, 51, 64, 16);
		atmContentPane.add(atmNameLabel);
		
		atmTextPane = new JTextPane();
		atmTextPane.setText("Please, insert your card and press ENTER...");
		atmTextPane.setBounds(132, 68, 271, 138);
		atmContentPane.add(atmTextPane);
		
		placeKeyButton();
		
		placeFunctionButton();
		
		placeLanguageButton();
		
		placeOptionButton();
		
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		
		//When the cancel button is clicked, call the cancel function
		if(e.getSource() == cancelButton) {
			cancleButtonPressed();
		}
		
		//When the state is 0(PIN Input state) and the enter button is clicked,
		//call function for PIN input screen
		if(state == 0) {
			if(e.getSource() == enterButton) {
				pinInputWindow();
			}
			
		}
		
		//When the state is 1(Option choosing)
		//Invoke a function, depending on which option button you click
		else if(state == 1) {
			optionChoosed(e);
		}
		
		//When the state is 2(Option 2) and the enter button is clicked,
		//call function for withdrawing
		else if(state == 2) {
			if(e.getSource() == enterButton) {
				withdrawingProcess();
			}
		}
		
		//When the state is 3(Option 3) and the enter button is clicked, 
		//call function for deposit
		else if(state == 3) {
			if(e.getSource() == enterButton) {
				depositProcess();
			}
		}
		
		//When the state is 4(Option 4-1) and the enter button is clicked, 
		//call function for inputing account to transfer
		else if(state == 4) {
			if(e.getSource() == enterButton) {
				inputTransferAccount();
			}
		}
		
		//When the state is 7(Option 4-2) and the enter button is clicked, 
		//call function for inputing amount to transfer
		else if(state == 7) {
			if(e.getSource() == enterButton) {
				inputTransferAmount();
			}
		}
		
		//When the state is 5(Option 5-1) and the enter button is clicked, 
		//call function for changing bank number
		else if(state == 5) {
			if(e.getSource() == enterButton) {
				changeBankNumber();
			}	
			
		}
		
		//When the state is 8(Option 5-2) and the enter button is clicked, 
		//call function for changing PIN code
		else if(state == 8) {
			if(e.getSource() == enterButton) {
				changePINCode();
			}
			
		}
		
		//When the state is -1(After Process) and the enter button is clicked,
		//call function for sending Thank you message
		else{
			if(e.getSource() == enterButton) {
				messageThankYou();
			}
		}
		
		//When the keyPadOn is 1,
		//call function for inputing key and clear button
		if(keyPadOn == 1) {
			keyPadOnFuc(e);
		}
	}
	
	//when clicking a button on the keypad, append the numbers entered in atmTextPane.
	//when you click the clear button, all numbers entered in atmTextPane are cleared.
	public void keyPadOnFuc(ActionEvent e) {
			if(e.getSource() == keyOne) {
				atmText.append("1");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keyTwo) {
				atmText.append("2");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keyThree) {
				atmText.append("3");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keyFour) {
				atmText.append("4");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keyFive) {
				atmText.append("5");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keySix) {
				atmText.append("6");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keySeven) {
				atmText.append("7");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keyEight) {
				atmText.append("8");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keyNine) {
				atmText.append("9");
				atmTextPane.setText(atmText.toString());
			}
			else if(e.getSource() == keyZero) {
				atmText.append("0");
				atmTextPane.setText(atmText.toString());
			}
			
			if(e.getSource() == clearButton) {
				atmText = new StringBuffer(atmText.toString().replaceAll("[0-9]", ""));
				atmTextPane.setText(atmText.toString());
			}
		
	}
	
	//Attach text, images, and action listener to the option button and place them on the panel.
	public void placeOptionButton(){
		optionPanel = new JPanel();
		optionPanel.setBounds(16, 68, 117, 138);
		atmContentPane.add(optionPanel);
		optionPanel.setLayout(new GridLayout(5, 1, 0, 0));
		
		optionOneButton = new JButton("OPTION 1");
		optionOneButton.setIcon(new ImageIcon("images/arr.png"));
		optionPanel.add(optionOneButton);
		optionOneButton.addActionListener(this);
		
		optionTwoButton = new JButton("OPTION 2");
		optionTwoButton.setIcon(new ImageIcon("images/arr.png"));
		optionPanel.add(optionTwoButton);
		optionTwoButton.addActionListener(this);
		
		optionThreeButton = new JButton("OPTION 3");
		optionThreeButton.setIcon(new ImageIcon("images/arr.png"));
		optionPanel.add(optionThreeButton);
		optionThreeButton.addActionListener(this);
		
		optionFourButton = new JButton("OPTION 4");
		optionFourButton.setIcon(new ImageIcon("images/arr.png"));
		optionPanel.add(optionFourButton);
		optionFourButton.addActionListener(this);
		
		optionFiveButton = new JButton("OPTION 5");
		optionFiveButton.setIcon(new ImageIcon("images/arr.png"));
		optionPanel.add(optionFiveButton);
		optionFiveButton.addActionListener(this);
	}
	
	//Attach text, images, and action listener to the language button and place them on the panel.
	public void placeLanguageButton() {
		languagePanel = new JPanel();
		languagePanel.setBounds(402, 68, 132, 83);
		atmContentPane.add(languagePanel);
		languagePanel.setLayout(new GridLayout(2, 1, 0, 0));
		
		languageEnglishButton = new JButton("ENGLISH");
		languageEnglishButton.setIcon(new ImageIcon("images/eng.png"));
		languagePanel.add(languageEnglishButton);
		languageEnglishButton.addActionListener(this);
		
		languageKoreanButton = new JButton("KOREAN");
		languageKoreanButton.setIcon(new ImageIcon("images/kor.png"));
		languagePanel.add(languageKoreanButton);
		languageKoreanButton.addActionListener(this);
	}
	
	//Attach text, images, and action listener to the function button and place them on the panel.
	public void placeFunctionButton() {
		functionPadPanel = new JPanel();
		functionPadPanel.setBounds(402, 207, 132, 183);
		atmContentPane.add(functionPadPanel);
		functionPadPanel.setLayout(new GridLayout(3, 1, 0, 0));
		
		cancelButton = new JButton("CANCEL");
		cancelButton.setIcon(new ImageIcon("images/cancel.png"));
		functionPadPanel.add(cancelButton);
		cancelButton.addActionListener(this);
		
		clearButton = new JButton("CLEAR");
		clearButton.setIcon(new ImageIcon("images/clear.png"));
		functionPadPanel.add(clearButton);
		clearButton.addActionListener(this);
		
		enterButton = new JButton("ENTER");
		enterButton.setIcon(new ImageIcon("images/enter.png"));
		functionPadPanel.add(enterButton);
		enterButton.addActionListener(this);
	}
	
	//Attach text, images, and action listener to the key button and place them on the panel.
	public void placeKeyButton() {
		keyPadPanel = new JPanel();
		keyPadPanel.setBounds(132, 207, 271, 183);
		atmContentPane.add(keyPadPanel);
		keyPadPanel.setLayout(new GridLayout(3, 4, 0, 0));
		
		keyOne = new JButton("");
		keyOne.setIcon(new ImageIcon("images/1.png"));
		keyPadPanel.add(keyOne);
		keyOne.addActionListener(this);
		
		keyTwo = new JButton("");
		keyTwo.setIcon(new ImageIcon("images/2.png"));
		keyPadPanel.add(keyTwo);
		keyTwo.addActionListener(this);
		
		keyThree = new JButton("");
		keyThree.setIcon(new ImageIcon("images/3.png"));
		keyPadPanel.add(keyThree);
		keyThree.addActionListener(this);
		
		keyFour = new JButton("");
		keyFour.setIcon(new ImageIcon("images/4.png"));
		keyPadPanel.add(keyFour);
		keyFour.addActionListener(this);
		
		keyFive = new JButton("");
		keyFive.setIcon(new ImageIcon("images/5.png"));
		keyPadPanel.add(keyFive);
		keyFive.addActionListener(this);
		
		keySix = new JButton("");
		keySix.setIcon(new ImageIcon("images/6.png"));
		keyPadPanel.add(keySix);
		keySix.addActionListener(this);
		
		keySeven = new JButton("");
		keySeven.setIcon(new ImageIcon("images/7.png"));
		keyPadPanel.add(keySeven);
		keySeven.addActionListener(this);
		
		keyEight = new JButton("");
		keyEight.setIcon(new ImageIcon("images/8.png"));
		keyPadPanel.add(keyEight);
		keyEight.addActionListener(this);
		
		keyNine = new JButton("");
		keyNine.setIcon(new ImageIcon("images/9.png"));
		keyPadPanel.add(keyNine);
		keyNine.addActionListener(this);
		
		
		keyZero = new JButton("");
		keyZero.setIcon(new ImageIcon("images/0.png"));
		keyZero.setBounds(223, 389, 90, 61);
		atmContentPane.add(keyZero);
		keyZero.addActionListener(this);
	}
	
	//Show the cancellation phrase on atmTextPane and change to PIN input screen.
	public void cancleButtonPressed() {
		atmTextPane.setText("Process is canceled by user! Please press ENTER...");
		state = 0;
		atmText = new StringBuffer();
	}
	
	//Receive PIN input, get only numbers from atmPane, 
	//determine if it is an existing PIN, 
	//and if existed, move the option selection state
	public void pinInputWindow() {
		keyPadOn = 1;
		//When coming to the first time at PIN input window
		if(atmText.toString().isEmpty()) {
			atmText.append("PIN: ");
			atmTextPane.setText(atmText.toString());
		}
		//When inputing a PIN and pressing enter
		else {
			//When you press enter without putting anything
			if(atmText.toString().replaceAll("[^0-9]", "").isEmpty())
				return;
			//saving only integer values from atmPane
			int keyInput = Integer.parseInt(atmText.toString().replaceAll("[^0-9]", ""));
			//Emptying the String Buffer
			atmText = new StringBuffer();
			//repeats to find the account having same pin code.
			for(BankAccount bankAccount : bankAccounts) {
				if( keyInput == bankAccount.getPinCode()) {
					state = 1;
					currentBankAccount = bankAccount;
					atmTextPane.setText("Welcome " + bankAccount.getBankUser().getName() +
							"\nPlease choose option:\n" +
							"OPTION 1: Balance Checking\n" +
							"OPTION 2: Withdrawing money\n" +
							"OPTION 3: Deposit\n" +
							"OPTION 4: Transfer\n" +
							"OPTION 5: Change Account Information\n"
							);
					keyPadOn = 0;
					break;
				}
			}
			//When not finding an account with the same pin code
			if(state == 0) {
				atmText.append("Wrong pin! Try Again:\nPIN:");
				atmTextPane.setText(atmText.toString());
			}
		}
	}
	
	//Change state according to the selected option, and change text in atmPane.
	public void optionChoosed(ActionEvent e) {
		if(e.getSource() == optionOneButton) {
			atmTextPane.setText("User: " + currentBankAccount.getBankUser().getName() +
					"\n" + "Balance: " + currentBankAccount.getBalance() +
					"\n" + "Press ENTER..."
					);
			state = -1;
		}
		else if(e.getSource() == optionTwoButton) {
			state = 2;
			atmTextPane.setText("Enter Withdrawal Amount: ");
			atmText.append("Enter Withdrawal Amount: ");
			keyPadOn = 1;
		}
		else if(e.getSource() == optionThreeButton) {
			state = 3;
			atmTextPane.setText("Enter Deposit Amount: ");
			atmText.append("Enter Deposit Amount: ");
			keyPadOn = 1;
		}
		else if(e.getSource() == optionFourButton) {
			state = 4;
			atmTextPane.setText("Enter Account Number(Receiver): ");
			atmText.append("Enter Account Number(Receiver): ");
			keyPadOn = 1;
		}
		else if(e.getSource() == optionFiveButton) {
			state = 5;
			atmTextPane.setText("Step One)" + "\nEnter New Bank Number(twelve-digit): ");
			atmText.append(atmTextPane.getText());
			keyPadOn = 1;
		}
	}
	
	//Receive withdrawing amount, get only numbers from atmPane, 
	//determine if current account's balance is greater than withdrawing amount, 
	//and if it is, subtract as much as withdrawing amount from the current account' balance.
	public void withdrawingProcess() {
			//When you press enter without putting anything
			if(atmText.toString().replaceAll("[^0-9]", "").isEmpty())
			return;
			//saving only integer values from atmPane and converting double.
			double keyInput = Integer.parseInt(atmText.toString().replaceAll("[^0-9]", ""));
			//Emptying the String Buffer
			atmText = new StringBuffer();
			//if current account's balance is greater than withdrawing amount
			if(currentBankAccount.getBalance() >= keyInput) {
				currentBankAccount.setBalance(currentBankAccount.getBalance() - keyInput);
				atmTextPane.setText("Success:)" + "\n" + "User: " + currentBankAccount.getBankUser().getName() +
						"\nWithdrawal Amount: " + keyInput + "\n" + "Current Balance: " + currentBankAccount.getBalance() +
						"\n" + "Press ENTER..."
						);
				state = -1;
				keyPadOn = 0;
			}
			//if current account's balance is lower than withdrawing amount
			else {
				atmTextPane.setText("Not enough money!\nPress ENTER...");
				state = -1;
				keyPadOn = 0;
			}
		
	}
	
	//Receive deposit amount, get only numbers from atmPane, 
	//and adding as much as deposit amount to the current account' balance.
	public void depositProcess() {
			//When you press enter without putting anything
			if(atmText.toString().replaceAll("[^0-9]", "").isEmpty())
			return;
			//saving only integer values from atmPane and converting double.
			double keyInput = Integer.parseInt(atmText.toString().replaceAll("[^0-9]", ""));
			//Emptying the String Buffer
			atmText = new StringBuffer();
			
			currentBankAccount.setBalance(currentBankAccount.getBalance() + keyInput);
			atmTextPane.setText("Success:)" + "\n" + "User: " + currentBankAccount.getBankUser().getName() +
						"\nDeposit Amount: " + keyInput + "\n" + "Current Balance: " + currentBankAccount.getBalance() +
						"\n" + "Press ENTER..."
						);
			state = -1;
			keyPadOn = 0;
	}
	
	//Receive bank number to transfer, get only numbers from atmPane, 
	//check to see if there is an account that corresponds to the bank number
	//and if it is, move to state to decide how much to transfer.
	public void inputTransferAccount() {
			//When you press enter without putting anything
			if(atmText.toString().replaceAll("[^0-9]", "").isEmpty())
			return;
			//saving only integer values from atmPane and converting String.
			String keyInput = atmText.toString().replaceAll("[^0-9]", "");
			//Emptying the String Buffer
			atmText = new StringBuffer();
			//iterating to check to see if there is an account that corresponds to the bank number
			for(BankAccount bankAccount : bankAccounts) {
				if( keyInput.equals(bankAccount.getBankNumber())) {
					state = 7;
					atmTextPane.setText("Transfer Account: " + bankAccount.getBankUser().getName() +
							"\n" + "Enter Transfer Amount: "
							);
					atmText.append(atmTextPane.getText());
					currentTransferAccount = bankAccount;
					keyPadOn = 1;
					break;
				}
			}
			//if there is not an account that corresponds to the bank number
			if(state == 4) {
				atmTextPane.setText("You entered the wrong account number!\nPress ENTER...");
				state = -1;
				keyPadOn = 0;
			}
		
	}
	
	//Receive amount to transfer, get only numbers from atmPane, 
	//determine if current account's balance is greater than amount to transfer
	//and if it is, subtract as much as withdrawing amount from the current account' balance
	//and adding as much as withdrawing amount to the account to transfer's balance
	public void inputTransferAmount() {
			//When you press enter without putting anything
			if(atmText.toString().replaceAll("[^0-9]", "").isEmpty())
			return;
			//saving only integer values from atmPane and converting double.
			double keyInput = Integer.parseInt(atmText.toString().replaceAll("[^0-9]", ""));
			//Emptying the String Buffer
			atmText = new StringBuffer();
			//if current account's balance is greater than amount to transfer
			if(currentBankAccount.getBalance() >= keyInput) {
				currentBankAccount.setBalance(currentBankAccount.getBalance() - keyInput);
				currentTransferAccount.setBalance(currentTransferAccount.getBalance() + keyInput);
				atmTextPane.setText("Transfer Amount: " + keyInput + "\n" + "Current Balance: " + currentBankAccount.getBalance() +
						"\n" + "Press ENTER..."
						);
				state = -1;
				keyPadOn = 0;
			}
			//if current account's balance is not greater than amount to transfer
			else {
				atmTextPane.setText("Not enough money!\nPress ENTER...");
				state = -1;
				keyPadOn = 0;
			}
		
	}
	
	//Receive new bank number, get only numbers from atmPane, 
	//determine if new bank number is 12-digit.
	//and determine if new bank number do not overlap with other accounts
	//and if it is change existing bank number to new one
	public void changeBankNumber() {
			//When you press enter without putting anything
			if(atmText.toString().replaceAll("[^0-9]", "").isEmpty())
			return;
			//saving only integer values from atmPane and converting String.
			String keyInput = atmText.toString().replaceAll("[^0-9]", "");
			//Emptying the String Buffer
			atmText = new StringBuffer();
			isUnique = 1;
			//if new bank number is 12-digit.
			if(keyInput.length() == 12) {
				//iterating for determine if new bank number do not overlap with other accounts
				for(BankAccount bankAccount : bankAccounts) {
					//if new bank number overlaps with other accounts
					if(!bankAccount.equals(currentBankAccount) && keyInput.equals(bankAccount.getBankNumber())) {
						atmTextPane.setText("Step One)\nAlready existed Bank Number!\nTry again(twelve-digit):");
						atmText.append(atmTextPane.getText());
						isUnique = 0;
						break;
					}
				}
				//if new bank number do not overlap with other accounts
				if(isUnique == 1) {
					atmTextPane.setText("Step Two)" + "\nEnter New PIN Code(four-digit): ");
					atmText.append(atmTextPane.getText());
					currentBankAccount.setBankNumber(keyInput);
					state = 8;
				}
				
			}
			//if new bank number is not 12-digit.
			else {
				atmTextPane.setText("Step One)\nWrong Bank Number Format!\nTry again(twelve-digit):");
				atmText.append(atmTextPane.getText());
			}
		
	}
	
	//Receive new PIN code, get only numbers from atmPane, 
	//determine if new bank number is 4-digit.
	//and determine if new PIN code do not overlap with other accounts
	//and if it is change existing PIN code to new one
	public void changePINCode() {
			//When you press enter without putting anything
			if(atmText.toString().replaceAll("[^0-9]", "").isEmpty())
			return;
			//saving only integer values from atmPane and converting String.
			String keyInput = atmText.toString().replaceAll("[^0-9]", "");
			//Emptying the String Buffer
			atmText = new StringBuffer();
			isUnique = 1;
			//if new PIN code is 4-digit.
			if(keyInput.length() == 4) {
				//iterating for determine if new PIN code do not overlap with other accounts
				for(BankAccount bankAccount : bankAccounts) {
					//if new PIN code overlaps with other accounts
					if( !bankAccount.equals(currentBankAccount) && Integer.parseInt(keyInput) == bankAccount.getPinCode()) {
						atmTextPane.setText("Step Two)\nAlready existed PIN Code!\nTry again(four-digit):");
						atmText.append(atmTextPane.getText());
						isUnique = 0;
						break;
					}
				}
				//if new PIN code do not overlap with other accounts
				if(isUnique == 1) {
					currentBankAccount.setPinCode(Integer.parseInt(keyInput));
					atmTextPane.setText("Compelete!\n[Changed Account Information]\n"
							+ "Name: " + currentBankAccount.getBankUser().getName() + "\n"
							+ "Bank Number: " + currentBankAccount.getBankNumber() + "\n"
							+ "PIN Code: " + currentBankAccount.getPinCode() + "\nPress ENTER...");
					state = -1;
					keyPadOn = 0;
				}
				
			}
			//if new PIN Code is not 4-digit.
			else {
				atmTextPane.setText("Step Two)\nWrong PIN code Format!\nTry again(four-digit):");
				atmText.append(atmTextPane.getText());
			}
		
	}
	//Send a thank you message at the end of ant process and move the PIN input window
	public void messageThankYou() {
		
			keyPadOn = 0;
			atmTextPane.setText("Thank you for banking with us!\npress ENTER...");
			state = 0;
		
	}
}


