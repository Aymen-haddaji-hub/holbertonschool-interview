#!/usr/bin/python3
""" Script that reads stdin line by line and computes metrics."""

from sys import stdin


data_list = {"size": 0, "lines": 1}

errors = {"200": 0, "301": 0, "400": 0, "401": 0,
          "403": 0, "404": 0, "405": 0, "500": 0}


def print_source():
    """ Print codes and numbers"""
    print("File size: {}".format(data_list["size"]))
    for key in sorted(errors.keys()):
        if errors[key] != 0:
            print("{}: {}".format(key, errors[key]))


def datasize(data):
    """ Count file codes and size"""
    data_list["size"] += int(data[-1])
    if data[-2] in errors:
        errors[data[-2]] += 1


if __name__ == "__main__":
    try:
        for line in stdin:
            try:
                datasize(line.split(" "))
            except Exception:
                pass
            if data_list["lines"] % 10 == 0:
                print_source()
            data_list["lines"] += 1
    except KeyboardInterrupt:
        print_source()
        raise
    print_source()
