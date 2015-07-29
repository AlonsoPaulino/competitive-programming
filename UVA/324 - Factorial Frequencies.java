import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main{

    public BigInteger getFact(int n){
        BigInteger aux = new BigInteger("1");
        for(int i = 2; i <= n; ++i) aux = aux.multiply(new BigInteger(String.valueOf(i)));
        return aux;
    }
    
    public static void main(String[] args) {
        
        int n;
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        
        while(sc.hasNext()){
           
            n = sc.nextInt();
            if(n == 0) break;

            int [] digits = new int[10];
            for(int i = 0; i < 10; ++i) digits[i] = new Integer(0);

            BigInteger fact = (new Main()).getFact(n);
            String result = String.valueOf(fact);
            
            for(int i = 0; i < result.length(); ++i){
                int val = Integer.parseInt(String.valueOf(result.charAt(i)));
                digits[val]++;
            }
            
            System.out.println(n + "!" + " --");
            for(int i = 0; i < 5; ++i){
                System.out.print("   " + "(" + i + ")" + "   " + digits[i]);
            }
            System.out.println("");
            for(int i = 5; i < 10; ++i){
                System.out.print("   " + "(" + i + ")" + "   " + digits[i]);
            }
            System.out.println("");
        }
    }
}
