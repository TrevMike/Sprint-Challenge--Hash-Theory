# Theory of Computation Sprint Challenge

## Computation

Fill out truth tables for the following expressions:
<!-- 0 = False and 1 = True -->

1. `(A ∧ ¬B)`   
<!-- (A and NOT B) -->
(alternate: `(A && !B)`)
<!-- true A "and" False B = True -->
```
A     B     result
-------------------
0     0       0  A is False and B is False so this is False. 
0     1       0  A is False and B is True so this is False. 
1     0       1  A is True and B is False so this is True. 
1     1       0  A is True and B is True so this is False. 
```


2. `(¬A ∨ B) ∧ ¬(A ∧ ¬B)`  
<!-- (NOT A or B) and NOT(A and NOT B) -->
 (alternate: `(!A || B) && !(A && !B)`)
 <!-- (False A or True B ) and False (True A and False B) -->
 <!-- Due to De Morgan's Law  !(A && !B) == (!A or B) --> 
 <!-- (!A || B) && (!A || B) which is the same is (!A || B) -->
 <!-- False A OR True B AND False A OR True B -->
 <!-- it can either be False A or True B for it to be True  -->
```
A     B     result
-------------------
0     0       1  A False A so its True.
0     1       1  A False A so its True. 
1     0       0  A True A so we check B and Its False so this is False.
1     1       1  A True A so we check B and its True so this is True. 
```

3. `¬(A ∧ B) ∨ ( (A ∧ C) ∧ ¬(B ∨ ¬C) )`   
<!--  NOT (A and B) or ( (A and C) and NOT(B or NOT C) )    -->
(alternate: `!(A && B) || ( (A && C) && !(B || !C) )`)
<!-- False (True A and True B) OR ( (True A and True C ) and False(True B or False C) ) -->
<!-- False A or False B and !(B || !C) == (!B && C) -->
<!-- (!A || !B) || ( (A && C) && (!B && C) -->
<!-- (False A OR False B) OR ( (True A and True C) AND (False B AND True C) )  -->
  * (Hint: Is it possible to calculate this using code?)
```
A     B     C     result
-------------------------
0     0     0       1     _
0     0     1       1     |
0     1     0       1     | all only need either a false A or B for it to be True.
0     1     1       1     |
1     0     0       1     |
1     0     1       1     _
1     1     0       0     \ ___ \
1     1     1       0     / --- / these have True A and B which would be False. 
```

## STRETCH GOAL

The sum of two binary digits can be represented with the following truth table:

* A + B
```
A     B     CARRY   SUM
------------------------
0     0       0      0
0     1       0      1
1     0       0      1
1     1       1      0
```
This can be represented with boolean algebra like so:

* `SUM = A ⊕ B`  (alternate: `A ^ B` or `A xor B`)
* `CARRY = A ∧ B`  (alternate: `A && B`)


How can you represent the SUM and CARRY of adding THREE digits with a truth table and in boolean algebra?

* A + B + C
```
A     B     C      carry   sum
--------------------------------
0     0     0        ?      ?
0     0     1        ?      ?
0     1     0        ?      ?
0     1     1        ?      ?
1     0     0        ?      ?
1     0     1        ?      ?
1     1     0        ?      ?
1     1     1        ?      ?
```
* SUM = ?
* CARRY = ?
