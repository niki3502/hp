import sys
import math

atgc = list()


def pr(x):
    return 10 ** (-x / 10)


def qs(date):
    for lst in date:
        a, t, g, c = 1, 1, 1, 1
        pos = lst.split()
        ref = pos[2]
        base = pos[4]
        baq = pos[5]
        j = 0
        for i in range(len(base)):

            if base[i] == '^':
                i += 2
            if base[i] == '.' or base[i] == ',':
                base = base[:i] + ref[0] + base[i + 1:]
            if base[i] == '-' and base[i - 1] != '^':
                i += 1 + int(base[i + 1])
                continue
            if base[i] == '$':
                continue
            if base[i] == '+' and base[i - 1] != '^':
                i += 1 + int(base[i + 1])
                continue

            if base[i] == 'A' or base[i] == 'a':
                a *= 1 - pr(ord(baq[j]) - 33)
                t *= pr(ord(baq[j]) - 33) / 3
                g *= pr(ord(baq[j]) - 33) / 3
                c *= pr(ord(baq[j]) - 33) / 3

            elif base[i] == 'T' or base[i] == 't':
                a *= pr(ord(baq[j]) - 33) / 3
                t *= 1 - pr(ord(baq[j]) - 33)
                g *= pr(ord(baq[j]) - 33) / 3
                c *= pr(ord(baq[j]) - 33) / 3

            elif base[i] == 'G' or base[i] == 'g':
                a *= pr(ord(baq[j]) - 33) / 3
                t *= pr(ord(baq[j]) - 33) / 3
                g *= 1 - pr(ord(baq[j]) - 33)
                c *= pr(ord(baq[j]) - 33) / 3

            elif base[i] == 'C' or base[i] == 'c':
                a *= pr(ord(baq[j]) - 33) / 3
                t *= pr(ord(baq[j]) - 33) / 3
                g *= pr(ord(baq[j]) - 33) / 3
                c *= 1 - pr(ord(baq[j]) - 33)

        j += 1
        atgc.append((a, t, g, c))
        print(pos[1], a, t, g, c, sep="\t")
    return


mpileup_date = open(sys.argv[1], 'r')
haplogroup_list = open(sys.argv[2], 'r')
# for line in mpileup_date:
#	print(line.split()[4])
qs(mpileup_date)
