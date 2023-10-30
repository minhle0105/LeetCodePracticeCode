package com.minhle.practiceleetcode;

import java.util.*;
import java.lang.*;
import java.io.*;

public class Cisco {
    private static String[] split(String address) {
        String[] res = new String[4];
        int index = 0;
        int i = 0;
        while (i < address.length()) {
            String add = "";
            for (int j = i; j < address.length(); j++) {
                if (address.charAt(j) == '.') {
                    break;
                }
                else {
                    add += address.charAt(j);
                }
                i++;
            }
            res[index++] = add;
            i++;
        }
        return res;
    }

    public static String  checkIPValidity(String addressIP)
    {
        String answer = "hello";
        // Write your code here
        String[] octet = split(addressIP);
        for (String oc : octet) {
            int o = Integer.parseInt(oc);
            if (o < 0 | o > 255) {
                return "INVALID";
            }
        }

        return "VALID";
    }
}
