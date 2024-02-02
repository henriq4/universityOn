// #include "tree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DT_TABLE_DEPTH (4)
#define WILDCARD_SPEC_FLOAT (-1.0)

enum { DT_VAL, DT_TABLE };

typedef float wildcard_t;

struct DTNodeStruct;
struct DTTableStruct;

struct DTTableStruct {
  int numEntries;
  struct DTNodeStruct **entries;
  struct DTNodeStruct *defaultEntry;
};

struct DTNodeStruct {
  int type;
  union {
    struct DTTableStruct subTree;
    double val;
  } data;
};

typedef struct DTNodeStruct DTNode;
typedef struct DTTableStruct DTTable;

static int *gTableSizes = NULL;
static DTNode *gTree = NULL;

static DTNode *dtNewNodeVal(double val) {
  DTNode *out;

  out = (DTNode *)malloc(sizeof(DTNode));
  out->type = DT_VAL;
  out->data.val = val;

  return out;
}

static DTNode *dtNewNodeTable(int numEntries) {
  DTNode *out;

  out = (DTNode *)malloc(sizeof(DTNode));
  out->type = DT_TABLE;
  dtInitTable(&out->data.subTree, numEntries);

  return out;
}

static void dtInitTable(DTTable *t, int numEntries) {
  t->numEntries = numEntries;
  t->entries = (DTNode **)malloc(numEntries * sizeof(DTNode *));
  memset(t->entries, 0, numEntries * sizeof(DTNode *));
  t->defaultEntry = NULL;
}

static void dtDestroyNode(DTNode *n) {
  if (NULL == n)
    return;

  switch (n->type) {
  case DT_VAL:
    break;
  case DT_TABLE:
    dtDestroyTable(&n->data.subTree);
    break;
  default:
    assert(0);
  }

  free(n);
}

static void dtDestroyTable(DTTable *t) {
  int i;

  for (i = 0; i < t->numEntries; i++) {
    dtDestroyNode(t->entries[i]);
  }
  dtDestroyNode(t->defaultEntry);
  free(t->entries);
  t->entries = NULL;
}

static DTNode *dtDeepCopyNode(const DTNode *in) {
  DTNode *out;

  if (NULL == in) {
    out = NULL;
  } else {
    switch (in->type) {
    case DT_VAL:
      out = dtNewNodeVal(in->data.val);
      break;
    case DT_TABLE:
      out = dtNewNodeTable(in->data.subTree.numEntries);
      dtDeepCopyTable(&out->data.subTree, &in->data.subTree);
      break;
    default:
      assert(0);
    }
  }

  return out;
}

static void dtDeepCopyTable(DTTable *out, const DTTable *in) {
  int i;

  dtInitTable(out, in->numEntries);
  out->defaultEntry = dtDeepCopyNode(in->defaultEntry);
  for (i = 0; i < in->numEntries; i++) {
    if (NULL != in->entries[i]) {
      out->entries[i] = dtDeepCopyNode(in->entries[i]);
    }
  }
}

static DTNode *dtConvertToTable(DTNode *in, int numEntries) {
  DTNode *out;

  assert(NULL != in);

  switch (in->type) {
  case DT_VAL:
    out = dtNewNodeTable(numEntries);
    out->data.subTree.defaultEntry = dtNewNodeVal(in->data.val);
    dtDestroyNode(in);
    break;
  case DT_TABLE:
    out = in;
    break;
  default:
    assert(0);
  }

  return out;
}

DTNode *dtAddInternal(DTNode *node, wildcard_t *vec, int index, double val) {
  int i;
  int allWildcards;
  DTNode **entryP;

  allWildcards = 1;
  for (i = index; i < DT_TABLE_DEPTH; i++) {
    if (vec[i] != WILDCARD_SPEC_FLOAT) {
      allWildcards = 0;
      break;
    }
  }

  if (allWildcards) {
    dtDestroyNode(node);
    node = dtNewNodeVal(val);
  } else if (WILDCARD_SPEC_FLOAT == vec[index]) {
    node = dtConvertToTable(node, gTableSizes[index]);
    node->data.subTree.defaultEntry =
        dtAddInternal(node->data.subTree.defaultEntry, vec, index + 1, val);
    for (i = 0; i < gTableSizes[index]; i++) {
      if (NULL != node->data.subTree.entries[i]) {
        node->data.subTree.entries[i] =
            dtAddInternal(node->data.subTree.entries[i], vec, index + 1, val);
      }
    }
  } else {
    node = dtConvertToTable(node, gTableSizes[index]);
    entryP = &node->data.subTree.entries[(int)vec[index]];
    if (NULL == *entryP) {
      *entryP = dtDeepCopyNode(node->data.subTree.defaultEntry);
    }
    *entryP = dtAddInternal(*entryP, vec, index + 1, val);
  }

  return node;
}

static double dtGetInternal(DTNode *node, wildcard_t *vec, int index) {
  DTNode *entry;

  assert(NULL != node);

  switch (node->type) {
  case DT_VAL:
    return node->data.val;
  case DT_TABLE:
    entry = node->data.subTree.entries[(int)vec[index]];
    if (NULL == entry) {
      entry = node->data.subTree.defaultEntry;
    }
    return dtGetInternal(entry, vec, index + 1);
  default:
    assert(0);
  }
}

static void dtSpaces(int indent) {
  int i;

  for (i = 0; i < indent; i++) {
    putchar(' ');
  }
}

static void dtDebugPrintNode(DTNode *n, int indent) {
  if (NULL == n) {
    dtSpaces(indent);
    printf("(NULL)\n");
    return;
  }

  switch (n->type) {
  case DT_VAL:
    dtSpaces(indent);
    printf("val = %lf\n", n->data.val);
    break;
  case DT_TABLE:
    dtDebugPrintTable(&n->data.subTree, indent);
    break;
  default:
    assert(0);
  }
}

static void dtDebugPrintTable(DTTable *t, int indent) {
  int i;

  dtSpaces(indent);
  printf("table:\n");
  dtSpaces(indent + 2);
  printf("default:\n");
  dtDebugPrintNode(t->defaultEntry, indent + 4);
  for (i = 0; i < t->numEntries; i++) {
    dtSpaces(indent + 2);
    if (NULL == t->entries[i]) {
      printf("entry %d: (default)\n", i);
    } else {
      printf("entry %d:\n", i);
      dtDebugPrintNode(t->entries[i], indent + 4);
    }
  }
}

void dtInit(int numActions, int numStates, int numObservations) {
  if (NULL != gTree)
    return;

  gTableSizes = (int *)malloc(DT_TABLE_DEPTH * sizeof(int));
  gTableSizes[0] = numActions;
  gTableSizes[1] = numStates;
  gTableSizes[2] = numStates;
  gTableSizes[3] = numObservations;

  gTree = dtNewNodeVal(0);
}

void dtAdd(int action, int cur_state, int next_state, int obs, double val) {
  int vec[DT_TABLE_DEPTH];
  vec[0] = action;
  vec[1] = cur_state;
  vec[2] = next_state;
  vec[3] = obs;

  gTree = dtAddInternal(gTree, vec, 0, val);
}

double dtGet(int action, int cur_state, int next_state, int obs) {
  int vec[DT_TABLE_DEPTH];
  vec[0] = action;
  vec[1] = cur_state;
  vec[2] = next_state;
  vec[3] = obs;

  return dtGetInternal(gTree, vec, 0);
}

void dtDeallocate(void) {
  dtDestroyNode(gTree);
  gTree = NULL;
  free(gTableSizes);
  gTableSizes = NULL;
}

void dtDebugPrint(const char *header) {
  printf("%s\n", header);
  dtDebugPrintNode(gTree, 2);
}

int testOnce() {
  FILE *file;
  file = fopen("assets/training.txt", "r");

  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }

  int nActions, nStates, nObservations;
  float v1, v2, v3, v4, v5, result;

  fscanf(file, "%d %d %d", &nActions, &nStates, &nObservations);
  printf("%d %d %d\n", nActions, nStates, nObservations);
  dtInit(nActions, nStates, nObservations);
  while (fscanf(file, "%f,%f,%f,%f,%f", &v1, &v2, &v3, &v4, &v5) == 5) {
    printf("%.1f %.1f %.1f %.1f %.1f\n", v1, v2, v3, v4, v5);

    dtAdd(v1, v2, v3, v4, v5);
    result = dtGet(v1, v2, v3, v4);
    printf("expecting: result=%lf\n", v5);
    printf("got:       result=%lf\n", result);
  }

  dtDeallocate();

  fclose(file);

  return 0;
}

int main(int argc, char **argv) {
  testOnce();
  return 0;
}
