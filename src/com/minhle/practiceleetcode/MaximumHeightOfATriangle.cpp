class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) 
    {
        return max(count(red, blue), count(blue, red));;
    }

    int count (int color1, int color2)
    {
        bool is_color1 = true;
        int row = 0;
        while (color1 > 0 || color2 > 0)
        {
            ++row;
            if (is_color1)
            {
                if (color1 < row)
                {
                    --row;
                    break;
                }
                color1 -= row;
            }
            else
            {
                if (color2 < row)
                {
                    --row;
                    break;
                }
                color2 -= row;
            }
            is_color1 = !is_color1;
        }
        return row;
    }
};
