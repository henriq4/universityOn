#ifndef DECISION_TREE_HGC
#define DECISION_TREE_HGC

extern void dtInit(int numActions, int numStates, int numObservations);
extern void dtAdd(int action, int cur_state, int next_state, int obs,
                  double val);
extern double dtGet(int action, int cur_state, int next_state, int obs);
extern void dtDeallocate(void);
extern void dtDebugPrint(const char *header);

#endif
