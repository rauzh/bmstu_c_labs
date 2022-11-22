#ifndef __TYPES_H_LAB_10__
#define __TYPES_H_LAB_10__

typedef struct
{
	int aim_type;
	char *name;
} data_t;

typedef struct node node_t;

struct node
{
	void *data;
	node_t *next;
};

#endif // __TYPES_H_LAB_10__
