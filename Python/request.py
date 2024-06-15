'''python -m pip install -U pip
python -m pip install -U matplotlib
'''
import string
import requests;
import lxml;
import lxml.html
import shutils;
import os;
import sys;
import email;
import re;
import random;
import io;
import itertools;
import collections
import functools
from functools import reduce
from colorama import Fore, Style, init;
import matplotlib;
import packaging;
import pandas;
import numpy;
import numbers;
import bisect
#print(dir(numbers))
html = requests.get('https://timesofindia.indiatimes.com/home/headlines')
#print(html.content)
doc = lxml.html.fromstring(html.content)
new_rel = doc.xpath("//div[@id='NEWS HEADLINES']")[0]
print(new_rel)