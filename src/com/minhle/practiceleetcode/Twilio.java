package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Twilio {

    // Question 1
    public static List<List<String>> validateImageSize(List<List<String>> imageUrls, String maxSize) {
        // Write your code here
        if (maxSize.equals("none")) {
            maxSize = "10MB";
        }
        List<List<String>> result = new ArrayList<>();
        for (List<String> imageUrl : imageUrls) {
            String urlOfEach = imageUrl.get(0);
            List<String> urlToAdd = new ArrayList<>();
            urlToAdd.add(urlOfEach);
            result.add(urlToAdd);
        }
        String dataUnit = String.valueOf(maxSize.charAt(maxSize.length() - 2));

        for (List<String> imageUrl : imageUrls) {
            boolean lessThanMaxSize = true;
            String size = imageUrl.get(1);
            double parsedMaxSize = Integer.parseInt(maxSize.substring(0, maxSize.length() - 2));
            if (dataUnit.equals("M")) {
                double imageSize = (double) Long.parseLong(size) / 1000000;
                if(imageSize > parsedMaxSize) {
                    lessThanMaxSize = false;
                }
            }
            else if (dataUnit.equals("K")) {
                double imageSize = (double) Long.parseLong(size) / 1000;
                if(imageSize > parsedMaxSize) {
                    lessThanMaxSize = false;
                }
            }
            else {
                double imageSize = (double) Long.parseLong(size) / 1000000000;
                if(imageSize > parsedMaxSize) {
                    lessThanMaxSize = false;
                }
            }
            String toAdd = lessThanMaxSize ? "TRUE" : "FALSE";
            result.get(imageUrls.indexOf(imageUrl)).add(toAdd);
        }

        return result;
    }

    // Question 2 - Helper Method 1
    private static boolean isE164(String address) {

        if (address.charAt(0) == '+') {
            address = address.substring(1);
        }
        if (address.length() > 15) {
            return false;
        }
        if (Integer.parseInt(String.valueOf(address.charAt(0))) == 0) {
            return false;
        }
        for (int i = 0; i < address.length(); i++) {
            try {
                int a = Integer.parseInt(String.valueOf(address.charAt(i)));
            }
            catch (Exception e) {
                return false;
            }
        }
        return true;
    }

    private static boolean checkWechat(String address) {
        String[] alphabets = "0123456789abcdefghijklmnopqrstuvwxyz-_@.".split("");
        List<String> list = new ArrayList<>();
        Collections.addAll(list, alphabets);
        for (char c : address.toCharArray()) {
            if (!list.contains(String.valueOf(c))) {
                return false;
            }
        }
        return true;

    }

    // Question 2 -
    public static String validatePhoneNumberFormat(String address) {
        // Write your code here
        String result = "";
        if (!address.contains(":")) {
            if (isE164(address)) {
                result = "SMS";
            }
            else {
                result = "INVALID_ADDRESS";
            }
        }
        else {
            if (address.indexOf(" ") > 0) {
                result = "INVALID_ADDRESS";
                return result;
            }
            int indexOfColon = address.indexOf(":");
            if (address.substring(indexOfColon + 1).length() < 1 || address.substring(indexOfColon + 1).length() > 248) {
                result = "INVALID_ADDRESS";
                return result;
            }
            if (address.substring(0, indexOfColon).equals("whatsapp") || address.substring(0, indexOfColon).equals("messenger")) {
                if (isE164(address.substring(indexOfColon + 1))) {
                    result = address.substring(0, indexOfColon).toUpperCase();
                }
                else {
                    result = "INVALID_ADDRESS";
                }
            }
            else {
                if (!address.substring(0, indexOfColon).equals("wechat")) {
                    result = "INVALID_ADDRESS";
                }
                else {
                    if (checkWechat(address.substring(indexOfColon+1))) {
                        result = "WECHAT";
                    }
                    else {
                        result = "INVALID_ADDRESS";
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(validatePhoneNumberFormat("whatsapp:this_is_not_an_E164_number"));
    }
}
