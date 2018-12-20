# LL-1-parse

## algorithm from stackoverflow

```
next <- first token of the input
stack <- START_SYMBOL
do {
    top <- stack.pop()
    if (top is a terminal and top == next) {
        next <- next token of the input
    } else if (top is a non terminal and PARSING_TABLE[top, next] exists) {
        stack.push(PARSING_TABLE[top, next]);
    } else {
         return invalid input;
    }
} while (stack is not empty);
return valid input;
```

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
