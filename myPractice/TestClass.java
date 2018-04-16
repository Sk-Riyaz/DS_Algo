
import java.util.*;

class TestClass {
   public static void main(String args[] ) throws Exception {
      Scanner s = new Scanner(System.in);
      int n = s.nextInt();
      int []arr= new int[n];
      int []cumm_sum= new int[n];
      int tot = 0;
      for( int i = 0; i < n; ++i )
      {
         int val = s.nextInt();
         if( val % 2 == 1 )
            arr[i] = 1;
         else
            arr[i] = -1;

         tot += arr[i];
         cumm_sum[i] = tot;
      }


      HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
      int count = 0;
      for(int i=0; i<n; i++){
         if (cumm_sum[i] == 0)
            count++;

         Integer temp = hm.get(cumm_sum[i]);
         if(temp != null) {
            count += temp;
            hm.put(cumm_sum[i], temp+1);
         } else
            hm.put(cumm_sum[i], 1);
      }
      System.out.println(count);
   }
}

