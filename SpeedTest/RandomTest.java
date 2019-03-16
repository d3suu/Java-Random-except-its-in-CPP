import java.util.*;
public class RandomTest {
   public static void main( String args[] ) {
      Random rnd = new Random(2137);
      for(long i = 0; i<=1000000000; i++){
	rnd.nextLong();
      }
   }    
}
