import java.util.*;

class Number implements Comparable<Number>
{
    int val;
    int nOneBits;

    public Number(int val_) {
        this.val = val_;
        this.nOneBits = 0;
        countOneBits();
    }

    private void countOneBits()
    {
        int curr = this.val;
        while (curr > 0)
        {
            if (curr % 2 == 1)
            {
                ++this.nOneBits;
            }
            curr /= 2;
        }
    }

    @Override
    public int compareTo(Number _number)
    {
        if (this.nOneBits == _number.nOneBits)
        {
            return Integer.compare(this.val, _number.val);
        }
        return Integer.compare(this.nOneBits, _number.nOneBits);
    }
}

class Solution {
    public int[] sortByBits(int[] arr) {
        List<Number> numbers = new ArrayList<>();
        for (int num : arr)
        {
            numbers.add(new Number(num));
        }
        Collections.sort(numbers);
        int[] res = new int[arr.length];
        int i = 0;
        for (Number number : numbers)
        {
            res[i] = number.val;
            i++;
        }
        return res;
    }
}
