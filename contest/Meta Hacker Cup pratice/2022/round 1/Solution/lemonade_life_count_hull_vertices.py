#!/usr/bin/python
###############################################################################
#                                                                             #
# Meta Hacker Cup 2022: Round 1                                               #
# Problem C: Lemonade Life                                                    #
#                                                                             #
# This script empirically tests the maximum possible number of vertices of a  #
# convex polygon with integer coordinates no greater than 1,000,000.          #
#                                                                             #
# It tries to fit as many vectors into the lower right quadrant such that:    #
# - the sum of all x and y-coordinates must each be at most 500,000, and      #
# - no vector is a scalar multiple of another.                                #
#                                                                             #
# For the latter to be true, each chosen vector's (x, y) coordinates must be  #
# coprime. It's important that we can't divide them by a common factor to get #
# a shorter vector, or we could fit more vectors onto the grid.               #
#                                                                             #
# For a quadrant of size 500000^2, the max comes out to 8400 vectors if we    #
# choose coprime vectors within [0,117]^2. This results in ~33600 vectors     #
# across all 4 quadrants.                                                     #
#                                                                             #
###############################################################################

LIM = 500000  # Coordinate bounds of one quadrant.

for LIM2 in range(100, 150):
    # Generate all coprimes pairs (a, b) s.t. 1 <= a <= b <= LIM2 using the
    # Farey sequence: https://en.wikipedia.org/wiki/Farey_sequence#Next_term
    pairs = []
    a, b, c, d = 0, 1, 1, LIM2
    while c <= LIM2:
        k = (LIM2 + b) // d
        a, b, c, d = c, d, k * c - a, k * d - b
        pairs.append((a, b))
        pairs.append((b, a))

    # Sort pairs by increasing slope.
    pairs = sorted(pairs, key=lambda pair: pair[0] / pair[1])

    # Greedily take prefix sums until we exceed bounds of the quadrant.
    xsum, ysum = 0, 0
    used = 0
    for i, (x, y) in enumerate(pairs):
        if xsum >= LIM or ysum >= LIM:
            break
        xsum += x
        ysum += y
        used += 1

    print(f"Used {used} of {len(pairs)} vectors in [0, {LIM2}]^2")
