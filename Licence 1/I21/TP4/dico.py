with open("dico-fr.txt", "r+") as file:
    lines = file.readlines()

words = [w.rstrip() for w in lines]
words = [w for w in words if len(w) > 1]
len_words = len(words)

m_word = ""
c_word = 0

i = 0
while i < len_words:
    wparent = words[i]
    childs = 0

    j = 0
    while j < len_words:
        wchild = words[i]

        if not len(wparent) == len(wchild):
            break

        similar = True
        index = 0
        while similar and index < len(wparent):
            if not wparent[index] in wchild:
                similar = False
            index += 1
        if similar: childs += 1
        j += 1

    if childs > c_word:
        c_word = childs
        m_word = wparent

    print((i + 1) / len_words * 100, "%")
    i += 1


print(m_word, "avec", c_word, "anagrammes")
