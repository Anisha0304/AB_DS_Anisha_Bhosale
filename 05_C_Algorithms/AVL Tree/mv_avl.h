//Conditional Compilation

#ifndef	_MV_avl_H
#define	_MV_avl_H
#ifndef	SUCCESS
#define	SUCCESS	0
#endif
#ifndef	FAILURE
#define	FAILURE	1
#endif

//Typdefs 

struct mv_avl;
typedef	struct mv_avl* tree_t;
typedef	struct mv_avl**	p_tree_t;
struct tree_node;
typedef	struct tree_node tree_node_t;
typedef	struct tree_node* p_tree_node_t;
typedef	struct tree_node** pp_tree_node_t;
typedef	void* data_t;
typedef	int ret_t;
typedef	int status_t;
typedef	status_t(*COMPAREDATAPROC)(data_t,data_t);
typedef void(*SHOWDATAPROC)(data_t);
typedef void(*DELETEDATAPROC)(data_t);

//struct type definitions

struct mv_avl
{
p_tree_node_t root;
size_t no_of_elements;
};
#define	SIZE_TREE (sizeof(struct mv_avl))
struct tree_node
{
data_t data;
p_tree_node_t parent;
p_tree_node_t left;
p_tree_node_t right;
};
#define	SIZE_NODE (sizeof(node_t))
enum
{
STATUS_NONE =0,
STATUS_EQUAL,      //When both data are equal
STATUS_LESSER,     //When new_data is lesser than pnode->data
STATUS_GREATER     //When new_data is greater than pnode->data
};

//BST Interface Functions

extern tree_t create_tree();

//Tree Insert Function
/**
 * 
 * Function: mv_avl_insert
 * Input: 1) Tree
 * 		2)New Data
 * 		3)Compare Data Callback Proc
 * Returns:status of insertion	
 * 
 */

extern ret_t mv_avl_insert(tree_t tree,data_t new_data,COMPAREDATAPROC pcomparedataproc);

//Tree Remove Function
/**
 * 
 * Function: mv_avl_remove
 * Input: 1) Tree
 *		2)Existing Data
 * 		3)Compare Data Callback Proc
 * Returns: removed data from tree if data present OR NULL if not present
 *  
 */

extern data_t mv_avl_remove(tree_t tree,data_t data,COMPAREDATAPROC pcomparedataproc);

//Tree Traversal Function

extern  void    mv_avl_inorder_recursive(tree_t tree,SHOWDATAPROC pshowdataproc);
extern  void    mv_avl_preorder_recursive(tree_t tree,SHOWDATAPROC pshowdataproc);
extern  void    mv_avl_postorder_recursive(tree_t tree,SHOWDATAPROC pshowdataproc);
extern  void    mv_avl_inorder_non_recursive(tree_t tree,SHOWDATAPROC pshowdataproc);
extern  void    mv_avl_preorder_non_recursive(tree_t tree,SHOWDATAPROC pshowdataproc);
extern  void    mv_avl_postorder_non_recursive(tree_t tree,SHOWDATAPROC pshowdataproc);
extern  void    mv_avl_destroy_recursive(p_tree_t ptree,DELETEDATAPROC pdeletedataproc);
extern  void    mv_avl_destroy_non_recursive(p_tree_t ptree,DELETEDATAPROC pdeletedataproc);

#endif /* _MV_avl_H */

