import numpy
lines = open('Bsmall.in', 'r').read().splitlines()
case = int(lines[0])

with open('output.txt', 'w') as out:
    for number in range(case):
        findTidy = lines[number+1]
        while True:
            tidyList = numpy.array(list(findTidy))
            lenth = len(tidyList)
            flag = False
            for i in range(1, lenth):
                if not tidyList[i-1] <= tidyList[i]:
                    tidyList[i-1] = int(tidyList[i-1]) - 1
                    tidyList[i:] = 9
                    flag = True
                    findTidy = list(tidyList)
                    break
            if not flag:
                break

        print 'Case #{}: {}'.format(number+1, int(''.join(tidyList)))
