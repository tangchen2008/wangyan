#!/usr/bin/env python
# coding=utf-8
import random

xy_2_unit = { "00": "", "10": "万", "20": "亿", "30": "京", "40": "兆", "50": "垓", "1": "十", "2": "百", "3": "千" }
digi_2_zh = { 0:"零", 1:"一", 2:"二", 3:"三", 4:"四", 5:"五", 6:"六", 7:"七", 8:"八", 9:"九" }


def foo(k, f=0):
    n = str(k)
    if len(n)==1:   
        return "" if k==0 else digi_2_zh[k]
    else:
        a = (len(n)-1)/4
        b = (len(n)-1)%4
        key=''.join([str(a),str(b)])
        ut = xy_2_unit.get(key, xy_2_unit.get(str(b)))
        print digi_2_zh[int(n[0:1])], ut,
        part = ''.join(n[1:])
        if len(part) - len(str(int(part))) >= 1:
            print digi_2_zh[0],
        return foo(int(part))


if __name__ == '__main__':
    num=27740003
    print num, '\t', foo(num)
    num=23392580
    print num, '\t', foo(num)
    num=27740803
    print num, '\t', foo(num)

