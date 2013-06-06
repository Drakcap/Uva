import java.util.Scanner;

public class Main {
    
    private int[] coins = {1, 5, 10, 25, 50};
    long[] sol = new long[7490];

    public Main() {
        sol[0] = 1;
        
        for (int j = 0; j < coins.length; j++) {
            for (int i = 1; i < 7490; i++) {
                if (i - coins[j] >= 0) {
                    sol[i] += sol[i - coins[j]];
                }
            }
        }
    
    }
    
    public long solve(int cents) {
        return sol[cents];
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cents;
        Main main = new Main();
        
        while (scanner.hasNextInt()) {
            cents = scanner.nextInt();
            System.out.println(main.solve(cents));
        }
    
    }
}