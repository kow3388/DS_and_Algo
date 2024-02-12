from moore_voting_algo import voting

if __name__ == '__main__':
    nums = [2, 2, 1, 1, 1, 2, 2]

    v = voting()
    majority = v.vote_algo(nums)

    print("The input array is")
    print(nums)
    print("The majority element is: {}".format(majority))
