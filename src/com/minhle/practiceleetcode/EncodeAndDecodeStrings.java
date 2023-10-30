public class Codec {
    // Encodes a list of strings to a single string.
    final String DELIMITER = "Ã";
    public String encode(List<String> strs) {
        StringBuilder res = new StringBuilder();
        for (String str : strs)
        {
            res.append(str).append(DELIMITER);
        }
        return res.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> res = new ArrayList<>();
        List<Integer> delimiter_positions = new ArrayList<>();
        for (int i = 0; i < s.length(); i++)
        {
            if (s.charAt(i) == DELIMITER.charAt(0))
            {
                delimiter_positions.add(i);
            }
        }
        int start = 0;
        for (int position : delimiter_positions)
        {
            String word = s.substring(start, position);
            res.add(word);
            start = position + 1;
        }
        return res;
    }
}
