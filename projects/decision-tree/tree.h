#ifndef ZMDP_SRC_PARSERS_DECISION_TREE_H_
#define ZMDP_SRC_PARSERS_DECISION_TREE_H_

/* Initialize the decision-tree library--dimensionality of the model
   must be specified so that tables in the decision tree can be
   allocated appropriately later. */
extern void dtInit(int numActions, int numStates, int numObservations);

/* Adds an entry to the decision tree.  Any of the first four arguments
   can be given the value -1 (== WILDCARD_SPEC), indicating a wildcard.
   Later calls to dtAdd() overwrite earlier calls. */
extern void dtAdd(int action, int cur_state, int next_state, int obs,
                  double val);

/* Returns the immediate reward for a particular [a,s,s',o] tuple. */
extern double dtGet(int action, int cur_state, int next_state, int obs);

/* Cleans up all decision tree data structures on the heap. */
extern void dtDeallocate(void);

/* Print a textual representation of the decision tree data structure to
   stdout.  Intended for debugging. */
extern void dtDebugPrint(const char *header);

#endif  // ZMDP_SRC_PARSERS_DECISION_TREE_H_