## Finite Automata

Have a $\Sigma = \{a, b\}$ with L = {w $\in \Sigma \mid$ w have 'aa' or 'bb' as subword}, we can construct this finite automata.

### Notations for finite automata

#### Function

$M = (Q, \Sigma, \delta, q_0, F)$

$Q = \{q_0, q_1, q_2, q_3\}$

$\Sigma = \{a, b\}$

$\delta = Qx\Sigma \to Q$

$q_o: q_0$

$F = \{q_2\}$

#### Table

| δ  | a  | b  |
|--- |--- |--- |
| q0 | q1 | q3 |
|->q1| q2 | q3 |
|*q2 | q2 | q2 |
| q3 | q1 | q2 |
