#!/usr/bin/python3
""" Module for counting hot article for a given subreddit """

import requests


def count_words(subreddit, word_list, word_count={}, after=None):
    """
    Queries the Reddit API and returns the count of words in
    word_list in the titles of all the hot articles
    of a given subreddit
    """

    response = requests.get("https://www.reddit.com/r/{}/hot.json"
                            .format(subreddit),
                            params={"after": after},
                            headers={"User-Agent": "My-User-Agent"},
                            allow_redirects=False)

    if response.status_code != 200:
        return None

    info = response.json()

    hot_l = [child.get("data").get("title")
             for child in info
             .get("data")
             .get("children")]

    if not hot_l:
        return None

    word_list = list(dict.fromkeys(word_list))

    if word_count == {}:
        word_count = {word: 0 for word in word_list}

    if response.status_code == 200:
        after = info["data"]["after"]
        children = [child for child in info["data"]["children"]]
        for child in children:
            title = child["data"]["title"]
            buffer = [token.lower() for token in title.split()]
            for word in word_list:
                word_count[word] += buffer.count(word)

    if not info.get("data").get("after"):
        sorted_counts = sorted(word_count.items(), key=lambda kv: kv[0])
        sorted_counts = sorted(word_count.items(),
                               key=lambda kv: kv[1], reverse=True)
        [print('{}: {}'.format(k, v)) for k, v in sorted_counts if v != 0]
    else:
        return count_words(subreddit, word_list, word_count,
                           info.get("data").get("after"))
