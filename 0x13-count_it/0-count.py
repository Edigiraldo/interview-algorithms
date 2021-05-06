#!/usr/bin/python3
"""Function count_words."""
import operator
import requests


def count_words(subreddit, word_list, after="", word_dict={}):
    """Recursive function that queries the Reddit API, parses the title
     of all hot articles, and prints a sorted count of given keywords."""
    url = "https://reddit.com/r/" + subreddit + "/hot.json?&after=" + after
    headers = {'user-agent': 'Chrome/81.0.4044.129'}
    reddit = requests.get(url, headers=headers).json()

    if 'error' in reddit or len(reddit['data']['children']) == 0:
        return None
    if len(word_dict) == 0:
        for word in word_list:
            word_dict[word] = 0

    children = reddit['data']['children']
    for child in children:
        words = child["data"]["title"].lower()
        words = words.split()
        for word in words:
            for w in word_list:
                if w.lower() == word:
                    word_dict[w] += 1

    after = reddit['data']['after']
    if after is None:
        dict_sorted = sorted(word_dict.items(),
                             key=operator.itemgetter(1), reverse=True)
        ordered = 0
        while ordered != 1:
            ordered = 1
            for i in range(len(dict_sorted)):
                if i < len(dict_sorted) - 1:
                    if dict_sorted[i][1] == dict_sorted[i+1][1]:
                        if dict_sorted[i][0] > dict_sorted[i+1][0]:
                            ordered = 0
                            aux = dict_sorted[i]
                            dict_sorted[i] = dict_sorted[i+1]
                            dict_sorted[i+1] = aux
        for w in dict_sorted:
            if w[1] > 0:
                print("{}: {}".format(w[0], w[1]))
    else:
        count_words(subreddit, word_list, after, word_dict)
