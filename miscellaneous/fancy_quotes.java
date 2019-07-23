import java.util.*;
import java.io.*;
public class fancy_quotes
{
public static void main(String args[]) throws IOException
{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int testcases = Integer.parseInt(br.readLine());
    outer : while(testcases--!=0)
    {
        String str = br.readLine();
        for (int i=0;i<str.length()-2;i++)
        {
            char ch = str.charAt(i);
            char ch2 = str.charAt(i+1);
            char ch3 = str.charAt(i+2);
            if (ch == 'n' && ch2 == 'o' && ch3 == 't')
            {
                if((i+2) == str.length() - 1 || str.charAt(i+3) == ' ')
                {
                System.out.println("Real Fancy");
                continue outer;
                }
            }
            //System.out.println("Fancy\n");
        }
        System.out.println("regularly fancy");

    }
}
}