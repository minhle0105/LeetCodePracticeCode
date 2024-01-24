package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class ReformatDate {
    static HashMap<String, String> monthConversion = new HashMap<>();
    private void createHashMap() {
        monthConversion.put("Jan", "01");
        monthConversion.put("Feb", "02");
        monthConversion.put("Mar", "03");
        monthConversion.put("Apr", "04");
        monthConversion.put("May", "05");
        monthConversion.put("Jun", "06");
        monthConversion.put("Jul", "07");
        monthConversion.put("Aug", "08");
        monthConversion.put("Sep", "09");
        monthConversion.put("Oct", "10");
        monthConversion.put("Nov", "11");
        monthConversion.put("Dec", "12");
    }

    private String parseMonth(String month) {
        return monthConversion.get(month);
    }


    public String reformatDate(String date) {
        createHashMap();
        int[] spacesIndex = new int[2];
        int counter = 0;
        for (int i = 0; i < date.length(); i++) {
            if (date.charAt(i) == ' ') {
                spacesIndex[counter++] = i;
            }
        }
        String day = "";
        if (spacesIndex[0] == 3) {
            day = date.substring(0,1);
        }
        else {
            day = date.substring(0,2);
        }
        if (Integer.parseInt(day) < 10) {
            day = "0" + day;
        }
        // 6th Jun 1933
        String month = date.substring(spacesIndex[0] + 1, spacesIndex[1]);
        month = parseMonth(month);
        String year = date.substring(spacesIndex[1]);

        String result = "";
        result += year;
        result += "-";
        result += month;
        result += "-";
        result += day;
        return result.trim();
    }

    @Test
    void firstTest() {
        String date = "6th Jun 1933";
        String expected = "1933-06-06";
        String actual = reformatDate(date);
        Assertions.assertEquals(expected, actual);
    }
}
