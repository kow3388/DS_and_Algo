from KMP_algo import KMP

if __name__ == "__main__":
    src = "abcabcabcabe"
    tar = "abcabe"

    k = KMP()
    found = k.search(src, tar)

    if found:
        print("{} is in {}".format(tar, src))
    else:
        print("{} is not in {}".format(tar, src))
