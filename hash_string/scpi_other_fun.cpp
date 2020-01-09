typedef struct btreenode
{
	int   data;                  //  结点数据 
	struct btreenode * LC;        //  左指针 
	struct btreenode * RC;        //  右指针 
}bnode;

int btree_build(bnode *root, char *str)