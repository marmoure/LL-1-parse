# LL-1-parse

## grammar

S -> if E then S else S

S -> begin S L

S -> print E

L -> end

L -> ; S L

L -> begin S L

E -> id = id

# parse table

Nonterminal | if | then | else | begin	| print	| end	| ;	| id	| =	| $
---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- 
S | S -> if E then S else S	 | ---- | ---- | S -> begin S L | S -> print E | ---- | ---- | ---- | ---- | ---- 
L | ---- | ---- | ---- | L -> begin S L | ---- | L -> end | L -> ; S L	 | ---- | ---- | ---- 
E | ---- | ---- | ---- | ---- | ---- | ---- | ---- | E -> id = id | ---- | ---- 
