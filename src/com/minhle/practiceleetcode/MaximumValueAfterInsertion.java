public class MaximumValueAfterInsertion
{
    class Solution {
        public String maxValue(String n, int x) 
        {
            return n.charAt(0) == '-' ? handleNegativeCase(n, x) : handlePositiveCase(n, x);
        }

        String handlePositiveCase(String n, int x)
        {
            for (int i = 0; i < n.length(); i++)
            {
                int cInt = Integer.parseInt(String.valueOf(n.charAt(i)));
                if (x > cInt)
                {
                    return n.substring(0, i) + (x) + n.substring(i);
                }
            }
            return n + (x);
        }

        String handleNegativeCase(String n, int x)
        {
            for (int i = 1; i < n.length(); i++)
            {
                int cInt = Integer.parseInt(String.valueOf(n.charAt(i)));
                if (x < cInt)
                {
                    return n.substring(0, i) + (x) + n.substring(i);
                }
            }
            return n + (x); 
        }
    }
}
