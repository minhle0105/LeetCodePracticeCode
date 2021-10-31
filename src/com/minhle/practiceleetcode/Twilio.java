package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class Twilio {
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

    /*
     * Complete the 'validatePhoneNumberFormat' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING address as parameter.
     */

    public static String validatePhoneNumberFormat(String address) {
        // Write your code here
        String result = "";
        String[] channels = {"whatsapp", "wechat", "messenger", "sms"};
        if (address.indexOf(":") < 0) {
            if (isE164(address)) {
                result = "SMS";
            }
            else {
                result = "INVALID_ADDRESS";
            }
            return result;
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
                    return result;
                }
            }
        }
        return result;

    }


    public static void main(String[] args) {
        validatePhoneNumberFormat("whatsapp:this_is_not_an_E164_number");
    }
}
