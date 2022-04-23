package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.Map;

public class EncodeDecodeTinyURL {
    Map<String, Integer> encodeUrl = new HashMap<>();
    Map<Integer, String> decodeUrl = new HashMap<>();

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        encodeUrl.put(longUrl, longUrl.hashCode());
        decodeUrl.put(longUrl.hashCode(), longUrl);
        return "http://tinyurl.com/" + encodeUrl.get(longUrl);
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        String code = shortUrl.substring(19);
        return decodeUrl.get(Integer.parseInt(code));
    }
}
