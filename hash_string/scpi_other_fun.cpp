typedef struct btreenode
{
	int   data;                  //  ������� 
	struct btreenode * LC;        //  ��ָ�� 
	struct btreenode * RC;        //  ��ָ�� 
}bnode;

int btree_build(bnode *root, char *str)