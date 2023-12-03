from Trie import Trie

def print_res(word: str, exist: bool, pre: bool) ->None:
    if pre:
        print('Is prefix \"{}\" exist?'.format(word))
    else:
        print('Is {} exist?'.format(word))

    if exist:
        print('Yes, {} exist!!!'.format(word))
    else:
        print('No, {} isn\'t exist!!!'.format(word))

if __name__ == "__main__":
    #insert: apple, search: apple, search: app, startsWith: app
    obj = Trie()

    obj.insert('apple')
    print('Insert word apple!')
    print_res('apple', obj.search('apple'), False)
    print_res('app', obj.search('app'), False)
    print_res('app', obj.startsWith('app'), True)
