
"""
Suppose you have two endpoints A and B, when you want to find a point C that has minimum sum of distance between AC and BC, the point C will always between A and B. Draw a graph and you will understand it. Lets keep moving forward. After we locating the point C between A and B, we can define that
dis(AC) = c - a; dis(CB) = b - c;
sum = dis(AC) + dis(CB) = b - a.
b - a will be a constant value, given specific b and a. Thus there will be no difference between points among A and B.

In this problem, we set two boundaries, saying i and j, and we move the i and j to do the computation.
So, the point must be the median one.
"""

