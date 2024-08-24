from manacher import manacher

if __name__ in '__main__':
    s = 'babcbabcbaccba'
    m = manacher(s)

    lps = m.lps()
    print('The LPS of {} is {}'.format(s, lps))
