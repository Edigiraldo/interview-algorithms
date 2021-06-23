#!/usr/bin/python3
"""Function makeChange."""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, it determines the fewest
    number of coins needed to meet a given amount total.

    - coins is a list of the values of the coins in your possession.
    - total is the value to meet with coins.
    - Return: fewest number of coins needed to meet total.
        - If total is 0 or less, returns 0
        - If total cannot be met returns -1.
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    if total < coins[-1]:
        return -1

    coin_idx = 0
    num_coins = 0
    while total > 0 and coin_idx < len(coins):
        coin_val = coins[coin_idx]
        factor = total // coin_val
        if factor != 0:
            num_coins += factor
            total -= factor * coin_val

        coin_idx += 1

    if total == 0:
        return num_coins

    return -1
