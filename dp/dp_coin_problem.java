import java.util.*;

class Main {

  private static Map<Integer, Integer> solutions = new HashMap<>();

  private static int solve(int[] coins, int target) {
	   int min = Integer.MAX_VALUE;
	   if(solutions.get(target) != null) {
		   return solutions.get(target);
	   }
	   for(int coin: coins) {
		   if(coin == target) return 1;
		   if(coin > target) return Integer.MAX_VALUE;
		   int possibleSol = solve(coins, target - coin);
		   if(possibleSol != Integer.MAX_VALUE && (1 + possibleSol ) < min) {
			   min = possibleSol + 1;
		   }
	   }
	   solutions.put(target, min);
	   return min;
  }

  public static void main(String args[]) { 
    int [] coins = new int[]{1, 5, 7, 9, 11};
	Scanner sc = new Scanner(System.in);
	int target = sc.nextInt();
	System.out.println(solve(coins, target));
  } 
}
