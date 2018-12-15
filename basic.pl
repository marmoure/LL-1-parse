/*************
   NOT
    _______
    |     |
  A-| NOT |-OUT
    |_____|
*************/
%   A  OUT
not(0,  1 ).
not(1,  0 ).

/*************
   AND Gate
    _______
  A-|     |
    | AND |-OUT
  B-|_____|
*************/
%   A  B  OUT
and(0, 0,  0 ).
and(0, 1,  0 ).
and(1, 0,  0 ).
and(1, 1,  1 ).

/*************
   OR Gate
    ______
  A-|    |
    | OR |-OUT
  B-|____|
*************/
%  A  B  OUT
or(0, 0,  0 ).
or(0, 1,  1 ).
or(1, 0,  1 ).
or(1, 1,  1 ).

/*************
   XOR Gate
    _______
  A-|     |
    | XOR |-OUT
  B-|_____|
*************/
%   A  B  OUT
xor(0, 0,  0 ).
xor(0, 1,  1 ).
xor(1, 0,  1 ).
xor(1, 1,  0 ).

/********
 
     MUX Gate

     SEL
    __|____
  A-|     |
    | MUX |-OUT
  B-|_____|
 ********/
%   A B SEL OUT

mux(A,B,0,   A).
mux(A,B,1,   B).


/********
 
 DMUX Gate

     SEL
    __|____
    |     |-A
 IN-| DMUX|
    |_____|-B
 ********/
%    IN SEL A B

dmux(IN,0,  IN,0).
dmux(IN,1,  0,IN).

/********
 
 AND16 Gate

        _______
  A[16]-|     |
        |AND16|-OUT[16]
  B[16]-|_____|
 ********/
% A[16] B[16] OUT[16]

and16([A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16],[B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16],[O1,O2,O3,O4,O5,O6,O7,O8,O9,O10,O11,O12,O13,O14,O15,O16]) :-
    and(A1,B1,O1),
    and(A2,B2,O2),
    and(A3,B3,O3),
    and(A4,B4,O4),
    and(A5,B5,O5),
    and(A6,B6,O6),
    and(A7,B7,O7),
    and(A8,B8,O8),
    and(A9,B9,O9),
    and(A10,B10,O10),
    and(A11,B11,O11),
    and(A12,B12,O12),
    and(A13,B13,O13),
    and(A14,B14,O14),
    and(A15,B15,O15),
    and(A16,B16,O16).

/********
 
 OR8WAY Gate
        ________
        |      |
  IN[8]-|OR8WAY|-OUT
        |______|
 ********/
% IN[8] OUT
or8way([0,0,0,0,0,0,0],0).
or8way([_,_,_,_,_,_,_],1).


