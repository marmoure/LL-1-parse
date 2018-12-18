# LL-1-parse

##grammar
S -> if E then S else S
S -> begin S L
S -> print E
L -> end
L -> ; S L
L -> begin S L
E -> id = id
