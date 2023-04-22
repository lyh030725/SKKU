import java.util.Random;
import java.util.Scanner;


public class Task3 {
	
	//the class for TestSystem's variables and functions
	public static class TestSystem{
		private int correctAnswerCount; //for storing the number of correct answer.
		
		//the default constructor initializing correctionCount
		public TestSystem() {
			correctAnswerCount = 0;
		}
		
		//the function generates two random numbers and returns the numbers
		public int[] generateTwoRandomNumbers() {
			Random randomGenerator = new Random();
			int randomTwoNums[] = new int[2];
			
			randomTwoNums[0] = randomGenerator.nextInt(50);
			randomTwoNums[1] = randomGenerator.nextInt(50);
			
			return randomTwoNums;
		}
		
		/* the function returns the feedback 
		corresponding to the number of correct answers. */
		public String returnFeedback() {
			String feedBack = new String(); // makes new empty string instance
			
			/* Allocate the corresponding feedback 
			according to the number of correct answers. */
			switch(correctAnswerCount) {
				case 0:
					feedBack = String.format("Try again.");
					break;
				
				case 1:
					feedBack = String.format("Very bad.");
					break;
					
				case 2:
					feedBack = String.format("Not bad.");
					break;
					
				case 3:
					feedBack = String.format("Good.");
					break;
					
				case 4:
					feedBack = String.format("Very good!");
					break;
					
				case 5:
					feedBack =  String.format("Excellent!");
					break;
					
				default:
					feedBack = String.format("None");
					break;
			}
			return feedBack;
		}
		
		/* the function starts the test.
		 * the function makes five random addition question
		 * and increases the number of correct answer 
		 * if the answer is the same as the user's input.
		*/
		public void startTest() {
			
			Scanner input = new Scanner(System.in);
			
			//Five iterating for creating a random addition question
			//and increases the number of correct answer if the answer is the same as the user's input.
			for(int i = 1; i <=5 ; ++i) {
				int randomNums[] = generateTwoRandomNumbers();
				
				System.out.print("Question " + i + " - Calculate the "
						+ "addition (" + randomNums[0] + " + " + randomNums[1]
								+ "): ");
				
				int userAnswer = input.nextInt();
				int realAnswer = randomNums[0] + randomNums[1];
				
				if(userAnswer == realAnswer) {
					correctAnswerCount++;
				}
				
			}
		}
		
		public void PrintAnswerCountAndFeedback() {
			System.out.println("Number of correct answer: " + correctAnswerCount);
			System.out.println(returnFeedback());
		}
		
	}
	

	public static void main(String[] args) {
		
		TestSystem testSystem = new TestSystem();
		
		
		testSystem.startTest();
		
		testSystem.PrintAnswerCountAndFeedback();
	}

}
