#!/usr/bin/env python3
"""Script that reads stdin line by line and computes metric."""
import sys


cont = 0
sz = 0
count_status = {"200": 0, "301": 0, "400": 0, "401": 0,
                "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for line in sys.stdin:
        line_split = line.split()

        if len(line_split) > 2:
            status = line_split[-2]
            size = line_split[-1]
            sz += int(size)

            if status in count_status:
                count_status[status] += 1

            cont += 1
            if cont % 10 == 0:
                print("File size: {}".format(sz))
                for k, v in sorted(count_status.items()):
                    if v != 0:
                        print("{}: {}".format(k, v))

finally:
    print("File size: {}".format(sz))
    for k, v in sorted(count_status.items()):
        if v != 0:
            print("{}: {}".format(k, v))
