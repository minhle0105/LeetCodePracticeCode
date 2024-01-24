package com.minhle.practiceleetcode;

import java.util.*;

public class DesignTwitter {
    static class User {
        int userId;
        Set<User> following;
        Set<User> followers;

        public User(int userId) {
            this.userId = userId;
            this.following = new HashSet<>();
            this.followers = new HashSet<>();
        }
    }

    static class Post {
        int postId;
        int userId;

        public Post(int postId, int userId) {
            this.postId = postId;
            this.userId = userId;
        }
    }

    static class Twitter {
        Map<Integer, User> map;
        List<Post> allPosts;

        public Twitter() {
            this.map = new HashMap<>();
            this.allPosts = new ArrayList<>();
        }

        public void postTweet(int userId, int tweetId) {
            if (!map.containsKey(userId)) {
                map.put(userId, new User(userId));
            }
            Post post = new Post(tweetId, userId);
            this.allPosts.add(post);
        }

        public List<Integer> getNewsFeed(int userId) {
            List<Integer> res = new ArrayList<>();
            for (int i = this.allPosts.size() - 1; i >= 0; i--) {
                if (allPosts.get(i).userId == userId || this.map.get(userId).following.contains(this.map.get(allPosts.get(i).userId))) {
                    res.add(allPosts.get(i).postId);
                }
                if (res.size() == 10) {
                    break;
                }
            }
            return res;
        }

        public void follow(int followerId, int followeeId) {
            if (!map.containsKey(followerId)) {
                map.put(followerId, new User(followerId));
            }
            if (!map.containsKey(followeeId)) {
                map.put(followeeId, new User(followeeId));
            }
            map.get(followerId).following.add(map.get(followeeId));
            map.get(followeeId).followers.add(map.get(followerId));
        }

        public void unfollow(int followerId, int followeeId) {
            map.get(followerId).following.remove(map.get(followeeId));
            map.get(followeeId).followers.remove(map.get(followerId));
        }
    }
}
